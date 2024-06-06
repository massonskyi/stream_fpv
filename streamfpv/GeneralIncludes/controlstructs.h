#ifndef CONTROLSTRUCTS_H
#define CONTROLSTRUCTS_H

#include <constants.h>

namespace ControlStructs {
    union ControlMessage{
        struct __attribute__ ((packed)){
            unsigned char message_id;
            unsigned char camera_number;
            unsigned int wrap_ip;
            unsigned short port;
            char reserved[4];
        }parted;

        char raw[Constants::CONTROL_MESSAGE_SIZE];
    };
}

namespace DataTransaction {
    union CaptureData{
        struct __attribute__ ((packed)){
            unsigned char message_id;
            unsigned char frame_num;
            unsigned char frame_part;
            unsigned short payload_size;
            unsigned char pkg_count;
            char payload[Constants::CAPTURE_SIZE_PKG-Constants::CAPTURE_HEADER_SIZE_PKG];
        }parted;


        char raw[Constants::CAPTURE_SIZE_PKG];
    };
}

#endif // CONTROLSTRUCTS_H
