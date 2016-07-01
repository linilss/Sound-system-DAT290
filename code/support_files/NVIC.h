/*
   NVIC.h
*/

#ifndef NVIC_H
#define NVIC_H

#include "misc.h"

void init_IRQ_Channel(uint8_t NVIC_IRQChannel,
                      uint8_t NVIC_IRQChannelPreemptionPriority,
                      uint8_t NVIC_IRQChannelSubPriority,
                      FunctionalState NVIC_IRQChannelCmd);

//** init_IRQ_Channel **
//-- NVIC_IRQChannel --
//   !! Cortex-M4 Processor Exceptions !!
//   NonMaskableInt_IRQn - Non Maskable Interrupt
//   MemoryManagement_IRQn - Cortex-M4 Memory Management Interrupt
//   BusFault_IRQn - 5 Cortex-M4 Bus Fault Interrupt
//   UsageFault_IRQn - Cortex-M4 Usage Fault Interrupt
//   SVCall_IRQn - Cortex-M4 SV Call Interrupt
//   DebugMonitor_IRQn - Cortex-M4 Debug Monitor Interrupt
//   PendSV_IRQn - 14 Cortex-M4 Pend SV Interrupt
//   SysTick_IRQn - Cortex-M4 System Tick Interrupt
//   !! STM32 specific Interrupts !!
//   WWDG_IRQn - Window WatchDog Interrupt
//   PVD_IRQn - PVD through EXTI Line detection Interrupt
//   TAMP_STAMP_IRQn - Tamper and TimeStamp interrupts through the EXTI line
//   RTC_WKUP_IRQn - RTC Wakeup interrupt through the EXTI line
//   FLASH_IRQn - FLASH global Interrupt
//   RCC_IRQn - RCC global Interrupt
//   EXTI0_IRQn - EXTI Line0 Interrupt
//   EXTI1_IRQn - EXTI Line1 Interrupt
//   EXTI2_IRQn - EXTI Line2 Interrupt
//   EXTI3_IRQn - EXTI Line3 Interrupt
//   EXTI4_IRQn - EXTI Line4 Interrupt
//   DMA1_Stream0_IRQn - DMA1 Stream 0 global Interrupt
//   DMA1_Stream1_IRQn - DMA1 Stream 1 global Interrupt
//   DMA1_Stream2_IRQn - DMA1 Stream 2 global Interrupt
//   DMA1_Stream3_IRQn - DMA1 Stream 3 global Interrupt
//   DMA1_Stream4_IRQn - DMA1 Stream 4 global Interrupt
//   DMA1_Stream5_IRQn - DMA1 Stream 5 global Interrupt
//   DMA1_Stream6_IRQn - DMA1 Stream 6 global Interrupt
//   ADC_IRQn - ADC1, ADC2 and ADC3 global Interrupts
//   !! STM32F40_41xxx Interrupts !!
//   CAN1_TX_IRQn - CAN1 TX Interrupt-
//   CAN1_RX0_IRQn - CAN1 RX0 Interrupt
//   CAN1_RX1_IRQn - CAN1 RX1 Interrupt
//   CAN1_SCE_IRQn - CAN1 SCE Interrupt
//   EXTI9_5_IRQn - External Line[9:5] Interrupts
//   TIM1_BRK_TIM9_IRQn - TIM1 Break interrupt and TIM9 global interrupt
//   TIM1_UP_TIM10_IRQn - TIM1 Update Interrupt and TIM10 global interrupt
//   TIM1_TRG_COM_TIM11_IRQn - TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt
//   TIM1_CC_IRQn - TIM1 Capture Compare Interrupt
//   TIM2_IRQn - TIM2 global Interrupt
//   TIM3_IRQn - TIM3 global Interrupt
//   TIM4_IRQn - TIM4 global Interrupt
//   I2C1_EV_IRQn - I2C1 Event Interrupt
//   I2C1_ER_IRQn - I2C1 Error Interrupt
//   I2C2_EV_IRQn - I2C2 Event Interrupt
//   I2C2_ER_IRQn - I2C2 Error Interrupt
//   SPI1_IRQn - SPI1 global Interrupt
//   SPI2_IRQn - SPI2 global Interrupt
//   USART1_IRQn - USART1 global Interrupt
//   USART2_IRQn - USART2 global Interrupt
//   USART3_IRQn - USART3 global Interrupt
//   EXTI15_10_IRQn - External Line[15:10] Interrupts
//   RTC_Alarm_IRQn - RTC Alarm (A and B) through EXTI Line Interrupt
//   OTG_FS_WKUP_IRQn - USB OTG FS Wakeup through EXTI line interrupt
//   TIM8_BRK_TIM12_IRQn - TIM8 Break Interrupt and TIM12 global interrupt
//   TIM8_UP_TIM13_IRQn - TIM8 Update Interrupt and TIM13 global interrupt
//   TIM8_TRG_COM_TIM14_IRQn - TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt
//   TIM8_CC_IRQn - TIM8 Capture Compare Interrupt
//   DMA1_Stream7_IRQn - DMA1 Stream7 Interrupt
//   FSMC_IRQn - FSMC global Interrupt
//   SDIO_IRQn - SDIO global Interrupt
//   TIM5_IRQn - TIM5 global Interrupt
//   SPI3_IRQn - SPI3 global Interrupt
//   UART4_IRQn - UART4 global Interrupt
//   UART5_IRQn - UART5 global Interrupt
//   TIM6_DAC_IRQn - TIM6 global and DAC1&2 underrun error interrupts
//   TIM7_IRQn - TIM7 global interrupt
//   DMA2_Stream0_IRQn - DMA2 Stream 0 global Interrupt
//   DMA2_Stream1_IRQn - DMA2 Stream 1 global Interrupt
//   DMA2_Stream2_IRQn - DMA2 Stream 2 global Interrupt
//   DMA2_Stream3_IRQn - DMA2 Stream 3 global Interrupt
//   DMA2_Stream4_IRQn - DMA2 Stream 4 global Interrupt
//   ETH_IRQn - Ethernet global Interrupt
//   ETH_WKUP_IRQn - Ethernet Wakeup through EXTI line Interrupt
//   CAN2_TX_IRQn - CAN2 TX Interrupt
//   CAN2_RX0_IRQn - CAN2 RX0 Interrupt
//   CAN2_RX1_IRQn - CAN2 RX1 Interrupt
//   CAN2_SCE_IRQn - CAN2 SCE Interrupt
//   OTG_FS_IRQn - USB OTG FS global Interrupt
//   DMA2_Stream5_IRQn - DMA2 Stream 5 global interrupt
//   DMA2_Stream6_IRQn - DMA2 Stream 6 global interrupt
//   DMA2_Stream7_IRQn - DMA2 Stream 7 global interrupt
//   USART6_IRQn - USART6 global interrupt
//   I2C3_EV_IRQn - I2C3 event interrupt
//   I2C3_ER_IRQn - I2C3 error interrupt
//   OTG_HS_EP1_OUT_IRQn - USB OTG HS End Point 1 Out global interrupt
//   OTG_HS_EP1_IN_IRQn - USB OTG HS End Point 1 In global interrupt
//   OTG_HS_WKUP_IRQn - USB OTG HS Wakeup through EXTI interrupt
//   OTG_HS_IRQn - USB OTG HS global interrupt
//   DCMI_IRQn - DCMI global interrupt
//   CRYP_IRQn - CRYP crypto global interrupt
//   HASH_RNG_IRQn - Hash and Rng global interrupt
//   FPU_IRQn - FPU global interrupt

