#ifndef VISORSUBCRIPTION_H
#define VISORSUBCRIPTION_H

#include <QObject>
#include <QHostAddress>

class QTcpSocket;

class VisorSubcription : public QObject
{
    Q_OBJECT
public:
    explicit VisorSubcription();
    ~VisorSubcription(void);
    bool sendStart(void);
    bool sendStop(void);
    bool init(const QHostAddress&, QHostAddress, quint16);

private:
    QHostAddress localHost;
    QTcpSocket* mSocket;
};

#endif // VISORSUBCRIPTION_H
