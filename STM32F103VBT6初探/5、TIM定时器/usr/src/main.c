#include"share.h"
/*********************************************************
下位机间隔1s向上位机发送hello world！
**********************************************************/

u8 flag=0;

int main(void)
{
  RCC_Configuration();
	delay_init(72);
	USART1_Init(9600);  //串口初始化 波特率9600
	TIM2_Init();       //定时器2初始化
  while(1)
	{
		if(flag==1)
		{
			printf("Hello World!");
			flag=0;
		}
	}
}


