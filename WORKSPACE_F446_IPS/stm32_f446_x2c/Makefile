PATH_TO_BIN = /local/sdk_elec/gcc-arm-none-eabi-5_2-2015q4/bin/

X2C_PATH = $(X2C_Root)

TARGET  = $(PATH_TO_BIN)arm-none-eabi-
CC      = $(TARGET)gcc
OBJCOPY = $(TARGET)objcopy
AS      = $(TARGET)gcc -x assembler-with-cpp -c
SIZE    = $(TARGET)size
OBJDUMP = $(TARGET)objdump
PROJECT_NAME = template
PROJECT_SRC = .
vpath %.c $(PROJECT_SRC)
#===============================================================================
SRCS = Src/main.c
#===============================================================================
SRCS += Device/startup_stm32f446xx.s
SRCS += Src/system_stm32f4xx.c
SRCS += Src/stm32F446_nucleo_ihm07m1_enib.c
SRCS += Src/stm32f4xx_hal_msp.c
SRCS += Src/stm32f4xx_it.c
SRCS += Src/SystemClock.c
SRCS += Src/quadEncoder.c
SRCS += Src/pwmTimer.c
SRCS += Src/tickTimer.c
SRCS += Src/pulseGenerator.c
SRCS += Src/sendtoXcos.c
SRCS += Src/drv/drv_uart.c
SRCS += Src/drv/drv_adc.c
SRCS += Src/drv/drv_can.c
SRCS += Src/motorControl.c
#===============================================================================
SRCS += Drivers/BSP/STM32F4xx-Nucleo/stm32f4xx_nucleo.c
#===============================================================================
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac_ex.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_usart.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_can.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
#===============================================================================
SRCS += Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_sin_q31.c
SRCS += Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_cos_q31.c
SRCS += Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_sin_q15.c
SRCS += Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_cos_q15.c
SRCS += Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_sin_f32.c
SRCS += Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_cos_f32.c
SRCS += Drivers/CMSIS/DSP_Lib/Source/CommonTables/arm_common_tables.c
SRCS += Drivers/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q31.c
SRCS += Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_sub_q31.c
SRCS += Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_add_q31.c
#===============================================================================
SRCS += X2C/X2C.c
##########################################################################
SRCS +=$(X2C_PATH)/Library/General/Controller/src/And_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/And_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/And_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/AutoSwitch_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/AutoSwitch_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/AutoSwitch_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/AutoSwitch_Float32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Constant_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Constant_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Constant_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Constant_Float32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Gain_FiP16.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Gain_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Gain_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Gain_Float32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Int2Real_FiP16_Float32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Int2Real_FiP32_Float32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Int2Real_FiP8_Float32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Limitation_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Limitation_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Limitation_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Limitation_Float32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/LookupTable_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/LookupTable_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/LookupTable_FiP8.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/LoopBreaker_FiP16.c
##SRCS +=$(X2C_PATH)/Library/General/Controller/src/LoopBreaker_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/LoopBreaker_Float32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/ManualSwitch_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/ManualSwitch_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/ManualSwitch_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Maximum_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Maximum_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Maximum_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Minimum_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Minimum_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Minimum_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/MinMaxPeriodic_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/MinMaxPeriodic_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/MinMaxPeriodic_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/MinMaxPeriodic_Float32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Not_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Not_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Not_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Or_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Or_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Or_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/RateLimiter_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/RateLimiter_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/RateLimiter_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/RateLimiter_Float32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Real2Int_Float32_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Real2Int_Float32_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Real2Int_Float32_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Saturation_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Saturation_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Saturation_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Saturation_Float32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/SaveSignal_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/SaveSignal_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/SaveSignal_FiP8.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/SaveSignal_Float32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Selector_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Selector_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Selector_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Selector_Float32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Sequencer_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Sequencer_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Sequencer_FiP8.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Sequencer_Float32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Sin2Limiter_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Sin2Limiter_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Sin2Limiter_FiP8.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Sin2Limiter_Float32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Sin3Gen_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Sin3Gen_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Sin3Gen_FiP8.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Sin3Gen_Float32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/SinGen_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/SinGen_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/SinGen_FiP8.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/SinGen_Float32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/TypeConv_FiP16_32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/TypeConv_FiP16_8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/TypeConv_FiP32_16.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/TypeConv_FiP32_8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/TypeConv_FiP8_16.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/TypeConv_FiP8_32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/uConstant_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/uConstant_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/uConstant_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/uConstant_Float32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/uGain_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/uGain_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/uGain_FiP8.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/uGain_Float32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/uRateLimiter_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/RateLimiter_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/uRateLimiter_FiP8.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/uRateLimiter_Float32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/uSaveSignal_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/uSaveSignal_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/uSaveSignal_FiP8.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/uSaveSignal_Float32.c
SRCS +=$(X2C_PATH)/Library/General/Controller/src/Xor_FiP16.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Xor_FiP32.c
#SRCS +=$(X2C_PATH)/Library/General/Controller/src/Xor_FiP8.c
##########################################################################
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Abs_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Abs_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Abs_FiP8.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Abs_Float32.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Add_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Add_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Add_FiP8.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Add_Float32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Atan2_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Atan2_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Atan2_FiP8.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Atan2_Float32.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Average_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Average_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Average_FiP8.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Average_Float32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Cos_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Cos_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Cos_FiP8.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Cos_Float32.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Div_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Div_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Div_FiP8.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Div_Float32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Exp_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Exp_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Exp_FiP8.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/L2Norm_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/L2Norm_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/L2Norm_FiP8.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/L2Norm_Float32.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Mult_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Mult_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Mult_FiP8.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Mult_Float32.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Negation_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Negation_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Negation_FiP8.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Negation_Float32.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sign_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sign_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sign_FiP8.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sin_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sin_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sin_FiP8.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sin_Float32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sqrt_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sqrt_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sqrt_FiP8.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sqrt_Float32.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sub_FiP16.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sub_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sub_FiP8.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sub_Float32.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sum_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sum_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sum_FiP8.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/Sum_Float32.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/uAdd_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/uAdd_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/uAdd_FiP8.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/uAdd_Float32.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/uSub_FiP16.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/uSub_FiP32.c
#SRCS +=$(X2C_PATH)/Library/Math/Controller/src/uSub_FiP8.c
SRCS +=$(X2C_PATH)/Library/Math/Controller/src/uSub_Float32.c
##########################################################################
#			LIB ENIB
##########################################################################
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/ramp_INT16.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/ramp_INT32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/ramp_F32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/clarke_INT16.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/clarke_INT32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/clarke_F32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/clarke_inv_INT16.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/clarke_inv_INT32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/clarke_inv_F32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/shift_right_INT16.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/shift_right_INT32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/shift_left_INT16.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/shift_left_INT32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/space_vector_INT16.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/space_vector_INT32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/space_vector_F32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/park_transf_INT16.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/park_transf_INT32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/park_transf_F32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/park_transf_inv_INT16.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/park_transf_inv_INT32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/park_transf_inv_F32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/sin_INT16.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/sin_INT32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/sin_F32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/cos_INT16.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/cos_INT32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/cos_F32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/pid_INT16.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/pid_INT32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/pid_F32.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/modulo_INT16.c
SRCS += $(X2C_PATH)/Library/ENIB/Controller/src/modulo_INT32.c

