#include <includes.h>
#include <stdlib.h> 
/*********************************************************************************************************
*                                           �궨��
*********************************************************************************************************/
extern void  BSP_Init (void);

void USART_OUT(USART_TypeDef* USARTx, uint8_t *Data,...);
int fputc(int ch,FILE  *f);
char *itoa(int value, char *string, int radix);

/*********************************************************************************************************
* ��    �� ��main
* �������� : ��ʼ��STM32
* ������� : none
* ���ز��� : none.
* ��    �� : 
* ��    �� �������ڡ��޸��������޸�ԭ��
* ����˵�� : �����⹦��˵�������磺�в������ȣ�
*********************************************************************************************************/ 
#define S1 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)//����ǰ���ź�
#define S2 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)//���ͺ����ź�
#define S3 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)//���������ź�
#define S4 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_9)//���������ź�
#define S5 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)//��������צ���ź�
#define S6 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)//��������צ���ź�
#define S7 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)//���ͺ�Ǳ��ź�
#define S8 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)//���ͺ�ǿ��ź�
#define D1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)//����ǰצ���ź�
#define D2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)//���ͺ�ǿ��ź�
#define D3 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)//�����ϸ�ˮƽ�ź�
#define D4 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)//�����ϸ�̧�ź�
#define D5 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)//���ͷ���״̬�ź�
#define D6 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)//���ͳ���״̬�ź�
#define D7 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)//���͸�ԭ״̬�ź�
#define D8 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)//���ͳ����ٶ��ź�
#define D9 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)//���ð���
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
/********************************************���²�Ҫ�������޸�*****************************************/

/*********************************************************
										printf�ض���
**********************************************************/
int fputc(int ch,FILE  *f)
{
	USART_SendData(USART1,(u8)ch);
	while (USART_GetFlagStatus(USART1,USART_FLAG_TC) == RESET);
	return ch;
}


/******************************************************
		��ʽ�������������
        "\r"	�س���	   USART_OUT(USART1, "abcdefg\r")   
		"\n"	���з�	   USART_OUT(USART1, "abcdefg\r\n")
		"%s"	�ַ���	   USART_OUT(USART1, "�ַ����ǣ�%s","abcdefg")
		"%d"	ʮ����	   USART_OUT(USART1, "a=%d",10)
**********************************************************/
void USART_OUT(USART_TypeDef* USARTx, uint8_t *Data,...)
{ 

	const char *s;
    int d;
    char buf[16];
    va_list ap;
    va_start(ap, Data);
    while(*Data!=0)
    {				                          //�ж��Ƿ񵽴��ַ���������
		if(*Data==0x5c)
        {									  //'\'
			switch (*++Data)
            {
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
		else if(*Data=='%')
        {									 
			switch (*++Data)
            {				
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
/******************* (C) COPYRIGHT 2019 �ܶ�STM32 *****END OF FILE****/
