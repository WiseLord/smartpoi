#include "input.h"

#include "pins.h"
#include "effect.h"

static volatile uint8_t btnCmd = 0;         // Command buffer
static volatile int16_t randTimer = 0;      // Random timer

void inputInit(void)
{
    IN(BUTTON_0);
    SET(BUTTON_0);
}

void inputRead(void)
{
    static uint8_t btnCnt = 0;              // Buttons press duration
    static uint8_t btnPrev = BTN_STATE_0;   // Previous buttons state

    uint8_t btnNow = BTN_STATE_0;

    if (~PIN(BUTTON_0) & BUTTON_0_LINE)
        btnNow |= BTN_0;
    /*
    if (~PIN(BUTTON_1) & BUTTON_1_LINE)
        btnNow |= BTN_1;
    if (~PIN(BUTTON_2) & BUTTON_2_LINE)
        btnNow |= BTN_2;
    if (~PIN(BUTTON_3) & BUTTON_3_LINE)
        btnNow |= BTN_3;
    */
    // If button event has happened, place it to command buffer
    if (btnNow) {
        if (btnNow == btnPrev) {
            btnCnt++;
            if (btnCnt == LONG_PRESS) {
                btnCmd = (btnPrev << 4);
                effectStop();
            }
        } else {
            btnPrev = btnNow;
        }
    } else {
        if ((btnCnt > SHORT_PRESS) && (btnCnt < LONG_PRESS)) {
            btnCmd = btnPrev;
            effectStop();
        }
        btnCnt = 0;
    }

    if (randTimer > 0) {
        randTimer--;
        if (randTimer == 0) {
            randTimer = RAND_TIMER_START;
            effectStop();
            effectNext();
        }
    }
}

uint8_t getBtnCmd(void)
{
    uint8_t ret = btnCmd;
    btnCmd = BTN_STATE_0;

    return ret;
}

int16_t getRandTimer(void)
{
    return randTimer;
}

void setRandTimer(int16_t value)
{
    randTimer = value;
}
