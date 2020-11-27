#include "move.h"
#include "stm32f10x.h"
#include "usart.h"
#include "sys.h"
#include "xunji.h"
#include "JDQ.h"
#include "pwm.h"
#include "servo.h"
#include "delay.h"
#include "mpu6050.h"  
#include "mpuiic.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"

  uint8_t x=0;
	float pitch,roll,yaw; 		//欧拉角
	short aacx,aacy,aacz;		//加速度传感器原始数据
	short gyrox,gyroy,gyroz;	//陀螺仪原始数据
	short temp;					//温度
	int flag_wheel = 0;//上坡后转弯标志位
	int restart_connect = 0;
	int flag_start_move = 0;//启动标志位
	int connect_over = 0;//交接状态标志位
	int slope_over = 0 ;//上坡是否结束标志位
  int flag_place = 5 ;  //红蓝场标志位，1,3,5蓝；0，2,4红；
	int across_over = 0;

void xunji_config(void)	
{
  GPIO_InitTypeDef GPIO_InitStructure;	
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); // 使能PC端口时钟
	
	 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //初始化PC端口
	
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //初始化PC端口
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //
	

	
	 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //初始化PC端口
	
	 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //初始化PC端口
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //初始化PC端口
	
	 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_15 ;	//选择对应的引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //初始化PC端口
}

void Read_xunji_Date(void)
{
 xunji_1;//检测两侧悬崖
 xunji_2;//检测两侧悬崖
 xunji_3;//检测火炬
 xunji_5;//检测交接区
 xunji_6;//检测交接区
}



