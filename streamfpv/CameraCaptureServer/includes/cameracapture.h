#ifndef CAMERACAPTURE_H
#define CAMERACAPTURE_H

#include <opencv4/opencv2/opencv.hpp>
#include <QObject>

class CameraCapture : public QObject
{
    Q_OBJECT
public:
    CameraCapture(int _numberCamera);
    ~CameraCapture();

    void setNumberCamera(int _numberCamera);

signals:
    void frameCapture(cv::Mat _frame);

public slots:
    void captureContinue();

private:
    QList<QPair<QString, int>> getVideoDevices();

    int mNumberCamera;
    cv::Mat mFrame;
    cv::VideoCapture mCameraCapture;
};

#endif // CAMERACAPTURE_H
