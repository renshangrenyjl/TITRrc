/*
���ļ�����IICЭ����ɶ�DRS3100�Ĳ���������IIC������������֧�֡�
�������ݰ�����
��ȡ8λɨ������1���ֽڣ�		0
��ȡ24λɨ������3���ֽڣ�		1~3
*/
#include "myiic.h" 
#include "drs3100.h"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
#include "delay.h"
#define DRS3100_Address 0x00	//DRS3100���豸��ַ
#define us  4


/********************************************************************************/
void DRS3100_getPoint24(unsigned char *p)	//��ȡ24�����ɨ�����������ص�pָ�������3���ֽڴ�
{
	unsigned char len=3;
 	iic_start(); 
	iic_send_byte((DRS3100_Address<<1)|0);//����������ַ+д����	
	if(iic_wait_ack())	//�ȴ�Ӧ��
	{
		IIC_Stop();		 
			
	}
    iic_send_byte(1);	//д�Ĵ�����ַ
    iic_wait_ack();		//�ȴ�Ӧ��
    iic_start();
	iic_send_byte((DRS3100_Address<<1)|1);//����������ַ+������	
    iic_wait_ack();		//�ȴ�Ӧ�� 
	while(len)
	{
		if(len==1)*p=iic_read_byte(0);//������,����nACK 
		else *p=iic_read_byte(1);		//������,����ACK  
		len--;
		p++; 
	}    
    iic_stop();	//����һ��ֹͣ���� 
}
/********************************************************************************/



//����IIC��ʼ�ź�
void iic_start(void)
{
	SDA_OUT();     //sda�����
	IIC_SDA=1;	  	  
	IIC_SCL=1;
	delay_us(us);
 	IIC_SDA=0;//START:when CLK is high,DATA change form high to low 
	delay_us(us);
	IIC_SCL=0;//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
//����IICֹͣ�ź�
void iic_stop(void)
{
	SDA_OUT();//sda�����
	IIC_SCL=0;
	IIC_SDA=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(us);
	IIC_SCL=1; 
	IIC_SDA=1;//����I2C���߽����ź�
	delay_us(us);							   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
unsigned char iic_wait_ack(void)
{
	u8 ucErrTime=0;
	SDA_IN();      //SDA����Ϊ����  
	IIC_SDA=1;delay_us(us);	   
	IIC_SCL=1;delay_us(us);	 
	while(READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			iic_stop();
			return 1;
		}
	}
	IIC_SCL=0;//ʱ�����0 	
	//printf("success");	
	return 0;  
} 
//����ACKӦ��
void iic_ack(void)
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=0;
	delay_us(us);
	IIC_SCL=1;
	delay_us(us);
	IIC_SCL=0;
}
//������ACKӦ��		    
void iic_nack(void)
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=1;
	delay_us(us);
	IIC_SCL=1;
	delay_us(us);
	IIC_SCL=0;
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void iic_send_byte(unsigned char txd)
{                        
    u8 t;   
	SDA_OUT(); 	    
    IIC_SCL=0;//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
        IIC_SDA=(txd&0x80)>>7;
        txd<<=1; 	  
		delay_us(us);   //��TEA5767��������ʱ���Ǳ����
		IIC_SCL=1;
		delay_us(us); 
		IIC_SCL=0;	
		delay_us(us);
    }	 
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
unsigned char iic_read_byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();//SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        IIC_SCL=0; 
         delay_us(us);
		IIC_SCL=1;
        receive<<=1;
        if(READ_SDA)receive++;   
		delay_us(us); 
    }					 
    if (!ack)
        iic_nack();//����nACK
    else
        iic_ack(); //����ACK   
    return receive;
}



/*********************************************************************************************/
