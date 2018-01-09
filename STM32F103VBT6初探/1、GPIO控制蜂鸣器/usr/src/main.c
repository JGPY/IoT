#include"share.h"
/*********·äÃùÆ÷Ä£¿é½Ó4ºÅ£¨·äÃùÆ÷£©¿Ú*************/
u16 n;
int main(void)
{
	RCC_Configuration();
	delay_init(72);
	
	buzzer_Init();
  while(1)
	{
		for(n=0;n<300;n++)
		{
			GPIO_SetBits( GPIOB,  GPIO_Pin_1);
			delay_ms(1);
			GPIO_ResetBits( GPIOB,  GPIO_Pin_1);
			delay_ms(1);
		}
		delay_ms(500);
	}
}


