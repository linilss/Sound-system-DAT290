/*
   TIM.c
*/

#define assert_param(x)

#include "TIM.h"

//Init TIM_TimeBase

void init_TIM_TimeBase(TIM_TypeDef* TIMx,
                       uint16_t TIM_Prescaler,
                       uint16_t TIM_CounterMode,
                       uint32_t TIM_Period,
                       uint16_t TIM_ClockDivision,
                       uint8_t TIM_RepetitionCounter)
{
   TIM_TimeBaseInitTypeDef TIM_TimeBase_InitStructure; //setup TIM_TimeBase_InitStructure
   TIM_TimeBaseStructInit(&TIM_TimeBase_InitStructure);

   TIM_DeInit(TIMx);

   TIM_TimeBase_InitStructure.TIM_Prescaler = TIM_Prescaler;
   TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode;
   TIM_TimeBase_InitStructure.TIM_Period = TIM_Period;
   TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_ClockDivision;
   TIM_TimeBase_InitStructure.TIM_RepetitionCounter = TIM_RepetitionCounter;

   TIM_TimeBaseInit(TIMx, &TIM_TimeBase_InitStructure);
}

void init_TIM_OC(TIM_TypeDef* TIMx,
                 uint16_t TIM_OCChannel,
                 uint16_t TIM_OCMode,
                 uint16_t TIM_OutputState,
                 uint16_t TIM_OutputNState,
                 uint32_t TIM_Pulse,
                 uint16_t TIM_OCPolarity,
                 uint16_t TIM_OCNPolarity,
                 uint16_t TIM_OCIdleState,
                 uint16_t TIM_OCNIdleState)
{
   TIM_OCInitTypeDef TIM_OC_InitStructure; //setup TIM_OC_InitStructure
   TIM_OCStructInit(&TIM_OC_InitStructure);

   TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode;
   TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState;
   TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState;
   TIM_OC_InitStructure.TIM_Pulse = TIM_Pulse;
   TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity;
   TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity;
   TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState;
   TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState;

   switch(TIM_OCChannel)
   {
      case TIM_OCChannel_1:
         TIM_OC1Init(TIMx, &TIM_OC_InitStructure);
         break;
      case TIM_OCChannel_2:
         TIM_OC2Init(TIMx, &TIM_OC_InitStructure);
         break;
      case TIM_OCChannel_3:
         TIM_OC3Init(TIMx, &TIM_OC_InitStructure);
         break;
      case TIM_OCChannel_4:
         TIM_OC4Init(TIMx, &TIM_OC_InitStructure);
         break;
      default:
         break;
   }
}

void init_TIM_IC(TIM_TypeDef* TIMx,
                 uint16_t TIM_Channel,
                 uint16_t TIM_ICPolarity,
                 uint16_t TIM_ICSelection,
                 uint16_t TIM_ICPrescaler,
                 uint16_t TIM_ICFilter)
{
   TIM_ICInitTypeDef TIM_IC_InitStructure; //setup TIM_IC_InitStructure
   TIM_ICStructInit(&TIM_IC_InitStructure);

   TIM_IC_InitStructure.TIM_Channel = TIM_Channel;
   TIM_IC_InitStructure.TIM_ICPolarity = TIM_ICPolarity;
   TIM_IC_InitStructure.TIM_ICSelection = TIM_ICSelection;
   TIM_IC_InitStructure.TIM_ICPrescaler = TIM_ICPrescaler;
   TIM_IC_InitStructure.TIM_ICFilter = TIM_ICFilter;

   TIM_ICInit(TIMx,&TIM_IC_InitStructure);
}

void init_TIM_BDTR(TIM_TypeDef* TIMx,
                   uint16_t TIM_OSSRState,
                   uint16_t TIM_OSSIState,
                   uint16_t TIM_LOCKLevel,
                   uint16_t TIM_DeadTime,
                   uint16_t TIM_Break,
                   uint16_t TIM_BreakPolarity,
                   uint16_t TIM_AutomaticOutput)
{
   TIM_BDTRInitTypeDef TIM_BDTR_InitStructure; //setup TIM_BDTR_InitStructure
   TIM_BDTRStructInit(&TIM_BDTR_InitStructure);

   TIM_BDTR_InitStructure.TIM_OSSRState = TIM_OSSRState;
   TIM_BDTR_InitStructure.TIM_OSSIState = TIM_OSSIState;
   TIM_BDTR_InitStructure.TIM_LOCKLevel = TIM_LOCKLevel;
   TIM_BDTR_InitStructure.TIM_DeadTime = TIM_DeadTime;
   TIM_BDTR_InitStructure.TIM_Break = TIM_Break;
   TIM_BDTR_InitStructure.TIM_BreakPolarity = TIM_BreakPolarity;
   TIM_BDTR_InitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput;

   TIM_BDTRConfig(TIMx,&TIM_BDTR_InitStructure);
}

