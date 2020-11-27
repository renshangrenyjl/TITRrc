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
	SystemInit();	// 配置系统时钟为72M
	 //uart_init(115200);
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
     TIM3_PWM_Init(1999,719);//这里的arr的值和psc的值可以修改，只要在不分频情况下为72MHZ
//			TIM_SetCompare4(TIM3, 1920);//爪子放下
//		      delay_ms(300);
//		TIM_SetCompare3(TIM3, 1750);//爪子打开	
	
	
		GPIO_InitTypeDef GPIO_InitStructure;	
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); // 使能PC端口时钟
	 RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOD, ENABLE);
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);
	
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);  //初始化PC端口
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_3 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB,&GPIO_InitStructure);  //初始化PC端口
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);  //初始化PC端口
  
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);  //初始化PC端口
	  
		
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //初始化PC端口
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //初始化PC端口
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //初始化PC端口
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);  //初始化PC端口
	
	
	
	

	while(1)
	{
		 move_one();
   
//		TIM_SetCompare2(TIM3, 1870);//爪子抬起
//		      delay_ms(300);
//		TIM_SetCompare1(TIM3, 1750);//爪子打开
//		delay_ms(300);
//		TIM_SetCompare2(TIM3, 1950);//爪子放下
//		      delay_ms(300);
//		TIM_SetCompare1(TIM3, 1800);//爪子闭合
//		delay_ms(300);


	}
	
		
}


