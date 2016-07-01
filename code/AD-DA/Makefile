
# Put your stlink folder here so make burn will work.
STLINK=~/stlink

STM_COMMON=../STM32F4-Discovery_FW_V1.1.0
PERIPHFILES=$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src
SUPPORTFILES=../support_files

# Put your source files here (or *.c, etc)
SRCS = main.c system_stm32f4xx.c
SRCS+= $(SUPPORTFILES)/DAC.c $(SUPPORTFILES)/ADC.c
SRCS+= $(PERIPHFILES)/stm32f4xx_dac.c $(PERIPHFILES)/stm32f4xx_adc.c $(PERIPHFILES)/stm32f4xx_rcc.c
SRCS+= $(PERIPHFILES)/stm32f4xx_tim.c $(PERIPHFILES)/stm32f4xx_gpio.c $(PERIPHFILES)/misc.c

# Binaries will be generated with this name (.elf, .bin, .hex, etc)
PROJ_NAME=timer


# Normally you shouldn't need to change anything below this line!
#######################################################################################

CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

CFLAGS  = -g -O2 -Wall -Tstm32_flash.ld 
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -I.
CFLAGS += -I$(SUPPORTFILES)

# Include files from STM libraries
CFLAGS += -I$(STM_COMMON)/Utilities/STM32F4-Discovery
CFLAGS += -I$(STM_COMMON)/Libraries/CMSIS/Include -I$(STM_COMMON)/Libraries/CMSIS/ST/STM32F4xx/Include
CFLAGS += -I$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/inc

# add startup file to build
SRCS += $(STM_COMMON)/Libraries/CMSIS/ST/STM32F4xx/Source/Templates/TrueSTUDIO/startup_stm32f4xx.s 
OBJS = $(SRCS:.c=.o)


.PHONY: proj

all: proj

proj: $(PROJ_NAME).elf

$(PROJ_NAME).elf: $(SRCS)
	$(CC) -DUSE_STDPERIPH_DRIVER $(CFLAGS) $^ -o $@ 
	#$(OBJCOPY) -O ihex $(PROJ_NAME).elf $(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin
	rm -f $(PROJ_NAME).elf

clean:
	rm -f *.o $(PROJ_NAME).elf $(PROJ_NAME).hex $(PROJ_NAME).bin

# Flash the STM32F4
burn: proj
	$(STLINK)/st-flash write $(PROJ_NAME).bin 0x8000000
