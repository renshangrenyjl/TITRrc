#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "sys.h"
#include "JDQ.h"
#include "pwm.h"
//#include "xunji.h"
#include "move.h"
#include "servo.h"
//#include "usart.h"
#include "mpu6050.h"   
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include "mpu_pid.h"
//u16 pwm=6000;



//
int main()
{
	Motion_TIM_Init();
	JDQ_Init();
	SystemInit();	// ����ϵͳʱ��Ϊ72M
	 //uart_init(115200);
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
     TIM3_PWM_Init(1999,719);//�����arr��ֵ��psc��ֵ�����޸ģ�ֻҪ�ڲ���Ƶ�����Ϊ72MHZ
//			TIM_SetCompare4(TIM3, 1920);//צ�ӷ���
//		      delay_ms(300);
//		TIM_SetCompare3(TIM3, 1750);//צ�Ӵ�	
	
	
		GPIO_InitTypeDef GPIO_InitStructure;	
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); // ʹ��PC�˿�ʱ��
	 RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOD, ENABLE);
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);
	
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);  //��ʼ��PC�˿�
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_3 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB,&GPIO_InitStructure);  //��ʼ��PC�˿�
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);  //��ʼ��PC�˿�
  
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);  //��ʼ��PC�˿�
	  
		
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //��ʼ��PC�˿�
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //��ʼ��PC�˿�
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //��ʼ��PC�˿�
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);  //��ʼ��PC�˿�
	
	
	
	

	while(1)
	{
		 move_one();
   
//		TIM_SetCompare2(TIM3, 1870);//צ��̧��
//		      delay_ms(300);
//		TIM_SetCompare1(TIM3, 1750);//צ�Ӵ�
//		delay_ms(300);
//		TIM_SetCompare2(TIM3, 1950);//צ�ӷ���
//		      delay_ms(300);
//		TIM_SetCompare1(TIM3, 1800);//צ�ӱպ�
//		delay_ms(300);


	}
	
		
}


