/*
************************************************************************************************
��Ҫ�İ����ļ�

�� ��: INCLUDES.C ucos�����ļ�
�� ��: Jean J. Labrosse
************************************************************************************************
*/

#ifndef __INCLUDES_H__
#define __INCLUDES_H__
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>

#include "stm32f4xx.h"
#include "arm_math.h"


/*********��ӡ��������******************************/
void USART_OUT(USART_TypeDef* USARTx, uint8_t *Data,...);
char *itoa(int value, char *string, int radix);

#endif































