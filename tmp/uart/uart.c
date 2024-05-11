///*********************************************************************************************************************/
///*-----------------------------------------------------Includes------------------------------------------------------*/
///*********************************************************************************************************************/
#include "IfxAsclin_Asc.h"
#include "IfxCpu_Irq.h"
#include "uart.h"
#include "IfxStdIf_DPipe.h"
#include "Ifx_Console.h"
//
///*********************************************************************************************************************/
///*------------------------------------------------------Macros-------------------------------------------------------*/
///*********************************************************************************************************************/
#define ASC_TX_BUFFER_SIZE      256
#define ASC_RX_BUFFER_SIZE      256
#define ASC_BAUDRATE            115200

#define ISR_PRIORITY_UART_TX    110
#define ISR_PRIORITY_UART_RX    111
#define ISR_PRIORITY_UART_ER    112
//
///*********************************************************************************************************************/
///*-------------------------------------------------Global variables--------------------------------------------------*/
///*********************************************************************************************************************/
static IfxAsclin_Asc g_ascHandle;
static IfxStdIf_DPipe g_ascStdInterface;

uint8 g_uartTxBuf[ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
uint8 g_uartRxBuf[ASC_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
//
///*********************************************************************************************************************/
///*---------------------------------------------Function Implementations----------------------------------------------*/
///*********************************************************************************************************************/
IFX_INTERRUPT(uartTxIsr, 0, ISR_PRIORITY_UART_TX);
IFX_INTERRUPT(uartRxIsr, 0, ISR_PRIORITY_UART_RX);
IFX_INTERRUPT(uartErIsr, 0, ISR_PRIORITY_UART_ER);

void uartTxIsr(void)
{
    IfxAsclin_Asc_isrTransmit(&g_ascHandle);
}

void uartRxIsr(void)
{
    IfxAsclin_Asc_isrReceive(&g_ascHandle);
}

void uartErIsr(void)
{
    while(1) {}
}

void initUart(void)
{
    IfxAsclin_Asc_Config ascConfig;
    IfxAsclin_Asc_initModuleConfig(&ascConfig, &MODULE_ASCLIN3);

    ascConfig.baudrate.baudrate = ASC_BAUDRATE;
    ascConfig.baudrate.oversampling = IfxAsclin_OversamplingFactor_16;

    ascConfig.bitTiming.medianFilter = IfxAsclin_SamplesPerBit_three;
    ascConfig.bitTiming.samplePointPosition = IfxAsclin_SamplePointPosition_8;

    ascConfig.interrupt.txPriority = ISR_PRIORITY_UART_TX;
    ascConfig.interrupt.rxPriority = ISR_PRIORITY_UART_RX;
    ascConfig.interrupt.erPriority = ISR_PRIORITY_UART_ER;
    ascConfig.interrupt.typeOfService = IfxSrc_Tos_cpu0;

    const IfxAsclin_Asc_Pins pins =
    {
            .cts        = NULL_PTR,
            .ctsMode    = IfxPort_InputMode_pullUp,
            .rx         = &IfxAsclin3_RXD_P32_2_IN,
            .rxMode     = IfxPort_InputMode_pullUp,
            .rts        = NULL_PTR,
            .rtsMode    = IfxPort_OutputMode_pushPull,
            .tx         = &IfxAsclin3_TX_P15_7_OUT,
            .txMode     = IfxPort_OutputMode_pushPull,
            .pinDriver  = IfxPort_PadDriver_cmosAutomotiveSpeed1
    };
    ascConfig.pins = &pins;

    ascConfig.txBuffer = g_uartTxBuf;
    ascConfig.txBufferSize = ASC_TX_BUFFER_SIZE;
    ascConfig.rxBuffer = g_uartRxBuf;
    ascConfig.rxBufferSize = ASC_RX_BUFFER_SIZE;

    IfxAsclin_Asc_initModule(&g_ascHandle, &ascConfig);

    IfxAsclin_Asc_stdIfDPipeInit(&g_ascStdInterface, &g_ascHandle);

    Ifx_Console_init(&g_ascStdInterface);
}

void writeUart(const uint8 chr)
{
    IfxAsclin_Asc_blockingWrite(&g_ascHandle, chr);
}

uint8 readUart(void)
{
    return IfxAsclin_Asc_blockingRead(&g_ascHandle);
}
