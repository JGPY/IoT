#include "share.h"

void TIM4_Configuration(void)
{
		TIM_TimeBaseInitTypeDef   TIM_TimeBaseStructure;
		TIM_OCInitTypeDef  TIM_OCInitStructure;
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);	    //打开TIM4定时器的时钟

		TIM_DeInit(TIM4);		                                    //TIMx寄存器重设为缺省值

		TIM_TimeBaseStructure.TIM_Period = 900;		            	//自动重装载寄存器周期的值 ARR=900
		TIM_TimeBaseStructure.TIM_Prescaler= 0;             		//TIMx 时钟频率除数的预分频值0 不分频
		TIM_TimeBaseStructure.TIM_ClockDivision= 0;     	    	//采样分频
		TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 	//向上计数模式
		TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

		/* Output Compare Active Mode configuration: Channel1 */
		TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 				//选择定时器模式:TIM脉冲宽度调制模式2
		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	//比较输出使能
		TIM_OCInitStructure.TIM_Pulse = 0; 								//设置待装入捕获比较寄存器的脉冲值
		TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		//输出极性:TIM输出比较极性高
	
		TIM_OC3Init(TIM4, &TIM_OCInitStructure); 	 					//根据TIM_OCInitStruct中指定的参数初始化外设TIMx
		TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);  				//使能TIMx在CCR3上的预装载寄存器

		TIM_ARRPreloadConfig(TIM4, ENABLE); 							//使能TIMx在ARR上的预装载寄存器

		/* TIM4 enable counter */
		TIM_Cmd(TIM4, ENABLE);  										//使能TIMx外设				//使能TIMx外设
}

void TIM4_NVIC_Configuration(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;

		NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

		NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;	 //指定抢占式优先级别1
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			 //指定响应优先级别1
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				 //使能TIM2中断
		NVIC_Init(&NVIC_InitStructure);
}

void PWM_LED_Init(void)
{
		LED_GPIO_Init();
		TIM4_Configuration();
}
