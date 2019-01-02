#include "main.h"
#include "motorControl.h"

#define OFFSET_THETA 800

extern void SystemClock_Config(void);
extern void findFirstIndex();
extern void MX_TIM1_Init(void);
extern void MC_FOC_Start_PWM_driving(void);
extern void MC_FOC_EnableInputs();

extern int32_t quadPos, theta_elec;
extern q31_t iq_mes;
extern int first_index_reached;
extern TIM_HandleTypeDef TimHandle_period;
extern uint16_t potentiometre;
extern uint16_t Ia_mes, Ib_mes, Ic_mes;
extern int32_t Ia_mes_ext, Ib_mes_ext;
extern q31_t alpha, beta, sinVal, cosVal;

int16_t speed_mes;

uint32_t pot;
int16_t Ia_bias, Ib_bias;
uint16_t g_ADCBuffer[3];
int32_t pulse = -1;

void (*rxCompleteCallback)(void);
void can_callback(void);

CAN_Message rxMsg;
CAN_Message txMsg;
long int counter = 0;

uint8_t *aTxBuffer[2];

xSemaphoreHandle xSemaphore_Fast = NULL;
xSemaphoreHandle xSemaphore_Slow = NULL;
xQueueHandle qh = NULL;
extern q31_t iq_err, iq_cde;
int32_t theta_elec_ex;
int32_t tab_speed[5000];
int FC1, FC2;

int mode = 0;
int consigne = 0;
int pos = 0;

//============================================================================
static void Fast_Task(void *pvParameters)
{
	vTaskDelay(5);
	Ia_bias = Ia_mes;
	Ib_bias = Ib_mes;
	int cnt_20 = 19;
	int16_t signe;
	int index = 0;

	for (;;)
	{

		if (first_index_reached == 0)
		{

#if USE_MOTOR
			findFirstIndex(); // stm32F446_nucleo_ihm07m1_enib.c
#else
			first_index_reached = 1;
#endif
		}
		else
		{

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1); // PC9 MES PER 1 --> To profile function
			//---------------------------------------------------
			Inports.pot = potentiometre;

			//---------------------------------------------------
			quadPos = quadEncoder_GetPos16(); // cf quadEncoder.c
			signe = ((int16_t)quadPos + OFFSET_THETA);

			if (signe > 8000)
			{
				quadPos = quadPos + OFFSET_THETA - 8000;
			}
			else
			{
				quadPos = quadPos + OFFSET_THETA;
			}

			theta_elec = quadPos % 2000; //theta_elec=quadPos/POLE_PAIR; // [0 8000] --> [0 2000]
			theta_elec_ex = (int32_t)(theta_elec)*16;

			Inports.theta_elec = theta_elec_ex;
			//........................................................

			Ia_mes_ext = ((int32_t)Ia_mes) - Ia_bias;
			Ib_mes_ext = ((int32_t)Ib_mes) - Ib_bias;

			Inports.Ia = Ia_mes_ext;
			Inports.Ib = Ib_mes_ext;

			//........................................................

			if (cnt_20 == 0)
			{
				Inports.pulse = pulse;

				speed_mes = -quadEncoder_GetSpeed();
				Inports.speed = speed_mes;
				cnt_20 = 19;

				if (index < 5000)
				{
					tab_speed[index] = speed_mes;
					index++;
				}
			}

			cnt_20--;

			X2C_Update();

			// Update Duty Cycle
			pwmSetDutyCycle(*Outports.pduty_1, *Outports.pduty_2, *Outports.pduty_3);

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0); // PC9
		}

		xSemaphoreTake(xSemaphore_Fast, portMAX_DELAY);
	}
}
//============================================================================
static void Print_Task(void *pvParameters)
{
	txFrame txf;
	for (;;)
	{
		txf.data0 = potentiometre;
		txf.data1 = pulse;
		txf.data2 = speed_mes;
		sendtoXcos(txf);
	}
}
//============================================================================
//	>>>>>>>>>>>>>>>>>>>>>>>>>>	MAIN  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//============================================================================
int main(void)
{
	HAL_Init();
	SystemClock_Config();

	adc1_Init();
	uart2_Init();
	quadEncoder_Init();
	pwmTimer_Init();
	tickTimerInit(PWM_COUNT_PERIOD);

	first_index_reached = 0;
	MC_FOC_Nucleo_Init();
	MC_FOC_Start_PWM_driving();
	pwmSetDutyCycle(420, 420, 420);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET); //BSP_X_NUCLEO_FAULT_LED_ON();
	MC_FOC_EnableInputs();

#if USE_PULSE
	pulseGenerator_Init(3000);
