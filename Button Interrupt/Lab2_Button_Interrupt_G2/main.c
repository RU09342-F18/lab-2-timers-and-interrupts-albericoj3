#include <msp430.h> 


/**
 * Button_Interrupt_G2
 * Author: Jordan Alberico
 * Created: 9/19/18
 * Last Edited: 9/19/18
 */

int buttonPress;

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1SEL = 0; //sets port1 to GPIO
    P1DIR |= BIT0; //set port 1.0 to output
    P1DIR &= ~BIT3; //set port 1.3 to input
    P1REN |= BIT3; //enable pull up resistor on BIT3
    P1OUT &= ~BIT0; //sets 1.0 to 0

    P1IE |= BIT3; //enables interrupt on port 1.3
    P1IES |= BIT3; //sets as falling edge
    P1IFG &= ~BIT3; //clear interrupt flag
    _BIS_SR(GIE); // enable global interrupt
    //Interrupt code provided by Professor Tang's slides
    while(1)
    {
        if (buttonPress == 1)
        {
            P1OUT ^= 0x01;
            __delay_cycles(1000000);
        }
        else {
            P1OUT &= ~BIT0;
        }
    }
	
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    if (buttonPress == 0)
    {
        buttonPress = 1;
    }
    else {
        buttonPress = 0;
    }

    P1IFG &= ~BIT3;
}
