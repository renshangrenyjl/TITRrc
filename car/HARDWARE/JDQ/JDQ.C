#include "JDQ.H"
#include "usart.h"


//继电器 IO初始化
void JDQ_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PB,PE端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;				 //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
 						 //PB.5 输出高
GPIO_SetBits(GPIOB,GPIO_Pin_12);//关

}
 
void JDQ_on(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);//继电器开启
	printf("继电器开启");
}

void JDQ_off(void)
{
	 GPIO_SetBits(GPIOB,GPIO_Pin_12);//关闭继电器
	printf("继电器关闭");
}



