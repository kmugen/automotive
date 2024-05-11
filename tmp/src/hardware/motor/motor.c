#include "motor.h"
#include "gpio.h"
#include "pwmHl.h"

#include "pinSettings.h"

void initMotors(void)
{
    GtmTomPwmHl_init();

    setPinOutput(PIN_DIR_CHA);
    setPinState(PIN_DIR_CHA, CW);
    setPinOutput(PIN_BRAKE_CHA);
    setPinState(PIN_BRAKE_CHA, FALSE);

    setPinOutput(PIN_DIR_CHB);
    setPinState(PIN_DIR_CHB, CW);
    setPinOutput(PIN_BRAKE_CHB);
    setPinState(PIN_BRAKE_CHB, FALSE);
}

void setMotorsPower(float32 power_chA, float32 power_chB)
{
    g_GtmTomPwmHl.tOn[0] = power_chA;
    g_GtmTomPwmHl.tOn[1] = power_chB;
    GtmTomPwmHl_run();
}
