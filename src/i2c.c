#include "stm32f10x.h"
#include "i2c.h"

extern uint32_t clock = 10000000UL; //PLL freq 
extern uint32_t I2C_speed = 100000UL; // 100 KHz I2C speed

void I2CSendData(uint8_t adress, uint8_t data){
	I2CSendStart();			// send START bit begin transmittion
	I2CSendAdress(adress);	// send slave adress
	I2CSendByte(data);		// send data to slave
	I2CSendStop();			// send STOP bit, end of transmittion  

}

void I2CSendStart(){
	I2C2->CR1 |= I2C_CR1_START; //send start bit
	while((I2C2->SR1 & I2C_SR1_SB) == 0); 
}

void I2CSendAdress(uint8_t adress){
	(void) I2C2->SR1;
	I2C2->DR = adress;
	while(!(I2C2->SR1 & I2C_SR1_ADDR));
	(void) I2C2->SR1;
	(void) I2C2->SR2;
}

void I2CSendByte(uint8_t byte){
	I2C2->DR = byte;
	while(!(I2C2->SR1 & I2C_SR1_BTF));
}

void I2CSendStop(){
	I2C2->CR1 |= I2C_CR1_STOP;
	while((I2C2->SR1 & I2C_SR2_BUSY)!=0); 
}

void I2CInit(){
	RCC->APB1ENR |= RCC_APB1ENR_I2C2EN; //I2C2 enable

		// I2C pins   
	GPIOB->CRH |= GPIO_CRH_CNF10;		// GPIOB10 alternate function open drain
	GPIOB->CRH |= GPIO_CRH_MODE10_1;	// GPIOB10 speed 2 MHz

	GPIOB->CRH |= GPIO_CRH_CNF11;		// GPIOB11 alternate function open drain
	GPIOB->CRH |= GPIO_CRH_MODE11_1;	// GPIOB11 speed 2 MHz
	/*SCL is PB10 and SDA is PB11*/

	I2C2->CR1 &= (uint32_t)I2C_CR1_SWRST;//I2C reset
	I2C2->CR1 = (uint32_t)0x00;

	I2C2->CR2 = clock/1000000UL;		// Peripheral clock frequency in MHz
	I2C2->CCR &=~I2C_CCR_CCR;
	I2C2->CCR |= clock/I2C_speed;		// I2C speed 100KHz Sm Mode
	I2C2->TRISE = clock/1000000UL+1;

	I2C2->CR1 |= I2C_CR1_PE;			// enable I2C2 
}
