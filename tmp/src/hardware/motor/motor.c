#include "motor.h"
#include "IfxPort.h"
#include "IfxPort_PinMap.h"
#include "pwmHl.h"

#define POWER   &MODULE_P10, 3
#define DIR     &MODULE_P10, 2
#define BRAKE   &MODULE_P02, 6

void initMotor(void)
{
    GtmTomPwmHl_init();
    IfxPort_setPinModeOutput(DIR, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinLow(DIR);
    IfxPort_setPinModeOutput(BRAKE, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinLow(BRAKE);
}

void setMotorPower(float32 power)
{
    g_GtmTomPwmHl.tOn[0] = g_GtmTomPwmHl.tOn[1] = power;
    GtmTomPwmHl_run();
}