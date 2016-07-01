/*
   USART.c
*/

#define assert_param(x)

#include "USART.h"

void init_SCI(USART_TypeDef* USARTx,
              uint32_t USART_BaudRate,
              uint16_t USART_WordLength,
              uint16_t USART_StopBits,
              uint16_t USART_Parity,
              uint16_t USART_Mode,
              uint16_t USART_HardwareFlowControl)
{
   static uint16_t usartDeInitFlag=0;

   USART_InitTypeDef USART_InitStructure; //setup UART_InitStructure
   USART_ClockInitTypeDef USART_ClockInitStructure; //setup UART_ClockInitStructure
   USART_ClockStructInit(&USART_ClockInitStructure);

   if (usartDeInitFlag==0)
   {
      USART_DeInit(USARTx); //Deinit USARTx
      usartDeInitFlag=1;
   }

   USART_InitStructure.USART_BaudRate = USART_BaudRate;
   USART_InitStructure.USART_WordLength = USART_WordLength;
   USART_InitStructure.USART_StopBits = USART_StopBits;
   USART_InitStructure.USART_Parity = USART_Parity;
   USART_InitStructure.USART_Mode = USART_Mode;
   USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl;

   USART_Init(USARTx, &USART_InitStructure);

   USART_ClockInit(USARTx, &USART_ClockInitStructure);

   USART_Cmd(USARTx, ENABLE);
}

//Write char to SCI TX
void write_SCI(USART_TypeDef* USARTx,uint16_t value)
{
   while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);
   USARTx->DR = value & (uint16_t)0xFF;
}

//Read char from SCI RX
uint16_t read_SCI(USART_TypeDef* USARTx)
{
   while (USART_GetFlagStatus(USARTx, USART_FLAG_RXNE) == RESET);
   return (uint16_t)(USARTx->DR & (uint16_t)0xFF);
}
