extern void SPIGPIOInit();
extern void SPIInit();
extern void SPISendByte(uint8_t byte);

#define CS1HIGH (GPIOB-> BSRR = GPIO_BSRR_BS12)
#define CS1LOW 	(GPIOB-> BSRR = GPIO_BSRR_BR12)