
#include <stdint.h>
#include <stdio.h>

#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_conf.h"

#include "drv_adc.h"
#include "stm32F446_nucleo_ihm07m1_enib.h"
#include "drv_uart.h"
#include "SystemClock.h"
#include "calc.h"
#include "config.h"
#include "tickTimer.h"
#include "drv_can.h"

#include "pulseGenerator.h"

#include "sendtoXcos.h"
#include "quadEncoder.h"
#include "pwmTimer.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "X2C.h"


extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern UART_HandleTypeDef huart2;


typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned char uint8_t;
typedef signed char int8_t;

