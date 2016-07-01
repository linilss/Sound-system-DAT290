/*
   I2C.h
*/

#ifndef I2C_H
#define I2C_H

#include "stm32f4xx_i2c.h"

void init_I2C(I2C_TypeDef* I2Cx,
              uint32_t I2C_ClockSpeed,
              uint16_t I2C_Mode,
              uint16_t I2C_DutyCycle,
              uint16_t I2C_OwnAddress1,
              uint16_t I2C_Ack,
              uint16_t I2C_AcknowledgedAddress);

//** init_I2C **
//-- I2Cx --
//   I2C1
//   I2C2
//   I2C3

//-- I2C_ClockSpeed --
//-- I2C_clock_speed --
//   1 - 400000 Hz

//-- I2C_Mode --
//   I2C_Mode_I2C
//   I2C_Mode_SMBusDevice
//   I2C_Mode_SMBusHost

//-- I2C_DutyCycle --
//--  I2C_duty_cycle_in_fast_mode --
//   I2C_DutyCycle_16_9 - I2C fast mode Tlow/Thigh = 16/9
//   I2C_DutyCycle_2 I2C fast mode Tlow/Thigh = 2

//-- I2C_OwnAddress1 --
//-- I2C_own_address1 --
//   <= 0x3FF

//-- I2C_Ack --
//-- I2C_acknowledgement --
//   I2C_Ack_Enable
//   I2C_Ack_Disable

//-- I2C_AcknowledgedAddress --
//-- I2C_acknowledged_address --
//   I2C_AcknowledgedAddress_7bit
//   I2C_AcknowledgedAddress_10bit

//*****************************************************************
//** Definitions for other functions **
//-- I2C_transfer_direction --
//   I2C_Direction_Transmitter
//   I2C_Direction_Receiver

//-- I2C registers --
//   I2C_Register_CR1
//   I2C_Register_CR2
//   I2C_Register_OAR1
//   I2C_Register_OAR2
//   I2C_Register_DR
//   I2C_Register_SR1
//   I2C_Register_SR2
//   I2C_Register_CCR
//   I2C_Register_TRISE

//-- I2C_NACK_position --
//   I2C_NACKPosition_Next
//   I2C_NACKPosition_Current

//-- I2C_SMBus_alert_pin_level --
//   I2C_SMBusAlert_Low
//   I2C_SMBusAlert_High

//-- I2C_PEC_position --
//   I2C_PECPosition_Next
//   I2C_PECPosition_Current

//-- I2C_interrupts_definition --
//   I2C_IT_BUF
//   I2C_IT_EVT
//   I2C_IT_ERR

//-- ADC_injected_channel_selection --
//   ADC_InjectedChannel_1
//   ADC_InjectedChannel_2
//   ADC_InjectedChannel_3
//   ADC_InjectedChannel_4

//-- ADC_analog_watchdog_selection --
//   ADC_AnalogWatchdog_SingleRegEnable
//   ADC_AnalogWatchdog_SingleInjecEnable
//   ADC_AnalogWatchdog_SingleRegOrInjecEnable)
//   ADC_AnalogWatchdog_AllRegEnable
//   ADC_AnalogWatchdog_AllInjecEnable
//   ADC_AnalogWatchdog_AllRegAllInjecEnable
//   ADC_AnalogWatchdog_None

//-- ADC_interrupts_definition --
//   ADC_IT_EOC
//   ADC_IT_AWD
//   ADC_IT_JEOC
//   ADC_IT_OVR
//   I2C_IT_SMBALERT
//   I2C_IT_TIMEOUT
//   I2C_IT_PECERR
//   I2C_IT_OVR
//   I2C_IT_AF
//   I2C_IT_ARLO
//   I2C_IT_BERR
//   I2C_IT_TXE
//   I2C_IT_RXNE
//   I2C_IT_STOPF
//   I2C_IT_ADD10
//   I2C_IT_BTF
//   I2C_IT_ADDR
//   I2C_IT_SB

//-- SR2 register flags --
//   I2C_FLAG_DUALF
//   I2C_FLAG_SMBHOST
//   I2C_FLAG_SMBDEFAULT
//   I2C_FLAG_GENCALL
//   I2C_FLAG_TRA
//   I2C_FLAG_BUSY
//   I2C_FLAG_MSL

//-- SR1 register flags --
//   I2C_FLAG_SMBALERT
//   I2C_FLAG_TIMEOUT
//   I2C_FLAG_PECERR
//   I2C_FLAG_OVR
//   I2C_FLAG_AF
//   I2C_FLAG_ARLO
//   I2C_FLAG_BERR
//   I2C_FLAG_TXE
//   I2C_FLAG_RXNE
//   I2C_FLAG_STOPF
//   I2C_FLAG_ADD10
//   I2C_FLAG_BTF
//   I2C_FLAG_ADDR
//   I2C_FLAG_SB

//** I2C Master Events **
//-- Communication start --
//   I2C_EVENT_MASTER_MODE_SELECT

//-- Address Acknowledge --
//   I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED
//   I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED
//   I2C_EVENT_MASTER_MODE_ADDRESS10

//-- Communication events --
//!! Master RECEIVER mode !!
//   I2C_EVENT_MASTER_BYTE_RECEIVED
//!! Master TRANSMITTER mode !!
//   I2C_EVENT_MASTER_BYTE_TRANSMITTING
//   I2C_EVENT_MASTER_BYTE_TRANSMITTED

//** I2C Slave Events **
//-- Communication start events --
//!! Single address managed by th slave !!
//   I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED
//   I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED
//!! Dual address managed by th slave !!
//   I2C_EVENT_SLAVE_RECEIVER_SECONDADDRESS_MATCHED
//   I2C_EVENT_SLAVE_TRANSMITTER_SECONDADDRESS_MATCHED
//!! General Call enabled for the slave !!
//   I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED

//-- Communication events --
//!! Slave RECEIVER mode !!
//   I2C_EVENT_SLAVE_BYTE_RECEIVED
//!! Master RECEIVER mode !!
//   I2C_EVENT_SLAVE_STOP_DETECTED
//!! Slave TRANSMITTER mode !!
//   I2C_EVENT_SLAVE_BYTE_TRANSMITTED
//   I2C_EVENT_SLAVE_BYTE_TRANSMITTING
//   I2C_EVENT_SLAVE_ACK_FAILURE

#endif