void xunji_start()
{

  uart_init(115200);
	//TIM3_PWM_Init(1999,719);
	static int count=0;
    delay_init();    //延时初始化		
	  xunji_config();   //循迹初始化
		Read_xunji_Date(); //读循迹线值
	  Motion_TIM_Init();
	
	
		
//		else if(xunji_5 == 1&&xunji_6 == 1&&(flag_place == 2||flag_place == 3||flag_place == 4)&&(yaw <60||yaw > -60))
//		{
//			Motion_setPWM(99,99);
//		}
	while(flag_place == 4&&yaw > 75)//红场检测到断桥
		{
			 //Motion_setPWM(-99,-99);
			//delay_ms(30);
			//printf("气缸弹出");
			Motion_setPWM(99,99);
			GPIO_ResetBits(GPIOB,GPIO_Pin_12);//继电器开启
				delay_ms(3000);
		while(across_over == 0)
		{
			Motion_setPWM(99,99);
		
			if(xunji_7 == 0&&xunji_8 == 0)
			{
				delay_ms(20);
				if(xunji_7 == 0&&xunji_8 == 0)
				{				
					GPIO_SetBits(GPIOB,GPIO_Pin_12);//关闭继电器
				across_over = 1;
					
				}
			}
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//得到温度值
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
		    }
				if(yaw < 77&&yaw > 72)
					{
						Motion_setPWM(99,99);
					}
				else if(yaw > 77)
					{
						Motion_setPWM(99,-99);
					}
				else if(yaw < 72)
					{
						Motion_setPWM(-99,99);
						
					}

			
			
		}
				// GPIO_SetBits(GPIOB,GPIO_Pin_12);//关闭继电器 //JDQ_off();//气缸收回
			//delay_ms(500);
			//printf("气缸收回");
			while(across_over == 1)
			{
				//Motion_setPWM(99,99);
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//得到温度值
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
		    }
				if(yaw < 77&&yaw > 72)
					{
						Motion_setPWM(99,99);
					}
				else if(yaw > 77)
					{
						Motion_setPWM(99,-99);
					}
				else if(yaw < 72)
					{
						Motion_setPWM(-99,99);
						
					}
				if(xunji_8 == 1)
				{
					delay_ms(20);
					while(xunji_8 == 1)
					{
						while(1)
						{
							Motion_setPWM(0,0);
					    delay_ms(300);
				      TIM_SetCompare4(TIM3, 1920);//爪子放下
		          delay_ms(300);
		          TIM_SetCompare3(TIM3, 1750);//爪子打开	
						}
						
					}
				 
				}
					 
			}
			
		}
	
		while(flag_place == 4&&yaw < -75)//蓝场检测到断桥
		{
			 //Motion_setPWM(-99,-99);
			//delay_ms(30);
			//printf("气缸弹出");
			Motion_setPWM(99,99);
			GPIO_ResetBits(GPIOB,GPIO_Pin_12);//继电器开启
				delay_ms(3000);
		while(across_over == 0)
		{
			Motion_setPWM(99,99);
		
			if(xunji_7 == 0&&xunji_8 == 0)
			{
				delay_ms(20);
				if(xunji_7 == 0&&xunji_8 == 0)
				{				
					GPIO_SetBits(GPIOB,GPIO_Pin_12);//关闭继电器
				across_over = 1;
					
				}
			}
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//得到温度值
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
		    }
				if(yaw > -77&&yaw < -72)
					{
						Motion_setPWM(99,99);
					}
				else if(yaw<-77)
					{
						Motion_setPWM(-99,99);
					}
				else if(yaw > -72)
					{
						Motion_setPWM(99,-99);
						
					}

			
			
		}
				// GPIO_SetBits(GPIOB,GPIO_Pin_12);//关闭继电器 //JDQ_off();//气缸收回
			//delay_ms(500);
			//printf("气缸收回");
			while(across_over == 1)
			{
				//Motion_setPWM(99,99);
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//得到温度值
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
		    }
       if(yaw > -77&&yaw < -72)
					{
						Motion_setPWM(99,99);
					}
				else if(yaw<-77)
					{
						Motion_setPWM(-99,99);
					}
				else if(yaw > -72)
					{
						Motion_setPWM(99,-99);
						
					}
				if(xunji_8 == 1)
				{
					delay_ms(20);
					while(xunji_8 == 1)
					{
						while(1)
						{
							Motion_setPWM(0,0);
					    delay_ms(300);
				      TIM_SetCompare4(TIM3, 1920);//爪子放下
		          delay_ms(300);
		          TIM_SetCompare3(TIM3, 1750);//爪子打开	
						}
						
					}
				 
				}
					 
			}
			
		}
		
		 if(xunji_5==0&&xunji_6==0&&(flag_place == 2||flag_place == 3||flag_place == 4))
		{
			  //直行
			//printf("X");
			//printf("直走");
				Motion_setPWM(100,100);
		
   	}
		else if(xunji_5==1&&xunji_6==0&&(flag_place == 2||flag_place == 3))
		{
			//执行右转程序
			//printf("右转");
//			Motion_setPWM(-85,-85);
//			delay_ms(10);
			Motion_setPWM(85,-99);
			delay_ms(100);
		}
		else if(xunji_5==1&&xunji_6==0&&flag_place == 4)
		{
			//执行右转程序
			//printf("右转");
//			Motion_setPWM(-85,-85);
//			delay_ms(10);
			Motion_setPWM(99,-99);
			delay_ms(200);
		}
		else if(xunji_5==0&&xunji_6==1&&(flag_place == 2||flag_place == 3))
		{
			//执行左转程序
			//printf("左转");
//			Motion_setPWM(-85,-85);
//			delay_ms(10);
			Motion_setPWM(-99,85);
			delay_ms(100);
		}
		else if(xunji_5==0&&xunji_6==1&&flag_place == 4)
		{
			//执行左转程序
			//printf("左转");
//			Motion_setPWM(-85,-85);
//			delay_ms(10);
			Motion_setPWM(-99,99);
			delay_ms(200);
		}
  
		 if(xunji_1 == 0 && xunji_2 == 1 && xunji_5 == 0 &&xunji_6 == 0 && flag_place  == 2)//进入红场交接区
			 
    {  
		  Motion_setPWM(99,99);
//			delay_ms(150);
			
			while(yaw < 88)
			{
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//得到温度值
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
		    }
				 Motion_setPWM(-85,99);
			}
			 Motion_setPWM(-99,-99);
			delay_ms(20);
		     while(connect_over == 0)
		   {
			   Motion_setPWM(0,0);
				 if(xunji_3 == 0)
				 {
					 delay_ms(5000);
					 TIM_SetCompare3(TIM3, 1800);//爪子闭合
					 delay_ms(3000);
					 TIM_SetCompare4(TIM3, 1860);//爪子抬起
					connect_over = 1;//抓取火把完成
				 }
		  }
			
			while(yaw > 5)
			{
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//得到温度值
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
		    }
				 Motion_setPWM(85,-99);
			}
			
			flag_place = 4;
  }

    else if(xunji_1 == 1 && xunji_2 == 0 &&xunji_5 == 0&&xunji_6 == 0&& flag_place  == 3)//进入蓝场交接区
    {
			Motion_setPWM(-99,-99);
		  delay_ms(150);
			while(yaw > -88)
			{
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//得到温度值
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
		    }
				 Motion_setPWM(99,-85);
			}
		 		while(connect_over == 0)
		   {
				 Motion_setPWM(0,0);
				if(xunji_3 == 0)
				{
						delay_ms(5000);
					 TIM_SetCompare3(TIM3, 1800);//爪子闭合
					 delay_ms(300);
					 TIM_SetCompare4(TIM3, 1860);//爪子抬起
					connect_over = 1;//抓取火把完成
				}
			 }
     while(yaw < -5)
			{
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//得到温度值
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
		    }
				 Motion_setPWM(-99,85);
			}
			flag_place = 4;
   }
}



