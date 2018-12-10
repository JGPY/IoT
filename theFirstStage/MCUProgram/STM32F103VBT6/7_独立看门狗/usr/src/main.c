#include"share.h"
/*********************************************************
下位机延时向上位机发送数据，
未超时则接受“喂狗了“ 
超时则接受“还没有喂狗“ 
**********************************************************/
int main(void)
{
  RCC_Configuration();
	delay_init(72);
	USART1_Init(9600);
	IWDG_Configuration();
	printf("还没有喂狗\r\n");
  while (1)
  {		
		delay_ms(1000);
		delay_ms(1000);
// 		delay_ms(1000);
// 		delay_ms(1000);
// 		delay_ms(1000);
// 		delay_ms(1000);
// 		delay_ms(1000);
// 		delay_ms(1000);
		IWDG_ReloadCounter();//喂狗程序。软件必须以一定的间隔写入0xAAAA，否则，当计数器为0时，看门狗会产生复位
		printf("喂狗了\r\n");	
    }
}

	




