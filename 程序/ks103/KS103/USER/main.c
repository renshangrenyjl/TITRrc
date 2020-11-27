/****************************************************************************
*			2014 太原工业学院机器人队
*
* 主芯片：STM32F407。
* 文件名: main.c
* 内容简述:

*
* 文件历史:
* 版本号  日期           
* 说明
* v0.2    2014-02-14          赵  创建该文件
*****************************************************************************/
#include "includes.h"	
#include "myiic.h"
#include "delay.h"
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
int main(void)	//主函数
{
  
    u16 buf;
    //float buf_x;
	BSP_Init();		 //硬件初始化
	IIC_Init();
    delay_init();//延时初始化
	SCB->VTOR = FLASH_BASE | 0x20000; /* Vector Table Relocation in Internal FLASH. */
	USART_OUT(USART1,"班级学号 ：1420273\r\n");    	  //向串口1发送开机字符

	 //KS10X_Change_Addr_Init(0xe8,0xd6);
     //Change_Addr(0xd0,0xd6);
	while(1)
	{
               
		IIC_Write_One_Byte(0xD0,0x02,0xB0);//设备地址  内部寄存器地址  内部寄存器数据  0xb0:0-5m范围 普通探测（不带温度补偿）返回us 最大探测耗时32ms           
        delay_ms(80);        //80
       
		buf = IIC_Read_One_Byte(0xD0,0x02);     //设备地址  存储单元地址
		
		buf<<=8;

		buf += IIC_Read_One_Byte(0xD0,0x03);     //设备地址   存储单元地址
		//buf_x=(float)buf/10;                     //0xb0指令默认在25摄氏度下通过具体探测计算出来的距离值
        //printf("%f\r\n",buf_x);//6553.500000
	    printf("%d\r\n",buf);//255
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







