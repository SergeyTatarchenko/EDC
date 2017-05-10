#include <stdint.h>
#include <stdio.h>
#include "stm32f10x.h"
#include "system_stm32f10x.h"
#include "i2c.h"
#include "lcd1602.h"
#include "gpio.h"


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



void main()
{
	int j=0;
	uint8_t LCD_ADRESS = 0x4E;


	SystemInit(); 		// call system configuration 
	GPIOInit();		//general I/O init
	I2CInit();			// I2C2 module init
	LCDInit();			// init LCD  wia I2C
	pointer=_A_;
	LCDSendWord(pointer);

	GPIOC->ODR |= GPIO_ODR_ODR13;	
	while(1);
}

void SPIInit(){
	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN; //SPI2 enable

	// SPI main pins
	GPIOB->CRH |= GPIO_CRH_CNF13_1;		// GPIOB13 alternate function push-pull
	GPIOB->CRH |= GPIO_CRH_MODE13;		// GPIOB13 speed 2 MHz

	GPIOB->CRH |= GPIO_CRH_CNF14_1;		// GPIOB14 input whith pull up
	GPIOB->CRH &=~GPIO_CRH_MODE13;		// GPIOB14 input mode

	GPIOB->CRH |= GPIO_CRH_CNF15_1;		// GPIOB15 alternate function push-pull
	GPIOB->CRH |= GPIO_CRH_MODE15;		// GPIOB15 speed 2 MHz
	/*SCK is PB13, MISO is PB14, MOSI is PB15*/
}
