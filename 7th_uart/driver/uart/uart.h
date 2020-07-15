/*****************************************************
* uart.h
*****************************************************/

#ifndef UART_H
#define UART_H

#include "s3c6410.h"

void putchar(char c);
char getchar(void);
void init_uart(void);

#endif
