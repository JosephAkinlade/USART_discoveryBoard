#include "stm32f4xx.h"                  // Device header

//This code works

void ConfigureClocks(void);
void ConfigureUSART2(void);
void ConfigureGPIOA(void);
void USART2_Transmit(char data);
void delay(int numberOfIncrements);

int main(void){
	ConfigureClocks();
	ConfigureGPIOA();
	ConfigureUSART2();
	while(1){
		USART2_Transmit('h');
		delay(1600000);
	}
	
}


void ConfigureClocks(void){
	while (!(RCC->CR & RCC_CR_HSIRDY)){}//wait for HSI clock to stabilize
	RCC->CFGR |= RCC_CFGR_HPRE_DIV2; //set AHB prescaler to 2 i.e. AHB clock = 16MHz / 2
	//APB clock = AHB clock = 8MHz since APB prescaler = 1
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //enable GPIOA clock
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;//enable USART2 clock
}

void ConfigureUSART2(void){
	USART2->CR1 |= USART_CR1_UE; //Enable USART
	//Word length = 8 bits, 1 Start bit, 1 Stop bit
	USART2->BRR = 0x34A; //Baud rate = 9600, oversampling by 16
  	USART2->CR1 |= USART_CR1_TE; //send idle frame as first transmission	
}

void ConfigureGPIOA(void){
	GPIOA->MODER |= GPIO_MODER_MODER2_1; //alternate function mode for PA2
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_0 | GPIO_AFRL_AFSEL2_1 | GPIO_AFRL_AFSEL2_2;//Select USART functionality for PA2
	GPIOA->MODER |= GPIO_MODER_MODE5_0; //PA5 as output
}

void USART2_Transmit(char data){
	while ((USART2->SR & USART_SR_TXE) == 0x00){}//wait for TXE bit to be set 
	USART2->DR = data;//place data to be transmitted into the TDR register
	GPIOA->ODR ^= GPIO_ODR_OD5; //toggle the LED
}

void delay(int numberOfIncrements){
	volatile int i = 0;
	while(i<numberOfIncrements){
		i++;
	}
}
