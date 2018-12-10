/************************哲文嵌入式技术工作室*****************************
文件名称          ：定义EXIT所应用的所有的头文件、函数声明、全局变量
编译环境          ：这部分程序基于MDK4.0编译环境
芯片型号          : STM32F103VET6
程序类型          : 应用类
晶振频率          : 8.000000 MHz
内存模式          : 
外部SRAM大小      : 
数据堆栈大小      : 
***************************************************************************/
#ifndef __EXIT_H
#define __EXIT_H

/********头文件********/
#include "share.h"

//EXIT函数声明
void EXTI_GPIO_Configuration(void);	
void EXTI_NVIC_Configuration(void);
void EXTI_Configuration(void);
void EXTI_KEY1_Init(void);

#endif

/******************* (C) COPYRIGHT 2013 哲文嵌入式技术工作室********************/
