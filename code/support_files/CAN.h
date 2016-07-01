/*
   CAN.h
*/

#ifndef CAN_H
#define CAN_H

#include "stm32f4xx_can.h"

//-- FunctionalState --
//   ENABLE
//   DISABLE

#define CAN_1 0x01
#define CAN_2 0x02

//Baud_rate=bus_clock/{(1+CAN_Prescaler)*[(1+BS1)+(1+BS2)]}
//BS1 should be round 3*BS2
void init_CAN(CAN_TypeDef* CANx,
              uint16_t CAN_Prescaler,
              uint8_t CAN_Mode,
              uint8_t CAN_SJW,
              uint8_t CAN_BS1,
              uint8_t CAN_BS2,
              FunctionalState CAN_TTCM,
              FunctionalState CAN_ABOM,
              FunctionalState CAN_AWUM,
              FunctionalState CAN_NART,
              FunctionalState CAN_RFLM,
              FunctionalState CAN_TXFP);

void init_CANFilter(uint8_t CAN_x,
					uint16_t CAN_FilterIdHigh,
                    uint16_t CAN_FilterIdLow,
                    uint16_t CAN_FilterMaskIdHigh,
                    uint16_t CAN_FilterMaskIdLow,
                    uint16_t CAN_FilterFIFOAssignment,
                    uint8_t CAN_FilterNumber,
                    uint8_t CAN_FilterMode,
                    uint8_t CAN_FilterScale,
                    FunctionalState CAN_FilterActivation);

CanTxMsg init_CANTxMessage(uint32_t StdId,
                           uint32_t ExtId,
                           uint8_t IDE,
                           uint8_t RTR,
                           uint8_t DLC,
                           uint8_t Data[8]);

uint32_t get_CANStdId(CanRxMsg* RxMessage);

uint32_t get_CANExtId(CanRxMsg* RxMessage);

uint32_t get_CANIDE(CanRxMsg* RxMessage);

uint8_t get_CANRTR(CanRxMsg* RxMessage);

uint8_t get_CANDLCStdId(CanRxMsg* RxMessage);

uint8_t * get_CANData(CanRxMsg* RxMessage);

//
//**init_CAN **
//-- CAN_Prescaler --
//-- CAN_clock_prescaler --
//   1 - 1024

//-- CAN_Mode --
//-- CAN_operating_mode --
//   CAN_Mode_Normal - normal mode
//   CAN_Mode_LoopBack - loopback mode
//   CAN_Mode_Silent - silent mode
//   CAN_Mode_Silent_LoopBack - loopback combined with silent mode
//-- CAN_operating_mode --
//   CAN_OperatingMode_Initialization - Initialization mode
//   CAN_OperatingMode_Normal - Normal mode
//   CAN_OperatingMode_Sleep - sleep mode

//-- CAN_SJW --
//-- CAN_synchronisation_jump_width --
//   CAN_SJW_1tq ((uint8_t)0x00) - 1 time quantum
//   CAN_SJW_2tq ((uint8_t)0x01) - 2 time quantum
//   CAN_SJW_3tq ((uint8_t)0x02) - 3 time quantum
//   CAN_SJW_4tq ((uint8_t)0x03) - 4 time quantum

//-- CAN_BS1 --
//-- CAN_time_quantum_in_bit_segment_1 --
//   CAN_BS1_1tq - 1 time quantum
//   CAN_BS1_2tq - 2 time quantum
//   CAN_BS1_3tq - 3 time quantum
//   CAN_BS1_4tq - 4 time quantum
//   CAN_BS1_5tq - 5 time quantum
//   CAN_BS1_6tq - 6 time quantum
//   CAN_BS1_7tq - 7 time quantum
//   CAN_BS1_8tq - 8 time quantum
//   CAN_BS1_9tq - 9 time quantum
//   CAN_BS1_10tq - 10 time quantum
//   CAN_BS1_11tq - 11 time quantum
//   CAN_BS1_12tq - 12 time quantum
//   CAN_BS1_13tq - 13 time quantum
//   CAN_BS1_14tq - 14 time quantum
//   CAN_BS1_15tq - 15 time quantum
//   CAN_BS1_16tq - 16 time quantum

//-- CAN_BS2 --
//-- CAN_time_quantum_in_bit_segment_2 --
//   CAN_BS2_1tq - 1 time quantum
//   CAN_BS2_2tq - 2 time quantum
//   CAN_BS2_3tq - 3 time quantum
//   CAN_BS2_4tq - 4 time quantum
//   CAN_BS2_5tq - 5 time quantum
//   CAN_BS2_6tq - 6 time quantum
//   CAN_BS2_7tq - 7 time quantum
//   CAN_BS2_8tq - 8 time quantum

//-- CAN_TTCM --
//-- Time triggered communication mode --
//   ENABLE
//   DISABLE

