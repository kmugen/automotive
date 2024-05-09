#ifndef SRC_TC275_GPIO_GPIO_H_
#define SRC_TC275_GPIO_GPIO_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "IfxPort_PinMap.h"
#include "IfxPort.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
/* TC275 쉴드바디 가용 포트 핀 */
#define P00_0       IfxPort_P00_0
#define P00_1       IfxPort_P00_1
#define P00_2       IfxPort_P00_2
#define P00_3       IfxPort_P00_3
#define P00_4       IfxPort_P00_4
#define P00_5       IfxPort_P00_5
#define P00_6       IfxPort_P00_6
#define P00_7       IfxPort_P00_7
#define P00_8       IfxPort_P00_8
#define P00_9       IfxPort_P00_9
#define P00_10      IfxPort_P00_10
#define P00_11      IfxPort_P00_11
#define P00_12      IfxPort_P00_12

#define P02_0       IfxPort_P02_0
#define P02_1       IfxPort_P02_1
#define P02_3       IfxPort_P02_3
#define P02_4       IfxPort_P02_4
#define P02_5       IfxPort_P02_5
#define P02_6       IfxPort_P02_6
#define P02_7       IfxPort_P02_7
#define P02_8       IfxPort_P02_8

#define P10_0       IfxPort_P10_0
#define P10_1       IfxPort_P10_1
#define P10_2       IfxPort_P10_2
#define P10_3       IfxPort_P10_3
#define P10_4       IfxPort_P10_4
#define P10_5       IfxPort_P10_5
#define P10_7       IfxPort_P10_7
#define P10_8       IfxPort_P10_8

#define P11_2       IfxPort_P11_2
#define P11_3       IfxPort_P11_3
#define P11_6       IfxPort_P11_6
#define P11_9       IfxPort_P11_9
#define P11_10      IfxPort_P11_10
#define P11_11      IfxPort_P11_11
#define P11_12      IfxPort_P11_12

#define P13_1       IfxPort_P13_1
#define P13_2       IfxPort_P13_2
#define P13_3       IfxPort_P13_3

#define P14_0       IfxPort_P14_0
#define P14_1       IfxPort_P14_1

#define P15_0       IfxPort_P15_0
#define P15_1       IfxPort_P15_1
#define P15_2       IfxPort_P15_2
#define P15_3       IfxPort_P15_3
#define P15_4       IfxPort_P15_4
#define P15_5       IfxPort_P15_5
#define P15_6       IfxPort_P15_6
#define P15_8       IfxPort_P15_8

#define P20_0       IfxPort_P20_0
#define P20_3       IfxPort_P20_3
#define P20_6       IfxPort_P20_6
#define P20_7       IfxPort_P20_7
#define P20_8       IfxPort_P20_8
#define P20_9       IfxPort_P20_9
#define P20_10      IfxPort_P20_10

#define P21_0       IfxPort_P21_0
#define P21_2       IfxPort_P21_2

#define P22_2       IfxPort_P22_2

#define P23_1       IfxPort_P23_1
#define P23_2       IfxPort_P23_2
#define P23_3       IfxPort_P23_3
#define P23_4       IfxPort_P23_4
#define P23_5       IfxPort_P23_5

#define P32_3       IfxPort_P32_3
#define P32_4       IfxPort_P32_4

#define P33_0       IfxPort_P33_0
#define P33_1       IfxPort_P33_1
#define P33_2       IfxPort_P33_2
#define P33_3       IfxPort_P33_3
#define P33_4       IfxPort_P33_4
#define P33_5       IfxPort_P33_5
#define P33_6       IfxPort_P33_6
#define P33_7       IfxPort_P33_7
#define P33_8       IfxPort_P33_8
#define P33_9       IfxPort_P33_9
#define P33_10      IfxPort_P33_10
#define P33_11      IfxPort_P33_11
#define P33_12      IfxPort_P33_12
#define P33_13      IfxPort_P33_13

/* gpio 모드 */
#define INPUT       0x10     /* input pull-up */
#define OUTPUT      0x80     /* output push-pull */

/* gpio 핀 state */
#define HIGH        IfxPort_State_high
#define LOW         IfxPort_State_low
#define TOGGLED     IfxPort_State_toggled

/* gpio 타입 */
#define gpio_t      IfxPort_Pin

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
extern void setPinMode(gpio_t pin, uint8 mode);

/*********************************************************************************************************************/
/*------------------------------------------Inline Function Implementation-------------------------------------------*/
/*********************************************************************************************************************/
static inline void setPinInput(gpio_t pin)
{
    setPinMode(pin, INPUT);
}

static inline void setPinOutput(gpio_t pin)
{
    setPinMode(pin, OUTPUT);
}

static inline void setPinState(gpio_t pin, uint32 state)
{
    pin.port->OMR.U = (state << pin.pinIndex);
}

static inline void setPinHigh(gpio_t pin)
{
    setPinState(pin, HIGH);
}

static inline void setPinLow(gpio_t pin)
{
    setPinState(pin, LOW);
}

static inline void togglePin(gpio_t pin)
{
    setPinState(pin, TOGGLED);
}

static inline boolean getPinState(gpio_t pin)
{
    return IfxPort_getPinState(pin.port, pin.pinIndex);
}

#endif /* SRC_TC275_GPIO_GPIO_H_ */
