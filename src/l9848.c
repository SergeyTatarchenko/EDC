#include "stm32f10x.h"
#include "spi.h"
#include "l9848.h"
#include "delay.h"

void L9848Setup(){

}

uint8_t L9848SetBit( uint8_t Channel, int ChannelNumber){
	uint8_t BitMask = 1;
	for (int i = 0; i < ChannelNumber; ++i){
		BitMask=BitMask<<1;
	}
	Channel |= BitMask;
	return Channel;
}

uint8_t L9848ResetBit(uint8_t Channel, int ChannelNumber){
	uint8_t BitMask = 1;
	for (int i = 0; i < ChannelNumber; ++i){
		BitMask=BitMask<<1;
	}
	Channel &=~ BitMask;
	return Channel;
}

void L9848SetChannel(int ChipNumber,int ChannelNumber){


}

void L9848ResetChannel(int ChipNumber,int ChannelNumber){

}

void test(uint8_t byte){
			uint8_t Channel = L9848SetBit(byte,1);
			CS1HIGH;
			delay(50000UL);
			SPISendByte(Channel);
			while((SPI2->SR & SPI_SR_BSY) != 0);
			delay(50000UL);
			CS1LOW;
}