#include "share.h"

void TIM2_Configuration(void)
{
		TIM_TimeBaseInitTypeDef   TIM_TimeBaseStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	    //打开TIM2定时器的时钟
  
  	TIM_DeInit(TIM2);		                                    //TIMx寄存器重设为缺省值
  
  	TIM_TimeBaseStructure.TIM_Period = 10000-1;		            	//自动重装载寄存器一个周期的值计5000次
  	TIM_TimeBaseStructure.TIM_Prescaler= 7200-1;          	//TIMx 时钟频率除数的预分频值(Period + 1) * (Prescaler + 1) / 72M = 1s
  	TIM_TimeBaseStructure.TIM_ClockDivision= 0;     	    	//采样分频
  	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 	//向上计数模式
  	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
  
  	TIM_ARRPreloadConfig(TIM2, ENABLE);                       	//允许自动重装载寄存器（ARR）
  	TIM_ITConfig(TIM2,TIM_IT_Update|TIM_IT_Trigger,ENABLE);	    //允许TIM2溢出中断

		TIM_SetCounter(TIM2,0);
		TIM_Cmd(TIM2, ENABLE); 
}

void TIM2_NVIC_Configuration(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;

		NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
  	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

		NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;	 //指定抢占式优先级别1
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			 //指定响应优先级别1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				 //使能TIM2中断
  	NVIC_Init(&NVIC_InitStructure);
}

void TIM2_Init(void)
{
	TIM2_NVIC_Configuration();
	TIM2_Configuration();	
}
