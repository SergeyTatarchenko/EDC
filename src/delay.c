
void delay(unsigned long p){
	 volatile unsigned long i;			// p=10 000 ~1ms
	for (int i = 0; i < p; ++i);

}