#include"share.h"
/*********************************************************
��λ������λ������hello world��
**********************************************************/
int main(void)
{
  RCC_Configuration();
	delay_init(72);
	USART1_Init(9600); //���ڳ�ʼ�� ������9600
  while(1)
	{
		printf("Hello World!");
		delay_ms(500);
	}
}


