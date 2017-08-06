#include "stm32f10x.h"

void GPIOInit(){
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; // GPIOC clocking ON
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // GPIOA clocking ON
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; // GPIOB clocking ON
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; // Alternate Function I/O clock enable
	
	//reset registers
	GPIOA->CRL &=(uint32_t)0x00;
	GPIOA->CRH &=(uint32_t)0x00;
	GPIOB->CRL &=(uint32_t)0x00;
	GPIOB->CRH &=(uint32_t)0x00;
	GPIOC->CRL &=(uint32_t)0x00;
	GPIOC->CRH &=(uint32_t)0x00;

	//led on PC13 
 	GPIOC->CRH &=~GPIO_CRH_CNF13;		// GPIOC13 output push pull
	GPIOC->CRH |= GPIO_CRH_MODE13_1; 	// GPIOC13 speed 2 MHz
	
	//eror lamp for debug
	GPIOB->CRL &=~GPIO_CRL_CNF1;		// GPIOC13 output push pull
	GPIOB->CRL |= GPIO_CRL_MODE1_1; 	// GPIOC13 speed 2 MHz

	// ADC input pin on PA1
	GPIOA->CRL &=~GPIO_CRL_CNF1;		// GPIOA1 input analog
	GPIOA->CRL &=~GPIO_CRL_MODE1; 		// GPIOA1 input mode 
	
	// ADC multiplexer pins on PA2..PA5
	GPIOA->CRL &=~GPIO_CRL_CNF2;		// GPIOA2 output push pull
	GPIOA->CRL |= GPIO_CRL_MODE2_1; 	// GPIOA2 speed 2 MHz
	
	GPIOA->CRL &=~GPIO_CRL_CNF3;		// GPIOA3 output push pull
	GPIOA->CRL |= GPIO_CRL_MODE3_1; 	// GPIOA3 speed 2 MHz
	
	GPIOA->CRL &=~GPIO_CRL_CNF4;		// GPIOA4 output push pull
	GPIOA->CRL |= GPIO_CRL_MODE4_1; 	// GPIOA4 speed 2 MHz
	
	GPIOA->CRL &=~GPIO_CRL_CNF5;		// GPIOA5 output push pull
	GPIOA->CRL |= GPIO_CRL_MODE5_1; 	// GPIOA5 speed 2 MHz
	
	// control button pins PA0,PA6,PA7
	GPIOA->CRL |= GPIO_CRL_CNF0_1;		// GPIOA0 input whith pull up
	GPIOA->CRL &=~GPIO_CRL_MODE0; 		// GPIOA0 input mode

	GPIOA->CRL |= GPIO_CRL_CNF6_1;		// GPIOA6 input whith pull up
	GPIOA->CRL &=~GPIO_CRL_MODE6; 		// GPIOA6 input mode

	GPIOA->CRL |= GPIO_CRL_CNF7_1;		// GPIOA7 input whith pull up
	GPIOA->CRL &=~GPIO_CRL_MODE7; 		// GPIOA7 input mode

	// source sensors pins
	GPIOB->CRH |= GPIO_CRH_CNF8_1;		// GPIOB8 input floating
	GPIOB->CRH &=~GPIO_CRH_MODE8;		// GPIOB8 input mode

	GPIOB->CRH |= GPIO_CRH_CNF9_1;		// GPIOB9 input floating
	GPIOB->CRH &=~GPIO_CRH_MODE9;		// GPIOB9 input mode
}	
