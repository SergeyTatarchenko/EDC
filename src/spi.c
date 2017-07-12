#include "stm32f10x.h"
#include "spi.h"


void SPIInit() {

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