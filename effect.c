#include "effect.h"

#include <stdlib.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "input.h"
#include "pins.h"
#include "program.h"
#include "ws281x.h"

// Cell in eeprom that stores random seed
#define EEPROM_SEED     0x00

// Current effect in loop
static Effect_t eff = EFFECT_END;
static volatile uint8_t run = EFFECT_STOPPED;

static uint8_t brArray[LED_NUM];
static bool randomize = true;

static const uint8_t rainbow[] PROGMEM = {
    RGB_RED,
    RGB_DARK_ORANGE,
    RGB_YELLOW,
    RGB_GREEN,
    RGB_AQUA,
    RGB_BLUE,
    RGB_PURPLE
};

static const uint8_t softRainbow[] PROGMEM = {
    0x30, 0x34, 0x38, 0x3C, 0x2C, 0x1C,
    0x0C, 0x0D, 0x0E, 0x0F, 0x0B, 0x07,
    0x03, 0x13, 0x23, 0x33, 0x32, 0x31,
};

// Shift all the strip and set first led to given color
static void effectShift(RGBColor color, uint8_t brightness)
{
    RGBLed rgbLed;

    ws281xSetBrColor(&rgbLed, brightness, color);
    ws281xShift();
    ws281xSetLed(0, &rgbLed);

    _delay_ms(25);
}

// Shift strip using array for first led color with repeats
static void effectFillArray(const uint8_t *array, uint8_t arrLen, uint8_t repeats)
{
    while (run) {
        for (uint8_t idx = 0; run && idx < arrLen; idx++) {
            for (uint8_t repeat = 0; run && repeat < repeats; repeat++) {
                RGBColor color = pgm_read_byte(array + idx);
                effectShift(color, BR_MAX);
            }
        }
    }
}

static void effectRunningLeds(const uint8_t *array, uint8_t arrLen, uint8_t pauses)
{
    while (run) {
        for (uint8_t idx = 0; run && idx < arrLen; idx++) {
            for (int8_t br = 0; run && br < 4; br++) {
                RGBColor color = pgm_read_byte(array + idx);
                effectShift(color, (uint8_t)br * 8);
            }
            for (int8_t br = 3; run && br >= 0; br--) {
                RGBColor color = pgm_read_byte(array + idx);
                effectShift(color, (uint8_t)br * 8);
            }
            for (uint8_t repeat = 0; run && repeat < pauses; repeat++) {
                RGBColor color = RGB_BLACK;
                effectShift(color, BR_MAX);
            }
        }
    }
}

static void effectRandomColor(void)
{
    RGBLed rgbLed;

    while (run) {
        rgbLed.red = rand() % (BR_MAX + 1);
        rgbLed.green =  rand() % (BR_MAX + 1);
        rgbLed.blue =  rand() % (BR_MAX + 1);
        ws281xSetLed(rand() % LED_NUM, &rgbLed);
        _delay_ms(50);
    }
}

static void effectStarSplash(uint8_t skips)
{
    RGBLed rgbLed;

    for (uint8_t i = 0; i < LED_NUM; i++) {
        brArray[i] = 0;
    }

    while (run) {
        uint8_t num = rand() % LED_NUM;
        for (uint8_t skip = 0; run && skip < skips; skip++) {
            for (uint8_t i = 0; run && i < LED_NUM; i++) {
                if (num == i) {
                    brArray[i] = BR_MAX;
                } else {
                    if (brArray[i] > 0) {
                        brArray[i]--;
                    }
                }
                ws281xSetBrColor(&rgbLed, brArray[i], RGB_WHITE);
                ws281xSetLed(i, &rgbLed);
                _delay_us(500);
            }
        }
    }
}

static void effectFill(RGBLed *led)
{
    for (uint8_t i = 0; run && i < LED_NUM; i++) {
        ws281xSetLed(i, led);
        _delay_ms(1);
    }
}

