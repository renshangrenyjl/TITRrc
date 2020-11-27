#include "myiic.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//IIC ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/6
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

//��ʼ��IIC
void IIC_Init(void)
{			
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//ʹ��GPIOBʱ��

  //GPIOB8,B9��ʼ������
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
  //GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;//��©�����
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��
	IIC_SCL=1;
	IIC_SDA=1;
}
//����IIC��ʼ�ź�
void IIC_Start(void)    //SCLΪ���ڼ䣬SDA�ɸߵ��͵�����
{
	SDA_OUT();     //sda�����
	IIC_SDA=1;	  	  
	IIC_SCL=1;
	delay_us(10);  //10
 	IIC_SDA=0;//START:when CLK is high,DATA change form high to low 
	delay_us(10);   //10
 	IIC_SCL=0;//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
//����IICֹͣ�ź�
void IIC_Stop(void)           //SCLΪ���ڼ䣬SDA�ɵ͵��ߵ�����
{
	SDA_OUT();/*sda�����    PB9���ģʽ*/
	IIC_SCL=0;
	IIC_SDA=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(10); //10
	IIC_SCL=1; 
	IIC_SDA=1;//����I2C���߽����ź�
	delay_us(10);  //10							   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	SDA_IN();      /*SDA����Ϊ����  PB9����ģʽ*/
	IIC_SDA=1;delay_us(6);	   
	IIC_SCL=1;delay_us(6);	 
	while(READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)//250  
        {
            IIC_Stop();	
		    return 1;
        }

	}
	IIC_SCL=0;//ʱ�����0 	   
	return 0;  
} 
//����ACKӦ��
void IIC_Ack(void)         //�ӻ����Ӧ���źţ���SDA�ź���Ϊ�͵�ƽ
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=0;
	delay_us(10);  //10
	IIC_SCL=1;
	delay_us(10);   //10
	IIC_SCL=0;
}
//������ACKӦ��		    
void IIC_NAck(void)       //�ӻ����Ӧ���źţ���SDA�ź���Ϊ�ߵ�ƽ
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=1;
	delay_us(10);  //10
	IIC_SCL=1;
	delay_us(10);  //10
	IIC_SCL=0;
}
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��
void IIC_Send_Byte(u8 txd)
{
    u8 t;  
	SDA_OUT();
    IIC_SCL=0;//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {
        IIC_SDA=(txd&0x80)>>7;
        txd<<=1;
		delay_us(10);   //��TEA5767��������ʱ���Ǳ����
		IIC_SCL=1;
		delay_us(10);
		IIC_SCL=0;
		delay_us(10); //10
    }
}
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK
u8 IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();//SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        IIC_SCL=0;
        delay_us(10);
		IIC_SCL=1;
        receive<<=1;
        if(READ_SDA)receive++;
		delay_us(5);
    }
    if (!ack)         
    IIC_NAck();//����nACK
    else
    IIC_Ack(); //����ACK          
    return receive;
}

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data)
{
    IIC_Start();/*��ʼ�ź�*/
    IIC_Send_Byte(daddr);/*�����豸��ַ���ź�*/
    IIC_Wait_Ack();
    IIC_Send_Byte(addr);/*�����ڲ��Ĵ�����ַ*/
    IIC_Wait_Ack();
    IIC_Send_Byte(data);/*�����ڲ��Ĵ�������*/
    IIC_Wait_Ack();
    IIC_Stop();  //����ֹͣ�ź�
}
u8 IIC_Read_One_Byte(u8 daddr,u8 addr)
{	//30 40
    u8 REG_data = 0;/*����������*/ 

    
    IIC_Start();/*��ʼ�ź�     ׼����ʼ��������*/
    IIC_Send_Byte(daddr);/*�����豸��ַ+д�ź�     ��ʼ�������ݣ���ַ+�źţ�*/    
    IIC_Wait_Ack();
    IIC_Send_Byte(addr);/*���ʹ��浥Ԫ��ַ,��0��ʼ*/
    IIC_Wait_Ack();
    IIC_Start();/*��ʼ�ź�*/
	IIC_Send_Byte(daddr+1);//�����豸��ַ+���ź� �������ģʽ
    IIC_Wait_Ack();
	delay_us(50);  //50
    REG_data=IIC_Read_Byte(0);   //��ȡһ���ֽڣ����ټ�����������Nack�������Ĵ�����ֵ
    IIC_Stop();//ֹͣ�ź�

	return REG_data;   //���ض���������
}

void KS10X_Change_Addr_Init(u8 OldAddr,u8 NewAddr)  //�޸�KS103�ӻ���ַ
{
    Change_Addr(OldAddr,NewAddr);
    delay_ms(80);
}
void Change_Addr(u8 OldAdddr,u8 NewAddr)  //�޸ĵ�ַʱ��
{
    IIC_Write_One_Byte(OldAdddr,0x02,0x9a);             
    delay_ms(1);
    IIC_Write_One_Byte(OldAdddr,0x02,0x92);
    delay_ms(1);
    IIC_Write_One_Byte(OldAdddr,0x02,0x9e);
    delay_ms(1);
    IIC_Write_One_Byte(OldAdddr,0x02,NewAddr);
    delay_ms(100);
}











