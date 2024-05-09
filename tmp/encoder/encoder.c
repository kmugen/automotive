/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "encoder.h"
#include "gpio.h"
#include "Platform_Types.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define CW                  1
#define CCW                 -1

#define PI                  3.141592f

#define TICK_PER_REV        48
#define REV_PER_TICK        2 * PI / TICK_PER_REV

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
sint32 g_cnt_ticks = 0;
sint8 g_encoder_dir = CW;

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/

void initEncoder(void)
{
    setPinInput(PIN_CH_A);
    setPinInput(PIN_CH_B);
}

void countEncoderTicks(void)
{
    static boolean prev_ch_A = FALSE;
    static boolean prev_ch_B = FALSE;
    static boolean cur_ch_A = FALSE;
    static boolean cur_ch_B = FALSE;

    cur_ch_A = getPinState(PIN_CH_A);
    cur_ch_B = getPinState(PIN_CH_B);

    /* 채널 A 상승 엣지, 방향 결정 */
    if ((prev_ch_A == FALSE) && (cur_ch_A == TRUE))
    {
        g_encoder_dir = (cur_ch_B == FALSE) ? CW : CCW;
    }

    if (prev_ch_A != cur_ch_A)
    {
        g_cnt_ticks += g_encoder_dir;
    }

    if (prev_ch_B != cur_ch_B)
    {
        g_cnt_ticks += g_encoder_dir;
    }

    prev_ch_A = cur_ch_A;
    prev_ch_B = cur_ch_B;
}

sint32 getEncoderTicks(void)
{
    return g_cnt_ticks;
}

float32 getEncoderPos(void)
{
    return g_cnt_ticks * REV_PER_TICK;
}

sint8 getEncoderDir(void)
{
    return g_encoder_dir;
}
