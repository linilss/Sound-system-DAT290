/*
   	DMA.h
*/

#ifndef DMA_H
#define DMA_H

#include "stm32f4xx_dma.h"

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
              uint32_t DMA_PeripheralBurst);

//** init_DMA **
//-- DMA_Channel --
//   DMA_Channel_0
//   DMA_Channel_1
//   DMA_Channel_2
//   DMA_Channel_3
//   DMA_Channel_4
//   DMA_Channel_5
//   DMA_Channel_6
//   DMA_Channel_7

//-- DMA_DIR --
//-- DMA_data_transfer_direction --
//   DMA_DIR_PeripheralToMemory
//   DMA_DIR_MemoryToPeripheral
//   DMA_DIR_MemoryToMemory

//-- DMA_BufferSize --
//-- DMA_data_buffer_size --
//   0x00001 - 0x10000

//-- DMA_PeripheralInc --
//-- DMA_peripheral_incremented_mode --
//   DMA_PeripheralInc_Enable
//   DMA_PeripheralInc_Disable

//-- DMA_MemoryInc --
//-- DMA_peripheral_incremented_mode --
//   DMA_MemoryInc_Enable
//   DMA_MemoryInc_Disable

//-- DMA_PeripheralDataSize --
//-- DMA_peripheral_data_size --
//  DMA_PeripheralDataSize_Byte
//  DMA_PeripheralDataSize_HalfWord
//  DMA_PeripheralDataSize_Word

//-- DMA_MemoryDataSize --
//-- DMA_memory_data_size --
//   DMA_MemoryDataSize_Byte
//   DMA_MemoryDataSize_HalfWord
//   DMA_MemoryDataSize_Word

//-- DMA_Mode --
//-- DMA_circular_normal_mode --
//   DMA_Mode_Normal
//   DMA_Mode_Circular

//-- DMA_Priority --
//-- DMA_priority_level --
//   DMA_Priority_Low
//   DMA_Priority_Medium
//   DMA_Priority_High
//   DMA_Priority_VeryHigh

//-- DMA_FIFOMode --
//-- DMA_fifo_direct_mode --
//   DMA_FIFOMode_Disable
//   DMA_FIFOMode_Enable

//-- DMA_FIFOThreshold --
//-- DMA_fifo_threshold_level --
//   DMA_FIFOThreshold_1QuarterFull
//   DMA_FIFOThreshold_HalfFull
//   DMA_FIFOThreshold_Full

//-- DMA_MemoryBurst --
//-- DMA_memory_burst --
//   DMA_MemoryBurst_Single
//   DMA_MemoryBurst_INC4
//   DMA_MemoryBurst_INC8
//   DMA_MemoryBurst_INC16

//-- DMA_PeripheralBurst --
//-- DMA_peripheral_burst --
//   DMA_PeripheralBurst_Single
//   DMA_PeripheralBurst_INC4
//   DMA_PeripheralBurst_INC8
//   DMA_PeripheralBurst_INC16

//*****************************************************************
//-- DMA All Peripherals
//   DMA1_Stream0
//   DMA1_Stream1
//   DMA1_Stream2
//   DMA1_Stream3
//   DMA1_Stream4
//   DMA1_Stream5
//   DMA1_Stream6
//   DMA1_Stream7
//   DMA2_Stream0
//   DMA2_Stream1
//   DMA2_Stream2
//   DMA2_Stream3
//   DMA2_Stream4
//   DMA2_Stream5
//   DMA2_Stream6
//   DMA2_Stream7

//-- DMA All Controllers --
//   DMA1
//   DMA2

//-- DMA Stream TypeDef --

//-- DMA_FIFOStatus --
//-- DMA_fifo_status_level --
//   DMA_FIFOStatus_Less1QuarterFull
//   DMA_FIFOStatus_1QuarterFull
//   DMA_FIFOStatus_HalfFull
//   DMA_FIFOStatus_3QuartersFull
//   DMA_FIFOStatus_Empty
//   DMA_FIFOStatus_Full

