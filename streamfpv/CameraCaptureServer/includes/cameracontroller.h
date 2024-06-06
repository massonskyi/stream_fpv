#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include <QObject>
#include <QUdpSocket>

class QLabel;
class QTcpServer;
class QTcpSocket;
class QThread;

class CameraCapture;
class CaptureSender;

class CameraController : public QObject
{
    Q_OBJECT
public:
    CameraController();
    ~CameraController();

signals:
    void setDestinationAddres(QHostAddress, unsigned short);
protected slots:
    void control();
    void lostConnection();
private:
    void startCameraCapture(int _cameraNumber);

    QTcpServer *mServer;
    QThread *mCameraThread, *mSenderThread;
    CameraCapture *mCamera;
    CaptureSender *mSender;
};
#endif // CAMERACONTROLLER_H
