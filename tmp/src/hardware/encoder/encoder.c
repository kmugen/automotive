/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "encoder.h"
#include "gpio.h"
#include "Platform_Types.h"
#include "pinSettings.h"

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
sint32 g_ticks_chA = 0;
sint8 g_dir_chA = CW;

sint32 g_ticks_chB = 0;
sint8 g_dir_chB = CW;

boolean g_cur_chA_1;
boolean g_cur_chA_2;
boolean g_prev_chA_1;
boolean g_prev_chA_2;
boolean g_cur_chB_1;
boolean g_cur_chB_2;
boolean g_prev_chB_1;
boolean g_prev_chB_2;

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/

void initEncoders(void)
{
    setPinInput(PIN_ENCODER_CHA_1);
    setPinInput(PIN_ENCODER_CHA_2);
    setPinInput(PIN_ENCODER_CHB_1);
    setPinInput(PIN_ENCODER_CHB_2);
}

void countEncoderTicks(void)
{
    g_cur_chA_1 = getPinState(PIN_ENCODER_CHA_1);
    g_cur_chA_2 = getPinState(PIN_ENCODER_CHA_2);

    /* 채널 A 상승 엣지, 방향 결정 */
    if ((g_prev_chA_1 == FALSE) && (g_cur_chA_1 == TRUE))
    {
        g_dir_chA = (g_cur_chA_2 == FALSE) ? CW : CCW;
    }

    if (g_prev_chA_1 != g_cur_chA_1)
    {
        g_ticks_chA += g_dir_chA;
    }

    if (g_prev_chA_2 != g_cur_chA_2)
    {
        g_ticks_chA += g_dir_chA;
    }

    g_prev_chA_1 = g_cur_chA_1;
    g_prev_chA_2 = g_cur_chA_2;

    g_cur_chB_1 = getPinState(PIN_ENCODER_CHB_1);
    g_cur_chB_2 = getPinState(PIN_ENCODER_CHB_2);

    /* 채널 A 상승 엣지, 방향 결정 */
    if ((g_prev_chB_1 == FALSE) && (g_cur_chB_1 == TRUE))
    {
        g_dir_chB = (g_cur_chB_2 == FALSE) ? CW : CCW;
    }

    if (g_prev_chB_1 != g_cur_chB_1)
    {
        g_ticks_chB += g_dir_chB;
    }

    if (g_prev_chB_2 != g_cur_chB_2)
    {
        g_ticks_chB += g_dir_chB;
    }

    g_prev_chB_1 = g_cur_chB_1;
    g_prev_chB_2 = g_cur_chB_2;


}

sint32 getEncoderTicks(uint8 chn)
{
    return ((chn == 0) ? g_ticks_chA :g_ticks_chB);
}

float32 getEncoderPos(uint8 chn)
{
    return ((chn == 0) ? g_ticks_chA :g_ticks_chB) * REV_PER_TICK;
}

sint8 getEncoderDir(uint8 chn)
{
    return ((chn == 0) ? g_dir_chA :g_dir_chB);
}
