#include <msp430.h> 

/**
 * Timer A Blink G2
 * Author: Jordan Alberico
 * Date Created: 9/19/18
 * Last Modified: 9/26/18
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1SEL = 0; //configure port 1 for GPIO
	P1DIR |= 0x01; //sets port 1.0 as an output
	P1DIR |= BIT6; //sets port 1.6 as an output
	TA0CCTL1 |= CCIE;
	CCR0 = 50000;
	CCR1 = 25000;
	TACTL = TASSEL_1 + MC_1 + TAIE; //ACLK up mode
	__bis_SR_register(GIE);      // Enable global interrupt
	while(1){

	}
}


#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer_A (void)
{
    switch (TA0IV)
    {
        case(2):
            P1OUT ^= BIT0;
            CCR1 =50000;
            break;

        case (4):
            break;

        case(10):
            P1OUT ^= BIT6;
            CCR1 = 25000;
            break;
    }

}


