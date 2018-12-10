#include"share.h"

void GPIO_CONFIG(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
													RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);  //失能JTAG/SWD
	 /****如配置减速电机所在外设的脚为输出****/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;//STBY
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //I/O口的方向-推挽式输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //I/O口的最高输出速度
	GPIO_Init(GPIOB, &GPIO_InitStructure); 
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2| GPIO_Pin_3| GPIO_Pin_4| GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //I/O口的方向-推挽式输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //I/O口的最高输出速度
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	
	/****配置PWM所在外设的脚为输出****/
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;         //I/O口的方向
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;        //I/O口的最高输出速度
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
}

void TIM2_Configuration(void)
{
  TIM_TimeBaseInitTypeDef   TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	    //打开TIM2定时器的时钟

	TIM_DeInit(TIM2);		                                    //TIMx寄存器重设为缺省值

	TIM_TimeBaseStructure.TIM_Period =1000;		            	//自动重装载寄存器周期的值 ARR=900
	TIM_TimeBaseStructure.TIM_Prescaler= 0;             		//TIMx 时钟频率除数的预分频值0 不分频
	TIM_TimeBaseStructure.TIM_ClockDivision= 0;     	    	//采样分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 	//向上计数模式
//	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	/* Output Compare Active Mode configuration: Channel1 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 				//选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	//比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; 								//设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		//输出极性:TIM输出比较极性高

		 					
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);  				//使能TIMx在CCR3上的预装载寄存器
	TIM_OC1Init(TIM2, &TIM_OCInitStructure); //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
		 					
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);  				//使能TIMx在CCR3上的预装载寄存器
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);   //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_ARRPreloadConfig(TIM2, ENABLE); 							//使能TIMx在ARR上的预装载寄存器
	
	/* TIM3 enable counter */
	TIM_Cmd(TIM2, ENABLE);  										//使能TIMx外设				//使能TIMx外设
}

void TB6612_Init(void)
{
	GPIO_CONFIG();
	TIM2_Configuration();
	T_STBY=1;//使能
}

void forward(u16 n)
{
	T_AIN2=0;
	T_AIN1=1;

	T_BIN2=1;
	T_BIN1=0;

	TIM_SetCompare1(TIM2,n+400);
	TIM_SetCompare2(TIM2,n+400);
}
void backward(u16 n)
{
	T_AIN2=1;//左
	T_AIN1=0;

	T_BIN2=0;//右
	T_BIN1=1;

	TIM_SetCompare1(TIM2,n+400);
	TIM_SetCompare2(TIM2,n+400);
}
void left(u16 n)
{
	T_AIN2=0;
	T_AIN1=1;

	T_BIN2=0;
	T_BIN1=1;

	TIM_SetCompare1(TIM2,n+400);
	TIM_SetCompare2(TIM2,n+400);
}
void right(u16 n)
{

	T_AIN2=1;
	T_AIN1=0;

	T_BIN2=1;
	T_BIN1=0;

	TIM_SetCompare1(TIM2,n+400);
	TIM_SetCompare2(TIM2,n+400);
}
void stop(void)
{
	T_AIN2=0;
	T_AIN1=0;

	T_BIN2=0;
	T_BIN1=0;	
}
