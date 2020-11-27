#include "JDQ.H"
#include "usart.h"


//�̵��� IO��ʼ��
void JDQ_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PB,PE�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;				 //LED0-->PB.5 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
 						 //PB.5 �����
GPIO_SetBits(GPIOB,GPIO_Pin_12);//��

}
 
void JDQ_on(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);//�̵�������
	printf("�̵�������");
}

void JDQ_off(void)
{
	 GPIO_SetBits(GPIOB,GPIO_Pin_12);//�رռ̵���
	printf("�̵����ر�");
}