/*
   SPI.h
*/

#ifndef SPI_H
#define SPI_H

#include "stm32f4xx_spi.h"

void SPI_CS_SetLow(GPIO_TypeDef* GPIOx,
                   uint32_t GPIO_Pin);

void SPI_CS_SetHigh(GPIO_TypeDef* GPIOx,
                    uint32_t GPIO_Pin);

void init_SPI(SPI_TypeDef* SPIx,
              uint16_t SPI_Direction,
              uint16_t SPI_Mode,
              uint16_t SPI_DataSize,
              uint16_t SPI_CPOL,
              uint16_t SPI_CPHA,
              uint16_t SPI_NSS,
              uint16_t SPI_BaudRatePrescaler,
              uint16_t SPI_FirstBit,
              uint16_t SPI_CRCPolynomial);

uint8_t SPI_SendByte(SPI_TypeDef* SPIx,
                     uint8_t byte);
uint16_t SPI_SendHalfWord(SPI_TypeDef* SPIx,
                          uint16_t HalfWord);

void init_I2S(SPI_TypeDef* SPIx,
              uint16_t I2S_Mode,
              uint16_t I2S_Standard,
              uint16_t I2S_DataFormat,
              uint16_t I2S_MCLKOutput,
              uint32_t I2S_AudioFreq,
              uint16_t I2S_CPOL);

//** SPI_CS_SetLow **
//-- GPIOx --
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

//** SPI_CS_SetHigh **
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

//** init_SPI **
//-- SPIx --
//   SPI1
//   SPI2
//   SPI3
//   SPI4
//   SPI5
//   SPI6

//-- SPI_Direction --
//   SPI_Direction_2Lines_FullDuplex
//   SPI_Direction_2Lines_RxOnly
//   SPI_Direction_1Line_Rx
//   SPI_Direction_1Line_Tx

//-- SPI_Mode --
//   SPI_Mode_Master
//   SPI_Mode_Slave

//-- SPI_DataSize --
//   SPI_DataSize_16b
//   SPI_DataSize_8b

//-- SPI_CPOL --
//   SPI_CPOL_Low
//   SPI_CPOL_High

//-- SPI_CPHA --
//   SPI_CPHA_1Edge
//   SPI_CPHA_2Edge

//-- SPI_NSS --
//   SPI_NSS_Soft
//   SPI_NSS_Hard

//-- SPI_BaudRatePrescaler --
//   SPI_BaudRatePrescaler_2
//   SPI_BaudRatePrescaler_4
//   SPI_BaudRatePrescaler_8
//   SPI_BaudRatePrescaler_16
//   SPI_BaudRatePrescaler_32
//   SPI_BaudRatePrescaler_64
//   SPI_BaudRatePrescaler_128
//   SPI_BaudRatePrescaler_256

//-- SPI_FirstBit --
//   SPI_FirstBit_MSB
//   SPI_FirstBit_LSB

//-- SPI_CRCPolynomial --
//   0x0000 - 0xFFFF

//** SPI_SendByte **
//-- SPIx --
//   SPI1
//   SPI2
//   SPI3
//   SPI4
//   SPI5
//   SPI6

//-- byte --
//   0x00-0xFF

//** SPI_SendHalfWord **
//-- SPIx --
//   SPI1
//   SPI2
//   SPI3
//   SPI4
//   SPI5
//   SPI6

//-- HalfWord --
//   0x0000 - 0xFFFF

//** init_I2S **
//-- SPI_I2S_Mode --
//   I2S_Mode_SlaveTx
//   I2S_Mode_SlaveRx
//   I2S_Mode_MasterTx
//   I2S_Mode_MasterRx

//-- SPI_I2S_Standard --
//   I2S_Standard_Phillips
//   I2S_Standard_MSB
//   I2S_Standard_LSB
//   I2S_Standard_PCMShort
//   I2S_Standard_PCMLong

