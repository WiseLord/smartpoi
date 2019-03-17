#ifndef INPUT_H
#define INPUT_H

#include <inttypes.h>
#define BTN_STATE_0             0x00

#define BTN_STATE_0             0x00
#define BTN_0                   (1 << 0)
#define BTN_1                   (1 << 1)

#define BTN_0_LONG              (BTN_0 << 4)
#define BTN_1_LONG              (BTN_1 << 4)

// Handling long press actions
#define SHORT_PRESS             50
#define LONG_PRESS              300

#define RAND_TIMER_OFF          -1
#define RAND_TIMER_START        5000

void inputInit(void);
void inputRead(void);
uint8_t getBtnCmd(void);

int16_t getRandTimer(void);
void setRandTimer(int16_t value);

#endif // INPUT_H
