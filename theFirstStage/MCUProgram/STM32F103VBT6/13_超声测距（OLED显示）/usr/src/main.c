#include"share.h"
/*********超声波模块接3号（超声）口*************/

u8 key,n;
float Distance;
void OLED_Show(void);

int main(void)
{
	RCC_Configuration();
	delay_init(72);
	CHAO_Init();     //超声初始化	
	OLED_Init();		 //初始化OLED
  
	OLED_Clear();    //清屏
	OLED_Show();     //屏幕显示
  while(1)
	{
		CHAO_Start();
		n=(int)(Distance*10)/1000%10+0x30;
		OLED_ShowString(60,3,&n);
		n=(int)(Distance*10)/100%10+0x30;
		OLED_ShowString(70,3,&n);
		n=(int)(Distance*10)/10%10+0x30;
		OLED_ShowString(80,3,&n);
		OLED_ShowString(90,3,".");		
		n=(int)(Distance*10)%10+0x30;
		OLED_ShowString(96,3,&n);
		OLED_ShowString(106,3,"cm");
		delay_ms(400);
	
	}
}

/*************************************
*********屏幕显示欢迎.....************
*************************************/
void OLED_Show(void)
{ 	
	OLED_ShowCHinese(22,0,11);//欢
	OLED_ShowCHinese(44,0,12);//迎
	OLED_ShowCHinese(66,0,13);//使
	OLED_ShowCHinese(88,0,14);//用
	 
	OLED_ShowCHinese(22,2,0); //科
	OLED_ShowCHinese(44,2,1); //乐
	OLED_ShowCHinese(66,2,2); //思
	OLED_ShowCHinese(88,2,3); //通
	
	OLED_ShowCHinese(33,4,4); //机
	OLED_ShowCHinese(55,4,5); //器
	OLED_ShowCHinese(77,4,6); //人

	OLED_ShowCHinese(23,6,47);//心形图标
	delay_ms(600);
	OLED_ShowCHinese(40,6,47);//心形图标
	delay_ms(600);
	OLED_ShowCHinese(57,6,47);//心形图标
	delay_ms(600);
	OLED_ShowCHinese(74,6,47);//心形图标
	delay_ms(600);
	OLED_ShowString(92,6,"OK!");//OK!
	delay_ms(600);
	OLED_Clear();
	
	OLED_ShowCHinese(2,0,81);//三角符号
	OLED_ShowCHinese(16,0,65);//距
	OLED_ShowCHinese(35,0,66);//离
	OLED_ShowCHinese(54,0,34);//探
	OLED_ShowCHinese(73,0,35);//测
	
	OLED_ShowCHinese(16,3,65);//距
	OLED_ShowCHinese(35,3,66);//离
	OLED_ShowString(50,3,":");		

}


