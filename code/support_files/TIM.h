/*
   TIM.h
*/

#ifndef TIM_H
#define TIM_H

#include "stm32f4xx_tim.h"

#define TIM_OCChannel_1 1
#define TIM_OCChannel_2 2
#define TIM_OCChannel_3 3
#define TIM_OCChannel_4 4

#define TIM_ICCompare_1 1
#define TIM_ICCompare_2 2
#define TIM_ICCompare_3 3
#define TIM_ICCompare_4 4

void init_TIM_TimeBase(TIM_TypeDef* TIMx,
                       uint16_t TIM_Prescaler,
                       uint16_t TIM_CounterMode,
                       uint32_t TIM_Period,
                       uint16_t TIM_ClockDivision,
                       uint8_t TIM_RepetitionCounter);

void init_TIM_OC(TIM_TypeDef* TIMx,
                 uint16_t TIM_OCChannel,
                 uint16_t TIM_OCMode,
                 uint16_t TIM_OutputState,
                 uint16_t TIM_OutputNState,
                 uint32_t TIM_Pulse,
                 uint16_t TIM_OCPolarity,
                 uint16_t TIM_OCNPolarity,
                 uint16_t TIM_OCIdleState,
                 uint16_t TIM_OCNIdleState);

void init_TIM_IC(TIM_TypeDef* TIMx,
                 uint16_t TIM_Channel,
                 uint16_t TIM_ICPolarity,
                 uint16_t TIM_ICSelection,
                 uint16_t TIM_ICPrescaler,
                 uint16_t TIM_ICFilter);

void init_TIM_BDTR(TIM_TypeDef* TIMx,
                   uint16_t TIM_OSSRState,
                   uint16_t TIM_OSSIState,
                   uint16_t TIM_LOCKLevel,
                   uint16_t TIM_DeadTime,
                   uint16_t TIM_Break,
                   uint16_t TIM_BreakPolarity,
                   uint16_t TIM_AutomaticOutput);

void TIM_OCPolarity_Config(TIM_TypeDef* TIMx,
                           uint8_t TIM_OCChannel,
                           uint8_t TIM_OCPolarityType,
                           uint16_t TIM_OCPolarity);

void config_TIM_OCPreload(TIM_TypeDef* TIMx,
                          uint8_t TIM_OCChannel,
                          uint16_t TIM_OCPreload);

void config_TIM_OCFast(TIM_TypeDef* TIMx,
                       uint8_t TIM_OCChannel,
                       uint16_t TIM_OCFast);

void config_TIM_ForcedOC(TIM_TypeDef* TIMx,
                         uint8_t TIM_OCChannel,
                         uint16_t TIM_ForcedAction);

void clear_TIM_OCRef(TIM_TypeDef* TIMx,
                     uint8_t TIM_OCChannel,
                     uint16_t TIM_OCClear);

void config_TIM_OCPolarity(TIM_TypeDef* TIMx,
                           uint8_t TIM_OCChannel,
                           uint16_t TIM_OCPolarity);

void compare_TIM_ICSet(TIM_TypeDef* TIMx,
                       uint8_t TIM_ICCompare_x,
                       uint32_t TIM_ICCompare_value);

//** init_TIM_TimeBase **
//-- TIMx --
//   TIM1
//   TIM2
//   TIM3
//   TIM4
//   TIM5
//   TIM6
//   TIM7
//   TIM8
//   TIM9
//   TIM10
//   TIM11
//   TIM12
//   TIM13
//   TIM14

//-- TIM_Prescaler --
//   0x0000 - 0xFFFF

//-- TIM_CounterMode --
//   TIM_CounterMode_Up
//   TIM_CounterMode_Down
//   TIM_CounterMode_CenterAligned1 - OC IRQ flags are only set
//                                    when counting down
//   TIM_CounterMode_CenterAligned2 - OC IRQ flags are only set
//                                    when counting up
//   TIM_CounterMode_CenterAligned3 - OC IRQ flags are set both
//                                    when counting up and down

