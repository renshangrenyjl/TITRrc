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
	float pitch,roll,yaw; 		//ŷ����
	short aacx,aacy,aacz;		//���ٶȴ�����ԭʼ����
	short gyrox,gyroy,gyroz;	//������ԭʼ����
	short temp;					//�¶�
	int flag_wheel = 0;//���º�ת���־λ
	int restart_connect = 0;
	int flag_start_move = 0;//������־λ
	int connect_over = 0;//����״̬��־λ
	int slope_over = 0 ;//�����Ƿ������־λ
  int flag_place = 5 ;  //��������־λ��1,3,5����0��2,4�죻
	int across_over = 0;

void xunji_config(void)	
{
  GPIO_InitTypeDef GPIO_InitStructure;	
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); // ʹ��PC�˿�ʱ��
	
	 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //��ʼ��PC�˿�
	
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //��ʼ��PC�˿�
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //
	

	
	 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //��ʼ��PC�˿�
	
	 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //��ʼ��PC�˿�
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //��ʼ��PC�˿�
	
	 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_15 ;	//ѡ���Ӧ������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);  //��ʼ��PC�˿�
}

void Read_xunji_Date(void)
{
 xunji_1;//�����������
 xunji_2;//�����������
 xunji_3;//�����
 xunji_5;//��⽻����
 xunji_6;//��⽻����
}



