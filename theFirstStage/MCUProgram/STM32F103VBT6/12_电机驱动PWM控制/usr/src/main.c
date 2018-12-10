#include"share.h"

/*********车轮电机分别接1号和2号口*************/

int main(void)
{
	RCC_Configuration();
	delay_init(72);
	TB6612_Init();   //电机初始化
  while(1)
	{
      forward(600);  
			delay_ms(500);
			forward(900);
			delay_ms(500);
			forward(600);
			delay_ms(500);
			stop();
		  delay_ms(1000);
	}
}


