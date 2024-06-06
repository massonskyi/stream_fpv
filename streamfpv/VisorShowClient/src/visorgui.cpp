#include "visorgui.h"
#include "visorcontroller.h"
#include "visorsubcription.h"
#include "imagewidget.h"
#include "networkmonitor.h"

#include "constants.h"


#include <opencv4/opencv2/opencv.hpp>

#include <QThread>
#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QStackedWidget>
#include <QStandardItemModel>
#include <QListWidget>
#include <QHeaderView>
#include <QMessageBox>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>

#ifdef ORANGE_PI_PLATFORM
#include <wiringPi.h>
#endif

VisorGUI::VisorGUI(QSize res, QWidget *parent) :
    QWidget(parent),visorDisplayThread(new QThread(this)),
    resolution(res),
    vSub(new VisorSubcription())

{
    setupUi();
    vController = new VisorController();
    vController->moveToThread(visorDisplayThread);
    connect(visorDisplayThread, &QThread::started, vController, &VisorController::startController);
    connect(vController, &VisorController::imageDataCollectionReady, this, &VisorGUI::displayImageData);
    connect(vController, &QObject::destroyed, visorDisplayThread, &QThread::quit);
    connect(visorDisplayThread, &QThread::finished, visorDisplayThread, &QThread::deleteLater);
    connect(this, &VisorGUI::updateAddress, vController, &VisorController::updateIp);
    connect(this, &VisorGUI::resetAddress, vController, &VisorController::resetIp);
    visorDisplayThread->start();
    /*
    QTimer* timer = new QTimer();
    timer->setInterval(5000);
    timer->setSingleShot(true);
    timer->start();
    */
}

VisorGUI::~VisorGUI(void){
    visorDisplayThread->quit();
    visorDisplayThread->wait();
}

void VisorGUI::setupUi(void) {
    setupWidgets();
    styleApplication();
    populateNetworkList();
    setupLayouts();
    setupConnections();
    showFullScreen();
    switchLayout();
}

void VisorGUI::styleApplication() {
    QFont defaultFont = QApplication::font();
    defaultFont.setFamily("Segoe UI");
    defaultFont.setPointSize(10);
    QApplication::setFont(defaultFont);

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(45, 45, 45));
    darkPalette.setColor(QPalette::WindowText, QColor(220, 220, 220));
    darkPalette.setColor(QPalette::Base, QColor(18, 18, 18));
    darkPalette.setColor(QPalette::AlternateBase, QColor(45, 45, 45));
    darkPalette.setColor(QPalette::ToolTipBase, QColor(255, 255, 220));
    darkPalette.setColor(QPalette::ToolTipText, QColor(220, 220, 220));
    darkPalette.setColor(QPalette::Text, QColor(220, 220, 220));
    darkPalette.setColor(QPalette::Button, QColor(45, 45, 45));
    darkPalette.setColor(QPalette::ButtonText, QColor(220, 220, 220));
    darkPalette.setColor(QPalette::Highlight, QColor(38, 79, 120));
    darkPalette.setColor(QPalette::HighlightedText, QColor(255, 255, 255));
    QApplication::setPalette(darkPalette);


    QString globalStyleSheet = R"(
        *{
         margin:0;
        }
        QWidget {
            color: #DCDCDC;
            background-color: #2D2D2D;
            margin:0;
        }
        QVBoxLayout{
            margin:0;
        }
        QLabel {
            font-size: 12px;
            border: none;
        }
        QListWidget {
            border: none;
            padding-left: 5px;
            font-size: 24px;
        }
        QListWidget::item {
            border-bottom: 1px solid #5A5A5A;
            padding: 5px;
        }
        QListWidget::item:selected {
            background-color: #7AC7A0;
            color: #403983;
        }
        ImageWidget{

        }
    )";
    this->setStyleSheet(globalStyleSheet);
}

void VisorGUI::setupWidgets() {
    stackedWidget = new QStackedWidget(this);

    centralWidgetCamera = new QWidget();
    centralWidgetSettings = new QWidget();

    cameraLayout = new QVBoxLayout(centralWidgetCamera);
    settingsLayout = new QVBoxLayout(centralWidgetSettings);

    waitVideoLabel = new QLabel("Ожидание видео ...");
    configureLabel(waitVideoLabel, 32, true, QSize(resolution.width(), resolution.height()), Qt::AlignCenter);

    networkTextLabel = new QLabel("Настройки сети:");
    networkTextLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    networkListWidget = new QListWidget(this);
    networkListWidget->installEventFilter(this);

    imageWidget = new ImageWidget();
    imageWidget->setBaseSize(QSize(resolution.width(), resolution.height()));
    // configureLabel(imageLabel, 32, true, , Qt::AlignCenter);

    centralWidgetCamera->installEventFilter(this);
}

