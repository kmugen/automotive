#include "driver_stm.h"

typedef struct
{
        Ifx_STM             *stmSfr;
        IfxStm_CompareConfig stmConfig;
} App_Stm;

App_Stm g_stm;
uint32 cnt_100us = 0;
schedulingFlag schedulingInfo;

IFX_INTERRUPT(STM_Int0Handler, 0, 100);
void STM_Int0Handler(void)
{
    IfxCpu_enableInterrupts();

    IfxStm_clearCompareFlag(g_stm.stmSfr, g_stm.stmConfig.comparator);
    IfxStm_increaseCompare(g_stm.stmSfr, g_stm.stmConfig.comparator, 10000);

    cnt_100us++;

    if ((cnt_100us % 1) == 0)
    {
        schedulingInfo.f_100us = 1;
    }
    if ((cnt_100us % 10) == 0)
    {
        schedulingInfo.f_1ms = 1;
    }
    if ((cnt_100us % 100) == 0)
    {
        schedulingInfo.f_10ms = 1;
    }
    if ((cnt_100us % 1000) == 0)
    {
        schedulingInfo.f_100ms = 1;
    }
}

void initStm(void)
{
    boolean irqState = IfxCpu_disableInterrupts();
    IfxStm_enableOcdsSuspend(&MODULE_STM0);
    g_stm.stmSfr = &MODULE_STM0;
    IfxStm_initCompareConfig(&g_stm.stmConfig);

    g_stm.stmConfig.triggerPriority = 100;
    g_stm.stmConfig.typeOfService   = IfxSrc_Tos_cpu0;
    g_stm.stmConfig.ticks           = 10000;

    IfxStm_initCompare(g_stm.stmSfr, &g_stm.stmConfig);

    IfxCpu_restoreInterrupts(irqState);
}
