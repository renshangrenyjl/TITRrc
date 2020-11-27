/****************************************************************************
*			2018 ̫ԭ��ҵѧԺ�����˶�
*
* ��оƬ��STM32F407��
* �ļ���: main.c
* ���ݼ���:

*
* �ļ���ʷ:
* �汾��  ����           
* ˵��
* v0.2    2014-02-14            
*****************************************************************************/
#include "includes.h"	
#include "delay.h"
#include "CAN.h"
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

CanTxMsg test_TxMsg;

CanRxMsg test_RxMsg;

uint8_t rec_flag = 0;

int main(void)	//������
{ 
    uint8_t mail_box;
	uint8_t i = 0;
//    int y = 0;
	BSP_Init();		 //Ӳ����ʼ��	
	delay_init();
    CAN_Config();//CAN��ʼ��
    CAN_Filter_Config();//CANɸѡ������
   
    
	SCB->VTOR = FLASH_BASE | 0x20000; /* Vector Table Relocation in Internal FLASH. */
	USART_OUT(USART1,"�༶ѧ�� ��1620273\r\n");    	  //�򴮿�1���Ϳ����ַ� 
	while(1)
	{	
		    //���°�������������
			//����Ҫ���͵�����
			test_TxMsg.StdId = 0x11110200;    //ID��
			test_TxMsg.ExtId = 0x13141314;         //��չID
			test_TxMsg.IDE = CAN_ID_EXT ;		//�ж�����չID���Ǳ�׼ID
			test_TxMsg.RTR = CAN_RTR_DATA ;			//����֡��ң��֡
			test_TxMsg.DLC = 8;//�����ж೤
			
			for(i=0;i<8;i++)
			{
				test_TxMsg.Data[i] = i;
			}			
			
			printf("\r\n ׼����������");
			//��������
            
			mail_box = CAN_Transmit(TEST_CAN, &test_TxMsg);//���ش洢�����ĸ����� 
			if(mail_box != CAN_TxStatus_NoMailBox)//���������CAN_TxStatus_NoMailBox�ͻ�洢������
			{
				//�ȴ�ֱ�����ݷ��͵�CAN�շ������
				while(CAN_TransmitStatus(TEST_CAN,mail_box) != CAN_TxStatus_Ok);//���û�гɹ��Ϳ�������
                
				
				//��һ����ʱ��ȴ�CAN�շ��������ݷ��͵�����
				delay_ms(1000);				
				printf("\r\n �����������");
			}
			else
			{
				printf("\r\n no mail box");
			}		
		
        
		
		
		//��������
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