//-- CAN_ABOM --
//-- automatic bus-off management --
//   ENABLE
//   DISABLE

//-- CAN_AWUM --
//-- automatic wake-up mode --
//   ENABLE
//   DISABLE

//-- CAN_NART --
//-- non-automatic retransmission mode --
//   ENABLE
//   DISABLE

//-- CAN_RFLM --
//-- Receive FIFO Locked mode --
//   ENABLE
//   DISABLE

//-- CAN_TXFP --
//-- Transmit FIFO priority --
//   ENABLE
//   DISABLE

//** init_CANFilter **
//-- CAN_x --
//   CAN_1
//   CAN_2
//-- CAN_FilterIdHigh --
//-- Filter identification number --
//!! MSB for 32 bit !!
//!! First one for 16 bit !!
//   0x0000 - 0xFFFF

//-- CAN_FilterIdLow --
//-- Filter identification number --
//!! LSB for 32 bit !!
//!! Second one for 16 bit !!
//   0x0000 - 0xFFFF

//-- CAN_FilterMaskIdHigh --
//-- Filter mask or identification number --
//!! MSB for 32 bit !!
//!! First one for 16 bit !!
//   0x0000 - 0xFFFF

//-- CAN_FilterMaskIdLow --
//-- Filter mask or identification number --
//!! LSB for 32 bit !!
//!! Second one for 16 bit !!
//   0x0000 - 0xFFFF

//-- CAN_FilterFIFOAssignment --
//   CAN_Filter_FIFO0 - Filter FIFO 0 assignment for filter x
//   CAN_Filter_FIFO1 - Filter FIFO 1 assignment for filter x
//-- Legacy defines --
//   CAN_FilterFIFO0 = CAN_Filter_FIFO0
//   CAN_FilterFIFO1 = CAN_Filter_FIFO1

//-- CAN_FilterNumber --
//-- Filter to be initialized --
//   0x0 - 0xD (0 - 13)

//-- CAN_FilterMode --
//-- CAN_filter_mode --
//   CAN_FilterMode_IdMask - identifier/mask mode
//   CAN_FilterMode_IdList - identifier list mode

//-- CAN_FilterScale --
//-- CAN_filter_scale --
//   CAN_FilterScale_16bit - Two 16-bit filters
//   CAN_FilterScale_32bit - One 32-bit filter

//-- CAN_FilterActivation --
//   ENABLE
//   DISABLE

//** init_CANTxMessage **
//-- StdId --
//-- Standard identifier --
//   0x000 - 0x7FF

//-- ExtId --
//-- Extended identifier --
//   0x00000000 - 0x1FFFFFFF
//-- CAN_identifier_type --

//-- IDE --
//-- CAN_identifier_type --
//   CAN_Id_Standard - Standard Id
//   CAN_Id_Extended - Extended Id

//-- RTR --
//-- CAN_remote_transmission_request --
//   CAN_RTR_Data - Data frame
//   CAN_RTR_Remote - Remote frame

//-- DLC --
//-- Frame length --
//   0x00 - 0x10 (0 - 8)

//-- Data --
//   0x00 - 0xFF (0 - 255)

//*****************************************************************
//** Definitions for other functions **
//** CAN Tx Message structure **
//   uint32_t StdId
//   uint32_t ExtId
//   uint8_t IDE
//   uint8_t RTR
//   uint8_t DLC
//   uint8_t Data[8]

//** CAN Rx Message structure **
//   uint32_t StdId
//   uint32_t ExtId
//   uint8_t IDE
//   uint8_t RTR
//   uint8_t DLC
//   uint8_t Data[8]
//   uint8_t FMI

//-- FMI --
//   index of the filter the message stored in the mailbox passes through
//   0x00 - 0xFF (0 - 255)

//-- CAN_InitStatus --
//   CAN_InitStatus_Failed - CAN initialization failed
//   CAN_InitStatus_Success - CAN initialization OK

//-- CAN_operating_mode_status --
//   CAN_ModeStatus_Failed - CAN entering the specific mode failed
//   CAN_ModeStatus_Success - CAN entering the specific mode Succeed

//-- CAN_Start_bank_filter_for_slave_CAN --
//   0x00 - 0x1B (1 - 27)

//-- CAN Tx mailbox --
//   0x0 - 0x2 (0 - 2)

//-- CAN_identifier_type
//   CAN_Id_Standard - Standard Id
//   CAN_Id_Extended - Extended Id
//-- Legacy defines --
//   CAN_ID_STD = CAN_Id_Standard
//   CAN_ID_EXT = CAN_Id_Extended

//-- CAN_remote_transmission_request --
//   CAN_RTR_Data - Data frame
//   CAN_RTR_Remote - Remote frame
//-- Legacy defines --
//   CAN_RTR_DATA = CAN_RTR_Data
//   CAN_RTR_REMOTE = CAN_RTR_Remote

