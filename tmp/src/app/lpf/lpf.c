/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "lpf.h"
#include "Platform_Types.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define T_S             0.0001f
#define PI              3.141592f
#define RPM_THRESHOLD   2000.0f
#define RPS_THRESHOLD   2 * PI * RPM_THRESHOLD / 60
#define MUL_LOW         4
#define MUL_HIGH        2

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
float32 lowPassFilter(float32 w_ref)
{
    static float32 prevLpf = 0.0f;

    float32 ret = 0.0f;
    float32 w_cut = (w_ref >= RPS_THRESHOLD) ? w_ref * MUL_HIGH : w_ref * MUL_LOW;

    ret = (prevLpf + (T_S * w_cut * w_ref)) / (1 + T_S * w_cut);
    prevLpf = ret;

    return ret;
}
