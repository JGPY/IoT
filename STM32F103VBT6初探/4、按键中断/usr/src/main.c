#include"share.h"

/*********************************************************
������ģ���4�ţ����������� 
ԭ����ͼ�İ���KEY1��KEY2�ֱ��Ӧ������İ���ѡ��Ͱ���ȷ��
**********************************************************/
u8 flag=0;

int main(void)
{
  RCC_Configuration();
	delay_init(72);
	buzzer_Init();      //��������ʼ��
	EXTI_KEY1_Init();  //�����жϳ�ʼ��

  while(1)
	{
		if(flag==1)
		{
			GPIO_SetBits( GPIOB,  GPIO_Pin_1);
			delay_ms(1);
			GPIO_ResetBits( GPIOB,  GPIO_Pin_1);
			delay_ms(1);
		}  
	}
}


