#ifndef  __APP_CFG_H__
#define  __APP_CFG_H__

/*******************�����������ȼ�*******************/
#define START_TASK_PRIO       10 							//��ʼ��������ȼ�����Ϊ��ͣ������������ȼ�
#define MOVE0_TASK_PRIO       20 							//�����������ȼ�
#define MOVE1_TASK_PRIO       21 							//�����������ȼ�
#define MOVE2_TASK_PRIO       22 							//�����������ȼ�
#define MOVE3_TASK_PRIO       23 							//�����������ȼ�
#define MOVE4_TASK_PRIO       24 							//�����������ȼ�
#define MOVE5_TASK_PRIO       25 							//�����������ȼ�

/************����ջ��С����λΪ OS_STK ��************/
/************ջ�ķ�������SRAM�е� ������flash�� 407��flashΪ1M SRAMΪ192K ************/
#define START_STK_SIZE  	  256					 		//���������ջ��С
#define MOVE0_STK_SIZE  	  256							//���������ջ��С
#define MOVE1_STK_SIZE  	  256							//���������ջ��С
#define MOVE2_STK_SIZE  	  256							//���������ջ��С
#define MOVE3_STK_SIZE  	  256							//���������ջ��С
#define MOVE4_STK_SIZE  	  256							//���������ջ��С
#define MOVE5_STK_SIZE  	  256							//���������ջ��С

/**************** �û��������� *******************/
void START_TASK(void *pdata);						//�������ӿ�	
void MOVE0_TASK(void *pdata);						//�������ӿ�
void MOVE1_TASK(void *pdata);						//�������ӿ�
void MOVE2_TASK(void *pdata);						//�������ӿ�
void MOVE3_TASK(void *pdata);						//�������ӿ�
void MOVE4_TASK(void *pdata);						//�������ӿ�
void MOVE5_TASK(void *pdata);						//�������ӿ�

#endif

