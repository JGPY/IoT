#include"share.h"

/*********���ֵ���ֱ��1�ź�2�ſ�*************/

int main(void)
{
	RCC_Configuration();
	delay_init(72);
	TB6612_Init();   //�����ʼ��
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


