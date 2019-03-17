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

    Effect_t effect = EFFECT_BEGIN;
    effectSetRandom(true);

    effectRun(effect);

    while (1) {
        switch (getBtnCmd()) {
        case BTN_0:
            effectNext();
            break;
        case BTN_0_LONG:
            effectSetRandom(!effectGetRandom());
            effectNext();
            break;
        case BTN_1:
            effectNext();
            break;
        case BTN_1_LONG:
            effectSwitchType();
            break;
        default:
            break;
        }

        effect = effectGet();
        effectRun(effect);
    }

    return 0;
}
