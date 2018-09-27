#include <msp430.h> 


/**
 * Button Based Delay FR2311
 * Author: Jordan Alberico
 * Date Created: 9/27/18
 * Last Modified: 9/27/18
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    P1SEL0 = 0; //configure port 1 for GPIO
    P1DIR |= 0x01; //sets port 1.0 as an output


    P1DIR &= ~BIT1; //sets port 1.1 as an input
    P1REN |= BIT1; //enable pull down resistor on BIT3

    P1IE |= BIT1; //enables interrupt on port 1.1
    P1IES |= BIT1; //sets as falling edge
    P1IFG &= ~BIT1; //clear interrupt flag

    TB0CCTL0 |= CCIE; //CCTL0 is configured as an interrupt
    PM5CTL0 &= ~LOCKLPM5;
    TB0CCR0 = 50000;
    TB0CTL = TBSSEL_1 + MC_1; //ACLK up mode
    __bis_SR_register(GIE);      // Enable global interrupt
    while(1);

}
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    if ((P1IES & BIT1) == BIT1) //checks if button press is on falling edge
    {
    P1IES &= ~BIT1; //sets as rising edge
    TBCTL = TBCLR; //clear TimerB
    TBCTL = MC_2 + TBSSEL_1 + ID_3; //sets as continuous, ACLOCK, and Interal divider of 3
    }
    else
    {
        TBCTL = MC_0 + TBSSEL_1 + ID_3; //stop clock, ACLOCK, and Interal divider of 3
        P1IES |= BIT1; //sets as falling edge
        TBCCR0 = TB0R; //CCR0 to current timer value
        TBCTL = MC_1 + TBSSEL_1 + ID_3; //up mode, ACLOCK, Internal Divider of 3
    }
    P1IFG &= ~BIT1; //clear interrupt flag
}


#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer_B (void)
{
    P1OUT ^= BIT0;

}


