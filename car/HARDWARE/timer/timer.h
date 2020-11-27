#ifndef __TIME_H_
#define __TIME_H_
#include "stm32f10x.h"

extern int a;

void TIM_3_Int_Init(u16 arr,u16 psc);
void TIM_3_PWM_Init(u16 arr,u16 psc);


#endif
