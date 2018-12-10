#include"share.h"
/*********LED模块接10号（红外）口*************/

u16 led0pwmval = 0,dir=1;

int main(void)
{
	RCC_Configuration();
	delay_init(72);	
	PWM_LED_Init();
  while(1)
	{
		delay_ms(2);	 
		if(dir)
		{
			led0pwmval++;
		}
		else 
		{
			led0pwmval--;
   		}
 		if(led0pwmval>900)
		{
			dir=0;
		}
		if(led0pwmval==0)
		{
			dir=1;
		}	
		TIM_SetCompare3(TIM4,led0pwmval);
	}
}


