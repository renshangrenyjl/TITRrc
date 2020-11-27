#include "stm32f4xx.h"
#include "CAN.h"
/*********************************************************************************************************
BSP简介：
		板级支持包（BSP）是介于主板硬件和操作系统中驱动层程序之间的一层，一般认为它属于操作系统一部分，主要是
	实现对操作系统的支持，为上层的驱动程序提供访问硬件设备寄存器的函数包，使之能够更好的运行于硬件主板。
	在嵌入式系统软件的组成中，就有BSP。BSP是相对于操作系统而言的，不同的操作系统对应于不同定义形式的BSP,
	例如VxWorks的BSP和Linux的BSP相对于某一CPU来说尽管实现的功能一样，可是写法和接口定义是完全不同的，所以写BSP
	一定要按照该系统BSP的定义形式来写（BSP的编程过程大多数是在某一个成型的BSP模板上进行修改）。这样才能与上层
	OS保持正确的接口，良好的支持上层OS。

作用：
	建立让操作系统运行的基本环境
	1、初始化CPU内部寄存器
	2、设定RAM工作时序
	3、时钟驱动及中断控制器驱动
	4、串口驱动
	
	完善操作系统运行的环境
	1、完善高速缓存和内存管理单元的驱动
	2、指定程序起始运行位置
	3、完善中断管理
	4、完善系统总线驱动
*********************************************************************************************************/
/*********************************************************************************************************
*                                         宏定义
*********************************************************************************************************/

