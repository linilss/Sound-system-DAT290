/*
   NVIC.c
*/

#define assert_param(x)

#include "NVIC.h"

NVIC_InitTypeDef NVIC_InitStructure;

/* Enable global Interrupt */
void init_IRQ_Channel(uint8_t NVIC_IRQChannel,
                      uint8_t NVIC_IRQChannelPreemptionPriority,
                      uint8_t NVIC_IRQChannelSubPriority,
                      FunctionalState NVIC_IRQChannelCmd)
{
   NVIC_InitStructure.NVIC_IRQChannel = NVIC_IRQChannel;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = NVIC_IRQChannelPreemptionPriority;
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = NVIC_IRQChannelSubPriority;
   NVIC_InitStructure.NVIC_IRQChannelCmd = NVIC_IRQChannelCmd;

   NVIC_Init(&NVIC_InitStructure);
}