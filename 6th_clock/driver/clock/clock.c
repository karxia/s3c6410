/***************************************************
*clock.c
***************************************************/

#include"clock.h"

void clock_init(){

//setting the lock time
	APLL_LOCK_REG = 0x0000FFFF;
	MPLL_LOCK_REG = 0x0000FFFF;
	EPLL_LOCK_REG = 0x0000FFFF;

//setting async mode
	OTHERS_REG &= ~0xc0;
	while((OTERS & 0xf00)!=0);

//setting clock div
	CLK_DIV0_REG = CLV_DIV_VAL;

	APLL_CON_REG = APLL_VAL;
	MPLL_CON_REG = MPLL_VAL;

	CLK_SRC_REG  = 0x03:
	


}
