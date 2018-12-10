#include"share.h"
/*********LED模块接9号（声音）口*************/
int main(void)
{
	RCC_Configuration();
	delay_init(72);
	LED_Init();   //LED初始化
  while(1)
	{

		GPIO_SetBits( GPIOB,  GPIO_Pin_4);
		delay_ms(800);
		GPIO_ResetBits( GPIOB,  GPIO_Pin_4);
		delay_ms(800);
	}
}


