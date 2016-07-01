/*
   RCC.h
*/

#ifndef RCC_H
#define RCC_H

#include "stm32f4xx_rcc.h"

#define RCC_GPIOA 0x00
#define RCC_GPIOB 0x01
#define RCC_GPIOC 0x02
#define RCC_GPIOD 0x03
#define RCC_GPIOE 0x04
#define RCC_GPIOF 0x05
#define RCC_GPIOG 0x06
#define RCC_GPIOH 0x07
#define RCC_GPIOI 0x08
#define RCC_GPIOJ 0x09
#define RCC_GPIOK 0x0A
#define RCC_CRC 0x0B
#define RCC_FLITF 0x0C
#define RCC_SRAM1 0x0D
#define RCC_SRAM2 0x0E
#define RCC_BKPSRAM 0x0F
#define RCC_SRAM3 0x10
#define RCC_CCMDATARAMEN 0x11
#define RCC_DMA1 0x12
#define RCC_DMA2 0x13
#define RCC_DMA2D 0x14
#define RCC_ETH_MAC 0x15
#define RCC_ETH_MAC_Tx 0x16
#define RCC_ETH_MAC_Rx 0x17
#define RCC_ETH_MAC_PTP 0x18
#define RCC_OTG_HS 0x19
#define RCC_OTG_HS_ULPI 0x1A

#define RCC_DCMI 0x20
#define RCC_CRYP 0x21
#define RCC_HASH 0x22
#define RCC_RNG 0x23
#define RCC_OTG_FS 0x24

#define RCC_FSMC 0x30

#define RCC_TIM2 0x40
#define RCC_TIM3 0x41
#define RCC_TIM4 0x42
#define RCC_TIM5 0x43
#define RCC_TIM6 0x44
#define RCC_TIM7 0x45
#define RCC_TIM12 0x46
#define RCC_TIM13 0x47
#define RCC_TIM14 0x48
#define RCC_WWDG 0x49
#define RCC_SPI2 0x4A
#define RCC_SPI3 0x4B
#define RCC_USART2 0x4C
#define RCC_USART3 0x4D
#define RCC_UART4 0x4E
#define RCC_UART5 0x4F
#define RCC_I2C1 0x50
#define RCC_I2C2 0x51
#define RCC_I2C3 0x52
#define RCC_CAN1 0x53
#define RCC_CAN2 0x54
#define RCC_PWR 0x55
#define RCC_DAC 0x56
#define RCC_UART7 0x57
#define RCC_UART8 0x58

#define RCC_TIM1 0x60
#define RCC_TIM8 0x61
#define RCC_USART1 0x62
#define RCC_USART6 0x63
#define RCC_ADC 0x64
#define RCC_ADC1 0x65
#define RCC_ADC2 0x66
#define RCC_ADC3 0x67
#define RCC_SDIO 0x68
#define RCC_SPI1 0x69
#define RCC_SPI4 0x6A
#define RCC_SYSCFG 0x6B
#define RCC_TIM9 0x6C
#define RCC_TIM10 0x6D
#define RCC_TIM11 0x6E
#define RCC_SPI5 0x6F
#define RCC_SPI6 0x70
#define RCC_SAI1 0x71
#define RCC_LTDC 0x72

