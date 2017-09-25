#include <stdint.h>
#include "i2c.h"
#include "lcd1602.h"
#include "delay.h"

uint8_t LCD_ADRESS = 0x4E;
uint8_t Command0[]={0x34,0x30};
uint8_t Command1_1[]={0x24,0x20};
uint8_t Command1[]={0x24,0x20,0x84,0x80};
uint8_t Command2[]={0x04,0x00,0x64,0x60};
uint8_t Command3[]={0x04,0x00,0xC4,0xC0};
uint8_t Command4[]={0x04,0x00,0x14,0x10};
uint8_t Command4_1[]={0x0C,0x08,0x1C,0x18};
uint8_t Command5[]={0x04,0x00,0x04,0x00};
uint8_t Command6[]={0x14,0x10,0x44,0x40};
uint8_t Command7[]={0xCC,0xC8,0x7C,0x78};

uint8_t _S_[]={0x5D,0x59,0x3D,0x39};
uint8_t _H_[]={0x4D,0x49,0x8D,0x89};
uint8_t _O_[]={0x4D,0x49,0xFD,0xF9};
uint8_t _R_[]={0x5D,0x59,0x2D,0x29};
uint8_t _T_[]={0x5D,0x59,0x4D,0x49};
uint8_t _C_[]={0x4D,0x49,0x3D,0x39};
uint8_t _I_[]={0x4D,0x49,0x9D,0x99};
uint8_t _U_[]={0x5D,0x59,0x5D,0x59};
uint8_t _N_[]={0x4D,0xE9,0xED,0xE9};
uint8_t _K_[]={0x4D,0x49,0xBD,0xB9};
uint8_t SP_[]={0x2D,0x29,0x0D,0x09};
uint8_t _A_[]={0x4D,0x49,0x1D,0x19};
uint8_t _1_[]={0x3D,0x39,0x1D,0x19};
uint8_t _2_[]={0x3D,0x39,0x2D,0x29};
uint8_t _3_[]={0x3D,0x39,0x3D,0x39};
uint8_t _4_[]={0x3D,0x39,0x4D,0x49};
uint8_t _5_[]={0x3D,0x39,0x5D,0x59};
uint8_t _6_[]={0x3D,0x39,0x6D,0x69};
uint8_t _7_[]={0x3D,0x39,0x7D,0x79};
uint8_t _8_[]={0x3D,0x39,0x8D,0x89};
uint8_t _9_[]={0x3D,0x39,0x9D,0x99};
uint8_t _0_[]={0x3D,0x39,0x0D,0x09};
uint8_t _P_[]={0x5D,0x59,0x0D,0x09};



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

void LCDSendOkMessage(){
	pointer=Command7;
	LCDSendWord(pointer);
	pointer=_O_;
	LCDSendWord(pointer);
	pointer=_K_;
	LCDSendWord(pointer);
		
}

void LCDSendErrorMessage(){
	pointer=_S_;
	LCDSendWord(pointer);
	pointer=_H_;
	LCDSendWord(pointer);
	pointer=_O_;
	LCDSendWord(pointer);
	pointer=_R_;
	LCDSendWord(pointer);
	pointer=_T_;
	LCDSendWord(pointer);
	pointer=SP_;
	LCDSendWord(pointer);
	pointer=_C_;
	LCDSendWord(pointer);
	pointer=_I_;
	LCDSendWord(pointer);
	pointer=_R_;
	LCDSendWord(pointer);
	pointer=_C_;
	LCDSendWord(pointer);
	pointer=_U_;
	LCDSendWord(pointer);
	pointer=_I_;
	LCDSendWord(pointer);
	pointer=_T_;
	LCDSendWord(pointer);
	pointer=SP_;
	LCDSendWord(pointer);
	pointer=_O_;
	LCDSendWord(pointer);
	pointer=_N_;
	LCDSendWord(pointer);
	pointer=Command7;
	LCDSendWord(pointer);
	pointer=_P_;
	LCDSendWord(pointer);
	pointer=_1_;
	LCDSendWord(pointer);
}

void LCDClearDisplay(){
	pointer=Command4_1;
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



