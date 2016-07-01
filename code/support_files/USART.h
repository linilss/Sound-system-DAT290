/*
   USART.h
*/

#ifndef USART_H
#define USART_H

#include "stm32f4xx_usart.h"

void init_SCI(USART_TypeDef* USARTx,
              uint32_t USART_BaudRate,
              uint16_t USART_WordLength,
              uint16_t USART_StopBits,
              uint16_t USART_Parity,
              uint16_t USART_Mode,
              uint16_t USART_HardwareFlowControl);

void write_SCI(USART_TypeDef* USARTx,
               uint16_t value);

uint16_t read_SCI(USART_TypeDef* USARTx);

void write_string_SCI(USART_TypeDef* USARTx,
                      uint8_t *textstring);

void write_value_SCI(USART_TypeDef*,uint16_t);

//** init_SCI **
//-- USARTx --
//   USART1
//   USART2
//   USART3
//   USART4
//   USART5
//   USART6
//   USART7
//   USART8

//-- USART_BaudRate --
//   0x000001 - 0x7270E1 (1 - 7500001)

//-- USART_WordLength --
//   USART_WordLength_8b
//   USART_WordLength_9b

//-- USART_StopBits --
//   USART_StopBits_1
//   USART_StopBits_0_5
//   USART_StopBits_2
//   USART_StopBits_1_5

//-- USART_Parity --
//   USART_Parity_No
//   USART_Parity_Even
//   USART_Parity_Odd

//-- USART_Mode --
//   USART_Mode_Rx
//   USART_Mode_Tx

//-- USART_HardwareFlowControl
//   USART_HardwareFlowControl_None
//   USART_HardwareFlowControl_RTS
//   USART_HardwareFlowControl_CTS
//   USART_HardwareFlowControl_RTS_CTS

//** write_SCI **
//-- USARTx --
//   USART1
//   USART2
//   USART3
//   USART4
//   USART5
//   USART6
//   USART7
//   USART8

//-- value --
//   0x00 - 0xFF for 8 bits word length
//   0x000 - 0x1FF for 9 bits word length

//** read_SCI **
//-- USARTx --
//   USART1
//   USART2
//   USART3
//   USART4
//   USART5
//   USART6
//   USART7
//   USART8

void write_string_SCI(USART_TypeDef* USARTx,
                      uint8_t *teststring);

//*****************************************************************
//** Definitions for other functions **
//-- USART_Clock --
//   USART_Clock_Disable
//   USART_Clock_Enable

//-- USART_Clock_Polarity --
//   USART_CPOL_Low
//   USART_CPOL_High

//-- USART_Clock_Phase --
//   USART_CPHA_1Edge
//   USART_CPHA_2Edge

//-- USART_Last_Bit --
//   USART_LastBit_Disable
//   USART_LastBit_Enable

//-- USART_Interrupt_definition --
//   USART_IT_PE
//   USART_IT_TXE
//   USART_IT_TC
//   USART_IT_RXNE
//   USART_IT_ORE_RX - In case interrupt is generated
//                     if the RXNEIE bit is set
//   USART_IT_IDLE
//   USART_IT_LBD
//   USART_IT_CTS
//   USART_IT_ERR
//   USART_IT_ORE_ER - In case interrupt is generated
//                     if the EIE bit is set
//   USART_IT_NE
//   USART_IT_FE

//-- USART_Legacy --
//   USART_IT_ORE = USART_IT_ORE_ER

//-- USART_DMA_Requests --
//   USART_DMAReq_Tx
//   USART_DMAReq_Rx

//-- USART_WakeUp_methods --
//   USART_WakeUp_IdleLine
//   USART_WakeUp_AddressMark

//-- USART_LIN_Break_Detection_Length --
//   USART_LINBreakDetectLength_10b
//   USART_LINBreakDetectLength_11b

//-- USART_IrDA_Low_Power --
//   USART_IrDAMode_LowPower
//   USART_IrDAMode_Normal

//-- USART_Flags --
//   USART_FLAG_CTS
//   USART_FLAG_LBD
//   USART_FLAG_TXE
//   USART_FLAG_TC
//   USART_FLAG_RXNE
//   USART_FLAG_IDLE
//   USART_FLAG_ORE
//   USART_FLAG_NE
//   USART_FLAG_FE
//   USART_FLAG_PE

//-- UART_Address --
//   0x0 - 0xF (0 - 15)

//-- USART_Data --
//   0x000 - 0x1ff (0 - 511)

#endif
