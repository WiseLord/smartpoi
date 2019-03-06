#include "ws281x.h"

#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <string.h>
#include "pins.h"

static uint8_t strip[LED_NUM * 3];

// Calculate timings in CPU cycles
#define T0H_CYCLES      (((F_CPU / 1000) * T0H ) / 1000000)
#define T1H_CYCLES      (((F_CPU / 1000) * T1H ) / 1000000)
#define THL_CYCLES      (((F_CPU / 1000) * THL ) / 1000000)

// w1 - NOPS needed for zero pulse
#define w1 (T0H_CYCLES - 2)
// w2 - NOPS difference between one pulse and zero pulse
#define w2 (T1H_CYCLES - 4 - w1)
// w3   NOPS required to finish loop
#define w3 (THL_CYCLES - 8 - w1 - w2)

#if w1>0
#define W1_NOPS w1
#else
#define W1_NOPS  0
#endif

#if w2>0
#define W2_NOPS w2
#else
#define W2_NOPS  0
#endif

#if w3>0
#define W3_NOPS w3
#else
#define W3_NOPS  0
#endif

#define NOP_0x01    "nop      \n\t"
#define NOP_0x02    "rjmp .+0 \n\t"
#define NOP_0x04    NOP_0x02 NOP_0x02
#define NOP_0x08    NOP_0x04 NOP_0x04
#define NOP_0x10    NOP_0x08 NOP_0x08
#define NOP_0x20    NOP_0x10 NOP_0x10

static const uint8_t gamma[BR_MAX + 1] PROGMEM = {
    0,   1,   2,   3,   4,   5,   7,   9,
    12,  15,  18,  22,  27,  32,  37,  44,
    50,  58,  66,  75,  85,  96,  107, 120,
    133, 147, 163, 179, 196, 215, 234, 255
};


// Ported from https://github.com/cpldcpu/light_ws2812
static void inline ws281xSend(uint8_t *data, uint16_t datlen, uint8_t maskhi)
{
    uint8_t curbyte, ctr, masklo;

    masklo    = ~maskhi & PORT(WS281X);
    maskhi |=        PORT(WS281X);

    uint8_t sreg = SREG; // Save SREG
    cli();

    while (datlen--) {
        curbyte = *data++;

        asm volatile(
            "       ldi   %0,8  \n\t"
            "loop%=:            \n\t"
            "       out   %2,%3 \n\t"    //  '1' [01] '0' [01] - re
// Phase 1 - pulse start (for both 0 and 1)
#if (W1_NOPS & 0x01)
            NOP_0x01
#endif
#if (W1_NOPS & 0x02)
            NOP_0x02
#endif
#if (W1_NOPS & 0x04)
            NOP_0x04
#endif
#if (W1_NOPS & 0x08)
            NOP_0x08
#endif
#if (W1_NOPS & 0x10)
            NOP_0x10
#endif
#if (W1_NOPS & 0x20)
            NOP_0x20
#endif
            "       sbrs  %1,7  \n\t"    //  '1' [03] '0' [02]
            "       out   %2,%4 \n\t"    //  '1' [--] '0' [03] - fe-low
            "       lsl   %1    \n\t"    //  '1' [04] '0' [04]
// Phase 2 - pulse continue, if needed (for 1)
#if (W2_NOPS & 0x01)
            NOP_0x01
#endif
#if (W2_NOPS & 0x02)
            NOP_0x02
#endif
#if (W2_NOPS & 0x04)
            NOP_0x04
#endif
#if (W2_NOPS & 0x08)
            NOP_0x08
#endif
#if (W2_NOPS & 0x10)
            NOP_0x10
#endif
#if (W2_NOPS & 0x20)
            NOP_0x20
#endif
// Phase 3 - finishing
            "       out   %2,%4 \n\t"    //  '1' [+1] '0' [+1] - fe-high
#if (W3_NOPS & 0x01)
            NOP_0x01
#endif
#if (W3_NOPS & 0x02)
            NOP_0x02
#endif
#if (W3_NOPS & 0x04)
            NOP_0x04
#endif
#if (W3_NOPS & 0x08)
            NOP_0x08
#endif
#if (W3_NOPS & 0x10)
            NOP_0x10
#endif
#if (W3_NOPS & 0x20)
            NOP_0x20
#endif
            "       dec   %0    \n\t"    //  '1' [+2] '0' [+2]
            "       brne  loop%=\n\t"    //  '1' [+3] '0' [+4]
            :   "=&d" (ctr)
            :   "r" (curbyte), "I" (_SFR_IO_ADDR(PORT(WS281X))), "r" (maskhi), "r" (masklo)
        );
    }

    SREG = sreg;    // Restore SREG
}

void ws281xInit(void)
{
    OUT(WS281X);
}


void ws281xSetLed(uint8_t num, const RGBLed *ws2811)
{
    uint8_t raw;

    for (uint8_t i = 0; i < 3; i++) {
        raw = ws2811->led[i];
        if (raw > BR_MAX)
            raw = BR_MAX;
        strip[3 * num + i] = pgm_read_byte(gamma + raw);
    }
}

void ws281xShift(void)
{
    memmove(strip + 3, strip , 3 * (LED_NUM - 1));
}

void ws281xSetBrColor(RGBLed *ws2811, uint8_t br, RGBColor color)
{
    uint8_t part;

    part = (color & RGB_RED) >> 4;
    ws2811->red = br * part / 3;

    part = (color & RGB_LIME) >> 2;
    ws2811->green = br * part / 3;

    part = (color & RGB_BLUE) >> 0;
    ws2811->blue = br * part / 3;
}

void ws221xUpdateStrip(void)
{
    ws281xSend(strip, 3 * LED_NUM, WS281X_LINE);
}
