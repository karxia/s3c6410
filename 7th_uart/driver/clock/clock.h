/*******************************************************
* clock.h
*
*******************************************************/
#ifndef __CLOCK_H__
#define __CLOCK_H__

#include<hardware.h>

#if defined(CONFIG_CLK_400_100_50)
#define STARTUP_AMDIV		400
#define STARTUP_MDIV		400
#define STARTUP_PDIV		6
#define STARTUP_SDIV		1
#elif defined(CONFIG_CLK_400_133_66)
#define STARTUP_AMDIV		400
#define STARTUP_MDIV		533
#define STARTUP_PDIV		6
#define STARTUP_SDIV		1
#elif defined(CONFIG_CLK_533_133_66)
#define STARTUP_AMDIV		533
#define STARTUP_MDIV		533
#define STARTUP_PDIV		6
#define STARTUP_SDIV		1
#elif defined(CONFIG_CLK_667_133_66)
#define STARTUP_AMDIV		667
#define STARTUP_MDIV		533
#define STARTUP_PDIV		6
#define STARTUP_SDIV		1
#endif

#define	STARTUP_PCLKDIV		3
#define STARTUP_HCLKX2DIV	1
#define STARTUP_HCLKDIV		1
#define STARTUP_MPLLDIV		1
#define STARTUP_APLLDIV		0

#define CLK_DIV_VAL	((STARTUP_PCLKDIV << 12) | (STARTUP_HCLKX2DIV << 9) | \
	(STARTUP_HCLKDIV << 8) | (STARTUP_MPLLDIV<<4) | STARTUP_APLLDIV)
#define MPLL_VAL	((1 << 31) | (STARTUP_MDIV << 16) | \
	(STARTUP_PDIV << 8) | STARTUP_SDIV)
#define STARTUP_MPLL	(((CONFIG_SYS_CLK_FREQ >> STARTUP_SDIV) / \
	STARTUP_PDIV) * STARTUP_MDIV)

#if defined(CONFIG_SYNC_MODE)
#define APLL_VAL	((1 << 31) | (STARTUP_MDIV << 16) | \
	(STARTUP_PDIV << 8) | STARTUP_SDIV)
#define STARTUP_APLL	(((CONFIG_SYS_CLK_FREQ >> STARTUP_SDIV) / \
	STARTUP_PDIV) * STARTUP_MDIV)
#define STARTUP_HCLK	(STARTUP_MPLL / (STARTUP_HCLKX2DIV + 1) / \
	(STARTUP_HCLKDIV + 1))
#else
#define APLL_VAL	((1 << 31) | (STARTUP_AMDIV << 16) | \
	(STARTUP_PDIV << 8) | STARTUP_SDIV)
#define STARTUP_APLL	(((CONFIG_SYS_CLK_FREQ >> STARTUP_SDIV) / \
	STARTUP_PDIV) * STARTUP_AMDIV)
#define STARTUP_HCLK	(STARTUP_MPLL / (STARTUP_HCLKX2DIV + 1) / \
	(STARTUP_HCLKDIV + 1))
#endif

void clock_init();

#endif /*clock.h*/
