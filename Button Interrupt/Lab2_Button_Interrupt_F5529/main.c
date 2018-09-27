#include <msp430.h> 


/**
 * Button_Interrupt_F5529
 * Author: Jordan Alberico
 * Created: 9/27/18
 * Last Edited: 9/27/18
 */

int buttonPress;

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1SEL = 0; //sets port1 to GPIO
    P2SEL = 0; //sets port2 to GPIO
    P1DIR |= BIT0; //set port 1.0 to output
    P2DIR &= ~BIT1; //set port 2.1 to input
    P2REN |= BIT1; //enable pull up resistor on Port 2, BIT1
    P1OUT &= ~BIT0; //sets 1.0 to 0


    P2IE |= BIT1; //enables interrupt on port 2.1
    P2IES |= BIT1; //sets as falling edge
    P2IFG &= ~BIT1; //clear interrupt flag
    _BIS_SR(GIE); // enable global interrupt
    //Interrupt code provided by Professor Tang's slides
    while(1)
    {
        if (buttonPress == 1)
        {
            P1OUT ^= 0x01;
            __delay_cycles(500000);
        }
        else {
            P1OUT &= ~BIT0;
        }
    }
	
}

#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{
    if (buttonPress == 0)
    {
        buttonPress = 1;
    }
    else {
        buttonPress = 0;
    }

    P2IFG &= ~BIT1;
}
