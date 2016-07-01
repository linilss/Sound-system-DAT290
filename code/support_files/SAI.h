/*
   SAI.h
*/

#ifndef SAI_H
#define SAI_H

#include "stm32f4xx_sai.h"

void init_SAI(SAI_Block_TypeDef* SAI_Block_x,
              uint32_t SAI_AudioMode,
              uint32_t SAI_Protocol,
              uint32_t SAI_DataSize,
              uint32_t SAI_FirstBit,
              uint32_t SAI_ClockStrobing,
              uint32_t SAI_Synchro,
              uint32_t SAI_OUTDRIV,
              uint32_t SAI_NoDivider,
              uint32_t SAI_MasterDivider,
              uint32_t SAI_FIFOThreshold);

void init_SAI_Frame(SAI_Block_TypeDef* SAI_Block_x,
                    uint32_t SAI_FrameLength,
                    uint32_t SAI_ActiveFrameLength,
                    uint32_t SAI_FSDefinition,
                    uint32_t SAI_FSPolarity,
                    uint32_t SAI_FSOffset);

void init_SAI_Slot(SAI_Block_TypeDef* SAI_Block_x,
	               uint32_t SAI_FirstBitOffset,
                   uint32_t SAI_SlotSize,
                   uint32_t SAI_SlotNumber,
                   uint32_t SAI_SlotActive);

//** init_SAI **
//-- SAI_AudioMode --
//   AI_Mode_MasterTx
//   SAI_Mode_MasterRx
//   SAI_Mode_SlaveTx
//   SAI_Mode_SlaveRx

//-- SAI_Protocol --
//   SAI_Free_Protocol
//   SAI_SPDIF_Protocol
//   SAI_AC97_Protocol

//-- SAI_DataSize --
//   SAI_DataSize_8b
//   SAI_DataSize_10b
//   SAI_DataSize_16b
//   SAI_DataSize_20b
//   SAI_DataSize_24b
//   SAI_DataSize_32b

//-- SAI_FirstBit --
//   SAI_FirstBit_MSB
//   SAI_FirstBit_LSB

//-- SAI_ClockStrobing --
//   SAI_ClockStrobing_FallingEdge
//   SAI_ClockStrobing_RisingEdge

//-- SAI_Synchro --
//   SAI_Asynchronous
//   SAI_Synchronous

//-- SAI_OUTDRIV --
//   SAI_OutputDrive_Disabled
//   SAI_OutputDrive_Enabled

//-- SAI_NoDivider --
//   SAI_MasterDivider_Enabled
//   SAI_MasterDivider_Disabled

//-- SAI_MasterDivider --
//   0 - 0xF (0 - 15)

//-- SAI_FIFOThreshold --
//   SAI_Threshold_FIFOEmpty
//   SAI_FIFOThreshold_1QuarterFull
//   SAI_FIFOThreshold_HalfFull
//   SAI_FIFOThreshold_3QuartersFull
//   SAI_FIFOThreshold_Full

//** init_SAI_Frame **
//-- SAI_FrameLength --
//   0x008 - 0x100 (8 - 256)

//-- SAI_ActiveFrameLength  --
//   0x01 - 0x80 (1 - 128)

//-- SAI_FSDefinition --
//   SAI_FS_StartFrame
//   I2S_FS_ChannelIdentification

//-- SAI_FSPolarity --
//   SAI_FS_ActiveLow
//   SAI_FS_ActiveHigh

//-- SAI_FSOffset --
//   SAI_FS_FirstBit
//   SAI_FS_BeforeFirstBit

//** init_SAI_Slot **
//-- SAI_FirstBitOffset --
//   0 - 0x18 (0 - 24)

//-- SAI_SlotSize --
//   SAI_SlotSize_DataSize
//   SAI_SlotSize_16b
//   SAI_SlotSize_32b

//-- SAI_SlotNumber --
//   0x01 - 0x10 (1 - 16)

//-- SAI_SlotActive --
//   SAI_Slot_NotActive
//   SAI_SlotActive_0
//   SAI_SlotActive_1
//   SAI_SlotActive_2
//   SAI_SlotActive_3
//   SAI_SlotActive_4
//   SAI_SlotActive_5
//   SAI_SlotActive_6
//   SAI_SlotActive_7
//   SAI_SlotActive_8
//   SAI_SlotActive_9
//   SAI_SlotActive_10
//   SAI_SlotActive_11
//   SAI_SlotActive_12
//   SAI_SlotActive_13
//   SAI_SlotActive_14
//   SAI_SlotActive_15
//   SAI_SlotActive_ALL

//*****************************************************************
//** Definitions for other functions **
//-- SAI_Mono_Streo_Mode --
//   SAI_MonoMode
//   SAI_StreoMode

//-- SAI_TRIState_Management --
//   SAI_Output_NotReleased
//   SAI_Output_Released

//-- SAI_Block_Companding_Mode --
//   SAI_NoCompanding
//   SAI_ULaw_1CPL_Companding
//   SAI_ALaw_1CPL_Companding
//   SAI_ULaw_2CPL_Companding
//   SAI_ALaw_2CPL_Companding

//-- SAI_Block_Mute_Value --
//   SAI_ZeroValue
//   SAI_LastSentValue

//-- SAI_Block_Mute_Frame_Counter --
//   0 - 0x3F (0 - 63)

//-- SAI_Block_Interrupts_Definition --
//   SAI_IT_OVRUDR
//   SAI_IT_MUTEDET
//   SAI_IT_WCKCFG
//   SAI_IT_FREQ
//   SAI_IT_CNRDY
//   SAI_IT_AFSDET
//   SAI_IT_LFSDET

//-- SAI_Block_Flags_Definition --
//   SAI_FLAG_OVRUDR
//   SAI_FLAG_MUTEDET
//   SAI_FLAG_WCKCFG
//   SAI_FLAG_FREQ
//   SAI_FLAG_CNRDY
//   SAI_FLAG_AFSDET
//   SAI_FLAG_LFSDET

//-- SAI_Block_Fifo_Status_Level --
//   SAI_FIFOStatus_Empty
//   SAI_FIFOStatus_Less1QuarterFull
//   SAI_FIFOStatus_1QuarterFull
//   SAI_FIFOStatus_HalfFull
//   SAI_FIFOStatus_3QuartersFull
//   SAI_FIFOStatus_Full

#endif