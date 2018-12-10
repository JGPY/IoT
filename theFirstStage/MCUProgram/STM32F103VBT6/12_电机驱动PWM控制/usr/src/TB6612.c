#include"share.h"

void GPIO_CONFIG(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
													RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);  //ʧ��JTAG/SWD
	 /****�����ü��ٵ����������Ľ�Ϊ���****/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;//STBY
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //I/O�ڵķ���-����ʽ���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //I/O�ڵ��������ٶ�
	GPIO_Init(GPIOB, &GPIO_InitStructure); 
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2| GPIO_Pin_3| GPIO_Pin_4| GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //I/O�ڵķ���-����ʽ���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //I/O�ڵ��������ٶ�
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	
	/****����PWM��������Ľ�Ϊ���****/
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;         //I/O�ڵķ���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;        //I/O�ڵ��������ٶ�
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
}

void TIM2_Configuration(void)
{
  TIM_TimeBaseInitTypeDef   TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	    //��TIM2��ʱ����ʱ��

	TIM_DeInit(TIM2);		                                    //TIMx�Ĵ�������Ϊȱʡֵ

	TIM_TimeBaseStructure.TIM_Period =1000;		            	//�Զ���װ�ؼĴ������ڵ�ֵ ARR=900
	TIM_TimeBaseStructure.TIM_Prescaler= 0;             		//TIMx ʱ��Ƶ�ʳ�����Ԥ��Ƶֵ0 ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision= 0;     	    	//������Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 	//���ϼ���ģʽ
//	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	/* Output Compare Active Mode configuration: Channel1 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 				//ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; 								//���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		//�������:TIM����Ƚϼ��Ը�

		 					
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);  				//ʹ��TIMx��CCR3�ϵ�Ԥװ�ؼĴ���
	TIM_OC1Init(TIM2, &TIM_OCInitStructure); //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
		 					
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);  				//ʹ��TIMx��CCR3�ϵ�Ԥװ�ؼĴ���
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);   //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_ARRPreloadConfig(TIM2, ENABLE); 							//ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	
	/* TIM3 enable counter */
	TIM_Cmd(TIM2, ENABLE);  										//ʹ��TIMx����				//ʹ��TIMx����
}

void TB6612_Init(void)
{
	GPIO_CONFIG();
	TIM2_Configuration();
	T_STBY=1;//ʹ��
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
	T_AIN2=1;//��
	T_AIN1=0;

	T_BIN2=0;//��
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