//-- NVIC_IRQChannelPreemptionPriority --
//   0x0 - 0xF

//-- NVIC_IRQChannelSubPriority --
//   0x0 - 0xF

//-- NVIC_IRQChannelCmd --
//   ENABLE
//   DISABLE

//*****************************************************************
//** Definitions for other functions **
//-- MISC_Vector_Table_Base --
//   NVIC_VectTab_RAM
//   NVIC_VectTab_FLASH

//-- MISC_System_Low_Power --
//   NVIC_LP_SEVONPEND
//   NVIC_LP_SLEEPDEEP
//   NVIC_LP_SLEEPONEXIT

//-- MISC_Preemption_Priority_Group --
//   NVIC_PriorityGroup_0 - 0 bits for pre-emption priority
//                          4 bits for subpriority
//   NVIC_PriorityGroup_1 - 1 bits for pre-emption priority
//                          3 bits for subpriority
//   NVIC_PriorityGroup_2 - 2 bits for pre-emption priority
//                          2 bits for subpriority
//   NVIC_PriorityGroup_3 - 3 bits for pre-emption priority
//                          1 bits for subpriority
//   NVIC_PriorityGroup_4 - 4 bits for pre-emption priority
//                          0 bits for subpriority

//-- NVIC_Preemption_Priority --
//   0x00 - 0x10

//-- NVIC_Sub_Priority --
//   0x00 - 0x10

//-- NVIC_Offset --
//   0x00000000 - 0x000FFFFF

//-- MISC_SysTick_clock_source
//   SysTick_CLKSource_HCLK_Div8
//   SysTick_CLKSource_HCLK

#endif
