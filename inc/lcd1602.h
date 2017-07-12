extern void LCDInit();
extern void delay(unsigned long p);
extern void LCDSendWord(uint8_t *pointer);
extern void LCDSendHalfWord( uint8_t *pointer);
extern void LCDClearDisplay(); 
extern void LCDSendErrorMessage();
extern void LCDSendOkMessage();