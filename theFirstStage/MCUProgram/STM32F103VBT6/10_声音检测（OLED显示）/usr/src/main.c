#include"share.h"
/*********����ģ���9�ſ�*************/

void OLED_Show(void);

int main(void)
{
	RCC_Configuration();
	delay_init(72);
	
	OLED_Init();		 //��ʼ��OLED
  sound_Init();    //�����ӿڳ�ʼ��
	OLED_Clear();    //����
	OLED_Show();     //��Ļ��ʾ
  while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)==0)
		{	
      OLED_ShowCHinese(70,3,82);//��
			delay_ms(300);
		}	
		else
		{
			OLED_ShowCHinese(70,3,83);//��	
		}
	}
}

/*************************************
*********��Ļ��ʾ��ӭ.....************
*************************************/
void OLED_Show(void)
{ 	
	OLED_ShowCHinese(22,0,11);//��
	OLED_ShowCHinese(44,0,12);//ӭ
	OLED_ShowCHinese(66,0,13);//ʹ
	OLED_ShowCHinese(88,0,14);//��
	 
	OLED_ShowCHinese(22,2,0); //��
	OLED_ShowCHinese(44,2,1); //��
	OLED_ShowCHinese(66,2,2); //˼
	OLED_ShowCHinese(88,2,3); //ͨ
	
	OLED_ShowCHinese(33,4,4); //��
	OLED_ShowCHinese(55,4,5); //��
	OLED_ShowCHinese(77,4,6); //��

	OLED_ShowCHinese(23,6,47);//����ͼ��
	delay_ms(600);
	OLED_ShowCHinese(40,6,47);//����ͼ��
	delay_ms(600);
	OLED_ShowCHinese(57,6,47);//����ͼ��
	delay_ms(600);
	OLED_ShowCHinese(74,6,47);//����ͼ��
	delay_ms(600);
	OLED_ShowString(92,6,"OK!");//OK!
	delay_ms(600);
	OLED_Clear();
	
		OLED_ShowCHinese(2,0,81);//���Ƿ���
		OLED_ShowCHinese(16,0,0);//��
		OLED_ShowCHinese(35,0,1);//��
		OLED_ShowCHinese(54,0,2);//˼
		OLED_ShowCHinese(73,0,3);//ͨ

		
		OLED_ShowCHinese(16,3,84);//��
		OLED_ShowCHinese(35,3,85);//��
		OLED_ShowString(55,3,":");
		
		

}