#define IS_RCC_PERIPHERAL(Peripheral) (((Peripheral) == RCC_GPIOA) || \
                                       ((Peripheral) == RCC_GPIOB) || \
                                       ((Peripheral) == RCC_GPIOC) || \
                                       ((Peripheral) == RCC_GPIOD) || \
                                       ((Peripheral) == RCC_GPIOE) || \
                                       ((Peripheral) == RCC_GPIOF) || \
                                       ((Peripheral) == RCC_GPIOG) || \
                                       ((Peripheral) == RCC_GPIOH) || \
                                       ((Peripheral) == RCC_GPIOI) || \
                                       ((Peripheral) == RCC_GPIOJ) || \
                                       ((Peripheral) == RCC_GPIOK) || \
                                       ((Peripheral) == RCC_CRC) || \
                                       ((Peripheral) == RCC_FLITF) || \
                                       ((Peripheral) == RCC_SRAM1) || \
                                       ((Peripheral) == RCC_SRAM2) || \
                                       ((Peripheral) == RCC_BKPSRAM) || \
                                       ((Peripheral) == RCC_SRAM3) || \
                                       ((Peripheral) == RCC_CCMDATARAMEN) || \
                                       ((Peripheral) == RCC_DMA1) || \
                                       ((Peripheral) == RCC_DMA2) || \
                                       ((Peripheral) == RCC_DMA2D) || \
                                       ((Peripheral) == RCC_ETH_MAC) || \
                                       ((Peripheral) == RCC_ETH_MAC_Tx) || \
                                       ((Peripheral) == RCC_ETH_MAC_Rx) || \
                                       ((Peripheral) == RCC_ETH_MAC_PTP) || \
                                       ((Peripheral) == RCC_OTG_HS) || \
                                       ((Peripheral) == RCC_OTG_HS_ULPI) || \
                                       ((Peripheral) == RCC_DCMI) || \
                                       ((Peripheral) == RCC_CRYP) || \
                                       ((Peripheral) == RCC_HASH) || \
                                       ((Peripheral) == RCC_RNG) || \
                                       ((Peripheral) == RCC_OTG_FS) || \
                                       ((Peripheral) == RCC_FSMC) || \
                                       ((Peripheral) == RCC_TIM2) || \
                                       ((Peripheral) == RCC_TIM3) || \
                                       ((Peripheral) == RCC_TIM4) || \
                                       ((Peripheral) == RCC_TIM5) || \
                                       ((Peripheral) == RCC_TIM6) || \
                                       ((Peripheral) == RCC_TIM7) || \
                                       ((Peripheral) == RCC_TIM12) || \
                                       ((Peripheral) == RCC_TIM13) || \
                                       ((Peripheral) == RCC_TIM14) || \
                                       ((Peripheral) == RCC_WWDG) || \
                                       ((Peripheral) == RCC_SPI2) || \
                                       ((Peripheral) == RCC_SPI3) || \
                                       ((Peripheral) == RCC_USART2) || \
                                       ((Peripheral) == RCC_USART3) || \
                                       ((Peripheral) == RCC_UART4) || \
                                       ((Peripheral) == RCC_UART5) || \
                                       ((Peripheral) == RCC_I2C1) || \
                                       ((Peripheral) == RCC_I2C2) || \
                                       ((Peripheral) == RCC_I2C3) || \
                                       ((Peripheral) == RCC_CAN1) || \
                                       ((Peripheral) == RCC_CAN2) || \
                                       ((Peripheral) == RCC_PWR) || \
                                       ((Peripheral) == RCC_DAC) || \
                                       ((Peripheral) == RCC_UART7) || \
                                       ((Peripheral) == RCC_UART8) || \
                                       ((Peripheral) == RCC_TIM1) || \
                                       ((Peripheral) == RCC_TIM8) || \
                                       ((Peripheral) == RCC_USART1) || \
                                       ((Peripheral) == RCC_USART6) || \
                                       ((Peripheral) == RCC_ADC) || \
                                       ((Peripheral) == RCC_ADC1) || \
                                       ((Peripheral) == RCC_ADC2) || \
                                       ((Peripheral) == RCC_ADC3) || \
                                       ((Peripheral) == RCC_SDIO) || \
                                       ((Peripheral) == RCC_SPI1) || \
                                       ((Peripheral) == RCC_SPI4) || \
                                       ((Peripheral) == RCC_SYSCFG) || \
                                       ((Peripheral) == RCC_TIM9) || \
                                       ((Peripheral) == RCC_TIM10) || \
                                       ((Peripheral) == RCC_TIM11) || \
                                       ((Peripheral) == RCC_SPI5) || \
                                       ((Peripheral) == RCC_SPI6) || \
                                       ((Peripheral) == RCC_SAI1) || \
                                       ((Peripheral) == RCC_LTDC))


void RCC_PeriphClockCmd(uint8_t Peripheral,
                        FunctionalState NewState);

