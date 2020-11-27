#include "stm32f4xx.h"
#include "CAN.h"
/*********************************************************************************************************
BSP��飺
		�弶֧�ְ���BSP���ǽ�������Ӳ���Ͳ���ϵͳ�����������֮���һ�㣬һ����Ϊ�����ڲ���ϵͳһ���֣���Ҫ��
	ʵ�ֶԲ���ϵͳ��֧�֣�Ϊ�ϲ�����������ṩ����Ӳ���豸�Ĵ����ĺ�������ʹ֮�ܹ����õ�������Ӳ�����塣
	��Ƕ��ʽϵͳ���������У�����BSP��BSP������ڲ���ϵͳ���Եģ���ͬ�Ĳ���ϵͳ��Ӧ�ڲ�ͬ������ʽ��BSP,
	����VxWorks��BSP��Linux��BSP�����ĳһCPU��˵����ʵ�ֵĹ���һ��������д���ͽӿڶ�������ȫ��ͬ�ģ�����дBSP
	һ��Ҫ���ո�ϵͳBSP�Ķ�����ʽ��д��BSP�ı�̹��̴��������ĳһ�����͵�BSPģ���Ͻ����޸ģ��������������ϲ�
	OS������ȷ�Ľӿڣ����õ�֧���ϲ�OS��

���ã�
	�����ò���ϵͳ���еĻ�������
	1����ʼ��CPU�ڲ��Ĵ���
	2���趨RAM����ʱ��
	3��ʱ���������жϿ���������
	4����������
	
	���Ʋ���ϵͳ���еĻ���
	1�����Ƹ��ٻ�����ڴ����Ԫ������
	2��ָ��������ʼ����λ��
	3�������жϹ���
	4������ϵͳ��������
*********************************************************************************************************/
/*********************************************************************************************************
*                                         �궨��
*********************************************************************************************************/

/*********************************************************************************************************
*                                          �ṹ�����
*********************************************************************************************************/
/*********************************************************************************************************
*                                          ��������
*********************************************************************************************************/
char *itoa(int value, char *string, int radix);
void USART_OUT(USART_TypeDef* USARTx, uint8_t *Data,...);
void RCC_Configuration(void);
void GPIO_Configuration(void);
void EXTI_Configuration(void);
//void NVIC_Configuration(void);
void USART1_Configuration(void);
void USART2_Configuration(void);
void USART3_Configuration(void);
void UART4_Configuration(void);
void TIM3_Configuration(void);
/*********************************************************************************************************
*                                          ��������
*********************************************************************************************************/
void BSP_Init(void)
{	
	RCC_Configuration();
//	GPIO_Configuration();				
 	EXTI_Configuration();
	//NVIC_Configuration();
	USART1_Configuration();				//������ڴ�ӡ����ʹ���ˣ��翪���ַ��� ����Ӳ��û�����õĻ� ���ӻ�����
	USART2_Configuration();
 	USART3_Configuration();	
	UART4_Configuration();	
 	TIM3_Configuration();
	//NVIC_Configuration();
}
/*******************************************************************************
* Function Name  : RCC_Configuration
* Description    : Configures the different system clocks.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RCC_Configuration(void)
{
	SystemInit();
	/*io��ʱ������ 168MHz*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA| RCC_AHB1Periph_GPIOB| RCC_AHB1Periph_GPIOC| RCC_AHB1Periph_GPIOD| 
							RCC_AHB1Periph_GPIOE , ENABLE); 
	/*APB2 84MHz ����timerʱ�ᱶƵΪ168mhz����������Щ�ڴ�ʱ���Ͽ�����ȥ�鿴*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1| RCC_APB2Periph_TIM1| RCC_APB2Periph_TIM8| 
							RCC_APB2Periph_TIM9| RCC_APB2Periph_SYSCFG, ENABLE);
	/*APB1 42MHz ����Ϊtimerʱ�ᱶƵΪ84MHz*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2| RCC_APB1Periph_TIM3| RCC_APB1Periph_TIM4| RCC_APB1Periph_TIM5|
							RCC_APB1Periph_TIM7| RCC_APB1Periph_TIM12| RCC_APB1Periph_USART2|
							 RCC_APB1Periph_USART3| RCC_APB1Periph_UART4| RCC_APB1Periph_CAN1,ENABLE);
}
/*******************************************************************************
* Function Name  : GPIO_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None			   
*******************************************************************************/
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;	

//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_All;			//ѡ��GPIOAȫ����16���ս�
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			//I/O������Ϊ�������ģʽ
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		//�ٶ�100M			  
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			//GPIO_PuPd_DOWN		�ֱ�������I/O�ڵ�����������
//	GPIO_Init(GPIOA, &GPIO_InitStructure);

