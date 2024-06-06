#ifndef VISORGUI_H
#define VISORGUI_H
#include "cmd_utils.h"

#include <opencv4/opencv2/opencv.hpp>

#include <QMainWindow>
#include <QWidget>
#include <QtNetwork>

class QLabel;
class QListWidget;
class QStackedWidget;
class QVBoxLayout;
class QPushButton;
class QListWidgetItem;
class VisorSubcription;
class QTimer;
class ImageWidget;
class VisorController;
class QTimer;
class VisorGUI : public QWidget
{
    Q_OBJECT
public:
    explicit VisorGUI(QSize res, QWidget *parent = nullptr);

    ~VisorGUI(void);
protected:
    bool eventFilter(QObject *object, QEvent *event) override;
signals:
    void updateAddress(QHostAddress _ip);
    void resetAddress();
private slots:
    void displayImageData(cv::Mat);
    void switchLayout(void);
    void onNetworkListItemClicked(QListWidgetItem*);
    // void updateListWithNetworkInterfaces(const std::vector<CmdUtils::Iface>& interfaces);

private:
    void onUpdateNetworkListPressed();
    void setupConnections(void);
    void setupUi(void);
    void styleApplication();
    void setupWidgets(void);
    void setupLayouts(void);
    void populateNetworkList(void);
    void configureLabel(QLabel*, int, bool, QSize, Qt::Alignment);
    void populateListWithNetworkInterfaces(QListWidget* , const std::vector<CmdUtils::Iface>&);
    void useIP(QPair<QString, QString> &);
    // void updateNetworkUsage(qreal value);

    VisorController *vController;
    VisorSubcription* vSub;
    QVBoxLayout* cameraLayout;
    QVBoxLayout* settingsLayout;
    QVBoxLayout* mainLayout;
    QWidget* centralWidgetCamera;
    QWidget* centralWidgetSettings;
    QWidget* mainWidget;
    QStackedWidget* stackedWidget;
    QListWidget* networkListWidget;
    QTimer* updateSystemInfoTimer;
    ImageWidget* imageWidget;
    QLabel* waitVideoLabel;
    QLabel* networkTextLabel;
    QThread* visorDisplayThread;
    QSize resolution;
    QString selectedIP;

    QTimer* updateListTimer;

};
#endif // VISORGUI_H
