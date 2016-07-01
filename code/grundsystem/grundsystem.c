#define	assert_param(x)

#include "../stm32f4xx.h"
#include "../support_files/include/USART.h"
#include "../support_files/include/GPIO.h"
#include "../support_files/include/RCC.h"
#include "../support_files/include/ADC.h"
#include "../support_files/include/DAC.h"
#include "../support_files/include/TIM.h"
#include "misc.h"

struct audio_settings {
	int equ_freqA;
	int equ_freqB;
	int equ_band1_vol;
	int equ_band2_vol;
	int equ_band3_vol;
	int echo_delay;
	int echo_vol_decay;
};

void serieport_init(void);
void serieport_print_str(char *str);
void serieport_print_int(int num);
void serieport_print_float(float val);
int serieport_getsettings(struct audio_settings *settings);
void serieport_print_settings(struct audio_settings *settings);
void ad_init();
void da_init();
float ad_readval();
void da_writeval(struct audio_settings *settings, float fval);
void process_sample();
void timer_init();

int main(void) {
	serieport_init();
	ad_init();
	da_init();
	timer_init();
	
	struct audio_settings settings;
	settings.equ_freqA = 200;
	settings.equ_freqB = 400;
	settings.equ_band1_vol = 100;
	settings.equ_band2_vol = 100;
	settings.equ_band3_vol = 100;
	settings.echo_delay = 48000 * 2;
	settings.echo_vol_decay = 50;
	
	serieport_print_settings(&settings);
		
	unsigned int value;
	
	while(1) {
		if (serieport_getsettings(&settings) == 1) {
			serieport_print_settings(&settings);
		}

	}
	return 0;
}

void TIM2_IRQHandler() {
	static float val = -1;
	struct audio_settings settings;
	
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		
		float sample = ad_readval();
		da_writeval(&settings, sample);
    }
}


float ad_readval() {
	ADC_SoftwareStartConv(ADC1);
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
	int ival = ADC_GetConversionValue(ADC1);
	float fval = (float) (ival - 2048) / 2048.0;
	return fval;
}

void da_writeval(struct audio_settings *settings, float fval) {
	int ival = (int) (fval * 2048.0) + 2048;
	if (ival < 0) { ival = 0; }
	else if (ival > 4095) { ival = 4095; }
	DAC_SetChannelData(DAC_Channel_1, DAC_Align_12b_R, ival);
}

void serieport_print_settings(struct audio_settings *settings) {
	serieport_print_str("\r\n");
	
	serieport_print_str("Frekvensband 1: 0 - ");
	serieport_print_int(settings->equ_freqA);
	serieport_print_str(" hz, volym ");
	serieport_print_int(settings->equ_band1_vol);
	serieport_print_str(".\r\n");
	
	serieport_print_str("Frekvensband 2: ");
	serieport_print_int(settings->equ_freqA);
	serieport_print_str(" - ");
	serieport_print_int(settings->equ_freqB);
	serieport_print_str(" hz, volym ");
	serieport_print_int(settings->equ_band2_vol);
	serieport_print_str(".\r\n");

	serieport_print_str("Frekvensband 3: ");
	serieport_print_int(settings->equ_freqB);
	serieport_print_str(" - 24000 hz, volym ");
	serieport_print_int(settings->equ_band3_vol);
	serieport_print_str(".\r\n");
	
	serieport_print_str("Eko-effekt: Delay ");
	serieport_print_int(settings->echo_delay);
	serieport_print_str(", volymminskning ");
	serieport_print_int(settings->echo_vol_decay);
	serieport_print_str(".\r\n");
}

void serieport_init(void) {
	RCC_PeriphClockCmd(RCC_USART6, ENABLE);
	RCC_PeriphClockCmd(RCC_GPIOC, ENABLE);
    init_GPIO(GPIOC, GPIO_Pin_6 | GPIO_Pin_7, GPIO_Mode_AF, GPIO_Fast_Speed, GPIO_OType_PP, GPIO_PuPd_UP);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);
	init_SCI(USART6, 9600, USART_WordLength_8b, USART_StopBits_1, USART_Parity_No, USART_Mode_Rx | USART_Mode_Tx, USART_HardwareFlowControl_None);
}

