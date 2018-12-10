#include"share.h"

u16 Distance_count;
extern float Distance;

void CHAO_GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE); 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;					            //PA7接TRIG
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		         //设为推挽输出模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	         
  GPIO_Init(GPIOA, &GPIO_InitStructure);	                     //初始化外设GPIO 

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				            //PB0接ECH0
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;		 						//设为输入
  GPIO_Init(GPIOB,&GPIO_InitStructure);		
}

void CHAO_EXTI_Configuration(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;

	//清空中断标志
	EXTI_ClearITPendingBit(EXTI_Line0);

	//选择中断管脚
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);
	
	//选择中断线路0
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	//设置为中断请求，非事件请求   
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; 
	//设置中断触发方式为上下降沿触发							
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	//外部中断使能 						
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                          
	EXTI_Init(&EXTI_InitStructure);
}

void TIM3_Configuration(void)
{
	TIM_TimeBaseInitTypeDef   TIM_TimeBaseStructure;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	    //打开TIM2定时器的时钟
  
  TIM_DeInit(TIM3);		                                    //TIMx寄存器重设为缺省值
  
  TIM_TimeBaseStructure.TIM_Period = 5000-1;		            	//自动重装载寄存器周期的值
  TIM_TimeBaseStructure.TIM_Prescaler= 7200-1;             	//TIMx 时钟频率除数的预分频值(Period + 1) * (Prescaler + 1) / 72M = 100ms
  TIM_TimeBaseStructure.TIM_ClockDivision= 0;     	    	//采样分频
  TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 	//向上计数模式
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
  
  TIM_ARRPreloadConfig(TIM3, ENABLE);                       	//允许自动重装载寄存器（ARR）
  TIM_ITConfig(TIM3,TIM_IT_Update|TIM_IT_Trigger,ENABLE);	    //允许TIM2溢出中断
}

void CHAO_NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
 // NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);             //选择中断分组2  
	NVIC_InitStructure.NVIC_IRQChannel =EXTI0_IRQn;			//使能超声波所在的外部中断通道EXTI0_IRQn 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//抢占优先级2 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//子优先级2 
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
}

void CHAO_Start(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_7); 		  //送>10US的高电平
  delay_us(20);		                      //延时20US
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
	delay_us(10);			//延时10us	
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		TIM_SetCounter(TIM3,0);
		TIM_Cmd(TIM3, ENABLE);                       			//开启时钟
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0));	  //等待低电平
		TIM_Cmd(TIM3, DISABLE);			                      //定时器2失能
		Distance_count=TIM_GetCounter(TIM3);							//计算距离的时间常数
		EXTI_ClearITPendingBit(EXTI_Line0);  							//清除EXTI0线路挂起位		
	}

}

