#include"share.h"
/*********************************************************
蜂鸣器模块接4号（蜂鸣器）口 
原的理图的按键KEY1和KEY2分别对应开发板的按键选择和按键确认
**********************************************************/
u16 n;

int main(void)
{
	RCC_Configuration();
	delay_init(72);
	KEY_Init();     //按键初始化
	buzzer_Init();  //蜂鸣器初始化
  while(1)
	{
		if(KEY1==0)
		{
			for(n=0;n<3;n++)
			{
				GPIO_SetBits( GPIOB,  GPIO_Pin_1);
				delay_ms(1);
				GPIO_ResetBits( GPIOB,  GPIO_Pin_1);
				delay_ms(1);
			}
		}	
	}
}


