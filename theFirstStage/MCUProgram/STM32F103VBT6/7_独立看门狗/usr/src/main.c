#include"share.h"
/*********************************************************
��λ����ʱ����λ���������ݣ�
δ��ʱ����ܡ�ι���ˡ� 
��ʱ����ܡ���û��ι���� 
**********************************************************/
int main(void)
{
  RCC_Configuration();
	delay_init(72);
	USART1_Init(9600);
	IWDG_Configuration();
	printf("��û��ι��\r\n");
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
		IWDG_ReloadCounter();//ι���������������һ���ļ��д��0xAAAA�����򣬵�������Ϊ0ʱ�����Ź��������λ
		printf("ι����\r\n");	
    }
}

	




