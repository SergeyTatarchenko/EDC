#include <stdint.h>
#include <stdio.h>
#include "stm32f10x.h"
#include "system_stm32f10x.h"
#include "i2c.h"
#include "lcd1602.h"
#include "gpio.h"
#include "spi.h"
#include "l9848.h"

#define LED_OFF (GPIOC-> ODR |= GPIO_ODR_ODR13)
#define LED_ON (GPIOC-> ODR &= ~GPIO_ODR_ODR13) 

#define BUTTON1 (GPIOA->IDR & GPIO_IDR_IDR7)

void main()
{
	uint8_t LCD_ADRESS = 0x4E;

	/*start prorgam*/
	delay(500000UL);

	SystemInit(); 		// call system configuration
	GPIOInit();			//general I/O init configuration
	/* enable and configure I2C bus  */
	I2CGPIOInit();
	I2CInit();
	/* configure LCD1602 */
	//LCDInit();			// init LCD through I2C (only when I2C is connected)
	/*enable and configure SPI bus */
	SPIGPIOInit();
	SPIInit();
	/*configure switch driver*/
	L9848Setup();
	LED_OFF;
	while(1){			
		if (BUTTON1 == 0) {
		delay(15000UL);
		if (BUTTON1 == 0) {
			GPIOB->ODR |= GPIO_ODR_ODR12;
			delay(10000UL);
			SPISendData(Channels[0]);
			delay(10000UL);
			GPIOB->ODR &= ~GPIO_ODR_ODR12;
			LED_ON;
			while(BUTTON1 == 0);
			}
		}
	}
}