//** RCC_PeriphClockCmd **
//-- Peripheral --
//   RCC_GPIOA
//   RCC_GPIOB
//   RCC_GPIOC
//   RCC_GPIOD
//   RCC_GPIOE
//   RCC_GPIOF
//   RCC_GPIOG
//   RCC_GPIOH
//   RCC_GPIOI
//   RCC_GPIOJ
//   RCC_GPIOK
//   RCC_CRC
//   RCC_FLITF
//   RCC_SRAM1
//   RCC_SRAM2
//   RCC_BKPSRAM
//   RCC_SRAM3
//   RCC_CCMDATARAMEN
//   RCC_DMA1
//   RCC_DMA2
//   RCC_DMA2D
//   RCC_ETH_MAC
//   RCC_ETH_MAC_Tx
//   RCC_ETH_MAC_Rx
//   RCC_ETH_MAC_PTP
//   RCC_OTG_HS
//   RCC_OTG_HS_ULPI
//   RCC_DCMI
//   RCC_CRYP
//   RCC_HASH
//   RCC_RNG
//   RCC_OTG_FS
//   RCC_FSMC
//   RCC_TIM2
//   RCC_TIM3
//   RCC_TIM4
//   RCC_TIM5
//   RCC_TIM6
//   RCC_TIM7
//   RCC_TIM12
//   RCC_TIM13
//   RCC_TIM14
//   RCC_WWDG
//   RCC_SPI2
//   RCC_SPI3
//   RCC_USART2
//   RCC_USART3
//   RCC_UART4
//   RCC_UART5
//   RCC_I2C1
//   RCC_I2C2
//   RCC_I2C3
//   RCC_CAN1
//   RCC_CAN2
//   RCC_PWR
//   RCC_DAC
//   RCC_UART7
//   RCC_UART8
//   RCC_TIM1
//   RCC_TIM8
//   RCC_USART1
//   RCC_USART6
//   RCC_ADC
//   RCC_ADC1
//   RCC_ADC2
//   RCC_ADC3
//   RCC_SDIO
//   RCC_SPI1
//   RCC_SPI4
//   RCC_SYSCFG
//   RCC_TIM9
//   RCC_TIM10
//   RCC_TIM11
//   RCC_SPI5
//   RCC_SPI6
//   RCC_SAI1
//   RCC_LTDC

//-- NewState --
//   ENABLE
//   DISABLE

//*****************************************************************
//** Definitions for other functions **
//-- RCC_HSE_configuration --
//   RCC_HSE_OFF
//   RCC_HSE_ON
//   RCC_HSE_Bypass

//-- RCC_PLL_Clock_Source --
//   RCC_PLLSource_HSI
//   RCC_PLLSource_HSE

//-- RCC_PLLM_value --
//   0x00 - 0x3F (0 - 63)

//-- RCC_PLLN_value --
//   0x0C0 - 0x1B0 (192 - 432)

//-- RCC_PLLP_value --
//   0x2, 0x4, 0x6, 0x8, (2, 4, 6, 8)

//-- RCC_PLLQ_value --
//   0x4 - 0xF (4 - 15)

//-- RCC_PLLI2SN_value --
//   0x0C0 - 0x1B0 (192 - 432)

//-- RCC_PLLI2SR_value --
//   0x2 - 0x7 (2 - 7)

//-- RCC_PLLI2SQ_value --
//   0x2 - 0xF (2 - 15)

//-- RCC_PLLSAIN_value --
//   0x0C0 - 0x1B0 (192 - 432)

//-- RCC_PLLSAIQ_value --
//   0x2 - 0xF (2 - 15)

//-- RCC_PLLSAIR_value --
//   0x2 - 0x7 (2 - 7)

//-- RCC_PLLSAI_DIVQ_value --
//   0x01 - 0x20 (1 - 32)

//-- RCC_PLLI2S_DIVQ_value --
//   0x01 - 0x20 (1 - 32)

//-- RCC_PLLSAI_DIVR_value --
//   RCC_PLLSAIDivR_Div2
//   RCC_PLLSAIDivR_Div4
//   RCC_PLLSAIDivR_Div8
//   RCC_PLLSAIDivR_Div16

//-- RCC_System_Clock_Source --
//   RCC_SYSCLKSource_HSI
//   RCC_SYSCLKSource_HSE
//   RCC_SYSCLKSource_PLLCLK

//-- RCC_AHB_Clock_Source --
//   RCC_SYSCLK_Div1
//   RCC_SYSCLK_Div2
//   RCC_SYSCLK_Div4
//   RCC_SYSCLK_Div8
//   RCC_SYSCLK_Div16
//   RCC_SYSCLK_Div64
//   RCC_SYSCLK_Div128
//   RCC_SYSCLK_Div256
//   RCC_SYSCLK_Div512

//-- RCC_APB1_APB2_Clock_Source --
//   RCC_HCLK_Div1
//   RCC_HCLK_Div2
//   RCC_HCLK_Div4
//   RCC_HCLK_Div8
//   RCC_HCLK_Div16