int move_one()
{
	NVIC_PriorityGroupConfig( 2 );
	delay_init();
	uart_init(115200);
	printf("程序开始\r\n");
	
	if( MPU_Init()!=0 )
	{
		printf("MPU6050初始化错误！\n");
		return 0;
	}
		
	if( mpu_dmp_init() )
	{
		printf("DMP初始化错误！\n");
		return 0;
	}
	
	
	while(1)
	{
		
			if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		{ 
			temp=MPU_Get_Temperature();	//得到温度值
			MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
		}
		//delay_ms(100);
		printf("\r\npitch:%f  roll:%f  yaw:%f\r\n",pitch,roll,yaw);

	    printf("move\r\n");
		
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3)==0)//红场启动按键
	 {
			flag_place = 0;
		 slope_over = 0;
		  flag_start_move = 0;
		 TIM_SetCompare4(TIM3, 1920);//爪子放下
		      delay_ms(300);
		TIM_SetCompare3(TIM3, 1750);//爪子打开	
		      delay_ms(300);
		 while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3)!=1);
	 }
	 if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)==0)//蓝场启动按键
	 {
			flag_place = 1;
		 slope_over = 0;
		 flag_start_move = 0;
		 TIM_SetCompare4(TIM3, 1920);//爪子放下
		     delay_ms(300);
		TIM_SetCompare3(TIM3, 1750);//爪子打开	
		     delay_ms(300);
		 while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)!=1);
	 }
		
	 if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_12)==0)//暂停按键
	 {
			flag_place = 5;
		  slope_over = 1;
		  connect_over = 0;
		 	Motion_setPWM(0,0);
		 TIM_SetCompare3(TIM3, 1800);//爪子闭合
		 delay_ms(300);
		 TIM_SetCompare4(TIM3, 1860);//爪子抬起
		 while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_12)!=1);

	 }
	 
	 	 if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2)==0)//交接完成后红场交接区重启按键
	 {
		  flag_place = 4;
		 flag_start_move = 1;
		 slope_over = 1;

		 TIM_SetCompare3(TIM3, 1800);//爪子闭合
		 delay_ms(300);
		 TIM_SetCompare4(TIM3, 1860);//爪子抬起
		 while(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2)!=1);
	 }
	 
	  if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)==0)//交接完成后蓝场交接区重启按键
	 {
		  flag_place = 4;
		 flag_start_move = 1;
		 slope_over = 1;
		 	TIM_SetCompare3(TIM3, 1800);//爪子闭合
		 delay_ms(300);
		 TIM_SetCompare4(TIM3, 1860);//爪子抬起
		 while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)!=1);
	 }
	 
	 	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_11)==0)//红场交接调试
	 {
		 flag_place = 2;
		 flag_start_move = 1;
		 slope_over = 1;
		 while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)!=1);
	 }
	 
	 if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_11)==0)//蓝场交接调试
	 {
		 flag_place = 3;
		 flag_start_move = 1;
		 slope_over = 1;
		 while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)!=1);
	 }
	 
	 
	 
	 
			if(flag_place == 0)//红场标志位
			{
						//printf("启动后右转一定角度");
				     Motion_setPWM(99,-99);
				   if(yaw < -47)
				   {
					  flag_start_move = 1;
						 flag_place = 2;
						// printf("右转结束");
						 Motion_setPWM(99,99);//上坡结束前直走
						 delay_ms(3000);
				   }
				}
			   
			if(flag_place == 1)//蓝场标志位
			{
					//printf("启动后左转一定角度");
				   Motion_setPWM(-99,99);
					if(yaw > 46)//正对斜坡临界值
					{
							 flag_start_move = 1;//正对斜坡结束标志位
						 flag_place = 3;//蓝场标志位
						 Motion_setPWM(99,99);//上坡结束前直走
						 delay_ms(3000);
						// printf("左转结束");
					}
		   	
		  }
		if( flag_start_move == 1)//已正对斜坡，开始执行以下程序
		{
				if(slope_over == 1)
		   {
					//printf("move0\r\n");
			     xunji_start();//完成上坡，继续前进
		   }	
				
		
		   if(slope_over == 0)		
		   {
				 Motion_setPWM(95,99); //上坡结束前直走
				 if(pitch>-13 )//前车身到达平面，坡度开始减缓，转弯开始标志值
      	{
//					while(stop == 0)
//					{
//							Motion_setPWM(0,0);
//						delay_ms(500);
//						stop++;
//					}
						if (flag_place == 2)//红场标志位
		          {

			          Motion_setPWM(-100,100);//红场上坡后左转;
						
					        if(yaw > 30)//上坡后旋转九十度临界值
						       {
				             slope_over = 1;//上坡结束标志位
										 
			             }
							}
						else if(flag_place == 3)//蓝场标志位
							{
					       Motion_setPWM(100,-100);//蓝场上坡后右转
							   if(yaw < -27)//上坡后旋转九十度临界值
			           {
				             slope_over = 1;//上坡结束标志位

			           }
							}
					}				
				
		    }		
		}
	     
  
  }//while
}
		

