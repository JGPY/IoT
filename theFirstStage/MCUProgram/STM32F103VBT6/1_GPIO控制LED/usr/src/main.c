#include"share.h"
/*********LEDģ���9�ţ���������*************/
int main(void)
{
	RCC_Configuration();
	delay_init(72);
	LED_Init();   //LED��ʼ��
  while(1)
	{

		GPIO_SetBits( GPIOB,  GPIO_Pin_4);
		delay_ms(800);
		GPIO_ResetBits( GPIOB,  GPIO_Pin_4);
		delay_ms(800);
	}
}


