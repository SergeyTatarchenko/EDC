#include "stm32f10x.h"
#include "spi.h"
#include "l9848.h"

uint8_t Channels[8]={0};

void L9848Setup(){

	uint8_t number = 0x01;
	for (int i = 0; i < 6; ++i)
	{
		Channels[i]=number;
		number = number*2;
	}
}
