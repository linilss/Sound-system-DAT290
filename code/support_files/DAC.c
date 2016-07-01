/*
   DAC.c
*/

//#define assert_param(x)

#include "DAC.h"

//Init DAC
void init_DAC(uint32_t DAC_Channel,
              uint32_t DAC_Trigger,
              uint32_t DAC_WaveGeneration,
              uint32_t DAC_LFSRUnmask_TriangleAmplitude,
              uint32_t DAC_OutputBuffer)
{
   DAC_InitTypeDef DAC_InitStructure; //setup DAC_InitStructure
   DAC_StructInit(&DAC_InitStructure);

   static uint16_t dacDeInitFlag=0;

   if (dacDeInitFlag==0)
   {
      DAC_DeInit();
      dacDeInitFlag=1;
   }

   DAC_InitStructure.DAC_Trigger = DAC_Trigger;
   DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration;
   DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_TriangleAmplitude;
   DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer;

   DAC_Init(DAC_Channel, &DAC_InitStructure);

   DAC_Cmd(DAC_Channel, ENABLE);
}

void DAC_SetChannelData(uint32_t DAC_Channel,
                        uint32_t DAC_Align,
                        uint16_t DAC_Data)
{
   if (DAC_Channel == DAC_Channel_1)
      DAC_SetChannel1Data(DAC_Align, DAC_Data);
   else
      DAC_SetChannel2Data(DAC_Align, DAC_Data);
}