#include "xunji.h"
//#include "stm32f10x.h"
//#include "sys.h"
//#include "delay.h"
//#include "usart.h"
//#include "pwm.h"

//	
//	
//void xunji_config(void)	
//{
//  GPIO_InitTypeDef GPIO_InitStructure;	
//  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); // 使能PC端口时钟
//	
//  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7 ;	//选择对应的引脚
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);  //初始化PC端口
//	
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 ;	//选择对应的引脚
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);  //
//	
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5 ;	//选择对应的引脚
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);  //
//	
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4 ;	//选择对应的引脚
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);  //
//	
//	 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8 ;	//选择对应的引脚
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);  //初始化PC端口
//	
//	 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9 ;	//选择对应的引脚
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,浮空上啦   
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);  //初始化PC端口
//}

//void Read_xunji_Date(void)
//{
// xunji_1;
// xunji_2;
// xunji_3;
// xunji_4;
// xunji_5;
// xunji_6;
//}

////void xunji_start()
////{
////		static int count=0;
////    delay_init();    //延时初始化		
////	  xunji_config();   //循迹初始化
////		Read_xunji_Date(); //读循迹线值
////	  
////	  //车前4个循迹模块从左到右分别是xunji_1，xunji_2，xunji_3，xunji_4
////   
////	 if(xunji_1==0&&xunji_2==0&&xunji_3==0&&xunji_4==0)//0000
////	  {
//////	  CarGo();		  //如果都没有读取到黑线，直走
//////		led4_on();
//////		led5_on();	  //如果都没有读取到黑线，全亮
////		  printf("\r\n没有读取到黑线");
////		  GPIO_SetBits( GPIOB,  GPIO_Pin_5);	
////	  
////	  }
////	 if(xunji_1==0&&xunji_2==1&&xunji_3==0&&xunji_4==0)//0110
////	  {
//////	  CarGo();        //如果两个读取到黑线，直走
////		   printf("\r\n有读取到黑线左转");
////		
////	  }	  
////	 if(xunji_1==0&&xunji_2==0&&xunji_2==1&&xunji_2==0)//0100
////	  {
//////	  CarBigLeft();   //如果第一个读取到黑线，4
////		  printf("\r\n有读取到黑线右转");
////		
////	  }
//// 	 if(xunji_1==1&&xunji_2==1&&xunji_2==1&&xunji_2==1)//0010
////	  {
//////	  CarBigRight();   //如果全部读取到黑线，全亮
////		  printf("\r\n全部黑线");
////		  GPIO_ResetBits( GPIOB,  GPIO_Pin_5);	
//////		  count++;
////		  delay_ms(3000);
////		  if(count<10)
////		  { printf("停止");
////		  count++;}
////		  else printf("继续");
////		
////	  }
//////	  if(xunji_1==1&&xunji_2==0&&xunji_3==0&&xunji_4==0)//1000
//////	  {
//////	  CarBigLeft();   //如果第一个读取到黑线，左转
//////	  delay_ms(10);
//////	  }
//////	  if(xunji_1==0&&xunji_2==0&&xunji_3==0&&xunji_4==1)//0001
//////	  {
//////	  CarBigRight();   //如果第四个读取到黑线，左转
//////	  delay_ms(10); 
//////	  }
////}
//void xunji_start()
//{		
//		static int count=0;
//    delay_init();    //延时初始化		
//	  xunji_config();   //循迹初始化
//		Read_xunji_Date(); //读循迹线值
//	  Motion_TIM_Init();
//		if(xunji_5==0&&xunji_6==0)
//		{
//			//执行相关语句
//			if(xunji_1==0&&xunji_2==0&&xunji_3==0&&xunji_4==0)//0000
//	  {

//		     printf("\r\n没有读取到黑线");
//		  	 Motion_setPWM(90,90);
//	  
//	  }
//	 else if(xunji_1==0&&xunji_2==1&&xunji_3==0&&xunji_4==0)//0110
//	  {

//		   printf("\r\n左侧二路有读取到黑线稍微左转");
//			 Motion_setPWM(-90,90);
//		
//	  }	  
//	 else if(xunji_1==0&&xunji_2==0&&xunji_3==1&&xunji_4==0)//0100
//	  {

//		  printf("\r\n右侧3路有读取到黑线稍微右转");
//			 Motion_setPWM(90,-90);
//		
//	  }
//		else if(xunji_1==0&&xunji_2==0&&xunji_3==1&&xunji_4==1)//0100
//	  {

//		  printf("\r\n右侧3路4路有读取到黑线右转90度");
//			 Motion_setPWM(90,-90);
//			delay_ms(500);
//		
//	  }
//		else if(xunji_1==1&&xunji_2==1&&xunji_3==0&&xunji_4==0)//0100
//	  {

//		  printf("\r\n左侧1路2路有读取到黑线左转90度");
//			 Motion_setPWM(-90,90);
//			delay_ms(500);
//		
//	  }
// 	 else if(xunji_1==1&&xunji_2==1&&xunji_3==1&&xunji_4==1)//0010
//	  {

//		  printf("\r\n全部黑线");	
//		  count++;
//		  if(count == 1)
//		  { 
//				printf("减速");
//				Motion_setPWM(70,70);
//				delay_ms(1000);
//			}
//		  else if(count >= 2)
//			{
//					printf("制动");
//				Motion_setPWM(0,0);
//			}
//			
//		
//	  }

//		
//	}
//		else if(xunji_5==1&&xunji_6==0)
//		{
//			//执行右转程序
//			Motion_setPWM(90,-90);
//		}
//		else if(xunji_5==0&&xunji_6==1)
//		{
//			//执行左转程序
//			Motion_setPWM(-90,90);
//		}
//}
