/*
   DMA.c
*/

#define assert_param(x)

#include "DMA.h"

//Init DMA
void init_DMA(DMA_Stream_TypeDef* DMAy_Streamy,
              uint32_t DMA_Channel,
              uint32_t DMA_PeripheralBaseAddr,
              uint32_t DMA_MemoryBaseAddr,
              uint32_t DMA_DIR,
              uint32_t DMA_BufferSize,
              uint32_t DMA_PeripheralInc
              uint32_t DMA_MemoryInc,
              uint32_t DMA_PeripheralDataSize,
              uint32_t DMA_MemoryDataSize,
              uint32_t DMA_Mode,
              uint32_t DMA_Priority,
              uint32_t DMA_FIFOMode,
              uint32_t DMA_FIFOThreshold,
              uint32_t DMA_MemoryBurst,
              uint32_t DMA_PeripheralBurst)
{
   DMA_InitTypeDef DMA_InitStructure;

   static uint16_t dmaDeInitFlag=0;

   if (dmaDeInitFlag==0)
   {
      DMA_DeInit(DMAy_Streamy);
      dmaDeInitFlag=1;
   }

   DMA_InitStructure.DMA_Channel = DMA_Channel;
   DMA_InitStructure.DMA_PeripheralBaseAddr = DMA_PeripheralBaseAddr;
   DMA_InitStructure.DMA_MemoryBaseAddr = DMA_MemoryBaseAddr;
   DMA_InitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay;
   DMA_InitStructure.DMA_DIR = DMA_DIR;
   DMA_InitStructure.DMA_BufferSize = DMA_BufferSize;
   DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc;
   DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc;
   DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize;
   DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize;
   DMA_InitStructure.DMA_Mode = DMA_Mode;
   DMA_InitStructure.DMA_Priority = DMA_Priority;
   DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode;
   DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold;
   DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst;
   DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst;

   DMA_Init(DMAy_Streamy,DMA_InitStructure
}