//-- SPI_I2S_Data_Format --
//   I2S_DataFormat_16b
//   I2S_DataFormat_16bextended
//   I2S_DataFormat_24b
//   I2S_DataFormat_32b

//-- SPI_I2S_MCLK_Output --
//   I2S_MCLKOutput_Enable
//   I2S_MCLKOutput_Disable

//-- SPI_I2S_Audio_Frequency --
//   I2S_AudioFreq_192k
//   I2S_AudioFreq_96k
//   I2S_AudioFreq_48k
//   I2S_AudioFreq_44k
//   I2S_AudioFreq_32k
//   I2S_AudioFreq_22k
//   I2S_AudioFreq_16k
//   I2S_AudioFreq_11k
//   I2S_AudioFreq_8k
//   I2S_AudioFreq_Default

//-- SPI_I2S_Clock_Polarity --
//   I2S_CPOL_Low
//   I2S_CPOL_High

//*****************************************************************
//** Definitions for other functions **

//-- SPI_I2S_DMA_transfer_requests --
//   SPI_I2S_DMAReq_Tx
//   SPI_I2S_DMAReq_Rx

//-- SPI_NSS_internal_software_management --
//   SPI_NSSInternalSoft_Set
//   SPI_NSSInternalSoft_Reset

//-- SPI_CRC_Transmit_Receive --
//   SPI_CRC_Tx
//   SPI_CRC_Rx

//-- SPI_direction_transmit_receive --
//   SPI_Direction_Rx
//   SPI_Direction_Tx

//-- SPI_I2S_interrupts_definition --
//   SPI_I2S_IT_TXE
//   SPI_I2S_IT_RXNE
//   SPI_I2S_IT_ERR
//   I2S_IT_UDR
//   SPI_I2S_IT_TIFRFE
//   SPI_I2S_IT_OVR
//   SPI_IT_MODF
//   SPI_IT_CRCERR
//   SPI_I2S_CLEAR = SPI_IT_CRCERR))

//-- SPI_I2S_flags_definition --
//   SPI_I2S_FLAG_RXNE
//   SPI_I2S_FLAG_TXE
//   I2S_FLAG_CHSIDE
//   I2S_FLAG_UDR
//   SPI_FLAG_CRCERR
//   SPI_FLAG_MODF
//   SPI_I2S_FLAG_OVR
//   SPI_I2S_FLAG_BSY
//   SPI_I2S_FLAG_TIFRFE

//-- SPI_CRC_polynomial --
//   0x0001 - 0xFFFF

//-- SPI_I2S_Legacy --
//   SPI_DMAReq_Tx         = SPI_I2S_DMAReq_Tx
//   SPI_DMAReq_Rx         = SPI_I2S_DMAReq_Rx
//   SPI_IT_TXE            = SPI_I2S_IT_TXE
//   SPI_IT_RXNE           = SPI_I2S_IT_RXNE
//   SPI_IT_ERR            = SPI_I2S_IT_ERR
//   SPI_IT_OVR            = SPI_I2S_IT_OVR
//   SPI_FLAG_RXNE         = SPI_I2S_FLAG_RXNE
//   SPI_FLAG_TXE          = SPI_I2S_FLAG_TXE
//   SPI_FLAG_OVR          = SPI_I2S_FLAG_OVR
//   SPI_FLAG_BSY          = SPI_I2S_FLAG_BSY
//   SPI_DeInit            = SPI_I2S_DeInit
//   SPI_ITConfig          = SPI_I2S_ITConfig
//   SPI_DMACmd            = SPI_I2S_DMACmd
//   SPI_SendData          = SPI_I2S_SendData
//   SPI_ReceiveData       = SPI_I2S_ReceiveData
//   SPI_GetFlagStatus     = SPI_I2S_GetFlagStatus
//   SPI_ClearFlag         = SPI_I2S_ClearFlag
//   SPI_GetITStatus       = SPI_I2S_GetITStatus
//   SPI_ClearITPendingBit = SPI_I2S_ClearITPendingBit

#endif