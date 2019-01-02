/*
 * can_bus_types.h
 *
 *  Created on: 28 nov. 2016
 *      Author: kerhoas
 */

#ifndef SRC_DRV_CAN_BUS_TYPES_H_
#define SRC_DRV_CAN_BUS_TYPES_H_

#include "main.h"

enum CANFormat {
    CANStandard = 0,
    CANExtended = 1,
    CANAny = 2
};
typedef enum CANFormat CANFormat;

enum CANType {
    CANData   = 0,
    CANRemote = 1
};
typedef enum CANType CANType;

struct CAN_Message {
    unsigned int   id;                 // 29 bit identifier
    unsigned char  data[8];            // Data field
    unsigned char  len;                // Length of data field in bytes
    CANFormat      format;             // 0 - STANDARD, 1- EXTENDED IDENTIFIER
    CANType        type;               // 0 - DATA FRAME, 1 - REMOTE FRAME
};
typedef struct CAN_Message CAN_Message;



#endif /* SRC_DRV_CAN_BUS_TYPES_H_ */
