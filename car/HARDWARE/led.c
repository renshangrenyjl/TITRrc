#include "led.h"
#include "stm32f10x.h"


void led_Init(void)
{
  GPIO_InitTypeDef   	GPIO_InitStructurs;

	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
  //RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

  GPIO_InitStructurs.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructurs.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitStructurs.GPIO_Speed=GPIO_Speed_50MHz;	
	GPIO_Init(GPIOC,&GPIO_InitStructurs);
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
	

	
	
	/*GPIO_InitStructurs.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructurs.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructurs.GPIO_Speed=GPIO_Speed_50MHz;	
	GPIO_Init(GPIOA,&GPIO_InitStructurs);
  GPIO_SetBits(GPIOA,GPIO_Pin_8);*/
	
}


