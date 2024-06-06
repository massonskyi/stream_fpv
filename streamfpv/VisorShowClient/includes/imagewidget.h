#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H
#include <QWidget>
#include <QPainter>
class ImageWidget : public QWidget {
    Q_OBJECT
public:
    ImageWidget(QWidget* parent = nullptr) : QWidget(parent) {}

    void setImage(const QImage& image) {
        currentImage = image;
        update();
    }

protected:
    void paintEvent(QPaintEvent* event) override {
        QWidget::paintEvent(event);
        QPainter painter(this);
        painter.drawImage(0, 0, currentImage);
    }

private:
    QImage currentImage;
};

#endif // IMAGEWIDGET_H
