#include "timer.h"


void TIM3_PWM_Init(u16 arr,u16 psc)
{
       
        GPIO_InitTypeDef GPIO_InitStructure;
        TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstruct;
        TIM_OCInitTypeDef TIM_OCInitStructure;
       
       
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//�ı���Ӧ�����źź�ʱ�Ӻţ������в�ͬ������PWM������˴���PA.7��TIM3_CH1û����ӳ��
        //RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); //�Ƿ�������ӳ��
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
       
       
        GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
        GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
        GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
        GPIO_Init(GPIOB,&GPIO_InitStructure);
  //GPIO_SetBits(GPIOA,GPIO_Pin_1);//��ʼΪ�͵�ƽ�����п���
       
        //GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);//�Ƿ�������ӳ��
       

        TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1;
        TIM_TimeBaseInitstruct.TIM_CounterMode=TIM_CounterMode_Up;
        TIM_TimeBaseInitstruct.TIM_Period=arr;
        TIM_TimeBaseInitstruct.TIM_Prescaler=psc;
        TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitstruct);
       

        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ�� PWM ģʽ 2
        TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
        TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //������Ը�
        TIM_OC3Init(TIM3, &TIM_OCInitStructure); //��ʼ�� TIM3 OC1
				TIM_OC4Init(TIM3, &TIM_OCInitStructure); //��ʼ�� TIM3 OC1
       
        TIM_Cmd(TIM3, ENABLE);
       
        TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
				TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);


}
