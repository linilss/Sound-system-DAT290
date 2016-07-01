/*
   GPIO.h
*/

#ifndef GPIO_H
#define GPIO_H

#define HIGH_BYTE 0x01
#define LOW_BYTE 0x00

#include "stm32f4xx_gpio.h"

void init_GPIO(GPIO_TypeDef* GPIOx,
               uint32_t GPIO_Pin,
               GPIOMode_TypeDef GPIO_Mode,
               GPIOSpeed_TypeDef GPIO_Speed,
               GPIOOType_TypeDef GPIO_OType,
               GPIOPuPd_TypeDef GPIO_PuPd);

void init_GPIO_RCC(GPIO_TypeDef* GPIOx,
               uint32_t GPIO_Pin,
               GPIOMode_TypeDef GPIO_Mode,
               GPIOSpeed_TypeDef GPIO_Speed,
               GPIOOType_TypeDef GPIO_OType,
               GPIOPuPd_TypeDef GPIO_PuPd);

void write_GPIO_Byte(GPIO_TypeDef* GPIOx,
                     uint8_t high_low_byte,
					 uint8_t byte_value);

uint8_t read_GPIO_Byte(GPIO_TypeDef* GPIOx,
                     uint8_t high_low_byte);

//** init_GPIO **
//-- GPIOx --
//   GPIOA
//   GPIOB
//   GPIOC
//   GPIOD
//   GPIOE
//   GPIOF
//   GPIOG - doesn´t apply to our processor
//   GPIOH - doesn´t apply to our processor
//   GPIOI - doesn´t apply to our processor
//   GPIOJ - doesn´t apply to our processor
//   GPIOK - doesn´t apply to our processor

//-- GPIO_Pin --
//   GPIO_Pin_0 - Pin 0 selected
//   GPIO_Pin_1 - Pin 1 selected
//   GPIO_Pin_2 - Pin 2 selected
//   GPIO_Pin_3 - Pin 3 selected
//   GPIO_Pin_4 - Pin 4 selected
//   GPIO_Pin_5 - Pin 5 selected
//   GPIO_Pin_6 - Pin 6 selected
//   GPIO_Pin_7 - Pin 7 selected
//   GPIO_Pin_8 - Pin 8 selected
//   GPIO_Pin_9 - Pin 9 selected
//   GPIO_Pin_10 - Pin 10 selected
//   GPIO_Pin_11 - Pin 11 selected
//   GPIO_Pin_12 - Pin 12 selected
//   GPIO_Pin_13 - Pin 13 selected
//   GPIO_Pin_14 - Pin 14 selected
//   GPIO_Pin_15 - Pin 15 selected
//   GPIO_Pin_All - All pins selected
#define GPIO_Pin_High_Byte ((uint16_t)0xFF00)  /* High byte pins selected */
#define GPIO_Pin_Low_Byte  ((uint16_t)0x00FF)  /* Low byte pins selected */

//-- GPIO_Mode --
//   GPIO_Mode_IN - GPIO Input Mode
//   GPIO_Mode_OUT - GPIO Output Mode
//   GPIO_Mode_AF - GPIO Alternate function Mode
//   GPIO_Mode_AN - GPIO Analog Mode

//-- GPIO_Speed --
//   GPIO_Low_Speed - Low speed
//   GPIO_Medium_Speed - Medium speed
//   GPIO_Fast_Speed - Fast speed
//   GPIO_High_Speed - High speed
//   !! legacy speeds !!
//   GPIO_Speed_2MHz    GPIO_Low_Speed
//   GPIO_Speed_25MHz - GPIO_Medium_Speed
//   GPIO_Speed_50MHz - GPIO_Fast_Speed
//   GPIO_Speed_100MHz - GPIO_High_Speed

//-- GPIO_OType --
//   GPIO_OType_PP - PushPull
//   GPIO_OType_OD - open drain

//-- GPIO_PuPd --
//   GPIO_PuPd_NOPULL - open input
//   GPIO_PuPd_UP - pull up
//   GPIO_PuPd_DOWN - pull down

//** write_GPIO_Byte **
//-- high_low_byte --
//   HIGH_BYTE
//   LOW_BYTE
//-- byte_value --
//   0x00-0xFF (0-255)

//*****************************************************************
//** Definitions for other functions **
//-- GPIO Bit SET and Bit RESET enumeration --
//   RESET
//   SET

//-- GPIO_Pin_sources --
//   GPIO_PinSource0
//   GPIO_PinSource1
//   GPIO_PinSource2
//   GPIO_PinSource3
//   GPIO_PinSource4
//   GPIO_PinSource5
//   GPIO_PinSource6
//   GPIO_PinSource7
//   GPIO_PinSource8
//   GPIO_PinSource9
//   GPIO_PinSource10
//   GPIO_PinSource11
//   GPIO_PinSource12
//   GPIO_PinSource13
//   GPIO_PinSource14
//   GPIO_PinSource15

