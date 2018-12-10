#ifndef __ULTRASOUND_H__
#define __ULTRASOUND_H__	

#include"share.h"

//函数或者变量声明
void CHAO_GPIO_Configuration(void);
void CHAO_EXTI_Configuration(void);
void TIM3_Configuration(void);
void CHAO_NVIC_Configuration(void);
void CHAO_Start(void);
// void CHAO_display(void);
void CHAO_Init(void);
#endif