void xunji_start()
{

  uart_init(115200);
	//TIM3_PWM_Init(1999,719);
	static int count=0;
    delay_init();    //��ʱ��ʼ��		
	  xunji_config();   //ѭ����ʼ��
		Read_xunji_Date(); //��ѭ����ֵ
	  Motion_TIM_Init();
	
	
		
//		else if(xunji_5 == 1&&xunji_6 == 1&&(flag_place == 2||flag_place == 3||flag_place == 4)&&(yaw <60||yaw > -60))
//		{
//			Motion_setPWM(99,99);
//		}
	while(flag_place == 4&&yaw > 75)//�쳡��⵽����
		{
			 //Motion_setPWM(-99,-99);
			//delay_ms(30);
			//printf("���׵���");
			Motion_setPWM(99,99);
			GPIO_ResetBits(GPIOB,GPIO_Pin_12);//�̵�������
				delay_ms(3000);
		while(across_over == 0)
		{
			Motion_setPWM(99,99);
		
			if(xunji_7 == 0&&xunji_8 == 0)
			{
				delay_ms(20);
				if(xunji_7 == 0&&xunji_8 == 0)
				{				
					GPIO_SetBits(GPIOB,GPIO_Pin_12);//�رռ̵���
				across_over = 1;
					
				}
			}
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//�õ��¶�ֵ
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
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
				// GPIO_SetBits(GPIOB,GPIO_Pin_12);//�رռ̵��� //JDQ_off();//�����ջ�
			//delay_ms(500);
			//printf("�����ջ�");
			while(across_over == 1)
			{
				//Motion_setPWM(99,99);
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//�õ��¶�ֵ
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
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
				      TIM_SetCompare4(TIM3, 1920);//צ�ӷ���
		          delay_ms(300);
		          TIM_SetCompare3(TIM3, 1750);//צ�Ӵ�	
						}
						
					}
				 
				}
					 
			}
			
		}
	
		while(flag_place == 4&&yaw < -75)//������⵽����
		{
			 //Motion_setPWM(-99,-99);
			//delay_ms(30);
			//printf("���׵���");
			Motion_setPWM(99,99);
			GPIO_ResetBits(GPIOB,GPIO_Pin_12);//�̵�������
				delay_ms(3000);
		while(across_over == 0)
		{
			Motion_setPWM(99,99);
		
			if(xunji_7 == 0&&xunji_8 == 0)
			{
				delay_ms(20);
				if(xunji_7 == 0&&xunji_8 == 0)
				{				
					GPIO_SetBits(GPIOB,GPIO_Pin_12);//�رռ̵���
				across_over = 1;
					
				}
			}
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//�õ��¶�ֵ
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
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
				// GPIO_SetBits(GPIOB,GPIO_Pin_12);//�رռ̵��� //JDQ_off();//�����ջ�
			//delay_ms(500);
			//printf("�����ջ�");
			while(across_over == 1)
			{
				//Motion_setPWM(99,99);
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//�õ��¶�ֵ
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
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
				      TIM_SetCompare4(TIM3, 1920);//צ�ӷ���
		          delay_ms(300);
		          TIM_SetCompare3(TIM3, 1750);//צ�Ӵ�	
						}
						
					}
				 
				}
					 
			}
			
		}
		
		 if(xunji_5==0&&xunji_6==0&&(flag_place == 2||flag_place == 3||flag_place == 4))
		{
			  //ֱ��
			//printf("X");
			//printf("ֱ��");
				Motion_setPWM(100,100);
		
   	}
		else if(xunji_5==1&&xunji_6==0&&(flag_place == 2||flag_place == 3))
		{
			//ִ����ת����
			//printf("��ת");
//			Motion_setPWM(-85,-85);
//			delay_ms(10);
			Motion_setPWM(85,-99);
			delay_ms(100);
		}
		else if(xunji_5==1&&xunji_6==0&&flag_place == 4)
		{
			//ִ����ת����
			//printf("��ת");
//			Motion_setPWM(-85,-85);
//			delay_ms(10);
			Motion_setPWM(99,-99);
			delay_ms(200);
		}
		else if(xunji_5==0&&xunji_6==1&&(flag_place == 2||flag_place == 3))
		{
			//ִ����ת����
			//printf("��ת");
//			Motion_setPWM(-85,-85);
//			delay_ms(10);
			Motion_setPWM(-99,85);
			delay_ms(100);
		}
		else if(xunji_5==0&&xunji_6==1&&flag_place == 4)
		{
			//ִ����ת����
			//printf("��ת");
//			Motion_setPWM(-85,-85);
//			delay_ms(10);
			Motion_setPWM(-99,99);
			delay_ms(200);
		}
  
		 if(xunji_1 == 0 && xunji_2 == 1 && xunji_5 == 0 &&xunji_6 == 0 && flag_place  == 2)//����쳡������
			 
    {  
		  Motion_setPWM(99,99);
//			delay_ms(150);
			
			while(yaw < 88)
			{
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//�õ��¶�ֵ
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
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
					 TIM_SetCompare3(TIM3, 1800);//צ�ӱպ�
					 delay_ms(3000);
					 TIM_SetCompare4(TIM3, 1860);//צ��̧��
					connect_over = 1;//ץȡ������
				 }
		  }
			
			while(yaw > 5)
			{
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//�õ��¶�ֵ
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
		    }
				 Motion_setPWM(85,-99);
			}
			
			flag_place = 4;
  }

    else if(xunji_1 == 1 && xunji_2 == 0 &&xunji_5 == 0&&xunji_6 == 0&& flag_place  == 3)//��������������
    {
			Motion_setPWM(-99,-99);
		  delay_ms(150);
			while(yaw > -88)
			{
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//�õ��¶�ֵ
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
		    }
				 Motion_setPWM(99,-85);
			}
		 		while(connect_over == 0)
		   {
				 Motion_setPWM(0,0);
				if(xunji_3 == 0)
				{
						delay_ms(5000);
					 TIM_SetCompare3(TIM3, 1800);//צ�ӱպ�
					 delay_ms(300);
					 TIM_SetCompare4(TIM3, 1860);//צ��̧��
					connect_over = 1;//ץȡ������
				}
			 }
     while(yaw < -5)
			{
				if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		   { 
			    temp=MPU_Get_Temperature();	//�õ��¶�ֵ
			    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			    MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
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
	printf("����ʼ\r\n");
	
	if( MPU_Init()!=0 )
	{
		printf("MPU6050��ʼ������\n");
		return 0;
	}
		
	if( mpu_dmp_init() )
	{
		printf("DMP��ʼ������\n");
		return 0;
	}
	
	
	while(1)
	{
		
			if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		{ 
			temp=MPU_Get_Temperature();	//�õ��¶�ֵ
			MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
		}
		//delay_ms(100);
		printf("\r\npitch:%f  roll:%f  yaw:%f\r\n",pitch,roll,yaw);

	    printf("move\r\n");
		
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3)==0)//�쳡��������
	 {
			flag_place = 0;
		 slope_over = 0;
		  flag_start_move = 0;
		 TIM_SetCompare4(TIM3, 1920);//צ�ӷ���
		      delay_ms(300);
		TIM_SetCompare3(TIM3, 1750);//צ�Ӵ�	
		      delay_ms(300);
		 while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3)!=1);
	 }
	 if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)==0)//������������
	 {
			flag_place = 1;
		 slope_over = 0;
		 flag_start_move = 0;
		 TIM_SetCompare4(TIM3, 1920);//צ�ӷ���
		     delay_ms(300);
		TIM_SetCompare3(TIM3, 1750);//צ�Ӵ�	
		     delay_ms(300);
		 while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)!=1);
	 }
		
	 if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_12)==0)//��ͣ����
	 {
			flag_place = 5;
		  slope_over = 1;
		  connect_over = 0;
		 	Motion_setPWM(0,0);
		 TIM_SetCompare3(TIM3, 1800);//צ�ӱպ�
		 delay_ms(300);
		 TIM_SetCompare4(TIM3, 1860);//צ��̧��
		 while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_12)!=1);

	 }
	 
	 	 if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2)==0)//������ɺ�쳡��������������
	 {
		  flag_place = 4;
		 flag_start_move = 1;
		 slope_over = 1;

		 TIM_SetCompare3(TIM3, 1800);//צ�ӱպ�
		 delay_ms(300);
		 TIM_SetCompare4(TIM3, 1860);//צ��̧��
		 while(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2)!=1);
	 }
	 
	  if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)==0)//������ɺ�������������������
	 {
		  flag_place = 4;
		 flag_start_move = 1;
		 slope_over = 1;
		 	TIM_SetCompare3(TIM3, 1800);//צ�ӱպ�
		 delay_ms(300);
		 TIM_SetCompare4(TIM3, 1860);//צ��̧��
		 while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)!=1);
	 }
	 
	 	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_11)==0)//�쳡���ӵ���
	 {
		 flag_place = 2;
		 flag_start_move = 1;
		 slope_over = 1;
		 while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)!=1);
	 }
	 
	 if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_11)==0)//�������ӵ���
	 {
		 flag_place = 3;
		 flag_start_move = 1;
		 slope_over = 1;
		 while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)!=1);
	 }
	 
	 
	 
	 
			if(flag_place == 0)//�쳡��־λ
			{
						//printf("��������תһ���Ƕ�");
				     Motion_setPWM(99,-99);
				   if(yaw < -47)
				   {
					  flag_start_move = 1;
						 flag_place = 2;
						// printf("��ת����");
						 Motion_setPWM(99,99);//���½���ǰֱ��
						 delay_ms(3000);
				   }
				}
			   
			if(flag_place == 1)//������־λ
			{
					//printf("��������תһ���Ƕ�");
				   Motion_setPWM(-99,99);
					if(yaw > 46)//����б���ٽ�ֵ
					{
							 flag_start_move = 1;//����б�½�����־λ
						 flag_place = 3;//������־λ
						 Motion_setPWM(99,99);//���½���ǰֱ��
						 delay_ms(3000);
						// printf("��ת����");
					}
		   	
		  }
		if( flag_start_move == 1)//������б�£���ʼִ�����³���
		{
				if(slope_over == 1)
		   {
					//printf("move0\r\n");
			     xunji_start();//������£�����ǰ��
		   }	
				
		
		   if(slope_over == 0)		
		   {
				 Motion_setPWM(95,99); //���½���ǰֱ��
				 if(pitch>-13 )//ǰ������ƽ�棬�¶ȿ�ʼ������ת�俪ʼ��־ֵ
      	{
//					while(stop == 0)
//					{
//							Motion_setPWM(0,0);
//						delay_ms(500);
//						stop++;
//					}
						if (flag_place == 2)//�쳡��־λ
		          {

			          Motion_setPWM(-100,100);//�쳡���º���ת;
						
					        if(yaw > 30)//���º���ת��ʮ���ٽ�ֵ
						       {
				             slope_over = 1;//���½�����־λ
										 
			             }
							}
						else if(flag_place == 3)//������־λ
							{
					       Motion_setPWM(100,-100);//�������º���ת
							   if(yaw < -27)//���º���ת��ʮ���ٽ�ֵ
			           {
				             slope_over = 1;//���½�����־λ

			           }
							}
					}				
				
		    }		
		}
	     
  
  }//while
}
		