//-- TIM_Period --
//   0x0000 - 0xFFFF

//-- TIM_ClockDivision --
//-- TIM_Clock_Division_CKD --
//   TIM_CKD_DIV1
//   TIM_CKD_DIV2
//   TIM_CKD_DIV4

//-- TIM_RepetitionCounter --
// 0x00 - 0xFF - only valid for TIM1 and TIM8

//** init_TIM_OC
//-- TIMx --
//   TIM1
//   TIM2
//   TIM3
//   TIM4
//   TIM5
//   TIM6
//   TIM7
//   TIM8
//   TIM9
//   TIM10
//   TIM11
//   TIM12
//   TIM13
//   TIM14

//-- TIM_OCChannel --
//   TIM_OCChannel_1
//   TIM_OCChannel_2
//   TIM_OCChannel_3
//   TIM_OCChannel_4

//-- TIM_OCMode --
//-- TIM_Output_Compare_and_PWM_modes --
//   TIM_OCMode_Timing - no output
//   TIM_OCMode_Active - high on OC match
//   TIM_OCMode_Inactive - low on OC match
//   TIM_OCMode_Toggle - toggle on OC match
//   TIM_OCMode_PWM1 - if upcounting - start high
//                     if downcounting - start low
//   TIM_OCMode_PWM2 - if upcounting - start low
//                     if downcounting - start high

//-- TIM_OutputState --
//-- TIM_Output_Compare_State --
//   TIM_OutputState_Disable - output disabled
//   TIM_OutputState_Enable - output enabled

//-- TIM_OutputNState --
//-- TIM_Output_Compare_N_State --
//   TIM_OutputNState_Disable - output disabled
//   TIM_OutputNState_Enable - output enabled

//-- TIM_Pulse --
//   0x0000 - 0xFFFF

//-- TIM_OCPolarity --
//-- TIM_Output_Compare_Polarity --
//   TIM_OCPolarity_High - output active high
//   TIM_OCPolarity_Low - output active low

//-- TIM_OCNPolarity --
//-- TIM_Output_Compare_N_Polarity --
//   TIM_OCNPolarity_High - output active high
//   TIM_OCNPolarity_Low - output active low

//-- TIM_OCIdleState --
//-- TIM_Output_Compare_Idle_State --
//   TIM_OCIdleState_Set - output high when idle
//   TIM_OCIdleState_Reset - output low when idle

//-- TIM_OCNIdleState --
//-- TIM_Output_Compare_N_Idle_State --
//   TIM_OCNIdleState_Set - output high when idle
//   TIM_OCNIdleState_Reset - output low when idle

//**init_TIM_IC **
//-- TIMx --
//   TIM1
//   TIM2
//   TIM3
//   TIM4
//   TIM5
//   TIM6
//   TIM7
//   TIM8
//   TIM9
//   TIM10
//   TIM11
//   TIM12
//   TIM13
//   TIM14

//-- TIM_Channel --
//   TIM_Channel_1
//   TIM_Channel_2
//   TIM_Channel_3
//   TIM_Channel_4

//-- TIM_ICPolarity --
//-- TIM_Input_Capture_Polarity --
//   TIM_ICPolarity_Rising
//   TIM_ICPolarity_Falling
//   TIM_ICPolarity_BothEdge

//-- TIM_ICSelection --
//-- TIM_Input_Capture_Selection --
//   TIM_ICSelection_DirectTI - TIM Input 1, 2, 3 or 4 is selected to be
//                              connected to IC1, IC2, IC3 or IC4,
//                              respectively
//   TIM_ICSelection_IndirectTI - TIM Input 1, 2, 3 or 4 is selected to be
//                                connected to IC2, IC1, IC4 or IC3,
//                                respectively
//   TIM_ICSelection_TRC - TIM Input 1, 2, 3 or 4 is selected to be
//                         connected to TRC


