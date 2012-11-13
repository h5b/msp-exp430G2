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

void
delay_one_sec(void)
{
	volatile unsigned int i;

	for (i = 0; i < 10; i++)
		__delay_cycles(100000UL);
}

int
main(void)
{
	/*
	 * Enforce Watchdog Timer Hold
	 * see Section 10.3 "Watchdog Timer+ Registers of the
	 * MSP430x2xx Family User's Guide
	 */
	WDTCTL = (WDTPW + WDTHOLD);

	P1DIR |= GRN_LED;
	P1OUT |= GRN_LED;

	while(1)
	{
		/* toggle Green LED once per second */
		P1OUT ^= GRN_LED;
		delay_one_sec();
	}

	/* never reached */
	return (0);
}
