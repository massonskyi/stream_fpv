#include <QCoreApplication>

#include "cameracontroller.h"
#include <constants.h>
#include <controlstructs.h>

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
	qDebug()<<"starting on arm with checking is true";
    }
#endif

    QCoreApplication a(argc, argv);

    CameraController controller;

    return a.exec();
}
