# Button Based Delay
The purpose of this code is to change the frequency of a blinking LED depending on how long the user depresses the button. When the code starts, the LED is blinking at a default frequency. Once the user depresses the button, an interrupt is triggered. The interrupt stops the previous timer, then begins a new timer counting in continuous mode. This is to time how long the user has depressed the button. Once the user releases the button, the intterupt senses a rising edge. This then updates the CCR0 register to have the value of the timer that was timing how long the button was held down. This then becomes the new frequency of the blinking LED.


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
