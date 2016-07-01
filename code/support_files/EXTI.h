/*
   EXTI.h
*/

#ifndef EXTI_H
#define EXTI_H

#include "stm32f4xx_exti.h"

void init_EXTI(uint32_t EXTI_Line,
               EXTIMode_TypeDef EXTI_Mode,
               EXTITrigger_TypeDef EXTI_Trigger,
               FunctionalState EXTI_LineCmd);

//** init_EXTI **
//-- EXTI_Line --
//   EXTI_Line0
//   EXTI_Line1
//   EXTI_Line2
//   EXTI_Line3
//   EXTI_Line4
//   EXTI_Line5
//   EXTI_Line6
//   EXTI_Line7
//   EXTI_Line8
//   EXTI_Line9
//   EXTI_Line10
//   EXTI_Line11
//   EXTI_Line12
//   EXTI_Line13
//   EXTI_Line14
//   EXTI_Line15
//   EXTI_Line16
//   EXTI_Line17
//   EXTI_Line18
//   EXTI_Line19
//   EXTI_Line20
//   EXTI_Line21
//   EXTI_Line22

//-- EXTI_Mode --
//   EXTI_Mode_Interrupt
//   EXTI_Mode_Event

//-- EXTI_Trigger --
//   EXTI_Trigger_Rising
//   EXTI_Trigger_Rising_Falling

//-- EXTI_LineCmd --
//   ENABLE
//   DISABLE

//*****************************************************************

#endif
