#include "visorcontroller.h"
#include "localconstants.h"
#include <constants.h>
#include <controlstructs.h>

#include <QThread>
#include <QDataStream>
#include <QImage>
#include <QtEndian>
#include <QBuffer>
#include <algorithm>
#ifdef ORANGE_PI_PLATFORM
#include <wiringPi.h>
#endif

VisorController::VisorController(QObject *parent)
    :QObject(parent),
    vUdpSocket(new QUdpSocket(this)),
    currentImgFrameNum(0),
    countReceivedPackage(0)
{

}

void VisorController::startController(){
    connect(vUdpSocket, &QUdpSocket::readyRead, this, &VisorController::dataAcquisitionProcess);
}

void VisorController::updateIp(const QHostAddress& _ip){
    if(!vUdpSocket->bind(_ip, VisorConstants::VISOR_PORT)){
        qDebug()<<"failed to bind socket on host:\t"
                 <<_ip
                 <<"\tand port:\t"
                 <<VisorConstants::VISOR_PORT
                 <<"\t\r";
        return;
    }
}
void VisorController::resetIp(){

    if(vUdpSocket->isValid()) {
        vUdpSocket->deleteLater();
        vUdpSocket = new QUdpSocket(this);
        startController();
    }
}

void VisorController::dataAcquisitionProcess(){
    QHostAddress sender;
    quint16 senderPort;

    while(vUdpSocket->hasPendingDatagrams()){
        QByteArray package;
        package.resize(vUdpSocket->pendingDatagramSize());

        if(vUdpSocket->readDatagram(package.data(), package.size(), &sender, &senderPort) != -1)
                collectionImageData(package);
    }

}
void VisorController::collectionImageData(const QByteArray& receivedPacket) {

#ifdef ORANGE_PI_PLATFORM
    //if constexpr (WRITE_CHECKING)
        digitalWrite(26, 1);
#endif

    DataTransaction::CaptureData parsedData;
    memcpy(parsedData.raw, receivedPacket.constData(), Constants::CAPTURE_SIZE_PKG);

    if(parsedData.parted.message_id != Constants::MESSAGE_ID_CODE)
        return;

    if (currentImgFrameNum != parsedData.parted.frame_num) {
        imageBuffers.clear();
        currentImgFrameNum = parsedData.parted.frame_num;
        countReceivedPackage = 0;
    }

    imageBuffers[parsedData.parted.frame_part] =
        QByteArray(parsedData.parted.payload, parsedData.parted.payload_size);

    countReceivedPackage += 1;

    if (countReceivedPackage == parsedData.parted.pkg_count)
    {

        // Получаем суммарный размер данных, чтобы избежать лишних перераспределений памяти
        size_t totalSize = 0;
        for (const auto& kvp : imageBuffers) {
            totalSize += kvp.size();
        }

        // Предварительно резервируем память вектора, чтобы избежать лишних перераспределений
        std::vector<char> data;
        data.reserve(totalSize);

        // Используем алгоритм std::for_each для объединения данных
        std::for_each(imageBuffers.begin(), imageBuffers.end(), [&data](const QByteArray& value) {
            data.insert(data.end(), value.begin(), value.end());
        });
        /*
        std::vector<char> data = std::accumulate(imageBuffers.begin(), imageBuffers.end(), std::vector<char>{},
                                                 [](std::vector<char>& result, const auto& kvp) {
                                                     result.insert(result.end(), kvp.begin(), kvp.end());
                                                     return result;
                                                 });*/
#ifdef ORANGE_PI_PLATFORM
        // if constexpr (WRITE_CHECKING)
                digitalWrite(26, 0);
#endif
        emit imageDataCollectionReady(cv::imdecode(data, cv::IMREAD_COLOR));

        countReceivedPackage = 0;
        currentImgFrameNum = parsedData.parted.frame_num;
        imageBuffers.clear();
    }
}
