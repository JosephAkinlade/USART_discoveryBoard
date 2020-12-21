#ifndef UART_H
#define UART_H

#include "stdint.h"
//USART2_TX is alternate function for PA2
extern void USART2_Init(void);
extern void GPIO_Init(void);
extern void USART2_Transmit(uint8_t ch);
extern void delay(int numberOfIncrements);

#endif //UART_H
