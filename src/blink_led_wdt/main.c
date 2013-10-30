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

#define ONE_SECOND	125 /* (10^6 / 8*10^3) = 125 */

volatile unsigned int count;

void
ISR_Watchdog(void)
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
	 * See Section 10.3.1 "WDTCTL, Watchdog Timer+ Registers"
	 * of the MSP430x2xx Family User's Guide
	 *
	 * Configure Watchdog to run in Interval Timer Mode (WDTTMSEL),
	 * Watchdog Timer Interval set to CLK/8192 (WDTIS0) so the
	 * ISR gets called every 8ms.
	 */
	WDTCTL = (WDTPW + WDTTMSEL + WDTCNTCL + WDTIS0);
	IE1 |= WDTIE;

	P1DIR |= GRN_LED;
	P1OUT |= GRN_LED;

	__enable_interrupt();

	while(1) {
		/*  all work is done in the ISR */
	}

	/* never reached */
	return (0);
}
