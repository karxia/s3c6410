/******************************************************************************
*uart.c
******************************************************************************/
#include "config.h"
#include "uart.h"

#ifdef DIR_CONFIG_UART0
void uart0_init()
{
	GPACON_REG &= ~0xff;
	GPACON_REG |= 0x22;
	
	ULCON0_REG = 0x3;
	UCON0_REG = 0x5;
	UFCON0_REG = 0x01;

	UBRDIV0_REG = 35;
	UDIVSLOT0_REG	= 0x1;

}
#endif

#ifdef DIR_CONFIG_UART1
void uart1_init()
{	
	GPACON_REG &=0xff0000;
	GPACON_REG |=0x220000;

	ULCON1_REG = 0x3;
	UCON1_REG  = 0x5;
	UFCON1_REG = 0x01;

	UBRDIV1_REG = 35;
	UDIVSLOT1_REG = 0x1;	
}
#endif


#ifdef DIR_CONFIG_UART2
void uart2_init()
{
	
	GPBCON_REG &=0xff;
	GPBCON_REG |=0x22;

	ULCON2_REG = 0x3;
	UCON2_REG  = 0x5;
	UFCON2_REG = 0x01;


	UBRDIV2_REG = 35;
	UDIVSLOT2_REG = 0x1;	
}
#endif


#ifdef DIR_CONFIG_UART3
void uart3_init()
{
}
#endif

void uart_init()
{
	#ifdef DIR_CONFIG_UART0
		uart0_init();
	#elif defined DIR_CONFIG_UART1
		uart1_init();
	#elif defined DIR_CONFIG_UART2
		uart2_init();
	#elif defined DIR_CONFIG_UART3
		uart3_init();
	#endif 
}



unsigned char getc(void)
{
	#ifdef DIR_CONFIG_UART0 
	while((UFSTAT0_REG & 0x7f)==0);
	return URXH0_REG;
	#endif

	#ifdef DIR_CONFIG_UART1 
	while((UFSTAT1_REG & 0x7f)==0);
	return URXH1_REG;
	#endif

	#ifdef DIR_CONFIG_UART2 
	while((UFSTAT2_REG & 0x7f)==0);
	return URXH2_REG;
	#endif

	#ifdef DIR_CONFIG_UART3 
	while((UFSTAT3_REG & 0x7f)==0);
	return URXH3_REG;
	#endif
}

void putc(unsigned char c)
{
	#ifdef DIR_CONFIG_UART0 
	while(UFSTAT0_REG & (1<<14));
	UTXH0_REG = c;
	#endif

	#ifdef DIR_CONFIG_UART1 
	while(UFSTAT1_REG & (1<<14));
	UTXH1_REG = c;
	#endif

	#ifdef DIR_CONFIG_UART2 
	while(UFSTAT2_REG & (1<<14));
	UTXH2_REG = c;
	#endif

	#ifdef DIR_CONFIG_UART3 
	while(UFSTAT3_REG & (1<<14));
	UTXH3_REG = c;
	#endif

}