#endif

	can_Init();			  // Default CAN BAUDRATE : 500kb/s
	can_Filter_disable(); // Accept everybody
	can_IrqInit();
	can_IrqSet(&can_callback);

	txMsg.id = 0x7FF;
	txMsg.data[0] = 1;
	txMsg.data[1] = 2;
	txMsg.len = 2;
	txMsg.format = CANStandard;
	txMsg.type = CANData;

	can_Write(txMsg); // TEST CAN BUS
	HAL_Delay(100);

	X2C_Init();

	//--------------------------------------------
	// 				FREERTOS
	//--------------------------------------------

	potentiometre = 450;

	xTaskCreate(Fast_Task, (const portCHAR *)"Fast_Task", 512, NULL, tskIDLE_PRIORITY + 3, NULL);
	xTaskCreate(Print_Task, (const portCHAR *)"Print_Task", 512, NULL, tskIDLE_PRIORITY + 1, NULL);

	vSemaphoreCreateBinary(xSemaphore_Fast);
	xSemaphoreTake(xSemaphore_Fast, portMAX_DELAY);

	vSemaphoreCreateBinary(xSemaphore_Slow);
	xSemaphoreTake(xSemaphore_Slow, portMAX_DELAY);

	__HAL_TIM_ENABLE_IT(&TimHandle_period, TIM_IT_UPDATE); // ??
	HAL_TIM_OC_Start(&TimHandle_period, TIM_CHANNEL_1);
	HAL_ADC_Start_DMA(&hadc1, g_ADCBuffer, 3);

	vTaskStartScheduler();

	return 0;
}
//============================================================================
//		INTERRUPTION CALLBACK ON TIMER PERIOD
//============================================================================
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	static BaseType_t xHigherPriorityTaskWoken;

	if (htim->Instance == TIM3) // Fast Task
	{
		xSemaphoreGiveFromISR(xSemaphore_Fast, &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	}

	if (htim->Instance == TIM5)
	{
		if (pulse == 0)
		{
			pulse = potentiometre;
		}
		else
		{
			pulse = 0;
		}
	}
}
//====================================================================
//			INTERRUPT CALLBACK ON CAN RECEIVE
//====================================================================
void can_callback(void)
{
	CAN_Message msg_rcv;

	can_Read(&msg_rcv);

	if (msg_rcv.id == 0x01)
	{ // Change mode
		mode = msg_rcv.data[0];
		if (mode == 0x03)
			pos_reached = msg_rcv.data[1];
	}
	else if (msg_rcv.id == 0x02)
	{ // Change consige
	}

	txMsg.id = 0x55; // Identifiant du message à envoyer

	for (int i = 0; i < 8; i++)
	{
		txMsg.data[i] = msg_rcv.data[i] + 1;
	}
	txMsg.len = 8; // Nombre d'octets à envoyer
	txMsg.format = CANStandard;
	txMsg.type = CANData;

	can_Write(txMsg);
}
//============================================================================
//		INTERRUPTION EXTI --> BLUE BUTTON / INDEX / FC1 / FC2
//============================================================================
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == GPIO_PIN_13)
	{
		MC_FOC_Nucleo_Init();
		first_index_reached = 0;
		MC_FOC_Start_PWM_driving();
		pwmSetDutyCycle(420, 420, 420);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET); //BSP_X_NUCLEO_FAULT_LED_ON();
		MC_FOC_EnableInputs();
		__HAL_TIM_ENABLE_IT(&TimHandle_period, TIM_IT_UPDATE); // ??
		HAL_TIM_OC_Start(&TimHandle_period, TIM_CHANNEL_1);
	}
	else if (GPIO_Pin == GPIO_PIN_10)
	{
		quadEncoder_CallbackIndexZ();
	}

	else if (GPIO_Pin == GPIO_PIN_4) // Fin de Course 1
	{
		FC1 = 1;
		FC2 = 0;

		txMsg.id = 0x55;

		txMsg.data[i] = 0x01;
		for (i = 1; i < 8; i++)
			txMsg.data[i] = msg_rcv.data[i] + 1;

		txMsg.len = 8;
		txMsg.format = CANStandard;
		txMsg.type = CANData;

		can_Write(txMsg);
	}
	else if (GPIO_Pin == GPIO_PIN_5) // Fin de Course 2
	{
		FC1 = 0;
		FC2 = 1;

		txMsg.id = 0x55;

		txMsg.data[i] = 0x02;
		for (i = 1; i < 8; i++)
			txMsg.data[i] = msg_rcv.data[i] + 1;

		txMsg.len = 8;
		txMsg.format = CANStandard;
		txMsg.type = CANData;

		can_Write(txMsg);
	}
}
//=================================================================
// Called if stack overflow during execution
extern void vApplicationStackOverflowHook(xTaskHandle *pxTask,
										  signed char *pcTaskName)
{
	//term_printf("stack overflow %x %s\r\n", pxTask, (portCHAR *)pcTaskName);
	/* If the parameters have been corrupted then inspect pxCurrentTCB to
	 * identify which task has overflowed its stack.
	 */
	for (;;)
	{
	}
}
//=================================================================
//This function is called by FreeRTOS idle task
extern void vApplicationIdleHook(void)
{
}
//=================================================================
// brief This function is called by FreeRTOS each tick
extern void vApplicationTickHook(void)
{
	//	HAL_IncTick();
}
//================================================================
#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}

#endif
