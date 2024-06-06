#include "capturesender.h"

#include <QtNetwork/QUdpSocket>

#ifdef ORANGE_PI_PLATFORM
#include <wiringPi.h>
#endif

CaptureSender::CaptureSender(QObject *parent) :
    QObject(parent),
    compression_params({cv::IMWRITE_JPEG_QUALITY, 80}),
    mIp(QHostAddress::Any),//other
    mPort(12000)
{
    memset(mPkgUnion.raw, 0, sizeof(mPkgUnion.raw));
}

void CaptureSender::init()
{
    mSenderSocket = new QUdpSocket(this);
}

void CaptureSender::setDestination(QHostAddress _ip, short _port)
{
    mIp = _ip;
    mPort = _port;
}

void CaptureSender::send(cv::Mat _frame)
{
#ifdef ORANGE_PI_PLATFORM
    if constexpr (WRITE_CHECKING)
        digitalWrite(26, 1);
#endif
    if (!cv::imencode(".jpg", _frame, mEncodedImage, compression_params)) {
        qWarning() << "Image encoding failed.";
        return;
    }

    if(mEncodedImage.empty())
        return;

    auto encode_size = mEncodedImage.size();
#ifdef ORANGE_PI_PLATFORM
    if constexpr (WRITE_CHECKING)
	qDebug()<<"codec size = "<<mEncodedImage.size();
#endif
    auto count_pkg = (encode_size / Constants::CAPTURE_PAYLOAD_SIZE_PKG);
    count_pkg = Constants::CAPTURE_PAYLOAD_SIZE_PKG * count_pkg < encode_size? count_pkg + 1: count_pkg;


    mPkgUnion.parted.message_id = Constants::MESSAGE_ID_CODE;
    mPkgUnion.parted.pkg_count = count_pkg;

    for(int i = 0; i < count_pkg; i++){
        memset(mPkgUnion.parted.payload, 0, Constants::CAPTURE_PAYLOAD_SIZE_PKG);
        int shift = i * Constants::CAPTURE_PAYLOAD_SIZE_PKG;
        auto remain = encode_size - Constants::CAPTURE_PAYLOAD_SIZE_PKG * i;
        remain = (remain > Constants::CAPTURE_PAYLOAD_SIZE_PKG) ? Constants::CAPTURE_PAYLOAD_SIZE_PKG : remain;

        mPkgUnion.parted.payload_size = remain;
        mPkgUnion.parted.frame_part = i;

        memcpy(mPkgUnion.parted.payload, mEncodedImage.data()+shift, remain);
#ifdef ORANGE_PI_PLATFORM
        if constexpr (WRITE_CHECKING)
            digitalWrite(26, 0);
#endif
        mSenderSocket->writeDatagram(mPkgUnion.raw, Constants::CAPTURE_SIZE_PKG, mIp, mPort);
        if(remain < Constants::CAPTURE_PAYLOAD_SIZE_PKG)
            break;
    }

    mPkgUnion.parted.frame_num++;
    mPkgUnion.parted.frame_num %= 255;
}