/*********************************************************************************************************
*                                          结构体变量
*********************************************************************************************************/
/*********************************************************************************************************
*                                          函数声明
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
*                                          程序配置
*********************************************************************************************************/
void BSP_Init(void)
{	
	RCC_Configuration();
//	GPIO_Configuration();				
 	EXTI_Configuration();
	//NVIC_Configuration();
	USART1_Configuration();				//如果串口打印功能使用了（如开机字符） 但是硬件没有配置的话 板子会死掉
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
	/*io口时钟配置 168MHz*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA| RCC_AHB1Periph_GPIOB| RCC_AHB1Periph_GPIOC| RCC_AHB1Periph_GPIOD| 
							RCC_AHB1Periph_GPIOE , ENABLE); 
	/*APB2 84MHz 配置timer时会倍频为168mhz，具体有哪些在此时钟上可跳进去查看*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1| RCC_APB2Periph_TIM1| RCC_APB2Periph_TIM8| 
							RCC_APB2Periph_TIM9| RCC_APB2Periph_SYSCFG, ENABLE);
	/*APB1 42MHz 配置为timer时会倍频为84MHz*/
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

//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_All;			//选择GPIOA全部的16个拐脚
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			//I/O口配置为输入操作模式
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		//速度100M			  
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			//GPIO_PuPd_DOWN		分别是配置I/O口的上拉和下拉
//	GPIO_Init(GPIOA, &GPIO_InitStructure);

//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;			//选择GPIOA全部的16个拐脚
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			//I/O口配置为输入操作模式
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		//速度100M			  
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			//GPIO_PuPd_DOWN		分别是配置I/O口的上拉和下拉
//	GPIO_Init(GPIOB, &GPIO_InitStructure);

//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_All;				//选择GPIO-B12口
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			//I/O口配置为输出操作模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			//配置为推挽输出类型																
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		//速度100M			  
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		//I/O口无上拉和下拉（高阻态）
//	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11;				//选择GPIO-B12口
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			//I/O口配置为输出操作模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			//配置为推挽输出类型																
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		//速度100M			  
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		//I/O口无上拉和下拉（高阻态）
	GPIO_Init(GPIOB, &GPIO_InitStructure);

//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13;				//选择GPIO-B13口
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			//I/O口配置为输出操作模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;			//配置开漏输出类型																
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		//速度100M			  
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		//I/O口无上拉和下拉（高阻态）
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0|GPIO_Pin_1;	//选择GPIO-C0和C1口
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			//I/O口配置为输出操作模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			//配置开漏输出类型																
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//速度50M   2，25，50，100四种选择			  
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		//I/O口无上拉和下拉（高阻态）
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
	GPIO_InitTypeDef GPIO_InitStructure;                                          //定义GPIO初始化结构体
	USART_InitTypeDef USART_InitStructure;                                         //定义USART初始化结构体
	/*时钟配置不需要配置AFIO 只要配置为复用功能即可*/
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);						  //配置PA9复用连接到USART1
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);					  //配置PA10复用连接到USART1
														  
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;                                       //设置初始化GPIO为PIN9
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;                               //设置GPIO的速度为50MHz
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //设置GPIO模式为复用模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  //设置GPIO输出类型为推挽输出
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;						          //设置GPIO为连接上拉电阻
	GPIO_Init(GPIOA,&GPIO_InitStructure);                                         //初始化GPIOA的PIN9

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;                                      //设置初始化GPIO为PIN10
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //设置GPIO的模式为复用模式
	GPIO_Init(GPIOA,&GPIO_InitStructure);                                         //初始化GPIOA的PIN10

    USART_InitStructure.USART_BaudRate=115200;                                    //设置USART的波特率为115200
    USART_InitStructure.USART_Parity=USART_Parity_No;                             //设置USART的校验位为None
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;                     //设置USART的数据位为8bit
    USART_InitStructure.USART_StopBits=USART_StopBits_1;                          //设置USART的停止位为1
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //失能硬件流控制
    USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;                   //设置USART的模式为发送接收模式
  	USART_Init(USART1, &USART_InitStructure);	
    
    NVIC_InitTypeDef NVIC_InitStructure;
      
    /* 嵌套向量中断控制器组选择 */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
      
    /* 配置USART为中断源 */
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    /* 抢断优先级为1 */
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    /* 子优先级为1 */
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    /* 使能中断 */
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    /* 初始化配置NVIC */
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
	
	GPIO_InitTypeDef GPIO_InitStructure;                                          //定义GPIO初始化结构体
	USART_InitTypeDef USART_InitStructure;                                         //定义USART初始化结构体
	/*时钟配置不需要配置AFIO 只要配置为复用功能即可*/
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource5,GPIO_AF_USART2);						  //配置PA9复用连接到USART1
    GPIO_PinAFConfig(GPIOD,GPIO_PinSource6,GPIO_AF_USART2);					  //配置PA10复用连接到USART1
														  
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;                                       //设置初始化GPIO为PIN9
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;                               //设置GPIO的速度为50MHz
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //设置GPIO模式为复用模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  //设置GPIO输出类型为推挽输出
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;						          //设置GPIO为连接上拉电阻
	GPIO_Init(GPIOD,&GPIO_InitStructure);                                         //初始化GPIOA的PIN9

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;                                      //设置初始化GPIO为PIN10
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //设置GPIO的模式为复用模式
	GPIO_Init(GPIOD,&GPIO_InitStructure);                                         //初始化GPIOA的PIN10

    USART_InitStructure.USART_BaudRate=115200;                                    //设置USART的波特率为115200
    USART_InitStructure.USART_Parity=USART_Parity_No;                             //设置USART的校验位为None
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;                     //设置USART的数据位为8bit
    USART_InitStructure.USART_StopBits=USART_StopBits_1;                          //设置USART的停止位为1
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //失能硬件流控制
    USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;                   //设置USART的模式为发送接收模式
  	USART_Init(USART2, &USART_InitStructure);	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); 
 	USART_Cmd(USART2, ENABLE);
}
/*******************************************************************************
* Function Name  : USART3_Configuration
* Description    : 陀螺仪通信
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
	GPIO_InitTypeDef GPIO_InitStructure;                                          //定义GPIO初始化结构体
	USART_InitTypeDef USART_InitStructure;                                         //定义USART初始化结构体
	/*时钟配置不需要配置AFIO 只要配置为复用功能即可*/
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource10,GPIO_AF_UART4);						  //配置PA9复用连接到USART1
    GPIO_PinAFConfig(GPIOC,GPIO_PinSource11,GPIO_AF_UART4);					  //配置PA10复用连接到USART1
														  
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;                                       //设置初始化GPIO为PIN9
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;                               //设置GPIO的速度为50MHz
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //设置GPIO模式为复用模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  //设置GPIO输出类型为推挽输出
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;						          //设置GPIO为连接上拉电阻
	GPIO_Init(GPIOC,&GPIO_InitStructure);                                         //初始化GPIOA的PIN9

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;                                      //设置初始化GPIO为PIN10
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //设置GPIO的模式为复用模式
	GPIO_Init(GPIOC,&GPIO_InitStructure);                                         //初始化GPIOA的PIN10

    USART_InitStructure.USART_BaudRate=115200;                                    //设置USART的波特率为115200
    USART_InitStructure.USART_Parity=USART_Parity_No;                             //设置USART的校验位为None
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;                     //设置USART的数据位为8bit
    USART_InitStructure.USART_StopBits=USART_StopBits_1;                          //设置USART的停止位为1
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //失能硬件流控制
    USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;                   //设置USART的模式为发送接收模式
  	USART_Init(UART4, &USART_InitStructure);	
	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE); 
 	USART_Cmd(UART4, ENABLE);
	USART_DMACmd(UART4,USART_DMAReq_Rx,ENABLE);  //使能串口4的DMA接收     
	
	
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
			  	
	TIM_TimeBaseStructure.TIM_Period = (25-1); //5ms读取一次数据 	 
	TIM_TimeBaseStructure.TIM_Prescaler = (840-1);//tim2为84MHz(8400/84M*10000=1s)
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
//	TIM_TimeBaseStructure.TIM_Period = 4000;	//2 == 1ms	   最大计数
//	TIM_TimeBaseStructure.TIM_Prescaler = (42000-1);	//tim5为84MHz	 分频   这个数能大不小
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0;		//时钟分割
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		 //向上计数
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
//	TIM_TimeBaseStructure.TIM_Period = 4000;	//2 == 1ms	   最大计数
//	TIM_TimeBaseStructure.TIM_Prescaler = (42000-1);	//tim5为84MHz	 分频   这个数能大不小
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0;		//时钟分割
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		 //向上计数
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
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_TIM12);		//  CH1	 //通道1
//	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM2);		//  CH2	 //通道2

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure); 				   //以上是对于需要用到的I/O口的配置
	
	TIM_TimeBaseStructure.TIM_Period  = 10000;			   //计数上限
	TIM_TimeBaseStructure.TIM_Prescaler = (35-1);		   //定时器时钟频率分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;		   //时钟分割，一般写0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	  //设置为向上计数模式
	TIM_TimeBaseInit(TIM12, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	 //比较寄存器使能
	TIM_OCInitStructure.TIM_Pulse = 9500;							//比较寄存器装载值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//输出比较极性高
									 //TIM_OCPolarity_Low			//输出比较极性低
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;			   //PWM模式1
	TIM_OC1Init(TIM12, &TIM_OCInitStructure);						//通道3使能
	TIM_OC1PreloadConfig(TIM12, TIM_OCPreload_Enable);

//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
//	TIM_OC4Init(TIM2, &TIM_OCInitStructure);					   //通道4使能
//	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM12, ENABLE);		 //使用定时器的比较输出功能时配置这句话
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
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;              		//输入操作模式
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;					//速度
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;              		//输入操作模式
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;					//速度
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	 
//	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource8);		 //选择gpioE2口作为外部中断使用
//	EXTI_InitStructure.EXTI_Line = EXTI_Line8;							 //使能外部中断线2
//	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;					 //外部中断
//	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_-Falling;  			 //配置为上升沿触发	//下降沿是EXTI_Trigger_Falling
//	EXTI_InitStructure.EXTI_LineCmd = ENABLE;											//双边沿 EXTI_Trigger_Rising_Falling
//	EXTI_Init(&EXTI_InitStructure);
//
//	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource9);		 //选择gpioE2口作为外部中断使用
//	EXTI_InitStructure.EXTI_Line = EXTI_Line9;							 //使能外部中断线2
//	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;					 //外部中断
//	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  			 //配置为上升沿触发	//下降沿是EXTI_Trigger_Falling
//	EXTI_InitStructure.EXTI_LineCmd = ENABLE;											//双边沿 EXTI_Trigger_Rising_Falling
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

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//优先级组选择  第0组
//	/*优先级组的分配只能设置一次		第几组，抢占式优先级就有几位*/

//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;			//串口中断
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//主优先级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//从优先级
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//使能
//	NVIC_Init(&NVIC_InitStructure);
//	
//	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;			//串口中断
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//主优先级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//从优先级
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//使能
//	NVIC_Init(&NVIC_InitStructure);

	
//	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;			//串口中断
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//主优先级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//从优先级
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//使能
//	NVIC_Init(&NVIC_InitStructure);
//	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream2_IRQn;			//外部中断	中断线2的中断		
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//主优先级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//从优先级
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//使能
//	NVIC_Init(&NVIC_InitStructure);	

//	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//外部中断	中断线2的中断		
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//主优先级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//从优先级
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//使能
//	NVIC_Init(&NVIC_InitStructure);		

//	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			//外部中断	中断线2的中断		
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//主优先级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//从优先级
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//使能
//	NVIC_Init(&NVIC_InitStructure);	
//
//	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;			//定时器2的中断
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//主优先级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//从优先级
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//使能
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
