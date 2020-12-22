#include "stm32f4xx.h"                  // Device header
#include "uart.h"

//COMMENTS
//1.)USE ODR register instead of BSRR register
//2.)EITHER toggle the ODR using XOR or set the desired bit with |= and clear it with &= ~
//e.g == SETTING and CLEARING
//GPIOA->ODR |= GPIO_ODR_OD5 (in my case; for the nucleo board) //turn LED on
//GPIOA->ODR &= ~GPIO_ODR_OD5 (in my case; for the nucleo board) //turn LED off

//e.g == TOGGLING
//GPIOA->ODR ^= GPIO_ODR_OD5 (in my case; for the nucleo board) [put your delay after this]

int main(void){
	GPIO_Init();
	USART2_Init();
	
	while(1){
		USART2_Transmit('h');
		delay(1600000);
		//GPIOD->BSRR = GPIO_BSRR_BR13;
		//USART2_Transmit('I');
		//delay(1600000);
	
	}

}