void serieport_print_str(char *str) {
	while (*str != '\0') {
		write_SCI(USART6, *str);
		str++;
	}
}

void serieport_print_float(float val) {
	int ival_whole = (int) val;
	serieport_print_int(ival_whole);
	serieport_print_str(".");
	int ival_frac = (val * 10000) - ival_whole;
	serieport_print_int(ival_frac);
}

void serieport_print_int(int num) {
	if (num == 0) {
		write_SCI(USART6, '0');
		return;
	} else if (num < 0) {
		write_SCI(USART6, '-');
		num = -num;
	}
	
	char buf[32];
	int i=0, j=0;
	while (num != 0 && i < 32) {
		int rem = num % 10;
		buf[i++] = '0' + rem;
		num /= 10;
	}
	for (j = i-1; j >= 0; j--) {
		write_SCI(USART6, buf[j]);
	}
}

int serieport_getsettings(struct audio_settings *settings) {
	static int id = 0;
	static int value = 0;
	
	if (USART_GetFlagStatus(USART6, USART_FLAG_RXNE) != RESET) {
		unsigned char data = (unsigned char) USART_ReceiveData(USART6);
		write_SCI(USART6, data);
		if (id == 0 && data >= 'A' && data <= 'G') {
			id = data - 'A' + 1;
		} else if (id > 0 && data == 'Z') {
			switch (id) {
				case 1:
					settings->equ_freqA = value;
					break;
				case 2:
					settings->equ_freqB = value;
					break;
				case 3:
					settings->equ_band1_vol = value;
					break;
				case 4:
					settings->equ_band2_vol = value;
					break;
				case 5:
					settings->equ_band3_vol = value;
					break;
				case 6:
					settings->echo_delay = value;
					break;
				case 7:
					settings->echo_vol_decay = value;
					break;
			}
			id = 0;
			value = 0;
			return 1;
		} else if (id > 0 && data >= '0' && data <= '9') {
			value *= 10;
			value += data - '0';
		}
	}
	return 0;
}

void ad_init() {
	RCC_PeriphClockCmd(RCC_ADC1, ENABLE);
	RCC_PeriphClockCmd(RCC_GPIOC, ENABLE);
	
	init_GPIO(GPIOC, GPIO_Pin_0, GPIO_Mode_AN, GPIO_Fast_Speed, GPIO_OType_PP, GPIO_PuPd_NOPULL);
	initCommon_ADC(ADC_Mode_Independent, ADC_Prescaler_Div2, ADC_DMAAccessMode_Disabled, ADC_TwoSamplingDelay_5Cycles);
	init_ADC(ADC_Resolution_12b, DISABLE, ENABLE, ADC_ExternalTrigConvEdge_None, ADC_ExternalTrigConv_T1_CC1, ADC_DataAlign_Right, 1);
	ADC_Cmd(ADC1,ENABLE);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_144Cycles);
}

void da_init() {
	RCC_PeriphClockCmd(RCC_DAC, ENABLE);
	init_DAC(DAC_Channel_1, DAC_Trigger_None, DAC_WaveGeneration_None, 0, DAC_OutputBuffer_Enable);
}

void timer_init() {
	RCC_PeriphClockCmd(RCC_TIM2, ENABLE);
	
	TIM_TimeBaseInitTypeDef timerInitStructure;
	timerInitStructure.TIM_Prescaler = 175-1;
	timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	timerInitStructure.TIM_Period = 10-1;
	timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	timerInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &timerInitStructure);
	TIM_Cmd(TIM2, ENABLE);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	NVIC_InitTypeDef nvicStructure;
	nvicStructure.NVIC_IRQChannel = TIM2_IRQn;
	nvicStructure.NVIC_IRQChannelPreemptionPriority = 0;
	nvicStructure.NVIC_IRQChannelSubPriority = 1;
	nvicStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvicStructure);
}
