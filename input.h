#ifndef INPUT_H
#define INPUT_H

#include <inttypes.h>
#define BTN_STATE_0             0x00

#define BTN_STATE_0             0x00
#define BTN_0                   (1 << 0)
/*
#define BTN_1                   (1 << 1)
#define BTN_2                   (1 << 2)
#define BTN_3                   (1 << 3)
*/
#define BTN_0_LONG              (BTN_0 << 4)
/*
#define BTN_1_LONG              (BTN_1 << 4)
#define BTN_2_LONG              (BTN_2 << 4)
#define BTN_3_LONG              (BTN_3 << 4)
*/

// Handling long press actions
#define SHORT_PRESS             6
#define LONG_PRESS              48

#define RAND_TIMER_OFF          -1
#define RAND_TIMER_START        (122 * 30)

void inputInit(void);
void inputRead(void);
uint8_t getBtnCmd(void);

int16_t getRandTimer(void);
void setRandTimer(int16_t value);

#endif // INPUT_H
