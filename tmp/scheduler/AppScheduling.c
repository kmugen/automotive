#include "AppScheduling.h"
#include "driver_stm.h"

#include "IfxPort.h"
#include "IfxPort_PinMap.h"

#include "motor.h"

#define RPS_MAX     654.32f
#define V_MAX       12
#define RPS_PER_V   RPS_MAX / V_MAX
#define V_PER_RPS   1 / RPS_PER_V
#define PI          3.141592f
#define T_S         0.001f
#define W_SS        120 * PI
#define MS_PER_SEC  1000

typedef struct
{
        uint32 cnt_1ms;
        uint32 cnt_10ms;
        uint32 cnt_100ms;
}TestCnt;

static void Task1ms(void);
static void Task10ms(void);
static void Task100ms(void);

TestCnt stTestCnt;

const float32 Kp = 1;
const float32 Ki = 10;

float32 w;
float32 w_ref;
float32 w_lpf;
float32 v_in;
float32 w_err;
float32 int_w_err;
float32 prev_theta;
float32 cur_theta;

static void Task1ms(void)
{
    stTestCnt.cnt_1ms++;

    if (stTestCnt.cnt_1ms < 4000 || stTestCnt.cnt_1ms >= 41000)
    {
        w_ref = 0;
    }
    else if (stTestCnt.cnt_1ms < 19000)
    {
        w_ref = W_SS / 15 * (((float32)stTestCnt.cnt_1ms / 1000) - 4);
    }
    else if (stTestCnt.cnt_1ms < 26000)
    {
        w_ref = W_SS;
    }
    else if (stTestCnt.cnt_1ms < 41000)
    {
        w_ref = W_SS / 15 * (41 - ((float32)stTestCnt.cnt_1ms / 1000));
    }
//    if (w_ref > 0)
//    {
////        w_lpf = lowPassFilter(w_ref);
//
//        cur_theta = getEncoderPos();
//        w = (cur_theta - prev_theta) * 1000;
//        prev_theta = cur_theta;
//
////        w_err = w_lpf - w;
//
//        w_err = w_ref - w;
//
//        int_w_err += w_err * 0.001;
//        if (int_w_err > 10)
//        {
//            int_w_err = 10;
//        }
//        if (int_w_err < -10)
//        {
//            int_w_err = -10;
//        }
//
//        v_in = (Kp * w_err) + (Ki * int_w_err);
//    }
//    else
//    {
//        v_in = 0;
//    }
//
//    if (v_in > 12)
//    {
//        v_in = 12;
//    }
//    else if (v_in < 0)
//    {
//        v_in = 0;
//    }



    setMotorPower(w_ref / RPS_MAX);
}

static void Task10ms(void)
{
    stTestCnt.cnt_10ms++;
}

static void Task100ms(void)
{
    stTestCnt.cnt_100ms++;
}

void AppScheduling(void)
{
    if(schedulingInfo.f_1ms == 1)
    {
        schedulingInfo.f_1ms = 0;
        Task1ms();

        if(schedulingInfo.f_10ms == 1)
        {
            schedulingInfo.f_10ms = 0;
            Task10ms();
        }

        if(schedulingInfo.f_100ms == 1)
        {
            schedulingInfo.f_100ms = 0;
            Task100ms();
        }
    }
}
