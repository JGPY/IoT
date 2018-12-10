/********ͷ�ļ�********/
#include "share.h"

/********NVIC���ú���********/
void EXTI_NVIC_Configuration(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;
				
		NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;     	   //ѡ���ж�ͨ��2
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռʽ�ж����ȼ�����Ϊ0
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;         //��Ӧʽ�ж����ȼ�����Ϊ0
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                                   //ʹ���ж�
		NVIC_Init(&NVIC_InitStructure);
}


/********EXTI_GPIO���ú���********/
void EXTI_GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA , ENABLE);
    
    /****����KEY��������Ľ�Ϊ����****/
  	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_11;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;    //I/O�ڵķ�������
  	GPIO_Init(GPIOA, &GPIO_InitStructure);                   //��ʼ������PA��11�˿�
}
/********EXTI���ú���********/
void EXTI_Configuration(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;

	//����жϱ�־
	EXTI_ClearITPendingBit(EXTI_Line11);

	//ѡ���жϹܽ�PA.11
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource11);

	//ѡ���ж���·11
	EXTI_InitStructure.EXTI_Line = EXTI_Line11;
	//����Ϊ�ж����󣬷��¼�����   
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; 
	//�����жϴ�����ʽΪ�½��ش���							
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	//�ⲿ�ж�ʹ�� 						
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                          
	EXTI_Init(&EXTI_InitStructure);
}

void EXTI_KEY1_Init(void)
{
	EXTI_GPIO_Configuration();	
	EXTI_NVIC_Configuration();
	EXTI_Configuration();
}