//-- DMA_Flag --
//-- DMA_flag_definitions --
//   DMA_FLAG_FEIF0  ((uint32_t)0x10800001)
//   DMA_FLAG_DMEIF0 ((uint32_t)0x10800004)
//   DMA_FLAG_TEIF0  ((uint32_t)0x10000008)
//   DMA_FLAG_HTIF0  ((uint32_t)0x10000010)
//   DMA_FLAG_TCIF0  ((uint32_t)0x10000020)
//   DMA_FLAG_FEIF1  ((uint32_t)0x10000040)
//   DMA_FLAG_DMEIF1 ((uint32_t)0x10000100)
//   DMA_FLAG_TEIF1  ((uint32_t)0x10000200)
//   DMA_FLAG_HTIF1  ((uint32_t)0x10000400)
//   DMA_FLAG_TCIF1  ((uint32_t)0x10000800)
//   DMA_FLAG_FEIF2  ((uint32_t)0x10010000)
//   DMA_FLAG_DMEIF2 ((uint32_t)0x10040000)
//   DMA_FLAG_TEIF2  ((uint32_t)0x10080000)
//   DMA_FLAG_HTIF2  ((uint32_t)0x10100000)
//   DMA_FLAG_TCIF2  ((uint32_t)0x10200000)
//   DMA_FLAG_FEIF3  ((uint32_t)0x10400000)
//   DMA_FLAG_DMEIF3 ((uint32_t)0x11000000)
//   DMA_FLAG_TEIF3  ((uint32_t)0x12000000)
//   DMA_FLAG_HTIF3  ((uint32_t)0x14000000)
//   DMA_FLAG_TCIF3  ((uint32_t)0x18000000)
//   DMA_FLAG_FEIF4  ((uint32_t)0x20000001)
//   DMA_FLAG_DMEIF4 ((uint32_t)0x20000004)
//   DMA_FLAG_TEIF4  ((uint32_t)0x20000008)
//   DMA_FLAG_HTIF4  ((uint32_t)0x20000010)
//   DMA_FLAG_TCIF4  ((uint32_t)0x20000020)
//   DMA_FLAG_FEIF5  ((uint32_t)0x20000040)
//   DMA_FLAG_DMEIF5 ((uint32_t)0x20000100)
//   DMA_FLAG_TEIF5  (uint32_t)0x20000200)
//   DMA_FLAG_HTIF5  ((uint32_t)0x20000400)
//   DMA_FLAG_TCIF5  ((uint32_t)0x20000800)
//   DMA_FLAG_FEIF6  ((uint32_t)0x20010000)
//   DMA_FLAG_DMEIF6 ((uint32_t)0x20040000)
//   DMA_FLAG_TEIF6  ((uint32_t)0x20080000)
//   DMA_FLAG_HTIF6  ((uint32_t)0x20100000)
//   DMA_FLAG_TCIF6  ((uint32_t)0x20200000)
//   DMA_FLAG_FEIF7  ((uint32_t)0x20400000)
//   DMA_FLAG_DMEIF7 ((uint32_t)0x21000000)
//   DMA_FLAG_TEIF7  ((uint32_t)0x22000000)
//   DMA_FLAG_HTIF7  ((uint32_t)0x24000000)
//   DMA_FLAG_TCIF7  ((uint32_t)0x28000000)

//-- DMA_IT Enable --
//-- DMA_interrupt_enable_definitions --
//   DMA_IT_TC
//   DMA_IT_HT
//   DMA_IT_TE
//   DMA_IT_DME
//   DMA_IT_FE

//-- DMA_IT --
//-- DMA_interrupts_definitions --
//   DMA_IT_FEIF0
//   DMA_IT_DMEIF0
//   DMA_IT_TEIF0
//   DMA_IT_HTIF0
//   DMA_IT_TCIF0
//   DMA_IT_FEIF1
//   DMA_IT_DMEIF1
//   DMA_IT_TEIF1
//   DMA_IT_HTIF1
//   DMA_IT_TCIF1
//   DMA_IT_FEIF2
//   DMA_IT_DMEIF2
//   DMA_IT_TEIF2
//   DMA_IT_HTIF2
//   DMA_IT_TCIF2
//   DMA_IT_FEIF3
//   DMA_IT_DMEIF3
//   DMA_IT_TEIF3
//   DMA_IT_HTIF3
//   DMA_IT_TCIF3
//   DMA_IT_FEIF4
//   DMA_IT_DMEIF4
//   DMA_IT_TEIF4
//   DMA_IT_HTIF4
//   DMA_IT_TCIF4
//   DMA_IT_FEIF5
//   DMA_IT_DMEIF5
//   DMA_IT_TEIF5
//   DMA_IT_HTIF5
//   DMA_IT_TCIF5
//   DMA_IT_FEIF6
//   DMA_IT_DMEIF6
//   DMA_IT_TEIF6
//   DMA_IT_HTIF6
//   DMA_IT_TCIF6
//   DMA_IT_FEIF7
//   DMA_IT_DMEIF7
//   DMA_IT_TEIF7
//   DMA_IT_HTIF7
//   DMA_IT_TCIF7

//-- DMA_PINCOS_Psize --
//-- DMA_peripheral_increment_offset
//   DMA_PINCOS_Psize
//   DMA_PINCOS_WordAligned

//-- DMA_FlowCtrl --
//-- DMA_flow_controller_definitions
//   DMA_FlowCtrl_Memory
//   DMA_FlowCtrl_Peripheral

//-- DMA_Memory --
//-- DMA_flow_controller_definitions
//   DMA_Memory_0
//   DMA_Memory_1

#endif
