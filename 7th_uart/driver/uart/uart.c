/************************************************
* uart.c
************************************************/
#include "uart.h"
void init_uart(void)
{
	GPACON_REG &= ~0xff;
	GPACON_REG |= 0x22;

	ULCON0_REG = 0x3;
	UCON0_REG  =	0x5;
	UFCON0_REG = 0x01;

	UMCON0_REG = 0;

	UBRDIV0_REG = 35;
	UDIVSLOT0_REG =  0x1;

}

unsigned char getc(void)
{
	while((UFSTAT0_REG &(1<<6)) == 0 && (UFSTAT0_REG & 0x3f)==0);
	return URXH0_REG;
}

void putc(char c)
{
	while(UFSTAT0_REG & (1<<14));
	UTXH0_REG = c;
}

//end uart.c
