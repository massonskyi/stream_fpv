#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H
#include "cmd_utils.h"

#include <QObject>
#include <QTimer>
#include <QObject>
#include <QTimer>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QtConcurrent/QtConcurrentRun>
class VisorGUI;
class NetworkMonitor : public QObject {
    Q_OBJECT

public:
    explicit NetworkMonitor(VisorGUI* gui, QObject* parent = nullptr) : QObject(parent), gui(gui) {
        timer.setInterval(1000);  // Update every second
        timer.start();
        connect(&timer, &QTimer::timeout, this, &NetworkMonitor::updateList);
    }

signals:
    void interfacesUpdated(const std::vector<CmdUtils::Iface>& interfaces);

private slots:
    void updateList() {
        QFuture<std::vector<CmdUtils::Iface>> future = QtConcurrent::run(CmdUtils::get_iface);
        if(future.isFinished())
            onInterfacesReceived();

    }

private:
    void onInterfacesReceived() {
        try {
            auto interfaces = future.result();
            emit interfacesUpdated(interfaces);
        } catch (const std::exception& e) {
            qDebug()<<e.what();
        }
    }

    QTimer timer;
    VisorGUI* gui;
    QFuture<std::vector<CmdUtils::Iface>> future;
};

#endif // TIMERMANAGER_H
