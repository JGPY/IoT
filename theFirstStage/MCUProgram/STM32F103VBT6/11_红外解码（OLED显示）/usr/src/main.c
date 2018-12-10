#include"share.h"
/*********�������ģ���10�ţ����⣩��*************/

u8 key=0,n;

void OLED_Show(void);

int main(void)
{
	RCC_Configuration();
	delay_init(72);
	
	Remote_Init();   //�����ʼ��
	OLED_Init();		 //��ʼ��OLED
  
	OLED_Clear();    //����
	OLED_Show();     //��Ļ��ʾ
  while(1)
	{
		key=Remote_Scan();
		n=key/100%10+0x30;
		OLED_ShowString(50,3,&n);
		n=key/10%10+0x30;
		OLED_ShowString(60,3,&n);
		n=key%10+0x30;
		OLED_ShowString(70,3,&n);
		delay_ms(400);
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
	OLED_ShowCHinese(16,0,36);//��
	OLED_ShowCHinese(35,0,37);//��

	
	OLED_ShowString(20,3,"ID:");			

}


