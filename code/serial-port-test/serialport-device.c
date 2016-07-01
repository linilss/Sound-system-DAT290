/*
	main.c
*/

#define	assert_param(x)

#include "../stm32f4xx.h"
#include "../support_files/include/USART.h"
#include "../support_files/include/GPIO.h"
#include "../support_files/include/RCC.h"

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
void serieport_print_settings(struct audio_settings *settings);
int serieport_read_settings(struct audio_settings *settings);

int main(void) {
	serieport_init();
	
	struct audio_settings settings;
	settings.equ_freqA = 200;
	settings.equ_freqB = 400;
	settings.equ_band1_vol = 100;
	settings.equ_band2_vol = 100;
	settings.equ_band3_vol = 100;
	settings.echo_delay = 48000 * 2;
	settings.echo_vol_decay = 50;
	
	serieport_print_settings(&settings);
	
	while(1) {
		if (serieport_read_settings(&settings)) {
			serieport_print_settings(&settings);
		}
	}
	return 0;
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

int serieport_read_settings(struct audio_settings *settings) {
	static int id = 0;
	static int value = 0;
	
	while (USART_GetFlagStatus(USART6, USART_FLAG_RXNE) != RESET) {
		unsigned char data = (unsigned char) USART_ReceiveData(USART6);
		write_SCI(USART6, data);
		if (id == 0) {
            if (data >= 'A' && data <= 'G') {
                id = data - 'A' + 1;
		} else {
			if (data == 'Z') {
				switch(id) {
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
			} else if (data >= '0' && data <= '9') {
				value *= 10;
				value += data - '0';
			}
		}
	}
	return 0;
}

/*
    while(1) {
        uint16_t data;
        while(USART_GetFlagStatus(USART6, USART_FLAG_RXNE) == RESET);
        data = USART_ReceiveData(USART6);
        while(USART_GetFlagStatus(USART6, USART_FLAG_TXE) == RESET);
        USART_SendData(USART6, data+1);
    }
*/
