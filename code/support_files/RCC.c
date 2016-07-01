/*
   RCC.c
*/

//#define assert_param(x)

#include "RCC.h"

void RCC_PeriphClockCmd(uint8_t Peripheral,
                        FunctionalState NewState)
{
   uint32_t Periph;

assert_param(IS_RCC_PERIPHERAL(Peripheral));

   switch(Peripheral)
   {
      case RCC_GPIOA: Periph = RCC_AHB1Periph_GPIOA;
                      break;
      case RCC_GPIOB: Periph = RCC_AHB1Periph_GPIOB;
                      break;
      case RCC_GPIOC: Periph = RCC_AHB1Periph_GPIOC;
                      break;
      case RCC_GPIOD: Periph = RCC_AHB1Periph_GPIOD;
                      break;
      case RCC_GPIOE: Periph = RCC_AHB1Periph_GPIOE;
                      break;
      case RCC_GPIOF: Periph = RCC_AHB1Periph_GPIOF;
                      break;
      case RCC_GPIOG: Periph = RCC_AHB1Periph_GPIOG;
                      break;
      case RCC_GPIOH: Periph = RCC_AHB1Periph_GPIOH;
                      break;
      case RCC_GPIOI: Periph = RCC_AHB1Periph_GPIOI;
                      break;
      case RCC_GPIOJ: Periph = RCC_AHB1Periph_GPIOJ;
                      break;
      case RCC_GPIOK: Periph = RCC_AHB1Periph_GPIOK;
                      break;
      case RCC_CRC: Periph = RCC_AHB1Periph_CRC;
                    break;
      case RCC_FLITF: Periph = RCC_AHB1Periph_FLITF;
                      break;
      case RCC_SRAM1: Periph = RCC_AHB1Periph_SRAM1;
                      break;
      case RCC_SRAM2: Periph = RCC_AHB1Periph_SRAM2;
                      break;
      case RCC_BKPSRAM: Periph = RCC_AHB1Periph_BKPSRAM;
                      break;
      case RCC_SRAM3: Periph = RCC_AHB1Periph_SRAM3;
                      break;
      case RCC_CCMDATARAMEN: Periph = RCC_AHB1Periph_CCMDATARAMEN;
                             break;
      case RCC_DMA1: Periph = RCC_AHB1Periph_DMA1;
                     break;
      case RCC_DMA2: Periph = RCC_AHB1Periph_DMA2;
                     break;
      case RCC_DMA2D: Periph = RCC_AHB1Periph_DMA2D;
                      break;
      case RCC_ETH_MAC: Periph = RCC_AHB1Periph_ETH_MAC;
                        break;
      case RCC_ETH_MAC_Tx: Periph = RCC_AHB1Periph_ETH_MAC_Tx;
                           break;
      case RCC_ETH_MAC_Rx: Periph = RCC_AHB1Periph_ETH_MAC_Rx;
                           break;
      case RCC_ETH_MAC_PTP: Periph = RCC_AHB1Periph_ETH_MAC_PTP;
                            break;
      case RCC_OTG_HS: Periph = RCC_AHB1Periph_OTG_HS;
                       break;
      case RCC_OTG_HS_ULPI: Periph = RCC_AHB1Periph_OTG_HS_ULPI;
                            break;

      case RCC_DCMI: Periph = RCC_AHB2Periph_DCMI;
                     break;
      case RCC_CRYP: Periph = RCC_AHB2Periph_CRYP;
                     break;
      case RCC_HASH: Periph = RCC_AHB2Periph_HASH;
                     break;
      case RCC_RNG: Periph = RCC_AHB2Periph_RNG;
                    break;
      case RCC_OTG_FS: Periph = RCC_AHB2Periph_OTG_FS;
                       break;

      case RCC_FSMC: Periph = RCC_AHB3Periph_FSMC;
                     break;

      case RCC_TIM2: Periph = RCC_APB1Periph_TIM2;
                     break;
      case RCC_TIM3: Periph = RCC_APB1Periph_TIM3;
                     break;
      case RCC_TIM4: Periph = RCC_APB1Periph_TIM4;
                     break;
      case RCC_TIM5: Periph = RCC_APB1Periph_TIM5;
                     break;
      case RCC_TIM6: Periph = RCC_APB1Periph_TIM6;
                     break;
      case RCC_TIM7: Periph = RCC_APB1Periph_TIM7;
                     break;
      case RCC_TIM12: Periph = RCC_APB1Periph_TIM12;
                      break;
      case RCC_TIM13: Periph = RCC_APB1Periph_TIM13;
                      break;
      case RCC_TIM14: Periph = RCC_APB1Periph_TIM14;
                      break;
      case RCC_WWDG: Periph = RCC_APB1Periph_WWDG;
                     break;
      case RCC_SPI2: Periph = RCC_APB1Periph_SPI2;
                     break;
      case RCC_SPI3: Periph = RCC_APB1Periph_SPI3;
                     break;
      case RCC_USART2: Periph = RCC_APB1Periph_USART2;
                       break;
      case RCC_USART3: Periph = RCC_APB1Periph_USART3;
                       break;
      case RCC_UART4: Periph = RCC_APB1Periph_UART4;
                      break;
      case RCC_UART5: Periph = RCC_APB1Periph_UART5;
                      break;
      case RCC_I2C1: Periph = RCC_APB1Periph_I2C1;
                     break;
      case RCC_I2C2: Periph = RCC_APB1Periph_I2C2;
                     break;
      case RCC_I2C3: Periph = RCC_APB1Periph_I2C3;
                     break;
      case RCC_CAN1: Periph = RCC_APB1Periph_CAN1;
                     break;
      case RCC_CAN2: Periph = RCC_APB1Periph_CAN2;
                     break;
      case RCC_PWR: Periph = RCC_APB1Periph_PWR;
                    break;
      case RCC_DAC: Periph = RCC_APB1Periph_DAC;
                    break;
      case RCC_UART7: Periph = RCC_APB1Periph_UART7;
                      break;
      case RCC_UART8: Periph = RCC_APB1Periph_UART8;
                      break;

      case RCC_TIM1: Periph = RCC_APB2Periph_TIM1;
                     break;
      case RCC_TIM8: Periph = RCC_APB2Periph_TIM8;
                     break;
      case RCC_USART1: Periph = RCC_APB2Periph_USART1;
                       break;
      case RCC_USART6: Periph = RCC_APB2Periph_USART6;
                       break;
      case RCC_ADC: Periph = RCC_APB2Periph_ADC;
                    break;
      case RCC_ADC1: Periph = RCC_APB2Periph_ADC1;
                     break;
      case RCC_ADC2: Periph = RCC_APB2Periph_ADC2;
                     break;
      case RCC_ADC3: Periph = RCC_APB2Periph_ADC3;
                     break;
      case RCC_SDIO: Periph = RCC_APB2Periph_SDIO;
                     break;
      case RCC_SPI1: Periph = RCC_APB2Periph_SPI1;
                     break;
      case RCC_SPI4: Periph = RCC_APB2Periph_SPI4;
                     break;
      case RCC_SYSCFG: Periph = RCC_APB2Periph_SYSCFG;
                       break;
      case RCC_TIM9: Periph = RCC_APB2Periph_TIM9;
                     break;
      case RCC_TIM10: Periph = RCC_APB2Periph_TIM10;
                      break;
      case RCC_TIM11: Periph = RCC_APB2Periph_TIM11;
                      break;
      case RCC_SPI5: Periph = RCC_APB2Periph_SPI5;
                      break;
      case RCC_SPI6: Periph = RCC_APB2Periph_SPI6;
                     break;
      case RCC_SAI1: Periph = RCC_APB2Periph_SAI1;
                     break;
      case RCC_LTDC: Periph = RCC_APB2Periph_LTDC;
                     break;
   }

   if (Peripheral <= 0x1A)
      RCC_AHB1PeriphClockCmd(Periph, NewState);
   else if ((Peripheral >= 0x20) && (Peripheral <= 0x24))
      RCC_AHB2PeriphClockCmd(Periph, NewState);
   else if  (Peripheral == 0x30)
      RCC_AHB3PeriphClockCmd(Periph, NewState);
   else if ((Peripheral >= 0x40) && (Peripheral <= 0x58))
      RCC_APB1PeriphClockCmd(Periph, NewState);
   else if ((Peripheral >=0x60) && (Peripheral <= 0x72))
      RCC_APB2PeriphClockCmd(Periph, NewState);

}
