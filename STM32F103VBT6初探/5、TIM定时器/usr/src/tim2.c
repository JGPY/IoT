#include "share.h"

void TIM2_Configuration(void)
{
		TIM_TimeBaseInitTypeDef   TIM_TimeBaseStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	    //��TIM2��ʱ����ʱ��
  
  	TIM_DeInit(TIM2);		                                    //TIMx�Ĵ�������Ϊȱʡֵ
  
  	TIM_TimeBaseStructure.TIM_Period = 10000-1;		            	//�Զ���װ�ؼĴ���һ�����ڵ�ֵ��5000��
  	TIM_TimeBaseStructure.TIM_Prescaler= 7200-1;          	//TIMx ʱ��Ƶ�ʳ�����Ԥ��Ƶֵ(Period + 1) * (Prescaler + 1) / 72M = 1s
  	TIM_TimeBaseStructure.TIM_ClockDivision= 0;     	    	//������Ƶ
  	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 	//���ϼ���ģʽ
  	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
  
  	TIM_ARRPreloadConfig(TIM2, ENABLE);                       	//�����Զ���װ�ؼĴ�����ARR��
  	TIM_ITConfig(TIM2,TIM_IT_Update|TIM_IT_Trigger,ENABLE);	    //����TIM2����ж�

		TIM_SetCounter(TIM2,0);
		TIM_Cmd(TIM2, ENABLE); 
}

void TIM2_NVIC_Configuration(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;

		NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
  	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

		NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;	 //ָ����ռʽ���ȼ���1
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			 //ָ����Ӧ���ȼ���1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				 //ʹ��TIM2�ж�
  	NVIC_Init(&NVIC_InitStructure);
}

void TIM2_Init(void)
{
	TIM2_NVIC_Configuration();
	TIM2_Configuration();	
}
