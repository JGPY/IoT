#include"share.h"
/*********************************************************
下位机向上位机发送hello world！
**********************************************************/
int main(void)
{
  RCC_Configuration();
	delay_init(72);
	USART1_Init(9600); //串口初始化 波特率9600
  while(1)
	{
		printf("Hello World!");
		delay_ms(500);
	}
}


