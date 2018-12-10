#include"share.h"

u16 Distance_count;
extern float Distance;

void CHAO_GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE); 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					            //PA7��TRIG
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		         //��Ϊ�������ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	         
  GPIO_Init(GPIOA, &GPIO_InitStructure);	                     //��ʼ������GPIO 

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				            //PB0��ECH0
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;		 						//��Ϊ����
  GPIO_Init(GPIOB,&GPIO_InitStructure);		
}

void CHAO_EXTI_Configuration(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;

	//����жϱ�־
	EXTI_ClearITPendingBit(EXTI_Line0);

	//ѡ���жϹܽ�
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);
	
	//ѡ���ж���·0
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	//����Ϊ�ж����󣬷��¼�����   
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; 
	//�����жϴ�����ʽΪ���½��ش���							
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	//�ⲿ�ж�ʹ�� 						
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                          
	EXTI_Init(&EXTI_InitStructure);
}

void TIM3_Configuration(void)
{
	TIM_TimeBaseInitTypeDef   TIM_TimeBaseStructure;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	    //��TIM2��ʱ����ʱ��
  
  TIM_DeInit(TIM3);		                                    //TIMx�Ĵ�������Ϊȱʡֵ
  
  TIM_TimeBaseStructure.TIM_Period = 5000-1;		            	//�Զ���װ�ؼĴ������ڵ�ֵ
  TIM_TimeBaseStructure.TIM_Prescaler= 7200-1;             	//TIMx ʱ��Ƶ�ʳ�����Ԥ��Ƶֵ(Period + 1) * (Prescaler + 1) / 72M = 100ms
  TIM_TimeBaseStructure.TIM_ClockDivision= 0;     	    	//������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 	//���ϼ���ģʽ
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
  
  TIM_ARRPreloadConfig(TIM3, ENABLE);                       	//�����Զ���װ�ؼĴ�����ARR��
  TIM_ITConfig(TIM3,TIM_IT_Update|TIM_IT_Trigger,ENABLE);	    //����TIM2����ж�
}

void CHAO_NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
 // NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);             //ѡ���жϷ���2  
	NVIC_InitStructure.NVIC_IRQChannel =EXTI0_IRQn;			//ʹ�ܳ��������ڵ��ⲿ�ж�ͨ��EXTI0_IRQn 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//��ռ���ȼ�2 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//�����ȼ�2 
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
}

void CHAO_Start(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_7); 		  //��>10US�ĸߵ�ƽ
  delay_us(20);		                      //��ʱ20US
  GPIO_ResetBits(GPIOA,GPIO_Pin_7);
	delay_ms(10);
	Distance=(Distance_count*1*340)/200.0;
}

// void CHAO_display(void)
// {
// 	Distance=(Distance_count*1*340)/200.0;
// }

void CHAO_Init(void)
{
	CHAO_GPIO_Configuration();
	CHAO_EXTI_Configuration();
	TIM3_Configuration();
	CHAO_NVIC_Configuration();
}

void EXTI0_IRQHandler(void)
{
	delay_us(10);			//��ʱ10us	
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		TIM_SetCounter(TIM3,0);
		TIM_Cmd(TIM3, ENABLE);                       			//����ʱ��
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0));	  //�ȴ��͵�ƽ
		TIM_Cmd(TIM3, DISABLE);			                      //��ʱ��2ʧ��
		Distance_count=TIM_GetCounter(TIM3);							//��������ʱ�䳣��
		EXTI_ClearITPendingBit(EXTI_Line0);  							//���EXTI0��·����λ		
	}

}