//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;			//ѡ��GPIOAȫ����16���ս�
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			//I/O������Ϊ�������ģʽ
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		//�ٶ�100M			  
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			//GPIO_PuPd_DOWN		�ֱ�������I/O�ڵ�����������
//	GPIO_Init(GPIOB, &GPIO_InitStructure);

//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_All;				//ѡ��GPIO-B12��
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			//I/O������Ϊ�������ģʽ
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			//����Ϊ�����������																
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		//�ٶ�100M			  
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		//I/O��������������������̬��
//	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11;				//ѡ��GPIO-B12��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			//I/O������Ϊ�������ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			//����Ϊ�����������																
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		//�ٶ�100M			  
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		//I/O��������������������̬��
	GPIO_Init(GPIOB, &GPIO_InitStructure);

//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13;				//ѡ��GPIO-B13��
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			//I/O������Ϊ�������ģʽ
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;			//���ÿ�©�������																
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		//�ٶ�100M			  
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		//I/O��������������������̬��
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0|GPIO_Pin_1;	//ѡ��GPIO-C0��C1��
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			//I/O������Ϊ�������ģʽ
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			//���ÿ�©�������																
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//�ٶ�50M   2��25��50��100����ѡ��			  
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		//I/O��������������������̬��
//	GPIO_Init(GPIOC, &GPIO_InitStructure);

}
/*******************************************************************************
* Function Name  : USART1_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART1_Configuration(void)
{	
	GPIO_InitTypeDef GPIO_InitStructure;                                          //����GPIO��ʼ���ṹ��
	USART_InitTypeDef USART_InitStructure;                                         //����USART��ʼ���ṹ��
	/*ʱ�����ò���Ҫ����AFIO ֻҪ����Ϊ���ù��ܼ���*/
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);						  //����PA9�������ӵ�USART1
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);					  //����PA10�������ӵ�USART1
														  
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;                                       //���ó�ʼ��GPIOΪPIN9
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;                               //����GPIO���ٶ�Ϊ50MHz
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //����GPIOģʽΪ����ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  //����GPIO�������Ϊ�������
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;						          //����GPIOΪ������������
	GPIO_Init(GPIOA,&GPIO_InitStructure);                                         //��ʼ��GPIOA��PIN9

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;                                      //���ó�ʼ��GPIOΪPIN10
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //����GPIO��ģʽΪ����ģʽ
	GPIO_Init(GPIOA,&GPIO_InitStructure);                                         //��ʼ��GPIOA��PIN10

    USART_InitStructure.USART_BaudRate=115200;                                    //����USART�Ĳ�����Ϊ115200
    USART_InitStructure.USART_Parity=USART_Parity_No;                             //����USART��У��λΪNone
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;                     //����USART������λΪ8bit
    USART_InitStructure.USART_StopBits=USART_StopBits_1;                          //����USART��ֹͣλΪ1
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //ʧ��Ӳ��������
    USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;                   //����USART��ģʽΪ���ͽ���ģʽ
  	USART_Init(USART1, &USART_InitStructure);	
    
    NVIC_InitTypeDef NVIC_InitStructure;
      
    /* Ƕ�������жϿ�������ѡ�� */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
      
    /* ����USARTΪ�ж�Դ */
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    /* �������ȼ�Ϊ1 */
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    /* �����ȼ�Ϊ1 */
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    /* ʹ���ж� */
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    /* ��ʼ������NVIC */
    NVIC_Init(&NVIC_InitStructure);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); 
 	USART_Cmd(USART1, ENABLE);
}	 
/*******************************************************************************
* Function Name  : USART2_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART2_Configuration(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;                                          //����GPIO��ʼ���ṹ��
	USART_InitTypeDef USART_InitStructure;                                         //����USART��ʼ���ṹ��
	/*ʱ�����ò���Ҫ����AFIO ֻҪ����Ϊ���ù��ܼ���*/
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource5,GPIO_AF_USART2);						  //����PA9�������ӵ�USART1
    GPIO_PinAFConfig(GPIOD,GPIO_PinSource6,GPIO_AF_USART2);					  //����PA10�������ӵ�USART1
														  
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;                                       //���ó�ʼ��GPIOΪPIN9
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;                               //����GPIO���ٶ�Ϊ50MHz
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //����GPIOģʽΪ����ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  //����GPIO�������Ϊ�������
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;						          //����GPIOΪ������������
	GPIO_Init(GPIOD,&GPIO_InitStructure);                                         //��ʼ��GPIOA��PIN9

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;                                      //���ó�ʼ��GPIOΪPIN10
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //����GPIO��ģʽΪ����ģʽ
	GPIO_Init(GPIOD,&GPIO_InitStructure);                                         //��ʼ��GPIOA��PIN10

    USART_InitStructure.USART_BaudRate=115200;                                    //����USART�Ĳ�����Ϊ115200
    USART_InitStructure.USART_Parity=USART_Parity_No;                             //����USART��У��λΪNone
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;                     //����USART������λΪ8bit
    USART_InitStructure.USART_StopBits=USART_StopBits_1;                          //����USART��ֹͣλΪ1
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //ʧ��Ӳ��������
    USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;                   //����USART��ģʽΪ���ͽ���ģʽ
  	USART_Init(USART2, &USART_InitStructure);	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); 
 	USART_Cmd(USART2, ENABLE);
}
/*******************************************************************************
* Function Name  : USART3_Configuration
* Description    : ������ͨ��
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART3_Configuration(void)
{	
}
/*******************************************************************************
* Function Name  : UART4_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void UART4_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;                                          //����GPIO��ʼ���ṹ��
	USART_InitTypeDef USART_InitStructure;                                         //����USART��ʼ���ṹ��
	/*ʱ�����ò���Ҫ����AFIO ֻҪ����Ϊ���ù��ܼ���*/
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource10,GPIO_AF_UART4);						  //����PA9�������ӵ�USART1
    GPIO_PinAFConfig(GPIOC,GPIO_PinSource11,GPIO_AF_UART4);					  //����PA10�������ӵ�USART1
														  
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;                                       //���ó�ʼ��GPIOΪPIN9
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;                               //����GPIO���ٶ�Ϊ50MHz
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //����GPIOģʽΪ����ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  //����GPIO�������Ϊ�������
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;						          //����GPIOΪ������������
	GPIO_Init(GPIOC,&GPIO_InitStructure);                                         //��ʼ��GPIOA��PIN9

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;                                      //���ó�ʼ��GPIOΪPIN10
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //����GPIO��ģʽΪ����ģʽ
	GPIO_Init(GPIOC,&GPIO_InitStructure);                                         //��ʼ��GPIOA��PIN10

    USART_InitStructure.USART_BaudRate=115200;                                    //����USART�Ĳ�����Ϊ115200
    USART_InitStructure.USART_Parity=USART_Parity_No;                             //����USART��У��λΪNone
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;                     //����USART������λΪ8bit
    USART_InitStructure.USART_StopBits=USART_StopBits_1;                          //����USART��ֹͣλΪ1
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //ʧ��Ӳ��������
    USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;                   //����USART��ģʽΪ���ͽ���ģʽ
  	USART_Init(UART4, &USART_InitStructure);	
	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE); 
 	USART_Cmd(UART4, ENABLE);
	USART_DMACmd(UART4,USART_DMAReq_Rx,ENABLE);  //ʹ�ܴ���4��DMA����     
	
	
}
/*******************************************************************************
* Function Name  : TIM1_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM1_Configuration(void)
{  	

}
/*******************************************************************************
* Function Name  : TIM2_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM2_Configuration(void)
{			
}
/*******************************************************************************
* Function Name  : TIM3_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM3_Configuration(void)
{ 
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;		 
			  	
	TIM_TimeBaseStructure.TIM_Period = (25-1); //5ms��ȡһ������ 	 
	TIM_TimeBaseStructure.TIM_Prescaler = (840-1);//tim2Ϊ84MHz(8400/84M*10000=1s)
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);		 
																						  
	TIM_ClearFlag(TIM3,TIM_FLAG_Update); 			 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);

}
/*******************************************************************************
* Function Name  : TIM4_Configuration
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM4_Configuration(void)
{  

//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_TimeBaseStructure.TIM_Period = 4000;	//2 == 1ms	   ������
//	TIM_TimeBaseStructure.TIM_Prescaler = (42000-1);	//tim5Ϊ84MHz	 ��Ƶ   ������ܴ�С
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0;		//ʱ�ӷָ�
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		 //���ϼ���
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
//	
//	TIM_ClearFlag(TIM4,TIM_FLAG_Update); 
//	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);
//	TIM_Cmd(TIM4, ENABLE);
}

/*******************************************************************************
* Function Name  : TIM5_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM5_Configuration(void)
{  
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_TimeBaseStructure.TIM_Period = 4000;	//2 == 1ms	   ������
//	TIM_TimeBaseStructure.TIM_Prescaler = (42000-1);	//tim5Ϊ84MHz	 ��Ƶ   ������ܴ�С
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0;		//ʱ�ӷָ�
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		 //���ϼ���
//	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
//	
//	TIM_ClearFlag(TIM5,TIM_FLAG_Update); 
//	TIM_ITConfig(TIM5,TIM_IT_Update,ENABLE);
//	TIM_Cmd(TIM5, ENABLE);
}
/*******************************************************************************
* Function Name  : TIM7_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM7_Configuration(void)
{	
}
/*******************************************************************************
* Function Name  : TIM8_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM8_Configuration(void)
{ 
}
/*******************************************************************************
* Function Name  : TIM9_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM9_Configuration(void)
{	
}
/*******************************************************************************
* Function Name  : TIM12_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM12_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;	
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	/* Connect TIM pins to AF3 */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_TIM12);		//  CH1	 //ͨ��1
//	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM2);		//  CH2	 //ͨ��2

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure); 				   //�����Ƕ�����Ҫ�õ���I/O�ڵ�����
	
	TIM_TimeBaseStructure.TIM_Period  = 10000;			   //��������
	TIM_TimeBaseStructure.TIM_Prescaler = (35-1);		   //��ʱ��ʱ��Ƶ�ʷ�Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;		   //ʱ�ӷָһ��д0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	  //����Ϊ���ϼ���ģʽ
	TIM_TimeBaseInit(TIM12, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	 //�ȽϼĴ���ʹ��
	TIM_OCInitStructure.TIM_Pulse = 9500;							//�ȽϼĴ���װ��ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//����Ƚϼ��Ը�
									 //TIM_OCPolarity_Low			//����Ƚϼ��Ե�
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;			   //PWMģʽ1
	TIM_OC1Init(TIM12, &TIM_OCInitStructure);						//ͨ��3ʹ��
	TIM_OC1PreloadConfig(TIM12, TIM_OCPreload_Enable);

//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
//	TIM_OC4Init(TIM2, &TIM_OCInitStructure);					   //ͨ��4ʹ��
//	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM12, ENABLE);		 //ʹ�ö�ʱ���ıȽ��������ʱ������仰
	/* TIM9 enable counter */
	TIM_Cmd(TIM12, ENABLE);		  
}

