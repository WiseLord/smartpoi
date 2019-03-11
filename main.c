#include <stdbool.h>

#include "isr.h"
#include "input.h"
#include "ws281x.h"
#include "effect.h"

#include "pins.h"

static void hwInit()
{
    inputInit();
    ws281xInit();
    effectInit();
    isrInit();
}

int main(void)
{
    hwInit();

    Effect_t effect = PROG_COLORS;
    effectSetRandom(false);

    effectRun(effect);

    while (1) {
        switch (getBtnCmd()) {
        case BTN_0:
            effectSetRandom(false);
            effectNext();
            break;
        case BTN_0_LONG:
            effectSetRandom(true);
            break;
        default:
            break;
        }

        effect = effectGet();
        effectRun(effect);
    }

    return 0;
}
