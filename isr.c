#include "isr.h"

#include <avr/interrupt.h>
#include <avr/io.h>

#include "ws281x.h"
#include "input.h"

void isrInit()
{
    TCCR0B = (1 << CS02) | (0 << CS01) | (0 << CS00);   // PSK = 256
    TIMSK0 |= (1 << TOIE0);                             // Overflow

    sei();
}

// Every ~8ms (8000000 / PSK / 256 = 122Hz)
ISR(TIMER0_OVF_vect)
{
    // Send data to LED strip
    ws221xUpdateStrip();

    // Handle input
    inputRead();
}