void VisorGUI::setupLayouts() {
    settingsLayout->addWidget(networkTextLabel);
    settingsLayout->addWidget(networkListWidget);


    cameraLayout->addWidget(imageWidget);
    cameraLayout->setContentsMargins(0,0,0,0);


    centralWidgetCamera->setLayout(cameraLayout);
    centralWidgetSettings->setLayout(settingsLayout);

    stackedWidget->addWidget(centralWidgetCamera);
    stackedWidget->addWidget(centralWidgetSettings);


    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(stackedWidget);
    mainLayout->setContentsMargins(0,0,0,0);

    setLayout(mainLayout);

//    mainWidget = new QWidget();
//    mainWidget->setLayout(mainLayout);
//    setCentralWidget(mainWidget);
}

void VisorGUI::configureLabel(QLabel *label, int pixelSize, bool bold, QSize minSize, Qt::Alignment alignment) {
    QFont font = label->font();
    font.setPixelSize(pixelSize);
    font.setBold(bold);
    label->setFont(font);
    label->setMinimumSize(minSize);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setAlignment(alignment);
}

void VisorGUI::setupConnections() {
    connect(networkListWidget, &QListWidget::itemClicked,this, &VisorGUI::onNetworkListItemClicked);
}

void VisorGUI::switchLayout() {
    int currentIndex = stackedWidget->currentIndex();
    int nextIndex = (currentIndex + 1) % stackedWidget->count();
    stackedWidget->setCurrentIndex(nextIndex);
}

bool VisorGUI::eventFilter(QObject *object, QEvent *event) {
    QKeyEvent *keyEvent = dynamic_cast<QKeyEvent *>(event);

    if (object == networkListWidget && event->type() == QEvent::KeyPress) {
        switch (keyEvent->key()) {
        case Qt::Key_Right:
        {
            QListWidgetItem* currentItem = networkListWidget->currentItem();
            if (currentItem) {
                onNetworkListItemClicked(currentItem);
                return true;
            }
        }
        break;
        case Qt::Key_Left:
            {
                networkListWidget->clear();
                networkListWidget->update();
                for(size_t i = 0; i< 10;i++){
                    QCoreApplication::processEvents();
                }
                /*
                */
                populateNetworkList();
            }
            break;
        default:
            break;
        }
    }

    if (object == centralWidgetCamera && event->type() == QEvent::KeyPress) {
        if (keyEvent && keyEvent->key() == Qt::Key_Left) {
            onUpdateNetworkListPressed();
            return true;
        }
    }
    if (event->type() == QEvent::FocusOut) {
        showFullScreen();
    }
    return QObject::eventFilter(object, event);
}

void VisorGUI::onNetworkListItemClicked(QListWidgetItem *item) {
    QPair<QString, QString> ips = item->data(Qt::UserRole).value<QPair<QString, QString>>();
    useIP(ips);
}

void VisorGUI::useIP(QPair<QString, QString> &ips) {

    vSub->init(QHostAddress(ips.first), QHostAddress(ips.second),Constants::START_PORT);

    if(vSub->sendStart()){
        emit updateAddress(QHostAddress(ips.first));
        switchLayout();
    }
    else{
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось отправить данные, проверьте правильность выбранного IP"));
    }
}



void VisorGUI::onUpdateNetworkListPressed(){
    switchLayout();
    vSub->sendStop();
    emit resetAddress();
}
void VisorGUI::populateNetworkList() {
    try {
        auto interfaces = CmdUtils::get_iface();
        populateListWithNetworkInterfaces(networkListWidget, interfaces);
    } catch (const std::exception& e) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не получилось получить данные сетевого интерфейса: %1").arg(e.what()));
    }
}

void VisorGUI::populateListWithNetworkInterfaces(QListWidget *listWidget, const std::vector<CmdUtils::Iface>& interfaces) {
    for (const auto &iface : interfaces) {
        auto arpList = CmdUtils::arp_scan(iface.iface_name.c_str());
        for (const auto &arpInfo : arpList) {
            QString entry = QString::fromStdString(arpInfo.name) + " - " + QString::fromStdString(arpInfo.ip);
            QPair<QString, QString> ips = qMakePair(QString::fromStdString(iface.iface_ip), QString::fromStdString(arpInfo.ip));

            auto item = new QListWidgetItem(entry, listWidget);

            item->setData(Qt::UserRole, QVariant::fromValue(ips));
        }
    }
}
void VisorGUI::displayImageData(cv::Mat decoded_image){

#ifdef ORANGE_PI_PLATFORM
    if constexpr (WRITE_CHECKING)
        digitalWrite(27, 1);
#endif

    QImage img(decoded_image.data, decoded_image.cols, decoded_image.rows, static_cast<int>(decoded_image.step), QImage::Format_BGR888);
    img = img.scaled(resolution.width(),resolution.height(),Qt::KeepAspectRatioByExpanding,Qt::FastTransformation);
    imageWidget->setImage(img);

#ifdef ORANGE_PI_PLATFORM
    if constexpr (WRITE_CHECKING)
        digitalWrite(27, 0);
#endif
}
