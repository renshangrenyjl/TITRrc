#ifndef __PWM_H
#define __PWM_H

#include "stm32f10x.h"


/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 我们这里默认使用TIM3

/*端口部分功能重映像*/
//#define            TIM_GPIO_Remap                GPIO_PartialRemap_TIM3

#define            GENERAL_TIM                   TIM4
#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_CLK               RCC_APB1Periph_TIM4
#define            GENERAL_TIM_Period            99
#define            GENERAL_TIM_Prescaler         71
// TIM3 输出比较通道1
#define            GENERAL_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH1_PORT          GPIOB
#define            GENERAL_TIM_CH1_PIN           GPIO_Pin_6

// TIM3 输出比较通道2
#define            GENERAL_TIM_CH2_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH2_PORT          GPIOB
#define            GENERAL_TIM_CH2_PIN           GPIO_Pin_7

// TIM3 输出比较通道3
#define            GENERAL_TIM_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH3_PORT          GPIOB
#define            GENERAL_TIM_CH3_PIN           GPIO_Pin_8

// TIM3 输出比较通道4
#define            GENERAL_TIM_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH4_PORT          GPIOB
#define            GENERAL_TIM_CH4_PIN           GPIO_Pin_9

//电机驱动控制端口LF
#define            DRIVER_GPIO_CLK               RCC_APB2Periph_GPIOA
#define            DRIVER_GPIO_PORT              GPIOA
#define            LF_DRIVER_A1_PIN              GPIO_Pin_4
#define            LF_DRIVER_A2_PIN              GPIO_Pin_5

//电机驱动控制端口LB
#define            LB_DRIVER_B1_PIN              GPIO_Pin_6
#define            LB_DRIVER_B2_PIN              GPIO_Pin_7

//电机驱动控制端口RF
#define            RF_DRIVER_A1_PIN              GPIO_Pin_8
#define            RF_DRIVER_A2_PIN              GPIO_Pin_12

//电机驱动控制端口RB

#define            RB_DRIVER_B1_PIN              GPIO_Pin_1
#define            RB_DRIVER_B2_PIN              GPIO_Pin_11





/**************************函数声明********************************/
void Motion_TIM_Init(void);
void Motion_setPWM(int PWML,int PWMR);



#endif /* __MOTION_PWM_H */

