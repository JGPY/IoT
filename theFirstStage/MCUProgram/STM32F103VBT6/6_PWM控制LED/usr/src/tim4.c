#include "share.h"

void TIM4_Configuration(void)
{
		TIM_TimeBaseInitTypeDef   TIM_TimeBaseStructure;
		TIM_OCInitTypeDef  TIM_OCInitStructure;
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);	    //��TIM4��ʱ����ʱ��

		TIM_DeInit(TIM4);		                                    //TIMx�Ĵ�������Ϊȱʡֵ

		TIM_TimeBaseStructure.TIM_Period = 900;		            	//�Զ���װ�ؼĴ������ڵ�ֵ ARR=900
		TIM_TimeBaseStructure.TIM_Prescaler= 0;             		//TIMx ʱ��Ƶ�ʳ�����Ԥ��Ƶֵ0 ����Ƶ
		TIM_TimeBaseStructure.TIM_ClockDivision= 0;     	    	//������Ƶ
		TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 	//���ϼ���ģʽ
		TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

		/* Output Compare Active Mode configuration: Channel1 */
		TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 				//ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	//�Ƚ����ʹ��
		TIM_OCInitStructure.TIM_Pulse = 0; 								//���ô�װ�벶��ȽϼĴ���������ֵ
		TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		//�������:TIM����Ƚϼ��Ը�
	
		TIM_OC3Init(TIM4, &TIM_OCInitStructure); 	 					//����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
		TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);  				//ʹ��TIMx��CCR3�ϵ�Ԥװ�ؼĴ���

		TIM_ARRPreloadConfig(TIM4, ENABLE); 							//ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���

		/* TIM4 enable counter */
		TIM_Cmd(TIM4, ENABLE);  										//ʹ��TIMx����				//ʹ��TIMx����
}

void TIM4_NVIC_Configuration(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;

		NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

		NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;	 //ָ����ռʽ���ȼ���1
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			 //ָ����Ӧ���ȼ���1
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				 //ʹ��TIM2�ж�
		NVIC_Init(&NVIC_InitStructure);
}

void PWM_LED_Init(void)
{
		LED_GPIO_Init();
		TIM4_Configuration();
}
