void delay(int count)
{
	volatile int i = count;
	while(i--);
}

int led_function(int start)
{
	int i = start;
	volatile unsigned long *gpkcon = (volatile unsigned long *)0x7F008800;
	volatile unsigned long *gpkdat = (volatile unsigned long *)0x7F008808;

	*gpkcon = 0x11110000;
	*gpkdat = 0xF0;

	delay(0x100000);

	while(1)
	{
		*gpkdat =(~(i<<4));
		i++;
		if(i==16)
			i = start;
		delay(0x100000);
		*gpkdat = 0xF0;
		delay(0x100000);
	}
	return 0;

}
