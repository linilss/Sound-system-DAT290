/*
   ADC.h
*/

#ifndef ADC_H
#define ADC_H

#include "stm32f4xx_adc.h"

void initCommon_ADC(uint32_t ADC_Mode,
                    uint32_t ADC_Prescaler,
                    uint32_t ADC_DMAAccessMode,
                    uint32_t ADC_TwoSamplingDelay);

void init_ADC(uint32_t ADC_Resolution,
              FunctionalState ADC_ScanConvMode,
              FunctionalState ADC_ContinuousConvMode,
              uint32_t ADC_ExternalTrigConvEdge,
              uint32_t ADC_ExternalTrigConv,
              uint32_t ADC_DataAlign,
              uint32_t ADC_NbrOfConversion);

//** initCommon_ADC **
//-- ADC_Mode --
//   ADC_Mode_Independent
//   ADC_DualMode_RegSimult_InjecSimult
//   ADC_DualMode_RegSimult_AlterTrig
//   ADC_DualMode_InjecSimult
//   ADC_DualMode_RegSimult
//   ADC_DualMode_Interl
//   ADC_DualMode_AlterTrig
//   ADC_TripleMode_RegSimult_InjecSimult
//   ADC_TripleMode_RegSimult_AlterTrig
//   ADC_TripleMode_InjecSimult
//   ADC_TripleMode_RegSimult
//   ADC_TripleMode_Interl
//   ADC_TripleMode_AlterTrig

//-- ADC_prescaler --
//   ADC_Prescaler_Div2
//   ADC_Prescaler_Div4
//   ADC_Prescaler_Div6
//   ADC_Prescaler_Div8

//-- ADC_DMAAccessMode --
//   ADC_DMAAccessMode_Disabled - DMA mode disabled
//   ADC_DMAAccessMode_1 - DMA mode 1 enabled (2 / 3 half-words one by one - 1 then 2 then 3)
//   ADC_DMAAccessMode_2 - DMA mode 2 enabled (2 / 3 half-words by pairs - 2&1 then 1&3 then 3&2)
//   ADC_DMAAccessMode_3

//-- ADC_TwoSamplingDelay --
//   ADC_TwoSamplingDelay_5Cycles
//   ADC_TwoSamplingDelay_6Cycles
//   ADC_TwoSamplingDelay_7Cycles
//   ADC_TwoSamplingDelay_8Cycles
//   ADC_TwoSamplingDelay_9Cycles
//   ADC_TwoSamplingDelay_10Cycles
//   ADC_TwoSamplingDelay_11Cycles
//   ADC_TwoSamplingDelay_12Cycles
//   ADC_TwoSamplingDelay_13Cycles
//   ADC_TwoSamplingDelay_14Cycles
//   ADC_TwoSamplingDelay_15Cycles
//   ADC_TwoSamplingDelay_16Cycles
//   ADC_TwoSamplingDelay_17Cycles
//   ADC_TwoSamplingDelay_18Cycles
//   ADC_TwoSamplingDelay_19Cycles
//   ADC_TwoSamplingDelay_20Cycles

//** Init_ADC **
//-- ADC_Resolution --
//   ADC_Resolution_12b
//   ADC_Resolution_10b
//   ADC_Resolution_8b
//   ADC_Resolution_6b

//-- ADC_ScanConvMode --
//   ENABLE
//   DISABLE

//-- ADC_ContinuousConvMode --
//   ENABLE
//   DISABLE

//-- ADC_ExternalTrigConvEdge --
//   ADC_ExternalTrigConvEdge_None
//   ADC_ExternalTrigConvEdge_Rising
//   ADC_ExternalTrigConvEdge_Falling
//   ADC_ExternalTrigConvEdge_RisingFalling

//-- ADC_external_trigger_sources_for_regular_channels_conversion --
//   ADC_ExternalTrigConv_T1_CC1
//   ADC_ExternalTrigConv_T1_CC2
//   ADC_ExternalTrigConv_T1_CC3
//   ADC_ExternalTrigConv_T2_CC2
//   ADC_ExternalTrigConv_T2_CC3
//   ADC_ExternalTrigConv_T2_CC4
//   ADC_ExternalTrigConv_T2_TRGO
//   ADC_ExternalTrigConv_T3_CC1
//   ADC_ExternalTrigConv_T3_TRGO
//   ADC_ExternalTrigConv_T4_CC4
//   ADC_ExternalTrigConv_T5_CC1
//   ADC_ExternalTrigConv_T5_CC2
//   ADC_ExternalTrigConv_T5_CC3
//   ADC_ExternalTrigConv_T8_CC1
//   ADC_ExternalTrigConv_T8_TRGO
//   ADC_ExternalTrigConv_Ext_IT11

