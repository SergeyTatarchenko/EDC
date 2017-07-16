#include <stdint.h>
#include <stdio.h>
#include "stm32f10x.h"
#include "system_stm32f10x.h"
#include "i2c.h"
#include "lcd1602.h"
#include "gpio.h"
#include "spi.h"
#include "l9848.h"



void main()
{
	int data = 0x01;
	uint8_t LCD_ADRESS = 0x4E;

	/*start prorgam*/
	delay(500000UL);

	SystemInit(); 		// call system configuration
	GPIOInit();			//general I/O init configuration
	/* enable and configure I2C bus  */
	I2CGPIOInit();
	I2CInit();
	/* configure LCD1602 */
	LCDInit();			// init LCD through I2C
	/*enable and configure SPI bus */	
	SPIGPIOInit();
	SPIInit();
	/*configure switch driver*/
	L9848Setup();

	while(1){

		if(((GPIOA->IDR & GPIO_IDR_IDR7) == 0)) {
		delay(15000UL);
		if((GPIOA->IDR & GPIO_IDR_IDR7) == 0) {
			GPIOB->ODR |= GPIO_ODR_ODR12;
			delay(10000UL);
			SPISendData(Channels[0]);
			delay(10000UL);
			GPIOB->ODR &= ~GPIO_ODR_ODR12;
			GPIOC->ODR |= GPIO_ODR_ODR13;
			while((GPIOA->IDR & GPIO_IDR_IDR7) == 0);
			}	
		}	

	}
}