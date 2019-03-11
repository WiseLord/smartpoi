#ifndef WS281X_H
#define WS281X_H

#include <inttypes.h>

#define LED_NUM 24

// Bit timings, measured experimentally
#define T0H     350     // Zero bit time (ns)
#define T1H     900     // One bit time (ns)
#define THL     1250    // Total period (ns)

#define BR_MIN  0
#define BR_MAX  31

typedef union {
    uint8_t led[3];
    struct {
        uint8_t green;
        uint8_t red;
        uint8_t blue;
    };
} RGBLed;

typedef enum {
    RGB_BLACK               = 0x00,
    RGB_NAVI                =                          0x02,
    RGB_BLUE                =                          0x03,
    RGB_GREEN               =              0x08,
    RGB_TEAL                =              RGB_GREEN | RGB_NAVI,
    RGB_DODGER_BLUE         =              RGB_GREEN | RGB_BLUE,
    RGB_LIME                =              0x0C,
    RGB_SPRING_GREEN        =              RGB_LIME  | RGB_NAVI,
    RGB_AQUA                =              RGB_LIME  | RGB_BLUE,
    RGB_MAROON              = 0x20,
    RGB_PURPLE              = RGB_MAROON |             RGB_NAVI,
    RGB_ELECTRIG_INDIGO     = RGB_MAROON |             RGB_BLUE,
    RGB_OLIVE               = RGB_MAROON | RGB_GREEN,
    RGB_GRAY                = RGB_MAROON | RGB_GREEN | RGB_NAVI,
    RGB_LIGHT_SLATE_BLUE    = RGB_MAROON | RGB_GREEN | RGB_BLUE,
    RGB_CHARTREUSE          = RGB_MAROON | RGB_LIME,
    RGB_LIGHT_GREEN         = RGB_MAROON | RGB_LIME  | RGB_NAVI,
    RGB_ELECTRIG_BLUE       = RGB_MAROON | RGB_LIME  | RGB_BLUE,
    RGB_RED                 = 0x30,
    RGB_DEEP_PINK           = RGB_RED    |             RGB_NAVI,
    RGB_MAGENTA             = RGB_RED    |             RGB_BLUE,
    RGB_DARK_ORANGE         = RGB_RED    | RGB_GREEN,
    RGB_LIGHT_CORAL         = RGB_RED    | RGB_GREEN | RGB_NAVI,
    RGB_FUCHSIA_PINK        = RGB_RED    | RGB_GREEN | RGB_BLUE,
    RGB_YELLOW              = RGB_RED    | RGB_LIME,
    RGB_WITCH_HAZE          = RGB_RED    | RGB_LIME  | RGB_NAVI,
    RGB_WHITE               = RGB_RED    | RGB_LIME  | RGB_BLUE,
} RGBColor;

void ws281xInit(void);
void ws281xSetLed(uint8_t num, const RGBLed *ws2811);
void ws281xShift(void);
void ws281xSetBrColor(RGBLed *ws2811, uint8_t br, RGBColor color);
void ws281xSetStripLed(uint8_t num, RGBColor color);
void ws221xUpdateStrip(void);

#endif // WS281X_H
