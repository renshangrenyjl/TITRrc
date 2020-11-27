#include "timer.h"


void TIM3_PWM_Init(u16 arr,u16 psc)
{
       
        GPIO_InitTypeDef GPIO_InitStructure;
        TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstruct;
        TIM_OCInitTypeDef TIM_OCInitStructure;
       
       
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//改变相应的引脚号和时钟号，就能有不同的引脚PWM输出，此处是PA.7，TIM3_CH1没有重映射
        //RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); //是否启用重映射
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
       
       
        GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
        GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
        GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
        GPIO_Init(GPIOB,&GPIO_InitStructure);
  //GPIO_SetBits(GPIOA,GPIO_Pin_1);//初始为低电平，可有可无
       
        //GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);//是否启用重映射
       

        TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1;
        TIM_TimeBaseInitstruct.TIM_CounterMode=TIM_CounterMode_Up;
        TIM_TimeBaseInitstruct.TIM_Period=arr;
        TIM_TimeBaseInitstruct.TIM_Prescaler=psc;
        TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitstruct);
       

        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择 PWM 模式 2
        TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
        TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性高
        TIM_OC3Init(TIM3, &TIM_OCInitStructure); //初始化 TIM3 OC1
				TIM_OC4Init(TIM3, &TIM_OCInitStructure); //初始化 TIM3 OC1
       
        TIM_Cmd(TIM3, ENABLE);
       
        TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
				TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);


}
