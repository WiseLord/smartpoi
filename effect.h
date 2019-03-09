#ifndef EFFECT_H
#define EFFECT_H

#include <stdbool.h>

#define EFFECT_STOPPED  0
#define EFFECT_RUNNING  1

typedef enum {
    EFFECT_RUNNING_LEDS,
    EFFECT_RANDOM_COLOR,
    EFFECT_FILL_RAINBOW,
    EFFECT_WAVE_RAINBOW,
    EFFECT_STAR_SPLASH,
    EFFECT_FADE_COLOR,

    EFFECT_RUN_PROGRAM,

    EFFECT_END
} Effect_t;

void effectInit(void);
void effectRun(Effect_t effect);
void effectStop(void);
Effect_t effectGet(void);
void effectLedsOff(void);
void effectSetRandom(bool value);
void effectNext(void);

#endif // EFFECT_H
