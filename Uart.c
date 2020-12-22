#include "stm32f4xx.h"                  // Device header
#include "Uart.h"


void USART2_Init(void){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;		//Enables clock access for GPIOA
	GPIOA->MODER |= GPIO_MODER_MODER2_1;		//alternate function mode for PA2
	GPIOA->AFR[0] |= GPIO_AFRL_AFRL2_0|GPIO_AFRL_AFRL2_1|GPIO_AFRL_AFRL2_2;//select usart2_tx for PA2
	
	//configure USART2 (Disco version)
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;//enable USART2 clock
	USART2->CR1 |= USART_CR1_UE;   //Enable usart
	USART2->BRR = 0x683;		//9600 at 16MHz clock,oversampling of 16
	USART2->CR1 |= USART_CR1_TE; //send idle frame as first transmission
	
}

void GPIO_Init(void){
	//RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	//GPIOD->MODER |= GPIO_MODER_MODER13_0;  //sets PD13 as output
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOD->MODER |= GPIO_MODER_MODER5_0;  //sets PA5 as output (for Nucleo board)
}

void USART2_Transmit(uint8_t data){
	while((USART2->SR & USART_SR_TXE) == 0x00){//Wait for data to be transferred to the shift register
		//GPIOD->BSRR = GPIO_BSRR_BR13;  //turn off led
	}
	USART2->DR = data;
	//GPIOD->BSRR |= GPIO_BSRR_BS13;//turn on led
	GPIOA->ODR ^= GPIO_ODR_OD5; //toggle the LED
	
}

void delay(int numberOfIncrements){
	volatile int i = 0;
	while(i<numberOfIncrements){
		i++;
	}
}

