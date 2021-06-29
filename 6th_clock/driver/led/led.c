/**************************************************************
*led.c
**************************************************************/
#include "led.h"

void delay()
{
	volatile int i = 0x10000;
	while(i--);

}

int led_init()
{
	int  i = 0;

	GPKCON0_REG = (GPKCON0_REG & 0x0000ffff) | 0x11110000;
    GPKDAT_REG = (GPKDAT_REG & 0xff0f)|0x50;

	delay();


	while(1)
	{
		GPKDAT_REG = (GPKDAT_REG & 0xff0f) | (i<<4);
	    i++;
		if(i==16) i = 0;
		delay();

	}

	
	return 0;
}

int led_set(int num, int status)
{

	return 0;
}
