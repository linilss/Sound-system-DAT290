/*
   EXTI.c
*/

#define assert_param(x)

#include "EXTI.h"

void init_EXTI(uint32_t EXTI_Line,
              EXTIMode_TypeDef EXTI_Mode,
              EXTITrigger_TypeDef EXTI_Trigger,
              FunctionalState EXTI_LineCmd)
{
   EXTI_InitTypeDef EXTI_InitStructure;

   static uint16_t extiDeInitFlag=0;

   if (extiDeInitFlag==0)
   {
      EXTI_DeInit();
      extiDeInitFlag=1;
   }

   EXTI_InitStructure.EXTI_Line = EXTI_Line;
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode;
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger;
   EXTI_InitStructure.EXTI_LineCmd = EXTI_LineCmd;

   EXTI_Init(&EXTI_InitStructure);
}
