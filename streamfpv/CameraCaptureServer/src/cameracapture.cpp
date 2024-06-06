#include "cameracapture.h"
#include "qdebug.h"
#include <constants.h>
#include <QThread>
#include <QProcess>
#include <QStringList>
#include <QDebug>
#ifdef ORANGE_PI_PLATFORM
#include <wiringPi.h>
#endif

CameraCapture::CameraCapture(int _numberCamera):mNumberCamera(_numberCamera){
    mCameraCapture.open(mNumberCamera ,cv::CAP_ANY);
    if (!mCameraCapture.isOpened()) {
        for(const auto& device : getVideoDevices()){
            if(mCameraCapture.open(device.second, cv::CAP_ANY)){
                qDebug()<<device.first << device.second;
                break;
            }
        }
    }
}

CameraCapture::~CameraCapture()
{
    if(mCameraCapture.isOpened())
        mCameraCapture.release();
}


void CameraCapture::setNumberCamera(int _numberCamera)
{
    mNumberCamera = _numberCamera;
}

void CameraCapture::captureContinue()
{
    bool checking = false;
    while (!QThread::currentThread()->isInterruptionRequested()) {
        if (mCameraCapture.grab()) {
            mCameraCapture.retrieve(mFrame);
            if (!mFrame.empty()) {

#ifdef ORANGE_PI_PLATFORM
                if constexpr (WRITE_CHECKING){
                    digitalWrite(27, checking ? 0 : 1);
			checking = !checking;
			qDebug()<<"frame size: (rows * cols)"<<mFrame.rows * mFrame.cols;
		}
#endif

                emit frameCapture(mFrame);

            }
        }

    }
}
QList<QPair<QString, int>> CameraCapture::getVideoDevices()
{
    QList<QPair<QString, int>> devices;

    QProcess process;
    process.start("v4l2-ctl", QStringList() << "--list-devices");
    if (!process.waitForStarted() || !process.waitForFinished())
    {
        qDebug() << "Error: Failed to execute the command";
        return devices;
    }

    QString result = process.readAllStandardOutput();
    QStringList lines = result.split('\n');
    QString deviceName;
    for (const QString &line : lines)
    {
        if (line.startsWith("USB2.0 PC CAMERA"))
        {
            deviceName = line;
        }
        else if (line.startsWith("\t/dev/video") || line.startsWith("\t/dev/media"))
        {
            if (!deviceName.isEmpty())
            {
                int startIndex = line.lastIndexOf("video");
                if (startIndex != -1)
                {
            devices.append(qMakePair(line.mid(startIndex), line.mid(startIndex).right(1).toInt()));
                }
            }
        }
    }

    return devices;
}
