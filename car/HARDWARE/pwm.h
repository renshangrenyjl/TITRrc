#ifndef __PWM_H
#define __PWM_H

#include "stm32f10x.h"


/************ͨ�ö�ʱ��TIM�������壬ֻ��TIM2��3��4��5************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������Ĭ��ʹ��TIM3

/*�˿ڲ��ֹ�����ӳ��*/
//#define            TIM_GPIO_Remap                GPIO_PartialRemap_TIM3

#define            GENERAL_TIM                   TIM4
#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_CLK               RCC_APB1Periph_TIM4
#define            GENERAL_TIM_Period            99
#define            GENERAL_TIM_Prescaler         71
// TIM3 ����Ƚ�ͨ��1
#define            GENERAL_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH1_PORT          GPIOB
#define            GENERAL_TIM_CH1_PIN           GPIO_Pin_6

// TIM3 ����Ƚ�ͨ��2
#define            GENERAL_TIM_CH2_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH2_PORT          GPIOB
#define            GENERAL_TIM_CH2_PIN           GPIO_Pin_7

// TIM3 ����Ƚ�ͨ��3
#define            GENERAL_TIM_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH3_PORT          GPIOB
#define            GENERAL_TIM_CH3_PIN           GPIO_Pin_8

// TIM3 ����Ƚ�ͨ��4
#define            GENERAL_TIM_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH4_PORT          GPIOB
#define            GENERAL_TIM_CH4_PIN           GPIO_Pin_9

//����������ƶ˿�LF
#define            DRIVER_GPIO_CLK               RCC_APB2Periph_GPIOA
#define            DRIVER_GPIO_PORT              GPIOA
#define            LF_DRIVER_A1_PIN              GPIO_Pin_4
#define            LF_DRIVER_A2_PIN              GPIO_Pin_5

//����������ƶ˿�LB
#define            LB_DRIVER_B1_PIN              GPIO_Pin_6
#define            LB_DRIVER_B2_PIN              GPIO_Pin_7

//����������ƶ˿�RF
#define            RF_DRIVER_A1_PIN              GPIO_Pin_8
#define            RF_DRIVER_A2_PIN              GPIO_Pin_12

//����������ƶ˿�RB

#define            RB_DRIVER_B1_PIN              GPIO_Pin_1
#define            RB_DRIVER_B2_PIN              GPIO_Pin_11





/**************************��������********************************/
void Motion_TIM_Init(void);
void Motion_setPWM(int PWML,int PWMR);



#endif /* __MOTION_PWM_H */

