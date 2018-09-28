# Button Based Delay



## MSP430G2ET
Pinout:<br/>
LED: Port 1.0, output<br/>
Button:Port 1.3, pull down resistor<br/>
Interrupt on Port 1.3, falling edge.<br/>

Uses TimerA set as ACLK in up mode. CCR0 initally to 50000.


## MSP430FR2311
Pinout:<br/>
LED: Port 1.0, output<br/>
Button:Port 1.1, pull down resistor<br/>
Interrupt on Port 1.3, falling edge.<br/>

Uses TimerB set as ACLK in up mode. CCR0 initally to 50000.


## How to Implement the Code
The pinouts for the MSP430G2ET and MSP430FR2311 are found above. The code must match these pinouts in order to work correctly. The global interrupt has to be enabled and the watchdog timer has to be stopped. 
