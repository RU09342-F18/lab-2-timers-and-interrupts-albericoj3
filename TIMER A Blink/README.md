# TIMER A Blink
The purpose of this lab is to blink two LEDs at different frequencies using a timer. In this case, LED1 blinks twice as fast as LED 2. Since this code uses timer interrupts, it is more efficient than polling since the microprocessor is in low power mode while the timer is timing. This reduces the power consumption of the microprocessor. 


## MSP430G2ET
Pinout:<br/>
LED1: 1.0, output<br/>
LED2: 1.6, output<br/>

Uses TimerA, ACLK in up mode. CCR0 initally set to 50000 and CCR1 initally set to 25000.

## MSP432P401R
Pinout:<br/>
LED1: 1.0, output<br/>
LED2: 2.0, output<br/>

Uses TimerA, ACLK in up mode. CCR0 initally set to 50000 and CCR1 initally set to 25000.<br/>
Uses this header for the timer interrupt:<br/>
`void TA0_0_IRQHandler(void) {}`

## How to Implement the Code
The pinouts for the MSP430G2ET and SP432P401R are found above. The code must be configured for these pinouts in order to work properly. The global interrupt must be enable and the watchdog timer must be shut off.
