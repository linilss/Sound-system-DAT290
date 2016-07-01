/*
   GPIO.c
*/

#define assert_param(x)

#include "GPIO.h"
#include "RCC.h"

//Init GPIO
void init_GPIO(GPIO_TypeDef* GPIOx,
               uint32_t GPIO_Pin,
               GPIOMode_TypeDef GPIO_Mode,
               GPIOSpeed_TypeDef GPIO_Speed,
               GPIOOType_TypeDef GPIO_OType,
               GPIOPuPd_TypeDef GPIO_PuPd)
{
   GPIO_InitTypeDef GPIO_InitStructure; //setup GPIO_InitStructure

   static uint16_t gpioDeInitFlag=0;

   if (gpioDeInitFlag==0)
   {
      GPIO_DeInit(GPIOx);
      gpioDeInitFlag=1;
   }

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed;
   GPIO_InitStructure.GPIO_OType = GPIO_OType;
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd;

   GPIO_Init(GPIOx,
             &GPIO_InitStructure);
}

void init_GPIO_RCC(GPIO_TypeDef* GPIOx,
               uint32_t GPIO_Pin,
               GPIOMode_TypeDef GPIO_Mode,
               GPIOSpeed_TypeDef GPIO_Speed,
               GPIOOType_TypeDef GPIO_OType,
               GPIOPuPd_TypeDef GPIO_PuPd)
{
	uint32_t GPIO_Port;

//	assert_param(IS_RCC_PERIPHERAL(GPIO_Port));
	
	if (GPIOx==GPIOA)
		GPIO_Port=RCC_GPIOA;
	else if (GPIOx==GPIOB)
		GPIO_Port=RCC_GPIOB;
	else if (GPIOx==GPIOC)
		GPIO_Port=RCC_GPIOC;
	else if (GPIOx==GPIOD)
		GPIO_Port=RCC_GPIOD;
	else if (GPIOx==GPIOE)
		GPIO_Port=RCC_GPIOE;
	else if (GPIOx==GPIOF)
		GPIO_Port=RCC_GPIOF;
	else if (GPIOx==GPIOG)
		GPIO_Port=RCC_GPIOG;
	else if (GPIOx==GPIOH)
		GPIO_Port=RCC_GPIOH;
	else if (GPIOx==GPIOI)
		GPIO_Port=RCC_GPIOI;
	else if (GPIOx==GPIOJ)
		GPIO_Port=RCC_GPIOJ;
	else if (GPIOx==GPIOK)
		GPIO_Port=RCC_GPIOK;

	RCC_PeriphClockCmd(GPIO_Port,
	                   ENABLE);
	
	init_GPIO(GPIOx,
              GPIO_Pin,
              GPIO_Mode,
              GPIO_Speed,
              GPIO_OType,
              GPIO_PuPd);
}
	
void write_GPIO_Byte(GPIO_TypeDef* GPIOx,
                     uint8_t high_low_byte,
					   uint8_t byte_value)
{
   uint16_t temp_word;
   temp_word=GPIO_ReadOutputData(GPIOx);
   if (high_low_byte==HIGH_BYTE)
   {
      temp_word=(temp_word & 0x00FF) | (byte_value<<8);
   }
   else if (high_low_byte==LOW_BYTE)
   {
      temp_word=(temp_word & 0xFF00) | byte_value;
   }
   GPIO_Write(GPIOx,
              temp_word);
}

uint8_t read_GPIO_Byte(GPIO_TypeDef* GPIOx,
                     uint8_t high_low_byte)
{
   uint16_t input_data;
   input_data=GPIO_ReadInputData(GPIOx);
   if (high_low_byte==HIGH_BYTE)
      return (input_data & 0xFF00)>>8;
   else
	  return input_data & 0x00FF;
}
