/****************************************************************************
*			2014 ̫ԭ��ҵѧԺ�����˶�
*
* ��оƬ��STM32F407��
* �ļ���: main.c
* ���ݼ���:

*
* �ļ���ʷ:
* �汾��  ����           
* ˵��
* v0.2    2014-02-14          ��  �������ļ�
*****************************************************************************/
#include "includes.h"	
#include "myiic.h"
#include "delay.h"
/*********************************************************************************************************
*                                          ��������
*********************************************************************************************************/
extern void BSP_Init (void);
extern void while_1(void);
/*********************************************************************************************************
* ��    �� ��main
* �������� : ��ʼ��STM32
* ������� : none
* ���ز��� : none.
* ��    �� : 
* ��    �� �������ڡ��޸��������޸�ԭ��
* ����˵�� : �����⹦��˵�������磺�в������ȣ�
*********************************************************************************************************/
int main(void)	//������
{
  
    u16 buf;
    //float buf_x;
	BSP_Init();		 //Ӳ����ʼ��
	IIC_Init();
    delay_init();//��ʱ��ʼ��
	SCB->VTOR = FLASH_BASE | 0x20000; /* Vector Table Relocation in Internal FLASH. */
	USART_OUT(USART1,"�༶ѧ�� ��1420273\r\n");    	  //�򴮿�1���Ϳ����ַ�

	 //KS10X_Change_Addr_Init(0xe8,0xd6);
     //Change_Addr(0xd0,0xd6);
	while(1)
	{
               
		IIC_Write_One_Byte(0xD0,0x02,0xB0);//�豸��ַ  �ڲ��Ĵ�����ַ  �ڲ��Ĵ�������  0xb0:0-5m��Χ ��ͨ̽�⣨�����¶Ȳ���������us ���̽���ʱ32ms           
        delay_ms(80);        //80
       
		buf = IIC_Read_One_Byte(0xD0,0x02);     //�豸��ַ  �洢��Ԫ��ַ
		
		buf<<=8;

		buf += IIC_Read_One_Byte(0xD0,0x03);     //�豸��ַ   �洢��Ԫ��ַ
		//buf_x=(float)buf/10;                     //0xb0ָ��Ĭ����25���϶���ͨ������̽���������ľ���ֵ
        //printf("%f\r\n",buf_x);//6553.500000
	    printf("%d\r\n",buf);//255
    }
}
/******************************************���²�Ҫ���޸�***************************************************************/

/******************************************************
		��ʽ�������������
        "\r"	�س���	   USART_OUT(USART1, "abcdefg\r")   
		"\n"	���з�	   USART_OUT(USART1, "abcdefg\r\n")
		"%s"	�ַ���	   USART_OUT(USART1, "�ַ����ǣ�%s","abcdefg")
		"%d"	ʮ����	   USART_OUT(USART1, "a=%d",10)
**********************************************************/
void USART_OUT(USART_TypeDef* USARTx, uint8_t *Data,...){ 

	const char *s;
    int d;
   
    char buf[16];
    va_list ap;
    va_start(ap, Data);

	while(*Data!=0){				                          //�ж��Ƿ񵽴��ַ���������
		if(*Data==0x5c){									  //'\'
			switch (*++Data){
				case 'r':							          //�س���
					USART_SendData(USARTx, 0x0d);	   

					Data++;
					break;
				case 'n':							          //���з�
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
				case 's':										  //�ַ���
                	s = va_arg(ap, const char *);
                	for ( ; *s; s++) {
                    	USART_SendData(USARTx,*s);
						while(USART_GetFlagStatus(USARTx, USART_FLAG_TC)==RESET);
                	}
					Data++;
                	break;
            	case 'd':										  //ʮ����
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
		��������ת�ַ�������
        char *itoa(int value, char *string, int radix)
		radix=10 ��ʾ��10����	��ʮ���ƣ�ת�����Ϊ0;  

	    ����d=-379;
		ִ��	itoa(d, buf, 10); ��
		
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







