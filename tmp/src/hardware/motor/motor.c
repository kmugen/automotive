#include "motor.h"
#include "IfxPort.h"
#include "IfxPort_PinMap.h"
#include "pwmHl.h"

#include "pinSettings.h"

void initMotors(void)
{
    GtmTomPwmHl_init();

    IfxPort_setPinModeOutput(DIR_CHA, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinLow(DIR_CHA);
    IfxPort_setPinModeOutput(BRAKE_CHA, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinLow(BRAKE_CHA);
}

void setMotorPower(float32 power)
{
    g_GtmTomPwmHl.tOn[0] = g_GtmTomPwmHl.tOn[1] = power;
    GtmTomPwmHl_run();
}
