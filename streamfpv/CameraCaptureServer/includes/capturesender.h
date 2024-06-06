#ifndef CAPTURESENDER_H
#define CAPTURESENDER_H

#include <QObject>
#include <QHostAddress>

#include <opencv4/opencv2/opencv.hpp>

#include <controlstructs.h>

class QUdpSocket;

class CaptureSender : public QObject
{
    Q_OBJECT
public:
    CaptureSender(QObject *parent = nullptr);

public slots:
    void init();
    void setDestination(QHostAddress _ip, short _port);
    void send(cv::Mat _frame);

private:


    std::vector<int> compression_params;
    QUdpSocket *mSenderSocket;
    QHostAddress mIp;
    short mPort;
    DataTransaction::CaptureData mPkgUnion;
    std::vector<uchar> mEncodedImage;
};

#endif // CAPTURESENDER_H
