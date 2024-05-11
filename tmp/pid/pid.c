/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "pid.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define CH_A    0
#define CH_B    1

const float32 t_s = 0.0001;

const float32 K_p_chA = 0.01;
const float32 K_i_chA = 0.01;
const float32 K_d_chA = 0;

const float32 K_p_chB = 0.01;
const float32 K_i_chB = 0.01;
const float32 K_d_chB = 0;

float32 g_prev_err_chA;
float32 g_prev_int_err_chA;

float32 g_prev_err_chB;
float32 g_prev_int_err_chB;

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
float32 pidController(uint8 channel, float32 err)
{
    float32 ret;
    if (channel == CH_A)
    {
        g_prev_int_err_chA = g_prev_int_err_chA + err * t_s;

        ret = (err * K_p_chA) + (g_prev_int_err_chA * K_i_chA) + ((err - g_prev_err_chA) / t_s * K_d_chA);

        g_prev_err_chA = err;
    }
    else
    {
        g_prev_int_err_chB = (g_prev_int_err_chB + err * t_s > 10);
        ret = (err * K_p_chB) + (g_prev_int_err_chB * K_i_chB) + ((err - g_prev_err_chB) / t_s * K_d_chB);
        g_prev_err_chB = err;
    }

    return ret;
}
