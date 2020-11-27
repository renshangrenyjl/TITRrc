#ifndef __CAN_H
#define	__CAN_H


#include "stm32f4xx.h"

//���Ŷ���
/*******************************************************/
#define TEST_CAN                             CAN1
//ʹ��can2�����ʱ�򣬱���ͬʱʹ��CAN1ʱ��
#define TEST_CAN_CLK                         (RCC_APB1Periph_CAN2 | RCC_APB1Periph_CAN1)//��ʹ��CAN2ʱ������ͬʱʹ��CAN1ʱ��
#define TEST_CAN_DIV                    			6  //��Ƶ����

#define TEST_CAN_RX_GPIO_PORT                GPIOA
#define TEST_CAN_RX_GPIO_CLK                 RCC_AHB1Periph_GPIOA
#define TEST_CAN_RX_PIN                      GPIO_Pin_11
#define TEST_CAN_RX_AF                       GPIO_AF_CAN1
#define TEST_CAN_RX_SOURCE                   GPIO_PinSource11

#define TEST_CAN_TX_GPIO_PORT                GPIOA
#define TEST_CAN_TX_GPIO_CLK                 RCC_AHB1Periph_GPIOA
#define TEST_CAN_TX_PIN                      GPIO_Pin_12
#define TEST_CAN_TX_AF                       GPIO_AF_CAN1
#define TEST_CAN_TX_SOURCE                   GPIO_PinSource12

#define TEST_CAN_IRQHandler                  CAN1_RX0_IRQHandler
#define TEST_CAN_IRQ                 					CAN1_RX0_IRQn
/************************************************************/

void CAN_Config(void);
void CAN_Filter_Config(void);

#endif 