/*******************************************************************************
* Function Name  : EXTI_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI_Configuration(void)
{	
//	EXTI_InitTypeDef	EXTI_InitStructure;	
//	GPIO_InitTypeDef	GPIO_InitStructure;	
//
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;              		//�������ģʽ
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;					//�ٶ�
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;              		//�������ģʽ
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;					//�ٶ�
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	 
//	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource8);		 //ѡ��gpioE2����Ϊ�ⲿ�ж�ʹ��
//	EXTI_InitStructure.EXTI_Line = EXTI_Line8;							 //ʹ���ⲿ�ж���2
//	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;					 //�ⲿ�ж�
//	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_-Falling;  			 //����Ϊ�����ش���	//�½�����EXTI_Trigger_Falling
//	EXTI_InitStructure.EXTI_LineCmd = ENABLE;											//˫���� EXTI_Trigger_Rising_Falling
//	EXTI_Init(&EXTI_InitStructure);
//
//	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource9);		 //ѡ��gpioE2����Ϊ�ⲿ�ж�ʹ��
//	EXTI_InitStructure.EXTI_Line = EXTI_Line9;							 //ʹ���ⲿ�ж���2
//	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;					 //�ⲿ�ж�
//	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  			 //����Ϊ�����ش���	//�½�����EXTI_Trigger_Falling
//	EXTI_InitStructure.EXTI_LineCmd = ENABLE;											//˫���� EXTI_Trigger_Rising_Falling
//	EXTI_Init(&EXTI_InitStructure);
}
/*******************************************************************************
* Function Name  : NVIC_Configuration
* Description    : Configures Vector Table base location.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
//void NVIC_Configuration(void)
//{   	
//	NVIC_InitTypeDef	NVIC_InitStructure;

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//���ȼ���ѡ��  ��0��
//	/*���ȼ���ķ���ֻ������һ��		�ڼ��飬��ռʽ���ȼ����м�λ*/

//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;			//�����ж�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//ʹ��
//	NVIC_Init(&NVIC_InitStructure);
//	
//	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;			//�����ж�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//ʹ��
//	NVIC_Init(&NVIC_InitStructure);

	
//	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;			//�����ж�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//ʹ��
//	NVIC_Init(&NVIC_InitStructure);
//	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream2_IRQn;			//�ⲿ�ж�	�ж���2���ж�		
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//ʹ��
//	NVIC_Init(&NVIC_InitStructure);	

//	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//�ⲿ�ж�	�ж���2���ж�		
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//ʹ��
//	NVIC_Init(&NVIC_InitStructure);		

//	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			//�ⲿ�ж�	�ж���2���ж�		
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//ʹ��
//	NVIC_Init(&NVIC_InitStructure);	
//
//	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;			//��ʱ��2���ж�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//ʹ��
//	NVIC_Init(&NVIC_InitStructure);	
//}
/*******************************************************************************
* Function Name  : CAN1_Configuration
* Description    : None
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void CAN1_Configuration(void)
{
}
