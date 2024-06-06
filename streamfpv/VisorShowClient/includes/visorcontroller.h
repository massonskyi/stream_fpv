#ifndef VISORCONTROLLER_H
#define VISORCONTROLLER_H
#include <QObject>
#include <QUdpSocket>
#include <opencv4/opencv2/opencv.hpp>

class VisorController: public QObject
{
        Q_OBJECT
public:
    explicit VisorController(QObject *parent = nullptr);
    void startController(void);

public slots:
    void dataAcquisitionProcess(void);
    void updateIp(const QHostAddress& _ip);
    void resetIp();
signals:
    void imageDataCollectionReady(cv::Mat);

private:
    void collectionImageData(const QByteArray&);

    QHostAddress localAddress;
    unsigned char currentImgFrameNum;
    unsigned short countReceivedPackage;
    QUdpSocket* vUdpSocket;
    QMap<unsigned char, QByteArray> imageBuffers;
};

#endif // VISORCONTROLLER_H
