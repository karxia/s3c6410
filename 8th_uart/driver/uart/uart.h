/******************************************************************************
*uart.h
******************************************************************************/
#ifndef UART_H
#define UART_H

#include "config.h"
#include "s3c6410.h"

#ifdef DIR_CONFIG_UART0
void uart0_init();
#endif

#ifdef DIR_CONFIG_UAER1
void uart1_init();
#endif

#ifdef DIR_CONFIG_UAER2
void uart2_init();
#endif


#ifdef DIR_CONFIG_UAER3
void uart3_init();
#endif


char getchar(void);

void  putchar(char);


#endif

