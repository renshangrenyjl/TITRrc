#include <includes.h>
#include <stdlib.h> 
/*********************************************************************************************************
*                                           宏定义
*********************************************************************************************************/
extern void  BSP_Init (void);

void USART_OUT(USART_TypeDef* USARTx, uint8_t *Data,...);
int fputc(int ch,FILE  *f);
char *itoa(int value, char *string, int radix);

/*********************************************************************************************************
* 名    称 ：main
* 功能描述 : 初始化STM32
* 输入参数 : none
* 返回参数 : none.
* 作    者 : 
* 修    改 ：（日期、修改人名、修改原因）
* 特殊说明 : （特殊功能说明，例如：有参数检查等）
*********************************************************************************************************/ 
#define S1 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)//发送前进信号
#define S2 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)//发送后退信号
#define S3 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)//发送向左信号
#define S4 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_9)//发送向右信号
#define S5 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)//发送铝管爪闭信号
#define S6 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)//发送铝管爪开信号
#define S7 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)//发送后盖闭信号
#define S8 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)//发送后盖开信号
#define D1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)//发送前爪闭信号
#define D2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)//发送后盖开信号
#define D3 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)//发送上盖水平信号
#define D4 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)//发送上盖抬信号
#define D5 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)//发送放球状态信号
#define D6 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)//发送冲坡状态信号
#define D7 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)//发送复原状态信号
#define D8 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)//发送冲坡速度信号
#define D9 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)//备用按键
int main(void)                                                                                                                                                       
{
    BSP_Init();
    while(1)
    {
        if(S1==0)
        {
            delay_ms(10);
            if(S1==0)
            {
                delay_ms(10);
                USART_SendData(USART2,'1');				
            } 
        }
        if(S2==0)
        {
            delay_ms(10);
            if(S2==0)
            {
                delay_ms(10);
                USART_SendData(USART2,'2');				
            } 
        }
		if(S3==0)
        {
            delay_ms(10);
            if(S3==0)
            {
                delay_ms(10);
                USART_SendData(USART2,'3');				
            } 
        } 
		if(S4==0)
        {
            delay_ms(10);
            if(S4==0)
            {
                delay_ms(10);
                USART_SendData(USART2,'4');				
            } 
        }
        if(D8==0)	
        {
            delay_ms(10);
            if(D8==0)
            {
                delay_ms(10);
                USART_SendData(USART2,'m');
            }
        }    
        if(S1==1&&S2==1&&S3==1&&S4==1&&D8==1)
        {
			delay_ms(10);
			if(S1==1&&S2==1&&S3==1&&S4==1&&D8==1)
            { 
                delay_ms(10);
                USART_SendData(USART2,'5');
            }
        }
        if(S5==0)	
        {   
            delay_ms(10);
            if(S5==0)
            {
                USART_SendData(USART2,'a');
            }
            while(S5!=1);
        }

        if(S6==0)	
        {
		    delay_ms(10);
            if(S6==0)
            {
                USART_SendData(USART2,'9');
            }
            while(S6!=1);
        }

        if(S7==0)	
        {
		    delay_ms(10);
            if(S7==0)
            {
                USART_SendData(USART2,'b');
            }
            while(S7!=1);
        }
	    if(S8==0)	
        {
		    delay_ms(10);
            if(S8==0)
            {   
                USART_SendData(USART2,'d');
            }
            while(S8!=1);
   
         }	
//        if(D1==0)	
//        {
//		    delay_ms(10);
//            if(D1==0)
//            {
//                USART_SendData(USART2,'c');
//            }
//            while(D1!=1);
//   
//        }
//	    if(D2==0)	
//        {
//            delay_ms(10);
//            if(D2==0)
//            {
//                USART_SendData(USART2,'f');
//            }
//            while(D2!=1); 
//        }
        if(D3==0)	
        {
            delay_ms(10);
            if(D3==0)
            {
                USART_SendData(USART2,'g');
            }
            while(D3!=1);
        }
        if(D4==0)	
        {
            delay_ms(10);
            if(D4==0)
            {
                USART_SendData(USART2,'e');
            }
            while(D4!=1);
        }
        if(D5==0)	
        {
            delay_ms(10);
            if(D5==0)
            {
                USART_SendData(USART2,'l');
            }
            while(D5!=1);
        }
        if(D6==0)	
        {
            delay_ms(10);
            if(D6==0)
            {
                USART_SendData(USART2,'q');
            }
            while(D6!=1);
  
        }
        if(D7==0)	
        {
            delay_ms(10);
            if(D7==0)
            {
                USART_SendData(USART2,'k');
            }
            while(D7!=1);
        }
	
        if(D9==0)	
        {
            delay_ms(10);
            if(D9==0)
            {
                USART_SendData(USART2,'j');
            }
            while(D9!=1);
   
        }	
    }
}
/********************************************以下不要擅自乱修改*****************************************/

/*********************************************************
										printf重定义
**********************************************************/
int fputc(int ch,FILE  *f)
{
	USART_SendData(USART1,(u8)ch);
	while (USART_GetFlagStatus(USART1,USART_FLAG_TC) == RESET);
	return ch;
}


/******************************************************
		格式化串口输出函数
        "\r"	回车符	   USART_OUT(USART1, "abcdefg\r")   
		"\n"	换行符	   USART_OUT(USART1, "abcdefg\r\n")
		"%s"	字符串	   USART_OUT(USART1, "字符串是：%s","abcdefg")
		"%d"	十进制	   USART_OUT(USART1, "a=%d",10)
**********************************************************/
void USART_OUT(USART_TypeDef* USARTx, uint8_t *Data,...)
{ 

	const char *s;
    int d;
    char buf[16];
    va_list ap;
    va_start(ap, Data);
    while(*Data!=0)
    {				                          //判断是否到达字符串结束符
		if(*Data==0x5c)
        {									  //'\'
			switch (*++Data)
            {
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
		else if(*Data=='%')
        {									 
			switch (*++Data)
            {				
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
/******************* (C) COPYRIGHT 2019 奋斗STM32 *****END OF FILE****/