//-- TIM_ICPrescaler --
//-- TIM_Input_Capture_Prescaler --
//   TIM_ICPSC_DIV1 - Capture performed each time an edge is detected
//                    on the capture input
//   TIM_ICPSC_DIV2 - Capture performed once every 2 events
//   TIM_ICPSC_DIV4 - Capture performed once every 4 events
//   TIM_ICPSC_DIV8 - Capture performed once every 8 events

//-- TIM_ICFilter --
//   0x0 - 0xF

//** init_TIM_BDTR **
//-- TIMx --
//   TIM1
//   TIM2
//   TIM3
//   TIM4
//   TIM5
//   TIM6
//   TIM7
//   TIM8
//   TIM9
//   TIM10
//   TIM11
//   TIM12
//   TIM13
//   TIM14

//-- TIM_OSSRState --
//-- TIM_OSSR_Off_State_Selection_for_Run_mode_state --
//   TIM_OSSRState_Enable
//   TIM_OSSRState_Disable

//-- TIM_OSSIState --
//-- TIM_OSSI_Off_State_Selection_for_Idle_mode_state --
//   TIM_OSSIState_Enable
//   TIM_OSSIState_Disable

//-- TIM_LOCKLevel --
//   TIM_LOCKLevel_OFF
//   TIM_LOCKLevel_1
//   TIM_LOCKLevel_2
//   TIM_LOCKLevel_3

//-- TIM_DeadTime --
//   0x00 - 0xFF

//-- TIM_Break --
//-- TIM_Break_Input_enable_disable --
//   TIM_Break_Enable
//   TIM_Break_Disable

//-- TIM_BreakPolarity --
//   TIM_BreakPolarity_Low
//   TIM_BreakPolarity_High

//-- TIM_AutomaticOutput --
//-- TIM_AOE_Bit_Set_Reset --
//   TIM_AutomaticOutput_Enable
//   TIM_AutomaticOutput_Disable

//** config_TIM_OCPreload **
//-- TIMx --
//   TIM1
//   TIM2
//   TIM3
//   TIM4
//   TIM5
//   TIM6
//   TIM7
//   TIM8
//   TIM9
//   TIM10
//   TIM11
//   TIM12
//   TIM13
//   TIM14

//-- TIM_OCChannel --
//   TIM_OCChannel_1
//   TIM_OCChannel_2
//   TIM_OCChannel_3
//   TIM_OCChannel_4

//-- TIM_OCPreload --
//-- TIM_Output_Compare_Preload_State --
//   TIM_OCPreload_Enable
//   TIM_OCPreload_Disable

//** TIM_OCPreloadConfig **
//-- TIM_OCPreload --

//** TIM_OCFastConfig **
//-- TIM_OCFast --
//-- TIM_Output_Compare_Fast_State --
//   TIM_OCFast_Enable
//   TIM_OCFast_Disable

//** TIM_ForcedOCConfig **
//-- TIM_ForcedAction --
//-- TIM_Forced_Action --
//   TIM_ForcedAction_Active
//   TIM_ForcedAction_InActive

//** TIM_ClearOCRef **
//-- TIM_OCClear --
//-- TIM_Output_Compare_Clear_State --
//   TIM_OCClear_Enable
//   TIM_OCClear_Disable

//** set_TIM_ICCompare_value **
//-- TIM_ICCompare_x
//   TIM_ICCompare_1
//   TIM_ICCompare_2
//   TIM_ICCompare_3
//   TIM_ICCompare_4

//-- TIM_ICCompare_value --
//!!   16 bit counter !!
//   0x0000 - 0xFFFF
//!! 32 bit counter !!
//   0x00000000 - 0xFFFFFFFF


//*****************************************************************
//** Definitions for other functions **
//-- TIM_One_Pulse_Mode --
//   TIM_OPMode_Single
//   TIM_OPMode_Repetitive

//-- TIM_Capture_Compare_State --
//   TIM_CCx_Enable
//   TIM_CCx_Disable

//-- TIM_Capture_Compare_N_State --
//   TIM_CCxN_Enable
//   TIM_CCxN_Disable