void config_TIM_OCPreload(TIM_TypeDef* TIMx,
                          uint8_t TIM_OCChannel,
                          uint16_t TIM_OCPreload)
{
   switch(TIM_OCChannel)
   {
      case TIM_OCChannel_1:
         TIM_OC1PreloadConfig(TIMx, TIM_OCPreload);
         break;
      case TIM_OCChannel_2:
         TIM_OC2PreloadConfig(TIMx, TIM_OCPreload);
         break;
      case TIM_OCChannel_3:
         TIM_OC3PreloadConfig(TIMx, TIM_OCPreload);
         break;
      case TIM_OCChannel_4:
         TIM_OC4PreloadConfig(TIMx, TIM_OCPreload);
         break;
      default:
         break;
   }
}

void config_TIM_OCFast(TIM_TypeDef* TIMx,
                       uint8_t TIM_OCChannel,
                       uint16_t TIM_OCFast)
{
   switch(TIM_OCChannel)
   {
      case TIM_OCChannel_1:
         TIM_OC1FastConfig(TIMx, TIM_OCFast);
         break;
      case TIM_OCChannel_2:
         TIM_OC2FastConfig(TIMx, TIM_OCFast);
         break;
      case TIM_OCChannel_3:
         TIM_OC3FastConfig(TIMx, TIM_OCFast);
         break;
      case TIM_OCChannel_4:
         TIM_OC4FastConfig(TIMx, TIM_OCFast);
         break;
      default:
         break;
   }
}

void config_TIM_ForcedOC(TIM_TypeDef* TIMx,
                      uint8_t TIM_OCChannel,
                      uint16_t TIM_ForcedAction)
{
   switch(TIM_OCChannel)
   {
      case TIM_OCChannel_1:
         TIM_ForcedOC1Config(TIMx, TIM_ForcedAction);
         break;
      case TIM_OCChannel_2:
         TIM_ForcedOC2Config(TIMx, TIM_ForcedAction);
         break;
      case TIM_OCChannel_3:
         TIM_ForcedOC3Config(TIMx, TIM_ForcedAction);
         break;
      case TIM_OCChannel_4:
         TIM_ForcedOC4Config(TIMx, TIM_ForcedAction);
         break;
      default:
         break;
   }
}

void clear_TIM_OCRef(TIM_TypeDef* TIMx,
                      uint8_t TIM_OCChannel,
                      uint16_t TIM_OCClear)
{
   switch(TIM_OCChannel)
   {
      case TIM_OCChannel_1:
         TIM_ClearOC1Ref(TIMx, TIM_OCClear);
         break;
      case TIM_OCChannel_2:
         TIM_ClearOC2Ref(TIMx, TIM_OCClear);
         break;
      case TIM_OCChannel_3:
         TIM_ClearOC3Ref(TIMx, TIM_OCClear);
         break;
      case TIM_OCChannel_4:
         TIM_ClearOC4Ref(TIMx, TIM_OCClear);
         break;
      default:
         break;
   }
}

void config_TIM_OCPolarity(TIM_TypeDef* TIMx,
                           uint8_t TIM_OCChannel,
                           uint16_t TIM_OCPolarity)
{
   switch(TIM_OCChannel)
   {
      case TIM_OCChannel_1:
         if((TIM_OCPolarity == TIM_OutputState_Disable)||
            (TIM_OCPolarity == TIM_OutputState_Enable))
            TIM_OC1PolarityConfig(TIMx, TIM_OCPolarity);
         else
            TIM_OC1NPolarityConfig(TIMx, TIM_OCPolarity);
         break;
      case TIM_OCChannel_2:
         if((TIM_OCPolarity == TIM_OutputState_Disable)||
            (TIM_OCPolarity == TIM_OutputState_Enable))
            TIM_OC2PolarityConfig(TIMx, TIM_OCPolarity);
         else
            TIM_OC2NPolarityConfig(TIMx, TIM_OCPolarity);
         break;
      case TIM_OCChannel_3:
         if((TIM_OCPolarity == TIM_OutputState_Disable)||
            (TIM_OCPolarity == TIM_OutputState_Enable))
            TIM_OC3PolarityConfig(TIMx, TIM_OCPolarity);
         else
            TIM_OC3NPolarityConfig(TIMx, TIM_OCPolarity);
         break;
      case TIM_OCChannel_4:
         TIM_OC4PolarityConfig(TIMx, TIM_OCPolarity);
         break;
      default:
         break;
   }
}

void compare_TIM_ICSet(TIM_TypeDef* TIMx,
                       uint8_t TIM_ICCompare_x,
                       uint32_t TIM_ICCompare_value)
{
   switch(TIM_ICCompare_x)
   {
      case TIM_ICCompare_1:
         TIM_SetCompare1(TIMx, TIM_ICCompare_value);
         break;
      case TIM_ICCompare_2:
         TIM_SetCompare2(TIMx, TIM_ICCompare_value);
         break;
      case TIM_ICCompare_3:
         TIM_SetCompare3(TIMx, TIM_ICCompare_value);
         break;
      case TIM_ICCompare_4:
         TIM_SetCompare4(TIMx, TIM_ICCompare_value);
         break;
      default:
         break;
   }
}