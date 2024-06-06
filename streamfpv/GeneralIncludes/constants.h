#ifndef CONSTANTS_H
#define CONSTANTS_H

constexpr bool WRITE_CHECKING = false;

#ifdef Q_PROCESSOR_ARM
#define ORANGE_PI_PLATFORM
#endif


namespace Constants {

constexpr unsigned short CONTROL_MESSAGE_SIZE = 12;

constexpr unsigned short CAPTURE_SIZE_PKG = 16384;
constexpr unsigned short CAPTURE_HEADER_SIZE_PKG = 6;
constexpr int CAPTURE_PAYLOAD_SIZE_PKG = CAPTURE_SIZE_PKG - CAPTURE_HEADER_SIZE_PKG;
constexpr unsigned short CAPTURE_PKG_MAX = 5;

constexpr unsigned short START_PORT = 9100;

constexpr unsigned char MESSAGE_ID_CODE = 0xF;
}


#endif // CONSTANTS_H