//-- RCC_Interrupt_Source
//   RCC_IT_LSIRDY
//   RCC_IT_LSERDY
//   RCC_IT_HSIRDY
//   RCC_IT_HSERDY
//   RCC_IT_PLLRDY
//   RCC_IT_PLLI2SRDY
//   RCC_IT_PLLSAIRDY
//   RCC_IT_CSS

//-- RCC_LSE_Configuration --
//   RCC_LSE_OFF
//   RCC_LSE_ON
//   RCC_LSE_Bypass

//-- RCC_RTC_Clock_Source --
//   RCC_RTCCLKSource_LSE
//   RCC_RTCCLKSource_LSI
//   RCC_RTCCLKSource_HSE_Div2
//   RCC_RTCCLKSource_HSE_Div3
//   RCC_RTCCLKSource_HSE_Div4
//   RCC_RTCCLKSource_HSE_Div5
//   RCC_RTCCLKSource_HSE_Div6
//   RCC_RTCCLKSource_HSE_Div7
//   RCC_RTCCLKSource_HSE_Div8
//   RCC_RTCCLKSource_HSE_Div9
//   RCC_RTCCLKSource_HSE_Div10
//   RCC_RTCCLKSource_HSE_Div11
//   RCC_RTCCLKSource_HSE_Div12
//   RCC_RTCCLKSource_HSE_Div13
//   RCC_RTCCLKSource_HSE_Div14
//   RCC_RTCCLKSource_HSE_Div15
//   RCC_RTCCLKSource_HSE_Div16
//   RCC_RTCCLKSource_HSE_Div17
//   RCC_RTCCLKSource_HSE_Div18
//   RCC_RTCCLKSource_HSE_Div19
//   RCC_RTCCLKSource_HSE_Div20
//   RCC_RTCCLKSource_HSE_Div21
//   RCC_RTCCLKSource_HSE_Div22
//   RCC_RTCCLKSource_HSE_Div23
//   RCC_RTCCLKSource_HSE_Div24
//   RCC_RTCCLKSource_HSE_Div25
//   RCC_RTCCLKSource_HSE_Div26
//   RCC_RTCCLKSource_HSE_Div27
//   RCC_RTCCLKSource_HSE_Div28
//   RCC_RTCCLKSource_HSE_Div29
//   RCC_RTCCLKSource_HSE_Div30
//   RCC_RTCCLKSource_HSE_Div31

//-- RCC_I2S_Clock_Source --
//   RCC_I2S2CLKSource_PLLI2S
//   RCC_I2S2CLKSource_Ext

//-- RCC_SAI_BlockA_Clock_Source --
//   RCC_SAIACLKSource_PLLSAI
//   RCC_SAIACLKSource_PLLI2S
//   RCC_SAIACLKSource_Ext

//-- RCC_SAI_BlockB_Clock_Source --
//   RCC_SAIACLKSource_PLLSAI
//   RCC_SAIACLKSource_PLLI2S
//   RCC_SAIACLKSource_Ext

//-- RCC_TIM_PRescaler_Selection --
//   RCC_TIMPrescDesactivated
//   RCC_TIMPrescActivated

//-- RCC_AHB1_Peripherals --
//   RCC_AHB1Periph_GPIOA
//   RCC_AHB1Periph_GPIOB
//   RCC_AHB1Periph_GPIOC
//   RCC_AHB1Periph_GPIOD
//   RCC_AHB1Periph_GPIOE
//   RCC_AHB1Periph_GPIOF
//   RCC_AHB1Periph_GPIOG
//   RCC_AHB1Periph_GPIOH
//   RCC_AHB1Periph_GPIOI
//   RCC_AHB1Periph_GPIOJ
//   RCC_AHB1Periph_GPIOK
//   RCC_AHB1Periph_CRC
//   RCC_AHB1Periph_FLITF
//   RCC_AHB1Periph_SRAM1
//   RCC_AHB1Periph_SRAM2
//   RCC_AHB1Periph_BKPSRAM
//   RCC_AHB1Periph_SRAM3
//   RCC_AHB1Periph_CCMDATARAMEN
//   RCC_AHB1Periph_DMA1
//   RCC_AHB1Periph_DMA2
//   RCC_AHB1Periph_DMA2D
//   RCC_AHB1Periph_ETH_MAC
//   RCC_AHB1Periph_ETH_MAC_Tx
//   RCC_AHB1Periph_ETH_MAC_Rx
//   RCC_AHB1Periph_ETH_MAC_PTP
//   RCC_AHB1Periph_OTG_HS
//   RCC_AHB1Periph_OTG_HS_ULPI

