# USART_discoveryBoard

Toggling an LED after every USART transmission.

To turn on the LED every USART transmission would require the use of OR logic to set the desired bit in the ODR register and
AND+NOT logic to clear the desired bit in the ODR register i.e. put it off after the delay then put another delay before turning it ON!!!

I think you should also put a delay after turning the LED off (with your BSRR version). With what you have, if you turn the LED on then wait, then turn it off and there's no delay before turning the LED back ON then it instantly goes ON that's why your LED wasn't flashing and kept staying ON.



**ENJOY!!!!!!!!!!!!!**
