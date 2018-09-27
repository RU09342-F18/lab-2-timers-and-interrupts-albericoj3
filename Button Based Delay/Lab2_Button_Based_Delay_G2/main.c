#include <msp430.h> 


/**
 * Button Based Delay G2
 * Author: Jordan Alberico
 * Date Created: 9/26/18
 * Last Modified: 9/26/18
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    P1SEL = 0; //configure port 1 for GPIO
    P1DIR |= 0x01; //sets port 1.0 as an output
    P1DIR &= ~BIT3; //sets port 1.3 as an input
    CCTL0 = CCIE; //CCTL0 is configured as an interrupt

    P1IE |= BIT3; //enables interrupt on port 1.3
    P1REN &= ~BIT3; //enable pull down resistor on BIT3
    P1IES |= BIT3; //sets as falling edge
    P1IFG &= ~BIT3; //clear interrupt flag
    CCR0 = 50000;
    TACTL = TASSEL_1 + MC_1; //ACLK up mode
    __bis_SR_register(GIE);      // Enable global interrupt
    while(1);

}
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    if ((P1IES & BIT3) == BIT3) //checks if button press is on falling edge
    {
    P1IES &= ~BIT3; //sets as rising edge
    TACTL = TACLR; //clear TimerA
    TACTL = MC_2 + TASSEL_1 + ID_3; //sets as continuous, ACLOCK, and Interal divider of 3
    }
    else
    {
        TACTL = MC_0 + TASSEL_1 + ID_3; //stop clock, ACLOCK, and Interal divider of 3
        P1IES |= BIT3; //sets as falling edge
        TACCR0 = TA0R; //CCR0 to current timer value
        TACTL = MC_1 + TASSEL_1 + ID_3; //up mode, ACLOCK, Internal Divider of 3
    }
    P1IFG &= ~BIT3; //clear interrupt flag
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
    P1OUT ^= BIT0;

}