//-- TIM_interrupt_sources --
//   TIM_IT_Update
//   TIM_IT_CC1
//   TIM_IT_CC2
//   TIM_IT_CC3
//   TIM_IT_CC4
//   TIM_IT_COM
//   TIM_IT_Trigger
//   TIM_IT_Break

//-- TIM_DMA_Base_address --
//   TIM_DMABase_CR1
//   TIM_DMABase_CR2
//   TIM_DMABase_SMCR
//   TIM_DMABase_DIER
//   TIM_DMABase_SR
//   TIM_DMABase_EGR)
//   TIM_DMABase_CCMR1
//   TIM_DMABase_CCMR2
//   TIM_DMABase_CCER
//   TIM_DMABase_CNT
//   TIM_DMABase_PSC
//   TIM_DMABase_ARR
//   TIM_DMABase_RCR
//   TIM_DMABase_CCR1
//   TIM_DMABase_CCR2
//   TIM_DMABase_CCR3
//   TIM_DMABase_CCR4
//   TIM_DMABase_BDTR
//   TIM_DMABase_DCR
//   TIM_DMABase_OR

//-- TIM_DMA_Burst_Length --
//   TIM_DMABurstLength_1Transfer
//   TIM_DMABurstLength_2Transfers
//   TIM_DMABurstLength_3Transfers
//   TIM_DMABurstLength_4Transfers
//   TIM_DMABurstLength_5Transfers
//   TIM_DMABurstLength_6Transfers
//   TIM_DMABurstLength_7Transfers
//   TIM_DMABurstLength_8Transfers
//   TIM_DMABurstLength_9Transfers
//   TIM_DMABurstLength_10Transfers
//   TIM_DMABurstLength_11Transfers
//   TIM_DMABurstLength_12Transfers
//   TIM_DMABurstLength_13Transfers
//   TIM_DMABurstLength_14Transfers
//   TIM_DMABurstLength_15Transfers
//   TIM_DMABurstLength_16Transfers
//   TIM_DMABurstLength_17Transfers
//   TIM_DMABurstLength_18Transfers

//-- TIM_DMA_sources --
//   TIM_DMA_Update
//   TIM_DMA_CC1
//   TIM_DMA_CC2
//   TIM_DMA_CC3
//   TIM_DMA_CC4
//   TIM_DMA_COM
//   TIM_DMA_Trigger

//-- TIM_External_Trigger_Prescaler --
//   TIM_ExtTRGPSC_OFF
//   TIM_ExtTRGPSC_DIV2
//   TIM_ExtTRGPSC_DIV4
//   TIM_ExtTRGPSC_DIV8

//-- TIM_Internal_Trigger_Selection --
//   TIM_TS_ITR0
//   TIM_TS_ITR1
//   TIM_TS_ITR2
//   TIM_TS_ITR3
//   TIM_TS_TI1F_ED
//   TIM_TS_TI1FP1
//   TIM_TS_TI2FP2
//   TIM_TS_ETRF

//-- TIM_TIx_External_Clock_Source --
//   TIM_TIxExternalCLK1Source_TI1
//   TIM_TIxExternalCLK1Source_TI2
//   TIM_TIxExternalCLK1Source_TI1ED

//-- TIM_External_Trigger_Polarity --
//   TIM_ExtTRGPolarity_Inverted
//   TIM_ExtTRGPolarity_NonInverted

//-- TIM_Prescaler_Reload_Mode --
//   TIM_PSCReloadMode_Update
//   TIM_PSCReloadMode_Immediate

//-- TIM_Encoder_Mode --
//   TIM_EncoderMode_TI1
//   TIM_EncoderMode_TI2
//   TIM_EncoderMode_TI12

//-- TIM_Event_Source --
//   TIM_EventSource_Update
//   TIM_EventSource_CC1
//   TIM_EventSource_CC2
//   TIM_EventSource_CC3
//   TIM_EventSource_CC4
//   TIM_EventSource_COM
//   TIM_EventSource_Trigger
//   TIM_EventSource_Break

