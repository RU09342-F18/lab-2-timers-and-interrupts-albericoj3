#include <msp.h>

/**
 * Timer A Blink MSP432P401R
 * Author: Jordan Alberico
 * Date Created: 9/19/18
 * Last Modified: 9/26/18
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1SEL0 = 0; //configure port 1 for GPIO
	P1DIR |= BIT0; //sets port 1.0 as an output
	P2DIR |= BIT0; //sets port 2.0 as an output
	//TA0CCTL1 |= CCIE;
	TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CCIE; // TACCR0 interrupt enabled
        TIMER_A0->CCR[0] = 50000;
	TIMER_A0->CCTL[1] = TIMER_A_CCTLN_CCIE; // TACCR1 interrupt enabled
	TA0CCR0 = 50000;
	TA0CCR1 = 25000;
	TA0CTL = TASSEL_1 + MC_1 + TAIE; //ACLK up mode
	__enable_irq();      // Enable global interrupt
         NVIC->ISER[0] = 1 << ((TA0_0_IRQn) & 31);
	while(1){

	}
}


void TA0_0_IRQHandler(void) {
    switch (TA0IV)
        {
            case(2):
                P1OUT ^= BIT0;
                TA0CCR1 =50000;
                break;
            case (4):
            case (6):
            case (8):
            case (10):
            case (12):
                break;
            case(14):
                P2OUT ^= BIT0;
                TA0CCR1 = 25000;
                break;
         }
}


