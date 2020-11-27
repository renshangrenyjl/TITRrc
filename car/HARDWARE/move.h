#ifndef  _MOVE_H_
#define  _MOVE_H_


#define xunji_3 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)
#define xunji_2 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6)
#define xunji_1 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7)
#define xunji_5 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8)
#define xunji_6 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9)
#define xunji_7 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14)
#define xunji_8 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15)
void xunji_start(void);
int move_one(void);
void upslope_wheel(void);
void xunji_config(void);
void Read_xunji_Date(void);

#endif



