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

#ifndef _BOARD_H_
#define _BOARD_H_

/* LEDs located at P1.0 (RED) and P1.6 (GREEN) */
#define GRN_LED		BIT6
#define RED_LED		BIT0

void ISR_Timer0_A0(void) __attribute__((interrupt(TIMER0_A0_VECTOR)));
void ISR_Timer0_A1(void) __attribute__((interrupt(TIMER0_A1_VECTOR)));
void ISR_Watchdog(void) __attribute__((interrupt(WDT_VECTOR)));

#endif /* _BOARD_H_ */
