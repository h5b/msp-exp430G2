/*
 * Copyright (c) 2012 Sebastian Trahm
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <msp430g2452.h>
#include "board.h"

#define ONE_SECOND	125	/*  125 = SMCLK/8/1000 */
#define COMPARE_VAL	1000	/* 1000 = SMCLK/8/125  */

void ISR_Timer0_A0(void) __attribute__((interrupt(TIMER0_A0_VECTOR)));
volatile unsigned int count = 0;

void
ISR_Timer0_A0(void)
{
	count++;

	if (count == ONE_SECOND) {
		P1OUT ^= GRN_LED;
		count = 0;
	}
}

int
main(void)
{
	/*
	 * See Section 10.3 "Watchdog Timer+ Registers of the
	 * MSP430x2xx Family User's Guide
	 *
	 * Enforce Watchdog Timer Hold
	 */
	WDTCTL = (WDTPW + WDTHOLD);

	/*
	 * See Section 12.3.1 TACTL, Timer_A Control Register
	 * of the MSP430x2xx Family User's Guide
	 *
	 * Configure Timer_A to run with SMCLK/8, Compare Match/Count Up Mode.
	 */
	TACTL |= (TASSEL_2 + ID_3 + TACLR);
	CCR0 = COMPARE_VAL;
	CCTL0 = CCIE;
	TACTL |= MC_1;

	P1DIR |= GRN_LED;
	P1OUT |= GRN_LED;

	__enable_interrupt();

	while(1) {
		/*  all work is done in the ISR */
	}

	/* never reached */
	return (0);
}
