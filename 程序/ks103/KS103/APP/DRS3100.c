/*
本文件根据IIC协议完成对DRS3100的操作，基于IIC主机驱动函数支持。
具体内容包括：
读取8位扫描结果（1个字节）		0
读取24位扫描结果（3个字节）		1~3
*/
#include "myiic.h" 
#include "drs3100.h"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
#include "delay.h"
#define DRS3100_Address 0x00	//DRS3100的设备地址
#define us  4


/********************************************************************************/
void DRS3100_getPoint24(unsigned char *p)	//获取24个点的扫描结果，并返回到p指向的连续3个字节处
{
	unsigned char len=3;
 	iic_start(); 
	iic_send_byte((DRS3100_Address<<1)|0);//发送器件地址+写命令	
	if(iic_wait_ack())	//等待应答
	{
		IIC_Stop();		 
			
	}
    iic_send_byte(1);	//写寄存器地址
    iic_wait_ack();		//等待应答
    iic_start();
	iic_send_byte((DRS3100_Address<<1)|1);//发送器件地址+读命令	
    iic_wait_ack();		//等待应答 
	while(len)
	{
		if(len==1)*p=iic_read_byte(0);//读数据,发送nACK 
		else *p=iic_read_byte(1);		//读数据,发送ACK  
		len--;
		p++; 
	}    
    iic_stop();	//产生一个停止条件 
}
/********************************************************************************/



//产生IIC起始信号
void iic_start(void)
{
	SDA_OUT();     //sda线输出
	IIC_SDA=1;	  	  
	IIC_SCL=1;
	delay_us(us);
 	IIC_SDA=0;//START:when CLK is high,DATA change form high to low 
	delay_us(us);
	IIC_SCL=0;//钳住I2C总线，准备发送或接收数据 
}	  
//产生IIC停止信号
void iic_stop(void)
{
	SDA_OUT();//sda线输出
	IIC_SCL=0;
	IIC_SDA=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(us);
	IIC_SCL=1; 
	IIC_SDA=1;//发送I2C总线结束信号
	delay_us(us);							   	
}
//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
unsigned char iic_wait_ack(void)
{
	u8 ucErrTime=0;
	SDA_IN();      //SDA设置为输入  
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
	IIC_SCL=0;//时钟输出0 	
	//printf("success");	
	return 0;  
} 
//产生ACK应答
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
//不产生ACK应答		    
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
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void iic_send_byte(unsigned char txd)
{                        
    u8 t;   
	SDA_OUT(); 	    
    IIC_SCL=0;//拉低时钟开始数据传输
    for(t=0;t<8;t++)
    {              
        IIC_SDA=(txd&0x80)>>7;
        txd<<=1; 	  
		delay_us(us);   //对TEA5767这三个延时都是必须的
		IIC_SCL=1;
		delay_us(us); 
		IIC_SCL=0;	
		delay_us(us);
    }	 
} 	    
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
unsigned char iic_read_byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();//SDA设置为输入
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
        iic_nack();//发送nACK
    else
        iic_ack(); //发送ACK   
    return receive;
}



/*********************************************************************************************/