//-- TIM_Update_Source --
//   TIM_UpdateSource_Global - Source of update is the counter
//                             overflow/underflow or the setting of UG bit,
//                             or an update generation through the slave mode
//                             controller
//   TIM_UpdateSource_Regular - Source of update is counter overflow/underflow

//-- TIM_Trigger_Output_Source --
//   TIM_TRGOSource_Reset
//   TIM_TRGOSource_Enable
//   TIM_TRGOSource_Update
//   TIM_TRGOSource_OC1
//   TIM_TRGOSource_OC1Ref
//   TIM_TRGOSource_OC2Ref
//   TIM_TRGOSource_OC3Ref
//   TIM_TRGOSource_OC4Ref

//-- TIM_Slave_Mode --
//   TIM_SlaveMode_Reset
//   TIM_SlaveMode_Gated
//   TIM_SlaveMode_Trigger
//   TIM_SlaveMode_External1

//-- TIM_Master_Slave_Mode --
//   TIM_MasterSlaveMode_Enable
//   TIM_MasterSlaveMode_Disable

//-- TIM_Remap --
//   TIM2_TIM8_TRGO
//   TIM2_ETH_PTP
//   TIM2_USBFS_SOF
//   TIM2_USBHS_SOF
//   TIM5_GPIO
//   TIM5_LSI
//   TIM5_LSE
//   TIM5_RTC
//   TIM11_GPIO
//   TIM11_HSE

//-- TIM_Flags --
//   TIM_FLAG_Update
//   TIM_FLAG_CC1
//   TIM_FLAG_CC2
//   TIM_FLAG_CC3
//   TIM_FLAG_CC4
//   TIM_FLAG_COM
//   TIM_FLAG_Trigger
//   TIM_FLAG_Break
//   TIM_FLAG_CC1OF
//   TIM_FLAG_CC2OF
//   TIM_FLAG_CC3OF
//   TIM_FLAG_CC4OF

//-- TIM_Input_Capture_Filter_Value --
//   0x0 - 0xF (0 - 15)

//-- TIM_External_Trigger_Filter --
//   0x0 - 0xF (0 - 15)

//-- TIM_Legacy --
//   TIM_DMABurstLength_1Byte   = TIM_DMABurstLength_1Transfer
//   TIM_DMABurstLength_2Bytes  = TIM_DMABurstLength_2Transfers
//   TIM_DMABurstLength_3Bytes  = TIM_DMABurstLength_3Transfers
//   TIM_DMABurstLength_4Bytes  = TIM_DMABurstLength_4Transfers
//   TIM_DMABurstLength_5Bytes  = TIM_DMABurstLength_5Transfers
//   TIM_DMABurstLength_6Bytes  = TIM_DMABurstLength_6Transfers
//   TIM_DMABurstLength_7Bytes  = TIM_DMABurstLength_7Transfers
//   TIM_DMABurstLength_8Bytes  = TIM_DMABurstLength_8Transfers
//   TIM_DMABurstLength_9Bytes  = TIM_DMABurstLength_9Transfers
//   TIM_DMABurstLength_10Bytes = TIM_DMABurstLength_10Transfers
//   TIM_DMABurstLength_11Bytes = TIM_DMABurstLength_11Transfers
//   TIM_DMABurstLength_12Bytes = TIM_DMABurstLength_12Transfers
//   TIM_DMABurstLength_13Bytes = TIM_DMABurstLength_13Transfers
//   TIM_DMABurstLength_14Bytes = TIM_DMABurstLength_14Transfers
//   TIM_DMABurstLength_15Bytes = TIM_DMABurstLength_15Transfers
//   TIM_DMABurstLength_16Bytes = TIM_DMABurstLength_16Transfers
//   TIM_DMABurstLength_17Bytes = TIM_DMABurstLength_17Transfers
//   TIM_DMABurstLength_18Bytes = TIM_DMABurstLength_18Transfers

#endif