void delay(int count)
{
	volatile int i = count;
	while(i--);
}


#define gpkcon (*((volatile unsigned long *)0x7f008800))

#define gpkdat (*((volatile unsigned long *)0x7f008808))

int led_function(int start)
{
	int i = start;

	gpkcon = 0x11110000;
	gpkdat = 0xF0;

	delay(0x100000);

	while(1)
	{
		gpkdat =(~(i<<4));
		i++;
		if(i==16)
			i = start;
		delay(0x100000);
		gpkdat = 0xF0;
		delay(0x100000);
	}
	return 0;

}