//-- CAN_transmit_constants --
//   CAN_TxStatus_Failed - CAN transmission failed
//   CAN_TxStatus_Ok - CAN transmission succeeded
//   CAN_TxStatus_Pending - CAN transmission pending
//   CAN_TxStatus_NoMailBox - CAN cell did not provide an empty mailbox
//-- Legacy defines --
//   CANTXFAILED = CAN_TxStatus_Failed
//   CANTXOK = CAN_TxStatus_Ok
//   CANTXPENDING = CAN_TxStatus_Pending
//   CAN_NO_MB = CAN_TxStatus_NoMailBox

//--  CAN_receive_FIFO_number_constants
//   CAN_FIFO0 - CAN FIFO 0 used to receive
//   CAN_FIFO1 - CAN FIFO 1 used to receive

//-- CAN_sleep_constants --
//   CAN_Sleep_Failed - CAN did not enter the sleep mode
//   CAN_Sleep_Ok - CAN entered the sleep mode
//-- Legacy defines --
//   CANSLEEPFAILED = CAN_Sleep_Failed
//   CANSLEEPOK = CAN_Sleep_Ok

//-- CAN_wake_up_constants --
//   CAN_WakeUp_Failed - CAN did not leave- the sleep mode
//   CAN_WakeUp_Ok - CAN leaved the sleep mode
//-- Legacy defines --
//   CANWAKEUPFAILED = CAN_WakeUp_Failed
//   CANWAKEUPOK = CAN_WakeUp_Ok

//-- CAN_Error_Code_constants --
//   CAN_ErrorCode_NoErr - No Error
//   CAN_ErrorCode_StuffErr - Stuff Error
//   CAN_ErrorCode_FormErr - Form Error
//   CAN_ErrorCode_ACKErr - Acknowledgment Error
//   CAN_ErrorCode_BitRecessiveErr - Bit Recessive Error
//   CAN_ErrorCode_BitDominantErr - Bit Dominant Error
//   CAN_ErrorCode_CRCErr - CRC Error
//   CAN_ErrorCode_SoftwareSetErr - Software Set Error

//-- CAN_flags --
//!! CAN transmit flags !!
//   CAN_FLAG_RQCP0 - Request MailBox0 Flag
//   CAN_FLAG_RQCP1 - Request MailBox1 Flag
//   CAN_FLAG_RQCP2 - Request MailBox2 Flag
//!! CAN receive flags !!
//   CAN_FLAG_FMP0 - FIFO 0 Message- Pending Flag
//   CAN_FLAG_FF0 - FIFO 0 Full Flag
//   CAN_FLAG_FOV0 - FIFO 0 Overrun Flag
//   CAN_FLAG_FMP1 - FIFO 1 Message Pending Flag
//   CAN_FLAG_FF1  - FIFO 1 Full Flag
//   CAN_FLAG_FOV1 - FIFO 1 Overrun Flag
//!! CAN operationg mode flags !!
//   CAN_FLAG_WKU - Wake up Flag
//   CAN_FLAG_SLAK - Sleep acknowledge Flag
//!! CAN error flags
//   CAN_FLAG_EWG  Error Warning Flag
//   CAN_FLAG_EPV  Error Passive Flag
//   CAN_FLAG_BOF  Bus-Off Flag
//   CAN_FLAG_LEC  Last error code Flag

//-- CAN_interrupts
//   CAN_IT_TME - Transmit mailbox empty Interrupt
//!! CAN receive interrupts !!
//   CAN_IT_FMP0 - FIFO 0 message pending - Interrupt
//   CAN_IT_FF0 - FIFO 0 full Interrupt
//   CAN_IT_FOV0 - FIFO 0 overrun Interrupt
//   CAN_IT_FMP1 - FIFO 1 message pending Interrupt
//   CAN_IT_FF1 - FIFO 1 full Interrupt
//   CAN_IT_FOV1 - FIFO 1 overrun - Interrupt
//!! CAN operating mode interrupts
//   CAN_IT_WKU - Wake-up Interrupt
//   CAN_IT_SLK  Sleep acknowledge Interrupt
//!! CAN error interrupts !!
//   CAN_IT_EWG - Error warning Interrupt
//   CAN_IT_EPV - Error passive Interrupt
//   CAN_IT_BOF - Bus-off Interrupt
//   CAN_IT_LEC - Last error code Interrupt
//   CAN_IT_ERR - Error Interrupt
//!! CAN flags named as interrupts !!
//   CAN_IT_RQCP0 = CAN_IT_TME
//   CAN_IT_RQCP1 = CAN_IT_TME
//   CAN_IT_RQCP2 = CAN_IT_TME

#endif
