########################################################################
CC=/usr/local/gcc-arm-none-eabi-6_2-2016q4/bin/arm-none-eabi-gcc
LD=/usr/local/gcc-arm-none-eabi-6_2-2016q4/bin/arm-none-eabi-gcc
CP=/usr/local/gcc-arm-none-eabi-6_2-2016q4/bin/arm-none-eabi-objcopy
########################################################################
LDSCRIPT=-T/home/sergey/workspace/projects/EDC_Diagnostic_Tool/software/stm32_flash.ld
########################################################################
INC+=-I/home/sergey/workspace/projects/EDC_Diagnostic_Tool/software/inc
SRC+=/home/sergey/workspace/projects/EDC_Diagnostic_Tool/software/src/main.c
SRC+=/home/sergey/workspace/projects/EDC_Diagnostic_Tool/software/src/system_stm32f10x.c
SRC+=/home/sergey/workspace/projects/EDC_Diagnostic_Tool/software/src/i2c.c
SRC+=/home/sergey/workspace/projects/EDC_Diagnostic_Tool/software/src/lcd1602.c
SRC+=/home/sergey/workspace/projects/EDC_Diagnostic_Tool/software/src/gpio.c
SRC+=/home/sergey/workspace/projects/EDC_Diagnostic_Tool/software/src/spi.c
SRC+=/home/sergey/workspace/projects/EDC_Diagnostic_Tool/software/src/l9848.c
ASM+=/home/sergey/workspace/projects/EDC_Diagnostic_Tool/software/src/startup_stm32f10x_md_vl.s
#######################################################################
OBJ=$(SRC:%.c=%.o)
OBJ+=$(ASM:%.s=%.o)
#######################################################################
CFLAGS += -mcpu=cortex-m3 
CFLAGS += -mlittle-endian
CFLAGS += -mthumb
CFLAGS += -Os
CFLAGS += $(INC)
LDFLAGS += -mcpu=cortex-m3
LDFLAGS += -mlittle-endian
LDFLAGS += -mthumb
LDFLAGS += $(LDSCRIPT)
LDFLAGS += -Wl,-gc-sections

######################################################################
all: start
	@echo "\n"
	@echo "COMPILATION COMPLETE"

start: main.elf
	@echo "\n"
	@echo "OUT"
	@echo "********************************************************"
	$(CP) -Oihex main.elf main.hex 
	@echo "********************************************************"

main.elf: $(OBJ)
	@echo "\n"
	@echo "LINK"
	@echo "********************************************************"
	$(LD) $(LDFLAGS) $(OBJ) -o main.elf
	@echo "********************************************************"

%.o: %.c
	@echo "\n"
	@echo "COMPILE C"
	@echo "********************************************************"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "********************************************************"

%.o: %.s
	@echo "\n"
	@echo "COMPILE S"
	@echo "********************************************************"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "********************************************************"
	