//-- GPIO_Alternat_function_selection_define --
//   !! AF 0 selection !!
//   GPIO_AF_RTC_50Hz - RTC_50Hz Alternate Function mapping
//   GPIO_AF_MCO - MCO (MCO1 and MCO2) Alternate Function mapping
//   GPIO_AF_TAMPER - TAMPER (TAMPER_1 and TAMPER_2) Alternate Function mapping
//   GPIO_AF_SWJ - SWJ (SWD and JTAG) Alternate Function mapping
//   GPIO_AF_TRACE - TRACE Alternate Function mapping
//   !! AF 1 selection !!
//   GPIO_AF_TIM1 - TIM1 Alternate Function mapping
//   GPIO_AF_TIM2 - TIM2 Alternate Function mapping
//   !! AF 2 selection !!
//   GPIO_AF_TIM3 - TIM3 Alternate Function mapping
//   GPIO_AF_TIM4 - TIM4 Alternate Function mapping
//   GPIO_AF_TIM5 - TIM5 Alternate Function mapping
//   !! AF 3 selection !!
//   GPIO_AF_TIM8 - TIM8 Alternate Function mapping
//   GPIO_AF_TIM9 - TIM9 Alternate Function mapping
//   GPIO_AF_TIM10 - TIM10 Alternate Function mapping
//   GPIO_AF_TIM11 - TIM11 Alternate Function mapping
//   !! AF 4 selection !!
//   GPIO_AF_I2C1 - I2C1 Alternate Function mapping
//   GPIO_AF_I2C2 - I2C2 Alternate Function mapping
//   GPIO_AF_I2C3 - I2C3 Alternate Function mapping
//   !! AF 5 selection !!
//   GPIO_AF_SPI1 - SPI1 Alternate Function mapping
//   GPIO_AF_SPI2 - SPI2/I2S2 Alternate Function mapping
//   GPIO_AF_SPI4 - SPI4 Alternate Function mapping
//   GPIO_AF_SPI5 - SPI5 Alternate Function mapping
//   GPIO_AF_SPI6 - SPI6 Alternate Function mapping
//   !! AF 6 selection !!
//   GPIO_AF_SPI3 - SPI3/I2S3 Alternate Function mapping
//   GPIO_AF_SAI1 - SAI1 Alternate Function mapping
//   !! AF 7 selection !!
//   GPIO_AF_USART1 - USART1 Alternate Function mapping
//   GPIO_AF_USART2 - USART2 Alternate Function mapping
//   GPIO_AF_USART3 - USART3 Alternate Function mapping
//   GPIO_AF_I2S3ext - I2S3ext Alternate Function mapping
//   !! AF 8 selection !!
//   GPIO_AF_UART4 - UART4 Alternate Function mapping
//   GPIO_AF_UART5 - UART5 Alternate Function mapping
//   GPIO_AF_USART6 - USART6 Alternate Function mapping
//   GPIO_AF_UART7 - UART7 Alternate Function mapping
//   GPIO_AF_UART8 - UART8 Alternate Function mapping
//   !! AF 9 selection !!
//   GPIO_AF_CAN1 - CAN1 Alternate Function mapping
//   GPIO_AF_CAN2 - CAN2 Alternate Function mapping
//   GPIO_AF_TIM12 - TIM12 Alternate Function mapping
//   GPIO_AF_TIM13 - TIM13 Alternate Function mapping
//   GPIO_AF_TIM14 - TIM14 Alternate Function mapping
//   !! AF 10 selection !!
//   GPIO_AF_OTG_FS - OTG_FS Alternate Function mapping
//   GPIO_AF_OTG_HS - OTG_HS Alternate Function mapping
//   !! AF 11 selection !!
//   GPIO_AF_ETH - ETHERNET Alternate Function mapping
//   !! AF 12 selection !!
//   GPIO_AF_FSMC - FSMC Alternate Function mapping
//   GPIO_AF_OTG_HS_FS - OTG HS configured in FS, Alternate Function mapping
//   GPIO_AF_SDIO - SDIO Alternate Function mapping
//   !! AF 13 selection !!
//   GPIO_AF_DCMI - DCMI Alternate Function mapping
//   !! AF 14 selection !!
//   GPIO_AF_LTDC - LCD-TFT Alternate Function mapping
//   !! AF 15 selection !!
//   GPIO_AF_EVENTOUT - EVENTOUT Alternate Function mapping

//-- GPIO_Legacy --
//   GPIO_Mode_AIN    GPIO_Mode_AN
//   GPIO_AF_OTG1_FS  GPIO_AF_OTG_FS
//   GPIO_AF_OTG2_HS  GPIO_AF_OTG_HS
//   GPIO_AF_OTG2_FS  GPIO_AF_OTG_HS_FS

#endif
