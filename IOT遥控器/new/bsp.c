#include<includes.h>

/*********************************************************************************************************
*                                          ȫ�ֱ���
*********************************************************************************************************/

/*********************************************************************************************************
*                                          ��������
*********************************************************************************************************/

void RCC_Configuration(void);	/* ��ʼ��ϵͳʱ�� */
void GPIO_Configuration(void);	/* IO�ڵ�����*/
void USART1_Configuration(void);	/* �������� */
void USART2_Configuration(void);

void  BSP_Init (void)
{
	RCC_Configuration();	/* ��ʼ��ϵͳʱ�� */
	GPIO_Configuration();	/* IO������ */
	USART1_Configuration();	/* ���� */
	USART2_Configuration();

}
/*********************************************************************************************************
* ��    �� ��RCC_Configuration
* �������� : ��ʼ��ϵͳʱ��
* ������� : none
* ���ز��� : none.
* ��    �� : 
* ��    �� �������ڡ��޸��������޸�ԭ��
* ����˵�� : �����⹦��˵�������磺�в������ȣ�
*********************************************************************************************************/
void RCC_Configuration(void)
{
	SystemInit(); 

	/*APB1 36MHz ����timerʱ�ᱶƵΪ72mhz����������Щ�ڴ�ʱ���Ͽ�����ȥ�鿴*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 | RCC_APB1Periph_USART2 , ENABLE);
	
	/*APB2 72MHz ����timerʱ�ᱶƵΪ144mhz����������Щ�ڴ�ʱ���Ͽ�����ȥ�鿴*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOB
  						| RCC_APB2Periph_GPIOA| RCC_APB2Periph_USART1 , ENABLE);
}

/*********************************************************************************************************
* ��    �� ��GPIO_Configuration
* �������� : ��ʼ��IO������
* ������� : none
* ���ز��� : none.
* ��    �� : 
* ��    �� �������ڡ��޸��������޸�ԭ��
* ����˵�� : �����⹦��˵�������磺�в������ȣ�
******************* **************************************************************************************/ 
void GPIO_Configuration(void)
{   
    GPIO_InitTypeDef GPIO_InitTypeDe;

    GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitTypeDe);
    
    GPIO_InitTypeDe.GPIO_Mode= GPIO_Mode_IPU ;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitTypeDe);
    
    GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU ;
    GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_5;
    GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitTypeDe);
	
    GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU ;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitTypeDe);
    
    GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_15;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeDe);
	  
      
    GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_11;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitTypeDe);
	
	GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeDe);
		
    GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeDe);
    
    GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeDe);
    
    GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeDe);
    
    GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_14;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeDe);
    
    GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_11;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeDe);
    
    GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU ;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeDe);
	
	GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeDe);

    GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeDe);
	
	GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU ;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_7;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeDe);

    GPIO_InitTypeDe.GPIO_Mode=GPIO_Mode_IPU ;
	GPIO_InitTypeDe.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitTypeDe. GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitTypeDe);
}
/*********************************************************************************************************
* ��    �� ��USART1_Configuration
* �������� : ��ʼ������1
* ������� : none
* ���ز��� : none.
* ��    �� : 
* ��    �� �������ڡ��޸��������޸�ԭ��
* ����˵�� : �����⹦��˵�������磺�в������ȣ�
*********************************************************************************************************/
void USART1_Configuration(void)
{
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	/* Configure USART1 Rx (PA.10) as input floating */

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������ģʽ	   
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure USART1 Tx (PA.09) as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//�����������
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = 9600;//����9600bps
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//����λ8λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//ֹͣλ1λ
	USART_InitStructure.USART_Parity = USART_Parity_No;	//��У��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
	/* Configure USART1 */
	USART_Init(USART1, &USART_InitStructure);//���ô��ڲ�������
	/* Enable USART1 Receive and Transmit interrupts */
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//ʹ�ܽ����ж�
	/* Enable the USART1 */
	USART_Cmd(USART1, ENABLE);	                  //ʹ�ܴ���
}
void USART2_Configuration(void)
{
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	/* Configure USART1 Rx (PA.10) as input floating */
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������ģʽ	   
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure USART1 Tx (PA.09) as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//�����������
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = 9600;//����9600bps
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//����λ8λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//ֹͣλ1λ
	USART_InitStructure.USART_Parity = USART_Parity_No;//��У��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //��Ӳ������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;					//�շ�ģʽ
	/* Configure USART1 */
	
	USART_Init(USART2, &USART_InitStructure);							//���ô��ڲ�������
	/* Enable USART1 Receive and Transmit interrupts */
//	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);                    //ʹ�ܽ����ж�
	/* Enable the USART1 */
	USART_Cmd(USART2, ENABLE);	                  //ʹ�ܴ���
}
/*******************************************************************************q
* Function Name  : TIM2_Configuration
* Description    : ��ʱ�� 1ms
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM2_Configuration(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = (10000 - 1);		 //arr  ��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = (7200 - 1);		 //	 psc ��Ƶ  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	 //ʱ�ӷָ�
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//���ϼ���
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	 
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);	/* ��ʱ���ж�ʹ�� */
	TIM_Cmd(TIM2, ENABLE);	/* ʹ�� */	
}
/*********************************************************************************************************
* ��    �� ��TIM3_Configuration
* �������� : ��ʼ����ʱ��  PWM
* ������� : none
* ���ز��� : none.
* ��    �� : 
* ��    �� �������ڡ��޸��������޸�ԭ��
* ����˵�� : �����⹦��˵�������磺�в������ȣ�
*********************************************************************************************************/
void TIM3_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	                   
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		 //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	        	
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = (10000- 1);					//arr  ��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = (15-1);	 			 	//��Ƶ	psc
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;				 	//ʱ�ӷָһ��д0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 	//����Ϊ���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	/* PWM1 Mode configuration: Channel1*/
	TIM_OCInitStructure.TIM_Pulse = 5000;						// ��ʼֵ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;			   //pwmģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//ʹ��ͨ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;	//�ߵ�ƽ
	
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);	                  
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);			//ʹ�ܻ���ʧ��TIMx��CCR3�ϵ�Ԥװ�ؼĴ���

	
	TIM_ARRPreloadConfig(TIM3, ENABLE);  /* �ж�ʹ�� */
	/* TIM3 enable counter */
	TIM_Cmd(TIM3, ENABLE);	/* ʹ�� */
}
/*******************************************************************************
* Function Name  : TIM4_Configuration
* Description    : ��ʱ��
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM4_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	/* ����ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;                   
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		 //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	        	
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = 199;					//arr  ��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = 7199;	 			 	//��Ƶ	psc
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;				 	//ʱ�ӷָһ��д0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 	//����Ϊ���ϼ���ģʽ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	/* PWM1 Mode configuration: Channel1*/
//	TIM_OCInitStructure.TIM_Pulse = 5000;						// ��ʼֵ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;			   //pwmģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//ʹ��ͨ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;	//�͵�ƽ	
//	TIM_OC3Init(TIM4, &TIM_OCInitStructure);	                  
//	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);	//ʹ�ܻ���ʧ��TIMx��CCR3�ϵ�Ԥװ�ؼĴ��� 
	
	TIM_OC1Init(TIM4,&TIM_OCInitStructure);        //ͨ��1
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
    TIM_OC2Init(TIM4,&TIM_OCInitStructure);        //ͨ��2
    TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
    TIM_OC3Init(TIM4, &TIM_OCInitStructure); //ʹ��ͨ��3
    TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
    TIM_OC4Init(TIM4, &TIM_OCInitStructure); //ʹ��ͨ��4
    TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);	
        
	TIM_ARRPreloadConfig(TIM4, ENABLE);  /* �ж�ʹ�� */
	/* TIM3 enable counter */
	TIM_Cmd(TIM4, ENABLE);	/* ʹ�� */
}
/*******************************************************************************
* Function Name  : TIM5_Configuration
* Description    : ������ģʽ						   PA0 PA1
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM5_Configuration(void)
{
	
}
/*******************************************************************************
* Function Name  : TIM6_Configuration
* Description    : pid��ʱ����
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM6_Configuration(void)
{ 
	
}
/*******************************************************************************
* Function Name  : TIM7_Configuration
* Description    : ��ʱ��
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM7_Configuration(void)
{		
}

/*******************************************************************************
* Function Name  : EXTI_Configuration		   �ж�����
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI_Configuration(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	//GPIOB.11 �ж����Լ��жϳ�ʼ������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;                        //���ó���������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	   
	GPIO_Init(GPIOB, &GPIO_InitStructure);                               //�����Ƕ�����Ҫ�õ���I/O�ڵ�����

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource11);          //ѡ��gpioC5����Ϊ�ⲿ�ж�ʹ��
	EXTI_InitStructure.EXTI_Line=EXTI_Line11;                            //ʹ���ⲿ�ж���5 
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	                //�ⲿ�ж�
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;             //�½��ش���
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;                           //�ж���ʹ��
	EXTI_Init(&EXTI_InitStructure);	

	//GPIOA.3 �ж����Լ��жϳ�ʼ������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;                        //���ó���������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	   
	GPIO_Init(GPIOA, &GPIO_InitStructure);                               //�����Ƕ�����Ҫ�õ���I/O�ڵ�����

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource3);          //ѡ��gpioC5����Ϊ�ⲿ�ж�ʹ��
	EXTI_InitStructure.EXTI_Line=EXTI_Line3;                            //ʹ���ⲿ�ж���5 
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	                //�ⲿ�ж�
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;             //�½��ش���
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;                           //�ж���ʹ��
	EXTI_Init(&EXTI_InitStructure);	
	}

/*********************************************************************************************************
* ��    �� ��NVIC_Configuration
* �������� : ��ʼ���ж����ȼ�
* ������� : none
* ���ز��� : none.
* ��    �� : 
* ��    �� �������ڡ��޸��������޸�ԭ��
* ����˵�� : �����⹦��˵�������磺�в������ȣ�
*********************************************************************************************************/
void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	            //ֻ���޸�һ��
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;	   	//�����ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;		   //��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			   //�����ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		//ʹ��
	NVIC_Init(&NVIC_InitStructure);
}










