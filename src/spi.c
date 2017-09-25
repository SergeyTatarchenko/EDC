#include "stm32f10x.h"
#include "spi.h"

#define CS1HIGH (GPIOB-> BSRR = GPIO_BSRR_BS12)
#define CS1LOW 	(GPIOB-> BSRR = GPIO_BSRR_BR12)


void SPIGPIOInit(){

	// SPI main pins
	GPIOB->CRH |= GPIO_CRH_MODE13_1; 	// GPIOB13 speed 2 MHz
	GPIOB->CRH |= GPIO_CRH_CNF13_1;		// GPIOB13 alternate function push-pull

	GPIOB->CRH &= ~GPIO_CRH_MODE14;		// GPIOB14 input mode
	GPIOB->CRH |= GPIO_CRH_CNF14_1;		// GPIOB14 input whith pull up
	GPIOB->BSRR = GPIO_BSRR_BS14;

	GPIOB->CRH |= GPIO_CRH_MODE15_1;	// GPIOB15 speed 2 MHz
	GPIOB->CRH |= GPIO_CRH_CNF15_1;		// GPIOB15 alternate function push-pull

	/*SCK is PB13, MISO is PB14, MOSI is PB15*/

	GPIOB->CRH |= GPIO_CRH_MODE12_1 ;	// GPIOB12 speed 2 MHz
	GPIOB->CRH &= ~GPIO_CRH_CNF12 ;		// GPIOB12 output push-pull
	
	// NSS1 pin

}
void SPIInit() {

	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN; //SPI2 enable

	/* SPI master configuration */
	SPI2-> CR1 |= SPI_CR1_BR;		// SPI baud rate is FQ/256
	SPI2-> CR1 &= ~SPI_CR1_CPHA;
	SPI2-> CR1 &= ~SPI_CR1_CPOL;
	SPI2-> CR1 &= ~SPI_CR1_DFF;		// 8 bit data frame
	SPI2-> CR1 |= SPI_CR1_SSI;		// internal slave selects
	SPI2-> CR1 |= SPI_CR1_SSM;		// NSS software management
	
	SPI2-> CR1 |= SPI_CR1_MSTR;		// SPI master mode
	SPI2-> CR1 |= SPI_CR1_SPE;		// SPI emable
}

void SPISendByte (uint8_t byte){
	SPI2-> DR = byte;
	while((SPI2->SR & SPI_SR_TXE) == 0);
	
}
