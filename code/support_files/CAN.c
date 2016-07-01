/*
   CAN.c
*/

#define assert_param(x)

#include "CAN.h"

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
              FunctionalState CAN_TXFP)
{
    CAN_InitTypeDef CAN_InitStructure;

   CAN_InitStructure.CAN_Prescaler = CAN_Prescaler;
   CAN_InitStructure.CAN_Mode = CAN_Mode;
   CAN_InitStructure.CAN_SJW = CAN_SJW;
   CAN_InitStructure.CAN_BS1 = CAN_BS1;
   CAN_InitStructure.CAN_BS2 = CAN_BS2;
   CAN_InitStructure.CAN_TTCM = CAN_TTCM;
   CAN_InitStructure.CAN_ABOM = CAN_ABOM;
   CAN_InitStructure.CAN_AWUM = CAN_AWUM;
   CAN_InitStructure.CAN_NART = CAN_NART;
   CAN_InitStructure.CAN_RFLM = CAN_RFLM;
   CAN_InitStructure.CAN_TXFP = CAN_TXFP;

    CAN_Init(CANx, &CAN_InitStructure);
}

void init_CANFilter(uint16_t CAN_FilterIdHigh,
                    uint16_t CAN_FilterIdLow,
                    uint16_t CAN_FilterMaskIdHigh,
                    uint16_t CAN_FilterMaskIdLow,
                    uint16_t CAN_FilterFIFOAssignment,
                    uint8_t CAN_FilterNumber,
                    uint8_t CAN_FilterMode,
                    uint8_t CAN_FilterScale,
                    FunctionalState CAN_FilterActivation)
{
   CAN_FilterInitTypeDef CAN_FilterInitStructure;

   CAN_FilterInitStructure.CAN_FilterIdHigh = CAN_FilterIdHigh;
   CAN_FilterInitStructure.CAN_FilterIdLow = CAN_FilterIdLow;
   CAN_FilterInitStructure.CAN_FilterMaskIdHigh = CAN_FilterMaskIdHigh;
   CAN_FilterInitStructure.CAN_FilterMaskIdLow = CAN_FilterMaskIdLow;
   CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FilterFIFOAssignment;
   CAN_FilterInitStructure.CAN_FilterNumber = CAN_FilterNumber;
   CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode;
   CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale;
   CAN_FilterInitStructure.CAN_FilterActivation = CAN_FilterActivation;

   CAN_FilterInit(&CAN_FilterInitStructure);
}

CanTxMsg init_CANTxMessage(uint32_t StdId,
                           uint32_t ExtId,
                           uint8_t IDE,
                           uint8_t RTR,
                           uint8_t DLC,
                           uint8_t Data[8])
{
   CanTxMsg CanTxMsgStructure;

   CanTxMsgStructure.StdId = StdId;
   CanTxMsgStructure.ExtId = ExtId;
   CanTxMsgStructure.IDE = IDE;
   CanTxMsgStructure.RTR = RTR;
   CanTxMsgStructure.DLC = DLC;
   CanTxMsgStructure.Data[8] = Data[8];

   return CanTxMsgStructure;
}

uint32_t get_CANStdId(CanRxMsg* RxMessage)
{
   return RxMessage->StdId;
}

uint32_t get_CANExtId(CanRxMsg* RxMessage)
{
   return RxMessage->ExtId;
}

uint32_t get_CANIDE(CanRxMsg* RxMessage)
{
   return RxMessage->IDE;
}

uint8_t get_CANRTR(CanRxMsg* RxMessage)
{
   return RxMessage->RTR;
}

uint8_t get_CANDLCStdId(CanRxMsg* RxMessage)
{
   return RxMessage->DLC;
}

uint8_t * get_CANData(CanRxMsg* RxMessage)
{
   return RxMessage->Data;
}
