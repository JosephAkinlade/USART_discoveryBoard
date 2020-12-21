#include "stm32f4xx.h"                  // Device header
#include "uart.h"

int main(void){
	GPIO_Init();
	USART2_Init();
	
	while(1){
		USART2_Transmit('h');
		delay(1600000);
		GPIOD->BSRR = GPIO_BSRR_BR13;
		//USART2_Transmit('I');
		//delay(1600000);
	
	}

}
