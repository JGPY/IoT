#include"share.h"
/*********************************************************
��λ�����1s����λ������hello world��
**********************************************************/

u8 flag=0;

int main(void)
{
  RCC_Configuration();
	delay_init(72);
	USART1_Init(9600);  //���ڳ�ʼ�� ������9600
	TIM2_Init();       //��ʱ��2��ʼ��
  while(1)
	{
		if(flag==1)
		{
			printf("Hello World!");
			flag=0;
		}
	}
}


