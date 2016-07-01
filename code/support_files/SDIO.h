/*
   SDIO.h
*/

#ifndef SDIO_H
#define SDIO_H

#include "stm32f4xx_sdio.h"

void init_SDIO(uint32_t SDIO_ClockEdge,
               uint32_t SDIO_ClockBypass,
               uint32_t SDIO_ClockPowerSave,
               uint32_t SDIO_BusWide,
               uint32_t SDIO_HardwareFlowControl,
               uint8_t SDIO_ClockDiv);

void send_SDIO_Command(uint32_t SDIO_Argument,
                       uint32_t SDIO_CmdIndex,
                       uint32_t SDIO_Response,
                       uint32_t SDIO_Wait,
                       uint32_t SDIO_CPSM);

void config_SDIO_Data(uint32_t SDIO_DataTimeOut,
                      uint32_t SDIO_DataLength,
                      uint32_t SDIO_DataBlockSize,
                      uint32_t SDIO_TransferDir,
                      uint32_t SDIO_TransferMode,
                      uint32_t SDIO_DPSM);

//** init_SDIO **
//-- SDIO_ClockEdge --
//   SDIO_ClockEdge_Rising
//   SDIO_ClockEdge_Falling

//-- SDIO_ClockBypass --
//   SDIO_ClockBypass_Disable
//   SDIO_ClockBypass_Enable

//-- SDIO_ClockPowerSave --
//   SDIO_ClockPowerSave_Disable
//   SDIO_ClockPowerSave_Enable

//-- SDIO_BusWide --
//   SDIO_BusWide_1b
//   SDIO_BusWide_4b
//   SDIO_BusWide_8b

//-- SDIO_HardwareFlowControl --
//   SDIO_HardwareFlowControl_Disable
//   SDIO_HardwareFlowControl_Enable

//-- SDIO_ClockDiv --
//
//

//*****************************************************************
//** Definitions for other functions **
//-- SDIO_Power_State --
//   SDIO_PowerState_OFF
//   SDIO_PowerState_ON

//-- SDIO_Interrupt_sources --
//   SDIO_IT_CCRCFAIL
//   SDIO_IT_DCRCFAIL
//   SDIO_IT_CTIMEOUT
//   SDIO_IT_DTIMEOUT
//   SDIO_IT_TXUNDERR
//   SDIO_IT_RXOVERR
//   SDIO_IT_CMDREND
//   SDIO_IT_CMDSENT
//   SDIO_IT_DATAEND
//   SDIO_IT_STBITERR
//   SDIO_IT_DBCKEND
//   SDIO_IT_CMDACT
//   SDIO_IT_TXACT
//   SDIO_IT_RXACT
//   SDIO_IT_TXFIFOHE
//   SDIO_IT_RXFIFOHF
//   SDIO_IT_TXFIFOF
//   SDIO_IT_RXFIFOF
//   SDIO_IT_TXFIFOE
//   SDIO_IT_RXFIFOE
//   SDIO_IT_TXDAVL
//   SDIO_IT_RXDAVL
//   SDIO_IT_SDIOIT
//   SDIO_IT_CEATAEND

//-- SDIO_Command_Index --
//   0x00 - 0x28 (0 - 40)

//-- SDIO_Response_Type --
//   SDIO_Response_No
//   SDIO_Response_Short
//   SDIO_Response_Long

//-- SDIO_Wait_Interrupt_State --
//   SDIO_Wait_No
//   SDIO_Wait_IT
//   SDIO_Wait_Pend

//-- SDIO_CPSM_State --
//   SDIO_CPSM_Disable
//   SDIO_CPSM_Enable


//-- SDIO_Response_Registers --
//   SDIO_RESP1
//   SDIO_RESP2
//   SDIO_RESP3
//   SDIO_RESP4

//-- SDIO_Data_Length --
//   0x00000000 - 0x01FFFFFF

//-- SDIO_Data_Block_Size --
//   SDIO_DataBlockSize_1b
//   SDIO_DataBlockSize_2b
//   SDIO_DataBlockSize_4b
//   SDIO_DataBlockSize_8b
//   SDIO_DataBlockSize_16b
//   SDIO_DataBlockSize_32b
//   SDIO_DataBlockSize_64b
//   SDIO_DataBlockSize_128b
//   SDIO_DataBlockSize_256b
//   SDIO_DataBlockSize_512b
//   SDIO_DataBlockSize_1024b
//   SDIO_DataBlockSize_2048b
//   SDIO_DataBlockSize_4096b
//   SDIO_DataBlockSize_8192b
//   SDIO_DataBlockSize_16384b

//-- SDIO_Transfer_Direction
//   SDIO_TransferDir_ToCard
//   SDIO_TransferDir_ToSDIO

//-- SDIO_Transfer_Type --
//   SDIO_TransferMode_Block
//   SDIO_TransferMode_Stream

//-- SDIO_DPSM_State --
//   SDIO_DPSM_Disable
//   SDIO_DPSM_Enable

//-- SDIO_Flags --
//   SDIO_FLAG_CCRCFAIL

//   SDIO_FLAG_DCRCFAIL
//   SDIO_FLAG_CTIMEOUT
//   SDIO_FLAG_DTIMEOUT
//   SDIO_FLAG_TXUNDERR
//   SDIO_FLAG_RXOVERR
//   SDIO_FLAG_CMDREND
//   SDIO_FLAG_CMDSENT
//   SDIO_FLAG_DATAEND
//   SDIO_FLAG_STBITERR
//   SDIO_FLAG_DBCKEND
//   SDIO_FLAG_CMDACT
//   SDIO_FLAG_TXACT
//   SDIO_FLAG_RXACT
//   SDIO_FLAG_TXFIFOHE
//   SDIO_FLAG_RXFIFOHF
//   SDIO_FLAG_TXFIFOF
//   SDIO_FLAG_RXFIFOF
//   SDIO_FLAG_TXFIFOE
//   SDIO_FLAG_RXFIFOE
//   SDIO_FLAG_TXDAVL
//   SDIO_FLAG_RXDAVL
//   SDIO_FLAG_SDIOIT
//   SDIO_FLAG_CEATAEND

//-- SDIO_Read_Wait_Mode --
//   SDIO_ReadWaitMode_DATA2
//   SDIO_ReadWaitMode_CLK

#endif