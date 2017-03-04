#include "stm32f10x.h"
#include "system.h"

#define RCC_CFGR_PLLSRC_HSE ((uint32_t)0x08)


uint32_t SystemCounter =0, HSEStatus=0; 

void SystemInit(void) {
	
	RCC->CFGR &= (uint32_t)0xf0ff0000;
	RCC->CR &= (uint32_t)0xfef6ffff;
	RCC->CR &= (uint32_t)0xFFFBFFFF;
	RCC->CFGR &= (uint32_t)0xFF80FFFF;
	RCC->CIR = 0x009F0000;
	RCC->CFGR2 = 0x00000000;
	RCC->CR|=(uint32_t)RCC_CR_HSEON; 
	do
		{
			HSEStatus=RCC->CR & RCC_CR_HSERDY;
			SystemCounter++;
		}
	while((HSEStatus==0) && (SystemCounter!= HSEStartUp_TimeOut));
	if((RCC->CR & RCC_CR_HSERDY)!= RESET)
		{
			HSEStatus=0x01;
		}
	else
		{
			HSEStatus=0x00;
		}
	if(HSEStatus == (uint32_t)0x01)
		{
			FLASH->ACR |= FLASH_ACR_PRFTBE;
			
			FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
			FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_0;
			
			RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
			RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;
			RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
			
			RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
			RCC->CFGR |= (uint32_t)RCC_CFGR_SW_HSE;    

    /* Wait till HSE is used as system clock source */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x04)
    {
    }
			  
			
		}
} 

