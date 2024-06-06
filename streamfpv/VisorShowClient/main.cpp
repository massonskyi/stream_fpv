#include <QApplication>
#include <QScreen>
#include "visorgui.h"
#include <constants.h>

#ifdef ORANGE_PI_PLATFORM
#include <wiringPi.h>
#endif

int main(int argc, char *argv[])
{
#ifdef ORANGE_PI_PLATFORM
    if constexpr (WRITE_CHECKING){
        wiringPiSetup();
        pinMode(27, OUTPUT);
        pinMode(26, OUTPUT);
        qDebug()<<"machine is arm, checking is true";
    }
#endif
    QApplication a(argc, argv);
    VisorGUI vGUI(a.screens()[0]->size());
    return a.exec();

}

