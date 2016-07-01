/*
   DAC.h
*/

#ifndef DAC_H
#define DAC_H

#include "stm32f4xx_dac.h"

void init_DAC(uint32_t DAC_Channel,
              uint32_t DAC_Trigger,
              uint32_t DAC_WaveGeneration,
              uint32_t DAC_LFSRUnmask_TriangleAmplitude,
              uint32_t DAC_OutputBuffer);

void DAC_SetChannelData(uint32_t DAC_Channel,
                        uint32_t DAC_Align,
                        uint16_t DAC_Data);

//**init_DAC **
//-- DAC_Channel --
//   DAC_Channel_1
//   DAC_Channel_2

//-- DAC_Trigger --
//   DAC_Trigger_None - Conversion is automatic once the DAC1_DHRxxxx register
//                      has been loaded, and not by external trigger
//   DAC_Trigger_T2_TRGO - TIM2 TRGO selected as external conversion trigger for DAC channel
//   DAC_Trigger_T4_TRGO - TIM4 TRGO selected as external conversion trigger for DAC channel
//   DAC_Trigger_T5_TRGO - TIM5 TRGO selected as external conversion trigger for DAC channel
//   DAC_Trigger_T6_TRGO - TIM6 TRGO selected as external conversion trigger for DAC channel
//   DAC_Trigger_T7_TRGO - TIM7 TRGO selected as external conversion trigger for DAC channel
//   DAC_Trigger_T8_TRGO - TIM8 TRGO selected as external conversion trigger for DAC channel
//   DAC_Trigger_Ext_IT9 - EXTI Line9 event selected as external conversion trigger for DAC channel */
//   DAC_Trigger_Software - Conversion started by software trigger for DAC channel

//-- DAC_WaveGeneration --
//   DAC_WaveGeneration_None
//   DAC_WaveGeneration_Noise
//   DAC_WaveGeneration_Triangle

//-- DAC_LFSRUnmask_TriangleAmplitude --
//   DAC_LFSRUnmask_Bit0 - Unmask DAC channel LFSR bit0 for noise wave generation
//   DAC_LFSRUnmask_Bits1_0 - Unmask DAC channel LFSR bit[1:0] for noise wave generation
//   DAC_LFSRUnmask_Bits2_0 - Unmask DAC channel LFSR bit[2:0] for noise wave generation
//   DAC_LFSRUnmask_Bits3_0 - Unmask DAC channel LFSR bit[3:0] for noise wave generation
//   DAC_LFSRUnmask_Bits4_0 - Unmask DAC channel LFSR bit[4:0] for noise wave generation
//   DAC_LFSRUnmask_Bits5_0 - Unmask DAC channel LFSR bit[5:0] for noise wave generation
//   DAC_LFSRUnmask_Bits6_0 - Unmask DAC channel LFSR bit[6:0] for noise wave generation
//   DAC_LFSRUnmask_Bits7_0 - Unmask DAC channel LFSR bit[7:0] for noise wave generation
//   DAC_LFSRUnmask_Bits8_0 - Unmask DAC channel LFSR bit[8:0] for noise wave generation
//   DAC_LFSRUnmask_Bits9_0 - Unmask DAC channel LFSR bit[9:0] for noise wave generation
//   DAC_LFSRUnmask_Bits10_0 - Unmask DAC channel LFSR bit[10:0] for noise wave generation
//   DAC_LFSRUnmask_Bits11_0 - Unmask DAC channel LFSR bit[11:0] for noise wave generation
//   DAC_TriangleAmplitude_1 - Select max triangle amplitude of 1
//   DAC_TriangleAmplitude_3 - Select max triangle amplitude of 3
//   DAC_TriangleAmplitude_7 - Select max triangle amplitude of 7
//   DAC_TriangleAmplitude_15 - Select max triangle amplitude of 15
//   DAC_TriangleAmplitude_31 - Select max triangle amplitude of 31
//   DAC_TriangleAmplitude_63 - Select max triangle amplitude of 63
//   DAC_TriangleAmplitude_127 - Select max triangle amplitude of 127
//   DAC_TriangleAmplitude_255 - Select max triangle amplitude of 255
//   DAC_TriangleAmplitude_511 - Select max triangle amplitude of 511
//   DAC_TriangleAmplitude_1023 - Select max triangle amplitude of 1023
//   DAC_TriangleAmplitude_2047 - Select max triangle amplitude of 2047
//   DAC_TriangleAmplitude_4095 - Select max triangle amplitude of 4095

//-- DAC_OutputBuffer --
//   DAC_OutputBuffer_Enable
//   DAC_OutputBuffer_Disable

//** DAC_SetChannelData **
//-- DAC_Channel --
//   DAC_Channel_1
//   DAC_Channel_2

//-- DAC_Align --
//   DAC_Align_12b_R
//   DAC_Align_12b_L
//   DAC_Align_8b_R

//-- DAC_Data --
//   0 - 0xFFF0

//*****************************************************************
//** Definitions for other functions **
//-- DAC_wave_generation --
//   DAC_Wave_Noise
//   DAC_Wave_Triangle

//-- DAC_interrupts_definition --
//   DAC_IT_DMAUDR

//-- DAC_flags_definition --
//   DAC_FLAG_DMAUDR

#endif
