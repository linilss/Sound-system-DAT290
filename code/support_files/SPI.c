/*
   SPI.c
*/

#define assert_param(x)

#include "GPIO.h"
#include "SPI.h"

void SPI_CS_SetLow(GPIO_TypeDef* GPIOx,
                   uint32_t GPIO_Pin)
{
   GPIO_ResetBits(GPIOx, GPIO_Pin);
}

void SPI_CS_SetHigh(GPIO_TypeDef* GPIOx,
                    uint32_t GPIO_Pin)
{
   GPIO_SetBits(GPIOx, GPIO_Pin);
}

void init_SPI(SPI_TypeDef* SPIx,
              uint16_t SPI_Direction,
              uint16_t SPI_Mode,
              uint16_t SPI_DataSize,
              uint16_t SPI_CPOL,
              uint16_t SPI_CPHA,
              uint16_t SPI_NSS,
              uint16_t SPI_BaudRatePrescaler,
              uint16_t SPI_FirstBit,
              uint16_t SPI_CRCPolynomial)
{
   SPI_InitTypeDef SPI_InitStructure; //setup SPI_InitStructure

   static uint16_t spiDeInitFlag=0;

   if (spiDeInitFlag==0)
   {
      SPI_I2S_DeInit(SPIx);
      spiDeInitFlag=1;
   }

   SPI_InitStructure.SPI_Direction = SPI_Direction;
   SPI_InitStructure.SPI_Mode = SPI_Mode;
   SPI_InitStructure.SPI_DataSize = SPI_DataSize;
   SPI_InitStructure.SPI_CPOL = SPI_CPOL;
   SPI_InitStructure.SPI_CPHA = SPI_CPHA;
   SPI_InitStructure.SPI_NSS = SPI_NSS;
   SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler;
   SPI_InitStructure.SPI_FirstBit = SPI_FirstBit;
   SPI_InitStructure.SPI_CRCPolynomial = SPI_CRCPolynomial;

   SPI_Init(SPIx, &SPI_InitStructure);
}

uint8_t SPI_SendByte(SPI_TypeDef* SPIx, uint8_t byte)
{
   SPI_CS_SetLow(GPIOB, GPIO_Pin_2);
   /*!< Loop while DR register in not empty */
   while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET);

   /*!< Send byte through the SPI1 peripheral */
   SPI_I2S_SendData(SPIx, byte);

   /*!< Wait to receive a byte  */
   while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET);
   SPI_CS_SetHigh(GPIOB, GPIO_Pin_2);
   /*!< Return the byte read from the SPI bus */
   return SPI_I2S_ReceiveData(SPIx);
}

uint16_t SPI_SendHalfWord(SPI_TypeDef* SPIx, uint16_t HalfWord)
{
   SPI_CS_SetLow(GPIOB, GPIO_Pin_2);
   /*!< Loop while DR register in not emplty */
   while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET);

   /*! < Send Half Word through the sFLASH peripheral */
   SPI_I2S_SendData(SPIx, HalfWord);

   /*!< Wait to receive a Half Word */
   while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET);
   SPI_CS_SetHigh(GPIOB, GPIO_Pin_2);
   /*!< Return the Half Word read from the SPI bus  */
   return SPI_I2S_ReceiveData(SPIx);
}