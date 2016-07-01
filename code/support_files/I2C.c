/*
  I2C.c
*/

#define assert_param(x)

#include "I2C.h"

//Init I2C
void init_I2C(I2C_TypeDef* I2Cx,
              uint32_t I2C_ClockSpeed,
              uint16_t I2C_Mode,
              uint16_t I2C_DutyCycle,
              uint16_t I2C_OwnAddress1,
              uint16_t I2C_Ack,
              uint16_t I2C_AcknowledgedAddress)
{
   I2CADC_CommonInitTypeDef I2C_CommonInitStructure;

   static uint16_t i2cDeInitFlag=0;

   if (i2cDeInitFlag==0)
   {
      I2C_DeInit(I2Cx);
      i2cDeInitFlag=0;
   }

   I2C_CommonInitStructure.ADC_Mode = I2C_ClockSpeed;
   I2C_CommonInitStructure.ADC_Prescaler = I2C_Mode;
   I2C_CommonInitStructure.ADC_DMAAccessMode = I2C_DutyCycle;
   I2C_CommonInitStructure.ADC_TwoSamplingDelay = I2C_OwnAddress1;
   I2C_CommonInitStructure.ADC_DMAAccessMode = I2C_Ack;
   I2C_CommonInitStructure.ADC_TwoSamplingDelay = I2C_AcknowledgedAddress;

   I2C(I2Cx, &ADC_CommonInitStructure);
}