//-- ADC_DataAlign --
//   ADC_DataAlign_Right
//   ADC_DataAlign_Left

//-- ADC_NbrOfConversion --
//   1 - 16

//*****************************************************************
//** Definitions for other functions **
//-- ADCx --
//   ADC1
//   ADC2
//   ADC3

//-- ADC Channels --
//   ADC_Channel_0
//   ADC_Channel_1
//   ADC_Channel_2
//   ADC_Channel_3
//   ADC_Channel_4
//   ADC_Channel_5
//   ADC_Channel_6
//   ADC_Channel_7
//   ADC_Channel_8
//   ADC_Channel_9
//   ADC_Channel_10
//   ADC_Channel_11
//   ADC_Channel_12
//   ADC_Channel_13
//   ADC_Channel_14
//   ADC_Channel_15
//   ADC_Channel_16
//   ADC_Channel_17
//   ADC_Channel_18
//   ADC_Channel_TempSensor
//   ADC_Channel_Vrefint = ADC_Channel_17
//   ADC_Channel_Vbat = ADC_Channel_18

//-- ADC_sampling_times --
//   ADC_SampleTime_3Cycles
//   ADC_SampleTime_15Cycles
//   ADC_SampleTime_28Cycles
//   ADC_SampleTime_56Cycles
//   ADC_SampleTime_84Cycles
//   ADC_SampleTime_112Cycles
//   ADC_SampleTime_144Cycles
//   ADC_SampleTime_480Cycles

//-- ADC_external_trigger_edge_for_injected_channels_conversion --
//   ADC_ExternalTrigInjecConvEdge_None
//   ADC_ExternalTrigInjecConvEdge_Rising
//   ADC_ExternalTrigInjecConvEdge_Falling
//   ADC_ExternalTrigInjecConvEdge_RisingFalling

//-- ADC_extrenal_trigger_sources_for_injected_channels_conversion --
//   ADC_ExternalTrigInjecConv_T1_CC4
//   ADC_ExternalTrigInjecConv_T1_TRGO
//   ADC_ExternalTrigInjecConv_T2_CC1
//   ADC_ExternalTrigInjecConv_T2_TRGO
//   ADC_ExternalTrigInjecConv_T3_CC2
//   ADC_ExternalTrigInjecConv_T3_CC4
//   ADC_ExternalTrigInjecConv_T4_CC1
//   ADC_ExternalTrigInjecConv_T4_CC2
//   ADC_ExternalTrigInjecConv_T4_CC3
//   ADC_ExternalTrigInjecConv_T4_TRGO
//   ADC_ExternalTrigInjecConv_T5_CC4
//   ADC_ExternalTrigInjecConv_T5_TRGO
//   ADC_ExternalTrigInjecConv_T8_CC2
//   ADC_ExternalTrigInjecConv_T8_CC3
//   ADC_ExternalTrigInjecConv_T8_CC4
//   ADC_ExternalTrigInjecConv_Ext_IT15

//-- ADC_injected_channel_selection --
//   ADC_InjectedChannel_1
//   ADC_InjectedChannel_2
//   ADC_InjectedChannel_3
//   ADC_InjectedChannel_4

//-- ADC_analog_watchdog_selection --
//   ADC_AnalogWatchdog_SingleRegEnable
//   ADC_AnalogWatchdog_SingleInjecEnable
//   ADC_AnalogWatchdog_SingleRegOrInjecEnable)
//   ADC_AnalogWatchdog_AllRegEnable
//   ADC_AnalogWatchdog_AllInjecEnable
//   ADC_AnalogWatchdog_AllRegAllInjecEnable
//   ADC_AnalogWatchdog_None

//-- ADC_interrupts_definition --
//   ADC_IT_EOC
//   ADC_IT_AWD
//   ADC_IT_JEOC
//   ADC_IT_OVR

//-- ADC_flags_definition --
//   ADC_FLAG_AWD
//   ADC_FLAG_EOC
//   ADC_FLAG_JEOC
//   ADC_FLAG_JSTRT
//   ADC_FLAG_STRT
//   ADC_FLAG_OVR

//-- ADC_thresholds --
//   0x000 - 0xFFF

//-- ADC_injected_offset --
//   0x000 - 0xFFF

//-- ADC_injected_length --
//   0x1 - 0x4

//-- ADC_injected_rank --
//   0x1 - 0x4

//-- ADC_regular_length --
//   0x01 - 0x10

//-- ADC_regular_discontinuous_mode_number --
//   0x1 - 0x8

#endif
