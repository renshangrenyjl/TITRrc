#ifndef  __APP_CFG_H__
#define  __APP_CFG_H__

/*******************设置任务优先级*******************/
#define START_TASK_PRIO       10 							//开始任务的优先级设置为最低，设置任务优先级
#define MOVE0_TASK_PRIO       20 							//设置任务优先级
#define MOVE1_TASK_PRIO       21 							//设置任务优先级
#define MOVE2_TASK_PRIO       22 							//设置任务优先级
#define MOVE3_TASK_PRIO       23 							//设置任务优先级
#define MOVE4_TASK_PRIO       24 							//设置任务优先级
#define MOVE5_TASK_PRIO       25 							//设置任务优先级

/************设置栈大小（单位为 OS_STK ）************/
/************栈的分配是在SRAM中的 不是在flash中 407的flash为1M SRAM为192K ************/
#define START_STK_SIZE  	  256					 		//设置任务堆栈大小
#define MOVE0_STK_SIZE  	  256							//设置任务堆栈大小
#define MOVE1_STK_SIZE  	  256							//设置任务堆栈大小
#define MOVE2_STK_SIZE  	  256							//设置任务堆栈大小
#define MOVE3_STK_SIZE  	  256							//设置任务堆栈大小
#define MOVE4_STK_SIZE  	  256							//设置任务堆栈大小
#define MOVE5_STK_SIZE  	  256							//设置任务堆栈大小

/**************** 用户任务声明 *******************/
void START_TASK(void *pdata);						//任务函数接口	
void MOVE0_TASK(void *pdata);						//任务函数接口
void MOVE1_TASK(void *pdata);						//任务函数接口
void MOVE2_TASK(void *pdata);						//任务函数接口
void MOVE3_TASK(void *pdata);						//任务函数接口
void MOVE4_TASK(void *pdata);						//任务函数接口
void MOVE5_TASK(void *pdata);						//任务函数接口

#endif

