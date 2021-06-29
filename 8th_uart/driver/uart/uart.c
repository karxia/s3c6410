/******************************************************************************
*uart.c
******************************************************************************/
#include "uart.h"

void uart0_init()
{
	GPACON_REG &= ~0xff;
	GPACON_REG |= 0x22;
	
	ULCON0_REG = 0x3;
	UCON0_REG = 0x5;
	UFCON0_REG = 0x01;

	UBRDIV0_REG = 35;
	UDIVSLOT0_REG	= 0x1;

	while(1) putchar("a");
}


void uart1_init()
{
}

void uart2_init()
{
}

void uart3_init()
{
}

char getchar()
{
	while((UFSTAT0_REG & 0x7f)==0);
	return URXH0_REG;
}

void putchar(char c)
{
	while(UFSTAT0_REG & (1<<14));
	UTXH0_REG = c;
}
