#ifndef SRC_HARDWARE_ENCODER_ENCODER_H_
#define SRC_HARDWARE_ENCODER_ENCODER_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define PIN_CH_A            P15_1
#define PIN_CH_B            P15_4

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
extern void initEncoder(void);
extern float32 getEncoderPos(void);
extern sint8 getEncoderDir(void);
extern void countEncoderTicks(void);

#endif /* SRC_HARDWARE_ENCODER_ENCODER_H_ */