SRCS +=X2C/X2C_redef.c

#===============================================================================
#							FREERTOS
#===============================================================================
FREE_RTOS_SRC = FreeRTOS/Source
SRCS += $(FREE_RTOS_SRC)/croutine.c $(FREE_RTOS_SRC)/list.c $(FREE_RTOS_SRC)/queue.c $(FREE_RTOS_SRC)/tasks.c 
SRCS += $(FREE_RTOS_SRC)/portable/GCC/ARM_CM4F/port.c
SRCS += $(FREE_RTOS_SRC)/portable/MemMang/heap_1.c
INC_DIRS = $(FREE_RTOS_SRC)/include/
INC_DIRS += $(FREE_RTOS_SRC)/portable/GCC/ARM_CM4F/
#===============================================================================
EXT_OBJ = $(EXT_SRCS:.c=.o)
#===============================================================================
INC_DIRS += Inc/
INC_DIRS += Src/drv/
INC_DIRS += X2C/
INC_DIRS += Drivers/STM32F4xx_HAL_Driver/Inc/
INC_DIRS += Drivers/CMSIS/Device/ST/STM32F4xx/Include/
INC_DIRS += Drivers/CMSIS/Include/
INC_DIRS += Drivers/BSP/STM32F4xx-Nucleo/
INC_DIRS += Drivers/BSP/X-NUCLEO-IHM07M1/
INC_DIRS += Drivers/BSP/Components/Common/
INC_DIRS += Drivers/BSP/Components/l6230/
INC_DIRS += Middlewares/ST/MC_6Step_Lib/Inc/ 
INC_DIRS +=/local/sdk_elec/gcc-arm-none-eabi-5_2-2015q4/arm-none-eabi/include/

INC_DIRS += $(X2C_PATH)/Library/Math/Controller/inc/
INC_DIRS += $(X2C_PATH)/Library/ENIB/Controller/inc/
INC_DIRS += $(X2C_PATH)/Library/General/Controller/inc/
INC_DIRS += $(X2C_PATH)/Controller/Common/	#Target.h

INCLUDE = $(addprefix -I,$(INC_DIRS))

#LIBSPEC = -L /home/kerhoas/X2C/Library/Math/Controller/lib/STM32F4_Math.lib
#LIBSPEC += -L /home/kerhoas/X2C/Library/Math/Controller/lib/STM32F4_General.lib

DEFS = -DSTM32F446xE

CFLAGS  = -ggdb -O4 -D__STM32F446_ENIB__ -D__STM32__ #-D__FPU_PRESENT -D__FPU_USED
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -Wl,--gc-sections -mfpu=fpv5-sp-d16 -mfloat-abi=hard -fsingle-precision-constant
WFLAGS += -Wall -Wextra -Warray-bounds -Wno-unused-parameter
LFLAGS = -TDevice/gcc.ld  $(LIBSPEC) -mfloat-abi=hard -lc -lgcc -lgcov -lm -Wl,-Map=$@.map 

.PHONY: all
all: $(PROJECT_NAME)

.PHONY: $(PROJECT_NAME)
$(PROJECT_NAME): $(PROJECT_NAME).elf

$(PROJECT_NAME).elf: $(SRCS) $(EXT_OBJ)
	$(CC) $(INCLUDE) $(DEFS) $(CFLAGS) $(WFLAGS) $(LFLAGS) $^ -o $@
	$(OBJCOPY) -O ihex $(PROJECT_NAME).elf   $(PROJECT_NAME).hex
	$(OBJCOPY) -O binary $(PROJECT_NAME).elf $(PROJECT_NAME).bin

%.o: %.c
	$(CC) -c -o $@ $(INCLUDE) $(DEFS) $(CFLAGS) $^

clean:
	rm -f *.o $(PROJECT_NAME).elf $(PROJECT_NAME).hex $(PROJECT_NAME).bin $(PROJECT_NAME).map

	
	