//-- RCC_AHB2_Peripherals --
//   RCC_AHB2Periph_DCMI
//   RCC_AHB2Periph_CRYP
//   RCC_AHB2Periph_HASH
//   RCC_AHB2Periph_RNG
//   RCC_AHB2Periph_OTG_FS

//-- RCC_AHB3_Peripherals --
//   RCC_AHB3Periph_FSMC

//-- RCC_APB1_Peripherals --
//   RCC_APB1Periph_TIM2
//   RCC_APB1Periph_TIM4
//   RCC_APB1Periph_TIM5
//   RCC_APB1Periph_TIM6
//   RCC_APB1Periph_TIM7
//   RCC_APB1Periph_TIM12
//   RCC_APB1Periph_TIM13
//   RCC_APB1Periph_TIM14
//   RCC_APB1Periph_WWDG
//   RCC_APB1Periph_SPI2
//   RCC_APB1Periph_SPI3
//   RCC_APB1Periph_USART2
//   RCC_APB1Periph_USART3
//   RCC_APB1Periph_UART4
//   RCC_APB1Periph_UART5
//   RCC_APB1Periph_I2C1
//   RCC_APB1Periph_I2C2
//   RCC_APB1Periph_I2C3
//   RCC_APB1Periph_CAN1
//   RCC_APB1Periph_CAN2
//   RCC_APB1Periph_PWR
//   RCC_APB1Periph_DAC
//   RCC_APB1Periph_UART7
//   RCC_APB1Periph_UART8

//-- RCC_APB2_Peripherals --
//   RCC_APB2Periph_TIM1
//   RCC_APB2Periph_TIM8
//   RCC_APB2Periph_USART1
//   RCC_APB2Periph_USART6
//   RCC_APB2Periph_ADC
//   RCC_APB2Periph_ADC1
//   RCC_APB2Periph_ADC2
//   RCC_APB2Periph_ADC3
//   RCC_APB2Periph_SDIO
//   RCC_APB2Periph_SPI1
//   RCC_APB2Periph_SPI4
//   RCC_APB2Periph_SYSCFG
//   RCC_APB2Periph_TIM9
//   RCC_APB2Periph_TIM10
//   RCC_APB2Periph_TIM11
//   RCC_APB2Periph_SPI5
//   RCC_APB2Periph_SPI6
//   RCC_APB2Periph_SAI1
//   RCC_APB2Periph_LTDC

//-- RCC_MCO1_Clock_Source_Prescaler --
//   RCC_MCO1Source_HSI
//   RCC_MCO1Source_LSE
//   RCC_MCO1Source_HSE
//   RCC_MCO1Source_PLLCLK
//   RCC_MCO1Div_1
//   RCC_MCO1Div_2
//   RCC_MCO1Div_3
//   RCC_MCO1Div_4
//   RCC_MCO1Div_5

//-- RCC_MCO2_Clock_Source_Prescaler --
//   RCC_MCO2Source_SYSCLK
//   RCC_MCO2Source_PLLI2SCLK
//   RCC_MCO2Source_HSE
//   RCC_MCO2Source_PLLCLK
//   RCC_MCO2Div_1
//   RCC_MCO2Div_2
//   RCC_MCO2Div_3
//   RCC_MCO2Div_4
//   RCC_MCO2Div_5

//-- RCC_Flag --
//   RCC_FLAG_HSIRDY
//   RCC_FLAG_HSERDY
//   RCC_FLAG_PLLRDY
//   RCC_FLAG_PLLI2SRDY
//   RCC_FLAG_PLLSAIRDY
//   RCC_FLAG_LSERDY
//   RCC_FLAG_LSIRDY
//   RCC_FLAG_BORRST
//   RCC_FLAG_PINRST
//   RCC_FLAG_PORRST
//   RCC_FLAG_SFTRST
//   RCC_FLAG_IWDGRST
//   RCC_FLAG_WWDGRST
//   RCC_FLAG_LPWRRST

//-- RCC_Calibration_value
//   0x00 - 0x1F (0 - 31)

#endif
