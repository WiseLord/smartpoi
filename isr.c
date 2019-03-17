#include "isr.h"

#include <avr/interrupt.h>
#include <avr/io.h>

#include "ws281x.h"
#include "input.h"

void isrInit()
{
    TCCR0B = (0 << CS02) | (1 << CS01) | (1 << CS00);   // PSK = 64
    TIMSK0 |= (1 << TOIE0);                             // Overflow

    sei();
}

// Every ~2ms (8000000 / PSK / 256 = 488Hz)
ISR(TIMER0_OVF_vect)
{
    // Send data to LED strip
    ws221xUpdateStrip();

    // Handle input
    inputRead();
}
