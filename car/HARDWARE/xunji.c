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
//  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); // ʹ��PC�˿�ʱ��
//	
//  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7 ;	//ѡ���Ӧ������
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);  //��ʼ��PC�˿�
//	
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 ;	//ѡ���Ӧ������
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);  //
//	
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5 ;	//ѡ���Ӧ������
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);  //
//	
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4 ;	//ѡ���Ӧ������
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);  //
//	
//	 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8 ;	//ѡ���Ӧ������
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);  //��ʼ��PC�˿�
//	
//	 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9 ;	//ѡ���Ӧ������
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);  //��ʼ��PC�˿�
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
////    delay_init();    //��ʱ��ʼ��		
////	  xunji_config();   //ѭ����ʼ��
////		Read_xunji_Date(); //��ѭ����ֵ
////	  
////	  //��ǰ4��ѭ��ģ������ҷֱ���xunji_1��xunji_2��xunji_3��xunji_4
////   
////	 if(xunji_1==0&&xunji_2==0&&xunji_3==0&&xunji_4==0)//0000
////	  {
//////	  CarGo();		  //�����û�ж�ȡ�����ߣ�ֱ��
//////		led4_on();
//////		led5_on();	  //�����û�ж�ȡ�����ߣ�ȫ��
////		  printf("\r\nû�ж�ȡ������");
////		  GPIO_SetBits( GPIOB,  GPIO_Pin_5);	
////	  
////	  }
////	 if(xunji_1==0&&xunji_2==1&&xunji_3==0&&xunji_4==0)//0110
////	  {
//////	  CarGo();        //���������ȡ�����ߣ�ֱ��
////		   printf("\r\n�ж�ȡ��������ת");
////		
////	  }	  
////	 if(xunji_1==0&&xunji_2==0&&xunji_2==1&&xunji_2==0)//0100
////	  {
//////	  CarBigLeft();   //�����һ����ȡ�����ߣ�4
////		  printf("\r\n�ж�ȡ��������ת");
////		
////	  }
//// 	 if(xunji_1==1&&xunji_2==1&&xunji_2==1&&xunji_2==1)//0010
////	  {
//////	  CarBigRight();   //���ȫ����ȡ�����ߣ�ȫ��
////		  printf("\r\nȫ������");
////		  GPIO_ResetBits( GPIOB,  GPIO_Pin_5);	
//////		  count++;
////		  delay_ms(3000);
////		  if(count<10)
////		  { printf("ֹͣ");
////		  count++;}
////		  else printf("����");
////		
////	  }
//////	  if(xunji_1==1&&xunji_2==0&&xunji_3==0&&xunji_4==0)//1000
//////	  {
//////	  CarBigLeft();   //�����һ����ȡ�����ߣ���ת
//////	  delay_ms(10);
//////	  }
//////	  if(xunji_1==0&&xunji_2==0&&xunji_3==0&&xunji_4==1)//0001
//////	  {
//////	  CarBigRight();   //������ĸ���ȡ�����ߣ���ת
//////	  delay_ms(10); 
//////	  }
////}
//void xunji_start()
//{		
//		static int count=0;
//    delay_init();    //��ʱ��ʼ��		
//	  xunji_config();   //ѭ����ʼ��
//		Read_xunji_Date(); //��ѭ����ֵ
//	  Motion_TIM_Init();
//		if(xunji_5==0&&xunji_6==0)
//		{
//			//ִ��������
//			if(xunji_1==0&&xunji_2==0&&xunji_3==0&&xunji_4==0)//0000
//	  {

//		     printf("\r\nû�ж�ȡ������");
//		  	 Motion_setPWM(90,90);
//	  
//	  }
//	 else if(xunji_1==0&&xunji_2==1&&xunji_3==0&&xunji_4==0)//0110
//	  {

//		   printf("\r\n����·�ж�ȡ��������΢��ת");
//			 Motion_setPWM(-90,90);
//		
//	  }	  
//	 else if(xunji_1==0&&xunji_2==0&&xunji_3==1&&xunji_4==0)//0100
//	  {

//		  printf("\r\n�Ҳ�3·�ж�ȡ��������΢��ת");
//			 Motion_setPWM(90,-90);
//		
//	  }
//		else if(xunji_1==0&&xunji_2==0&&xunji_3==1&&xunji_4==1)//0100
//	  {

//		  printf("\r\n�Ҳ�3·4·�ж�ȡ��������ת90��");
//			 Motion_setPWM(90,-90);
//			delay_ms(500);
//		
//	  }
//		else if(xunji_1==1&&xunji_2==1&&xunji_3==0&&xunji_4==0)//0100
//	  {

//		  printf("\r\n���1·2·�ж�ȡ��������ת90��");
//			 Motion_setPWM(-90,90);
//			delay_ms(500);
//		
//	  }
// 	 else if(xunji_1==1&&xunji_2==1&&xunji_3==1&&xunji_4==1)//0010
//	  {

//		  printf("\r\nȫ������");	
//		  count++;
//		  if(count == 1)
//		  { 
//				printf("����");
//				Motion_setPWM(70,70);
//				delay_ms(1000);
//			}
//		  else if(count >= 2)
//			{
//					printf("�ƶ�");
//				Motion_setPWM(0,0);
//			}
//			
//		
//	  }

//		
//	}
//		else if(xunji_5==1&&xunji_6==0)
//		{
//			//ִ����ת����
//			Motion_setPWM(90,-90);
//		}
//		else if(xunji_5==0&&xunji_6==1)
//		{
//			//ִ����ת����
//			Motion_setPWM(-90,90);
//		}
//}
