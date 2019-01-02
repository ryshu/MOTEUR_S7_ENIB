/*
 * drv_adc.c
 *
 *  Created on: 25 oct. 2016
 *      Author: kerhoas
 */

#include "drv_adc.h"

uint16_t G_NbAdcConf = 0;              /* Number of ADC configured */

ADC_DataLinkTypeDef* G_ADC_Data[2];
ADC_HandleTypeDef* G_ADC_Handler[2];
uint16_t ADC1_RegularConvertedValue[3];
ADC_DataLinkTypeDef ADC1_DataLink;

extern uint16_t g_ADCBuffer[3];
extern uint16_t potentiometre, Ia_mes, Ib_mes;

void adc1_Init(void)
{
  ADC_ChannelConfTypeDef sConfig;

  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION12b;
  hadc1.Init.ScanConvMode = ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE; // Conversions Triggered
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc1.Init.ExternalTrigConv =ADC_EXTERNALTRIGCONV_T3_CC1;

  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 3;
  hadc1.Init.DMAContinuousRequests = ENABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SEQ_CONV;
  HAL_ADC_Init(&hadc1);

  sConfig.Channel = ADC_CHANNEL_9; // POT VALUE
  sConfig.Rank = 3;
  sConfig.SamplingTime =  ADC_SAMPLETIME_84CYCLES;
  HAL_ADC_ConfigChannel(&hadc1, &sConfig);

  sConfig.Channel = ADC_CHANNEL_0; // Ia VALUE
  sConfig.Rank = 1;
  HAL_ADC_ConfigChannel(&hadc1, &sConfig);

  sConfig.Channel = ADC_CHANNEL_11; // Ib VALUE
  sConfig.Rank = 2;
  HAL_ADC_ConfigChannel(&hadc1, &sConfig);

  hdma_adc1.Instance = DMA2_Stream0;
  hdma_adc1.Init.Channel = DMA_CHANNEL_0;
  hdma_adc1.Init.Direction = DMA_PERIPH_TO_MEMORY;
  hdma_adc1.Init.PeriphInc = DMA_PINC_DISABLE;
  hdma_adc1.Init.MemInc = DMA_MINC_ENABLE;
  hdma_adc1.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
  hdma_adc1.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
  hdma_adc1.Init.Mode = DMA_CIRCULAR;
  hdma_adc1.Init.Priority = DMA_PRIORITY_HIGH;
  hdma_adc1.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
  HAL_DMA_Init(&hdma_adc1);

  __HAL_LINKDMA(&hadc1,DMA_Handle,hdma_adc1);
}


//============================================================================
//		INTERRUPTION ADC
//============================================================================
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);
	Ia_mes	 = g_ADCBuffer[0];
	Ib_mes	=  g_ADCBuffer[1];
	potentiometre =  g_ADCBuffer[2];

//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);
}
//============================================================================
