/****************************************************************************
*			2018 太原工业学院机器人队
*
* 主芯片：STM32F407。
* 文件名: main.c
* 内容简述:

*
* 文件历史:
* 版本号  日期           
* 说明
* v0.2    2014-02-14            
*****************************************************************************/
#include "includes.h"	
#include "delay.h"
#include "CAN.h"
/*********************************************************************************************************
*                                          函数声明
*********************************************************************************************************/
extern void BSP_Init (void);
extern void while_1(void);
/*********************************************************************************************************
* 名    称 ：main
* 功能描述 : 初始化STM32
* 输入参数 : none
* 返回参数 : none.
* 作    者 : 
* 修    改 ：（日期、修改人名、修改原因）
* 特殊说明 : （特殊功能说明，例如：有参数检查等）
*********************************************************************************************************/

CanTxMsg test_TxMsg;

CanRxMsg test_RxMsg;

uint8_t rec_flag = 0;

int main(void)	//主函数
{ 
    uint8_t mail_box;
	uint8_t i = 0;
//    int y = 0;
	BSP_Init();		 //硬件初始化	
	delay_init();
    CAN_Config();//CAN初始化
    CAN_Filter_Config();//CAN筛选器函数
   
    
	SCB->VTOR = FLASH_BASE | 0x20000; /* Vector Table Relocation in Internal FLASH. */
	USART_OUT(USART1,"班级学号 ：1620273\r\n");    	  //向串口1发送开机字符 
	while(1)
	{	
		    //按下按键，发送数据
			//设置要发送的数据
			test_TxMsg.StdId = 0x11110200;    //ID号
			test_TxMsg.ExtId = 0x13141314;         //扩展ID
			test_TxMsg.IDE = CAN_ID_EXT ;		//判断是扩展ID还是标准ID
			test_TxMsg.RTR = CAN_RTR_DATA ;			//数据帧，遥控帧
			test_TxMsg.DLC = 8;//数据有多长
			
			for(i=0;i<8;i++)
			{
				test_TxMsg.Data[i] = i;
			}			
			
			printf("\r\n 准备发送数据");
			//发送数据
            
			mail_box = CAN_Transmit(TEST_CAN, &test_TxMsg);//返回存储到了哪个邮箱 
			if(mail_box != CAN_TxStatus_NoMailBox)//如果不等于CAN_TxStatus_NoMailBox就会存储到邮箱
			{
				//等待直至数据发送到CAN收发器完成
				while(CAN_TransmitStatus(TEST_CAN,mail_box) != CAN_TxStatus_Ok);//如果没有成功就卡在这里
                
				
				//给一定的时间等待CAN收发器把数据发送到总线
				delay_ms(1000);				
				printf("\r\n 发送数据完成");
			}
			else
			{
				printf("\r\n no mail box");
			}		
		
        
		
		
		//接收数据
		if(rec_flag == 1)
		{		

			printf("\r\nCAN Rx.StdId =%x",test_RxMsg.StdId);
			printf("\r\nCAN Rx.ExtId =%x",test_RxMsg.ExtId);
			printf("\r\nCAN Rx.IDE =%x",test_RxMsg.IDE);
			printf("\r\nCAN Rx.RTR =%x",test_RxMsg.RTR);
			printf("\r\nCAN Rx.DLC =%x",test_RxMsg.DLC);
			printf("\r\nCAN Rx.FMI =%x",test_RxMsg.FMI);
			
			for(i=0;i<test_RxMsg.DLC;i++)
			{
				printf("\r\nCAN Rx.Data[%d] =%x",i,test_RxMsg.Data[i]);
			}			
			
			rec_flag = 0;
			
		}
		
	}	
}
/******************************************以下不要乱修改***************************************************************/

/******************************************************
		格式化串口输出函数
        "\r"	回车符	   USART_OUT(USART1, "abcdefg\r")   
		"\n"	换行符	   USART_OUT(USART1, "abcdefg\r\n")
		"%s"	字符串	   USART_OUT(USART1, "字符串是：%s","abcdefg")
		"%d"	十进制	   USART_OUT(USART1, "a=%d",10)
**********************************************************/
void USART_OUT(USART_TypeDef* USARTx, uint8_t *Data,...){ 

	const char *s;
    int d;
   
    char buf[16];
    va_list ap;
    va_start(ap, Data);

	while(*Data!=0){				                          //判断是否到达字符串结束符
		if(*Data==0x5c){									  //'\'
			switch (*++Data){
				case 'r':							          //回车符
					USART_SendData(USARTx, 0x0d);	   

					Data++;
					break;
				case 'n':							          //换行符
					USART_SendData(USARTx, 0x0a);	
					Data++;
					break;
				
				default:
					Data++;
				    break;
			}
		}
		else if(*Data=='%'){									  //
			switch (*++Data){				
				case 's':										  //字符串
                	s = va_arg(ap, const char *);
                	for ( ; *s; s++) {
                    	USART_SendData(USARTx,*s);
						while(USART_GetFlagStatus(USARTx, USART_FLAG_TC)==RESET);
                	}
					Data++;
                	break;
            	case 'd':										  //十进制
                	d = va_arg(ap, int);
                	itoa(d, buf, 10);
                	for (s = buf; *s; s++) {
                    	USART_SendData(USARTx,*s);
						while(USART_GetFlagStatus(USARTx, USART_FLAG_TC)==RESET);
                	}
					Data++;
                	break;
				default:
					Data++;
				    break;
			}		 
		}
		else USART_SendData(USARTx, *Data++);
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TC)==RESET);
	}
}
int fputc(int ch, FILE *f)

{

USART_SendData(USART1, (unsigned char) ch);// USART1 ???? USART2 ?

while (!(USART1->SR & USART_FLAG_TXE));

return (ch);

}
/******************************************************
		整形数据转字符串函数
        char *itoa(int value, char *string, int radix)
		radix=10 标示是10进制	非十进制，转换结果为0;  

	    例：d=-379;
		执行	itoa(d, buf, 10); 后
		
		buf="-379"							   			  
**********************************************************/
char *itoa(int value, char *string, int radix)
{
    int     i, d;
    int     flag = 0;
    char    *ptr = string;

    /* This implementation only works for decimal numbers. */
    if (radix != 10)
    {
        *ptr = 0;
        return string;
    }

    if (!value)
    {
        *ptr++ = 0x30;
        *ptr = 0;
        return string;
    }

    /* if this is a negative value insert the minus sign. */
    if (value < 0)
    {
        *ptr++ = '-';

        /* Make the value positive. */
        value *= -1;
    }

    for (i = 10000; i > 0; i /= 10)
    {
        d = value / i;

        if (d || flag)
        {
            *ptr++ = (char)(d + 0x30);
            value -= (d * i);
            flag = 1;
        }
    }

    /* Null terminate the string. */
    *ptr = 0;

    return string;

} /* NCL_Itoa */





