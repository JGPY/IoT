#include"share.h"
/*********************************************************
������ģ���4�ţ����������� 
ԭ����ͼ�İ���KEY1��KEY2�ֱ��Ӧ������İ���ѡ��Ͱ���ȷ��
**********************************************************/
u16 n;

int main(void)
{
	RCC_Configuration();
	delay_init(72);
	KEY_Init();     //������ʼ��
	buzzer_Init();  //��������ʼ��
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


