** Ignore the "Lab2_TimerA_Blink_G2" folder, it was added by mistake **

# Button Interrupt
The purpose of this code is to blink an LED when the button is pressed on the development board. Unlike the button blink code found in Lab 1, this code uses an interrupt to turn on the processor from low power mode and execute code in the `__interrupt void Port_1(void)` block of code. The reason an interrupt is used over polling is so that the processor can go into low power mode while waiting for the button input. This reduces power consumption by the processor and makes the code more efficient. The button is set up as normally open in momentary. That way, when the button is pressed, it triggers a falling edge. The falling edge is configured as the interrupt. Inside the interrupt, the button will switch state of a variable from 0 to 1 depending on its previous state. 

## MSP430G2ET
Pinout: <br/>
LED - Port 1.0, output <br/>
Button - Port 1.3, input, pull up resistor <br/>
Interrupt on Port 1.3, falling edge

## MSP430F5529
Pinout: <br/>
LED - Port 1.0, output <br/>
Button - Port 2.1, input, pull up resistor <br/>
Interrupt on Port 2.1, falling edge

## How to Implement the Code
The pinouts for the MSP430G2ET and MSP430F5529 are found above. The LED and button must be configured to the ports above to run the code properly. The global interrupt must be enabled and the watchdog timer must be disabled to run the code.
