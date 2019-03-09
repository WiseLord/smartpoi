#ifndef PINS_H
#define PINS_H

#include <avr/io.h>
//#include "arduinopromini.h"
#include "arduinoleonardo.h"

#define CONCAT(x,y)         x ## y

#define DDR(x)              CONCAT(DDR,x)
#define PORT(x)             CONCAT(PORT,x)
#define PIN(x)              CONCAT(PIN,x)

#define OUT(x)              (DDR(x) |= x ## _LINE)
#define IN(x)               (DDR(x) &= ~x ## _LINE)
#define SET(x)              (PORT(x) |= x ## _LINE)
#define CLR(x)              (PORT(x) &= ~x ## _LINE)
#define READ(x)             (PIN(x) & x ## _LINE)

#define WS281X              ARDUINO_A3
#define WS281X_LINE         ARDUINO_A3_LINE

#define BUTTON_0            ARDUINO_D2
#define BUTTON_0_LINE       ARDUINO_D2_LINE

#define LED_RED             ARDUINO_D13
#define LED_RED_LINE        ARDUINO_D13_LINE

#endif // PINS_H
