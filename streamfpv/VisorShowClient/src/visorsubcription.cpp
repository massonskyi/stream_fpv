#include "visorsubcription.h"
#include "localconstants.h"

#include <controlstructs.h>

#include <QTcpSocket>



VisorSubcription::VisorSubcription()
    : mSocket(new QTcpSocket(this))
{
}

VisorSubcription::~VisorSubcription(void){
    if(sendStop())
        mSocket->close();
}

bool VisorSubcription::init(const QHostAddress& _localHost, QHostAddress _address, quint16 _port){
   if(mSocket->isOpen()) return false;
   localHost = _localHost;
   mSocket->connectToHost(_address, _port);
   return mSocket->waitForConnected();
}

bool VisorSubcription::sendStart(){

    if(mSocket->state() == QAbstractSocket::ConnectedState){
        ControlStructs::ControlMessage cm;
        cm.parted.message_id = 0xff;
        cm.parted.camera_number = 3;
        cm.parted.wrap_ip = localHost.toIPv4Address();
        cm.parted.port = VisorConstants::VISOR_PORT;

        QByteArray byteData(reinterpret_cast<char*>(&cm), sizeof(cm));

        mSocket->write(byteData);
        return mSocket->waitForBytesWritten();
    }else{
        return false;
    }
}

bool VisorSubcription::sendStop(void){
    if(mSocket->state() == QAbstractSocket::ConnectedState){
        ControlStructs::ControlMessage cm;
        cm.parted.message_id = 0xE;
        cm.parted.camera_number = 2;
        cm.parted.wrap_ip = localHost.toIPv4Address();
        cm.parted.port = VisorConstants::VISOR_PORT;

        QByteArray byteData(reinterpret_cast<char*>(&cm), sizeof(cm));

        mSocket->write(byteData);
        return mSocket->waitForBytesWritten();
    }else{
        return false;
    }
}
