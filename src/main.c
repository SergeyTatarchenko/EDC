#include <stdint.h>
#include <stdio.h>
#include "stm32f10x.h"
#include "system_stm32f10x.h"
#include "i2c.h"
#include "lcd1602.h"
#include "gpio.h"
#include "spi.h"

void Test();


void main()
{
	int TestComplete;
	uint8_t LCD_ADRESS = 0x4E;


	SystemInit(); 		// call system configuration 
	GPIOInit();			//general I/O init
	I2CInit();			// I2C2 module init
	LCDInit();			// init LCD  wia I2C	

	GPIOC->ODR |= GPIO_ODR_ODR13;

	while(1){
		



	}
}

void Test(){
	if((GPIOB->IDR & (uint16_t)GPIO_IDR_IDR9) != 0) {
		LCDSendErrorMessage();
	}
	if((GPIOB->IDR & (uint16_t)GPIO_IDR_IDR9) == 0) {
		LCDSendOkMessage();
	}
		
}
/*// test 
		if(((GPIOA->IDR & GPIO_IDR_IDR7) == 0) && TestComplete == 0 ) {
		delay(15000UL);
		if(((GPIOA->IDR & GPIO_IDR_IDR7) == 0) && TestComplete == 0 ) {
			Test();
			TestComplete=1;
			while((GPIOA->IDR & GPIO_IDR_IDR7) == 0);
			}	
		}	
		// reset
		if(((GPIOA->IDR & GPIO_IDR_IDR6) == 0) && TestComplete == 1 ) {
		delay(15000UL);
		if(((GPIOA->IDR & GPIO_IDR_IDR6) == 0) && TestComplete == 1 ) {
			LCDClearDisplay();
			TestComplete=0;
			while((GPIOA->IDR & GPIO_IDR_IDR6) == 0);
			}
		}	
*/