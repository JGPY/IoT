/********头文件********/
#include "share.h"

/********NVIC配置函数********/
void EXTI_NVIC_Configuration(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;
				
		NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;     	   //选择中断通道2
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //抢占式中断优先级设置为0
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;         //响应式中断优先级设置为0
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                                   //使能中断
		NVIC_Init(&NVIC_InitStructure);
}


/********EXTI_GPIO配置函数********/
void EXTI_GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA , ENABLE);
    
    /****配置KEY所在外设的脚为输入****/
  	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_11;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;    //I/O口的方向，输入
  	GPIO_Init(GPIOA, &GPIO_InitStructure);                   //初始化外设PA的11端口
}
/********EXTI配置函数********/
void EXTI_Configuration(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;

	//清空中断标志
	EXTI_ClearITPendingBit(EXTI_Line11);

	//选择中断管脚PA.11
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource11);

	//选择中断线路11
	EXTI_InitStructure.EXTI_Line = EXTI_Line11;
	//设置为中断请求，非事件请求   
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; 
	//设置中断触发方式为下降沿触发							
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	//外部中断使能 						
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                          
	EXTI_Init(&EXTI_InitStructure);
}

void EXTI_KEY1_Init(void)
{
	EXTI_GPIO_Configuration();	
	EXTI_NVIC_Configuration();
	EXTI_Configuration();
}

