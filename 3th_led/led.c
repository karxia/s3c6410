void delay()
{
	volatile int i = 0x100000;
	while(i--);
}

int led_function()
{
	int i = 0;
	volatile unsigned long *gpkcon = (volatile unsigned long *)0x7F008800;
	volatile unsigned long *gpkdat = (volatile unsigned long *)0x7F008808;

	*gpkcon = 0x11110000;
	*gpkdat = 0xF0;

	delay();

	while(1)
	{
		*gpkdat =(~(i<<4));
		i++;
		if(i==16)
			i = 0;
		delay();
		*gpkdat = 0xF0;
		delay();
	}
	return 0;

}