static void effectfFadeColor()
{
    RGBLed rgbLed;

    while (run) {
        rgbLed.red = BR_MAX;
        rgbLed.green =  0;
        rgbLed.blue =  0;

        // R00 => RG0
        for (int8_t part = 0; run && part <= BR_MAX; part++) {
            rgbLed.green = (uint8_t)part;
            effectFill(&rgbLed);
        }
        // RG0 => 0G0
        for (int8_t part = BR_MAX; run && part >= BR_MIN; part--) {
            rgbLed.red = (uint8_t)part;
            effectFill(&rgbLed);
        }
        // 0G0 => 0GB
        for (int8_t part = 0; run && part <= BR_MAX; part++) {
            rgbLed.blue = (uint8_t)part;
            effectFill(&rgbLed);
        }
        // 0GB => 00B
        for (int8_t part = BR_MAX; run && part >= BR_MIN; part--) {
            rgbLed.green = (uint8_t)part;
            effectFill(&rgbLed);
        }
        // 00B => R0B
        for (int8_t part = 0; run && part <= BR_MAX; part++) {
            rgbLed.red = (uint8_t)part;
            effectFill(&rgbLed);
        }
        // R0B => R00
        for (int8_t part = BR_MAX; run && part >= BR_MIN; part--) {
            rgbLed.blue = (uint8_t)part;
            effectFill(&rgbLed);
        }
    }
}

static void effectRunProgram()
{
    RGBLed rgbLed;

    uint16_t height = pgm_read_word(&colors.height);
    const uint8_t *data = pgm_read_ptr(&colors.data);

    size_t line = 0;
    while (run) {
        for (uint8_t i = 0; run && i < LED_NUM; i++) {
            brArray[i] = BR_MAX;
            ws281xSetBrColor(&rgbLed, brArray[i], pgm_read_byte(&data[line * LED_NUM + i]));
            ws281xSetLed(i, &rgbLed);
        }
        if (++line >= height)
            line = 0;
        _delay_ms(20);
    }
}

void effectInit(void)
{
    // Update random seed in eeprom
    uint32_t seed = eeprom_read_dword(EEPROM_SEED);
    srand(seed);
    seed = (uint32_t)rand();
    eeprom_write_dword(EEPROM_SEED, seed);

    OUT(LED_RED);
    effectSetRandom(true);
}

void effectRun(Effect_t effect)
{
    run = 1;
    eff = effect;

    switch (effect) {
    case EFFECT_RUNNING_LEDS:
        effectRunningLeds(rainbow, sizeof (rainbow), 5);
        break;
    case EFFECT_RANDOM_COLOR:
        effectRandomColor();
        break;
    case EFFECT_FILL_RAINBOW:
        effectFillArray(rainbow, sizeof (rainbow), LED_NUM);
        break;
    case EFFECT_WAVE_RAINBOW:
        effectFillArray(softRainbow, sizeof (softRainbow), 3);
        break;
    case EFFECT_STAR_SPLASH:
        effectStarSplash(2);
        break;
    case EFFECT_FADE_COLOR:
        effectfFadeColor();
        break;
    case EFFECT_RUN_PROGRAM:
        effectRunProgram();
        break;
    default:
        break;
    }
}

void effectStop()
{
    run = 0;
}

Effect_t effectGet()
{
    return eff;
}

void effectLedsOff(void)
{
    RGBLed rgbLed;

    rgbLed.red = 0;
    rgbLed.green = 0;
    rgbLed.blue = 0;

    for (uint8_t i = 0; i < LED_NUM; i++) {
        ws281xSetLed(i, &rgbLed);
    }
}

void effectSetRandom(bool value)
{
    randomize = value;

    if (value) {
        setRandTimer(RAND_TIMER_START);
        SET(LED_RED);
    } else {
        setRandTimer(RAND_TIMER_OFF);
        CLR(LED_RED);
    }
}

void effectNext(void)
{
    if (++eff >= EFFECT_END) {
        eff = EFFECT_RUNNING_LEDS;
    }
}
