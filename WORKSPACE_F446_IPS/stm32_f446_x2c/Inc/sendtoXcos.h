/*
 * sendtoXcos.h
 *
 *  Created on: 1 juil. 2016
 *      Author: kerhoas
 */

#ifndef INC_SENDTOXCOS_H_
#define INC_SENDTOXCOS_H_


#include "main.h"
#include "drv_uart.h"

#define BINARYSOURCE_EOF      1
#define BINARYSOURCE_OK       0
#define BINARYSOURCE_ERROR    255

union DataTransformation
{
    struct
    {
        unsigned char b0;
        unsigned char b1;
        unsigned char b2;
        unsigned char b3;
    } buffer; // byte
    struct
    {
        unsigned char value;
        unsigned char dummy1;
        unsigned char dummy2;
        unsigned char dummy3;
    } b; // byte
    struct
    {
      unsigned short value;
      unsigned short dummy1;
    } w; // word
    struct
    {
      unsigned long value;
    } d; // double word
    struct
    {
      float value;
    } f;
};

// Frame received
typedef struct
{
    unsigned char outputs;
    unsigned char pwm9;
    unsigned char pwm10;
    unsigned char pwm11;
    unsigned char crc1;
    unsigned char crc2;
} rxFrame;

// Frame to Transmit
typedef struct
{
    unsigned short data0;
    unsigned short data1;
    unsigned short data2;
    unsigned char crc1;
    unsigned char crc2;
} txFrame;


void sendtoXcos(txFrame txf);

#endif /* INC_SENDTOXCOS_H_ */
