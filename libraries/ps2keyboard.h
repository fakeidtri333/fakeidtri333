

#ifndef PS2KBD_H
#define PS2KBD_H

#include <stdint.h>


#define	KBD_INT		INT0_vect		/* Interrupt to be activated on negative edge of clock signal */
#define	KBD_SET_INT()	MCUCR |= _BV(ISC01)	/* Code to trigger the appropriate interrupt on the negative edge */
#define KBD_EN_INT()	GICR |= _BV(INT0)	/* Code to enable the appropriate interrupt */

#define	KBD_DATA_PORT	PORTD
#define	KBD_DATA_DDR	DDRD
#define	KBD_DATA_PIN	PIND
#define	KBD_DATA_BIT	PD3

#define	KBD_CLOCK_PORT	PORTD
#define	KBD_CLOCK_DDR	DDRD
#define	KBD_CLOCK_BIT	PD2

#define	KBD_BUFSIZE	8

// Bits in keyboard status register


#define	KBD_SHIFT	1			/* SHIFT is held down */
#define	KBD_CTRL	2			/* CTRL is held down */
#define KBD_ALT		4			/* ALT is held down */
#define	KBD_NUMLOCK	8			/* NUM LOCK is activated */
#define	KBD_CAPS	16			/* CAPS LOCK is activated */
#define	KBD_SCROLL	32			/* SCROLL LOCK is activated */

#define	KBD_SEND	64			/* This and the next bits are for internal use */
#define	KBD_EX		128
#define	KBD_BREAK	256
#define	KBD_LOCKED	512


// "Public" function declarations

// Initialize keyboard routines: activate appropriate interrupts. This also executes a
// sei() to enable them.

void kbd_init();

// Returns the next character waiting in the buffer or 0 if there are no characters
// left.

unsigned char kbd_getchar();

// Sends data to the keyboard
// If another sending cycle is in progress this function waits (blocks) for 5 ms and then
// tries again.

void kbd_send(uint8_t data);

// Returns the value of the keyboard status register. Can be used to check if SHIFT,
// CAPS LOCK or NUM LOCK is activated.

uint16_t kbd_get_status();

#endif
