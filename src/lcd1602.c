#include <stdint.h>
#include "i2c.h"
#include "lcd1602.h"


uint8_t LCD_ADRESS = 0x4E;
uint8_t Command0[]={0x34,0x30};
uint8_t Command1_1[]={0x24,0x20};
uint8_t Command1[]={0x24,0x20,0x84,0x80};
uint8_t Command2[]={0x04,0x00,0x64,0x60};
uint8_t Command3[]={0x04,0x00,0xC4,0xC0};
uint8_t Command4[]={0x04,0x00,0x14,0x10};
uint8_t Command5[]={0x04,0x00,0x04,0x00};
uint8_t Command6[]={0x14,0x10,0x44,0x40};
uint8_t *pointer;

void LCDInit(){

	delay(1000000UL);
	pointer=Command0;
	LCDSendHalfWord(pointer);
	pointer=Command1_1;
	LCDSendHalfWord(pointer);
	pointer=Command1;
	LCDSendWord(pointer);
	pointer=Command2;
	LCDSendWord(pointer);
	pointer=Command3;
	LCDSendWord(pointer);
	pointer=Command4;
	LCDSendWord(pointer);
	pointer=Command5;
	LCDSendWord(pointer);	
	pointer=Command6;
	LCDSendWord(pointer);
}

void LCDSendHalfWord( uint8_t *pointer){
	int i;
	for (i = 0; i < 2; ++i)
	{
		I2CSendData(LCD_ADRESS,pointer[i]);
	}

	delay(200000UL);
}

void LCDSendWord(uint8_t *pointer){
	int i;
	for (i = 0; i < 4; ++i)
	{
		I2CSendData(LCD_ADRESS,pointer[i]);
	}

	delay(200000UL);
}



void delay(unsigned long p){
	 volatile unsigned long i;			// p=10 000 ~1ms
	for (int i = 0; i < p; ++i);

}