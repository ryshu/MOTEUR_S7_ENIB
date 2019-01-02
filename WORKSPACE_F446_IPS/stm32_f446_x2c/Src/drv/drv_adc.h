/*
 * drv_adc.h
 *
 *  Created on: 25 oct. 2016
 *      Author: kerhoas
 */

#ifndef SRC_DRV_DRV_ADC_H_
#define SRC_DRV_DRV_ADC_H_

#include "main.h"

void adc1_Init(void);
uint32_t adc_getPotValue(void);
uint32_t adc_getIaValue(void);
uint32_t adc_getIbValue(void);


typedef struct {
  uint16_t* RegularValueBuffer;        /*!< Regular buffer for converted value*/
  uint16_t* InjectedValueBuffer;       /*!< Injected buffer for converted value*/
  uint32_t RegularCurrentRank;         /*!< Regular current rank*/
  uint32_t InjectedCurrentRank;        /*!< Injected current rank*/
  uint32_t nbRegChannel;               /*!< Number of regular channel*/
  uint32_t nbInjChannel;               /*!< Number of injected channel*/
  uint8_t useDMA;                      /*!< DMA aquisition mode */
  void (* ItEOCFcn)(void);
  void (* ItJEOCFcn)(void);
  void (* ItAWDFcn)(void);
  void (* ItOVRFcn)(void);
} ADC_DataLinkTypeDef;

extern uint16_t G_NbAdcConf;           /* Number of ADC configured */

/* Array of ADC data information */
extern ADC_DataLinkTypeDef* G_ADC_Data[2];
extern ADC_HandleTypeDef* G_ADC_Handler[2];

ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

/* ADC1 Regular channel Converted value buffer */
extern uint16_t ADC1_RegularConvertedValue[3];

/* ADC1 data information*/
extern ADC_DataLinkTypeDef ADC1_DataLink;


#endif /* SRC_DRV_DRV_ADC_H_ */
