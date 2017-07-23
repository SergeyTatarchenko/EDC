#
#
# makefile for stm32f103c8t6
#
# \|/ project tree \|/
# \/				       \/
#	src
#		*.c
#		*.s
#	inc
#		*.h
#	Makefile
#	stm32_flash.ld
#-------------------------------------------------------------------
CC=/usr/local/gcc-arm-none-eabi-6_2-2016q4/bin/arm-none-eabi-gcc
LD=/usr/local/gcc-arm-none-eabi-6_2-2016q4/bin/arm-none-eabi-gcc
CP=/usr/local/gcc-arm-none-eabi-6_2-2016q4/bin/arm-none-eabi-objcopy
#-------------------------------------------------------------------
source_dirs:= src
include_dirs:= inc
LDSCRIPT=-Tstm32_flash.ld
#-------------------------------------------------------------------
VPATH := $(source_dirs)
search_wildcards_c:= $(addsuffix /*.c, $(source_dirs))
search_wildcards_s:= $(addsuffix /*.s, $(source_dirs))
source_files_c:= $(wildcard $(search_wildcards_c))
source_files_s:= $(wildcard $(search_wildcards_s))
source_files += $(source_files_c)
source_files += $(source_files_s)
object_files =  $(source_files_c:.c=.o)
object_files += $(source_files_s:.s=.o)
include := $(addprefix -I,$(include_dirs))
#-------------------------------------------------------------------
CFLAGS += -mcpu=cortex-m3
CFLAGS += -mlittle-endian
CFLAGS += -mthumb
CFLAGS += -Os
CFLAGS += $(include)
CFLAGS += -c
#-------------------------------------------------------------------
LDFLAGS += -mcpu=cortex-m3
LDFLAGS += -mlittle-endian
LDFLAGS += -mthumb
LDFLAGS += $(LDSCRIPT)
LDFLAGS += -Wl,-gc-sections
#-------------------------------------------------------------------


target: program
	@echo "MAKE COMPLETE"
	rm $(notdir $(object_files)) edc.elf

program: edc.elf
	$(CP) -Oihex edc.elf edc.hex

edc.elf: $(object_files)
	@echo "LINKING"
	$(LD) $(LDFLAGS) $(notdir $(object_files)) -o edc.elf
.c.o:
	$(CC) $(CFLAGS) -c $<
.s.o:
	$(CC) $(CFLAGS) -c $<
#-------------------------------------------------------------------
