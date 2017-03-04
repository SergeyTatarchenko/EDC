#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "system.h"
void main(void)
{
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);


	
	GPIO_InitTypeDef  ledinit;
	ledinit.GPIO_Mode = GPIO_Mode_Out_PP;
	ledinit.GPIO_Speed = GPIO_Speed_2MHz;
	ledinit.GPIO_Pin = GPIO_Pin_All; 
	GPIO_Init(GPIOC, &ledinit);
	if((RCC->CR & RCC_CR_HSERDY)!=(uint32_t)0x00){
	GPIO_SetBits  (GPIOC,GPIO_Pin_13);
	}	
	while(1){}
}

