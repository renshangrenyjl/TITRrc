#include "mpu_pid.h"
#include "time.h"


struct _pid
	{
    float Setpitch;            //�����趨ֵ
    float Actualpitch;        //����ʵ��ֵ
    float err;                //����ƫ��ֵ
    float err_last;            //������һ��ƫ��ֵ
    float Kp,Ki,Kd;            //������������֡�΢��ϵ��
    float OUT;          //�����ѹֵ������ִ�����ı�����
    float integral;   		//�������ֵ
		float limit;
  }pid;  

void PID_pitch_init()
{
   //printf("PID_init begin \n");
    pid.Setpitch = 0.0;
    pid.Actualpitch = 0.0;
    pid.err = 0.0;
    pid.err_last = 0.0;
    pid.OUT = 0.0;
    pid.integral = 0.0;
    pid.Kp = 3.5;
    pid.Ki = 0;
    pid.Kd = 0;
		pid.limit = 50;
   // printf("PID_init end \n");
}

float PID_realize(float Target,float Actual)
{
			if(pid.Actualpitch > pid.limit)
    {
      pid.Actualpitch =  pid.limit;
    }
    else if(pid.Actualpitch < -pid.limit)
    {
      pid.Actualpitch =  -pid.limit;
    }
	
		pid.Setpitch = Target;
		pid.Actualpitch = Actual;
    pid.err = pid.Setpitch-pid.Actualpitch;
    pid.integral += pid.err;
    pid.OUT = pid.Kp*pid.err+pid.Ki*pid.integral+pid.Kd*(pid.err-pid.err_last);
    pid.err_last = pid.err;
    
		return pid.OUT;
	
}
    

