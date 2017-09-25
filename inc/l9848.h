extern void L9848Setup();
extern uint8_t L9848SetBit(uint8_t Channel, int ChannelNumber);
extern uint8_t L9848ResetBit(uint8_t Channel, int ChannelNumber);
extern void L9848SetChannel(int ChipNumber,int ChannelNumber);
extern void L9848ResetChannel(int ChipNumber,int ChannelNumber);
extern uint8_t ChannelsStatus;
extern void test(uint8_t byte);