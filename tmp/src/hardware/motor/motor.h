#ifndef MOTOR_H_
#define MOTOR_H_

#include "Ifx_Types.h"

#define CW      FALSE
#define CCW     TRUE

extern void initMotors(void);
extern void setMotorsPower(float32 power_chA, float32 power_chB);

#endif /* MOTOR_H_ */
