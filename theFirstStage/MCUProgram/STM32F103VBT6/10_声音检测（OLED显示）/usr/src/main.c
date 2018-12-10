#include"share.h"
/*********声音模块接9号口*************/

void OLED_Show(void);

int main(void)
{
	RCC_Configuration();
	delay_init(72);
	
	OLED_Init();		 //初始化OLED
  sound_Init();    //声音接口初始化
	OLED_Clear();    //清屏
	OLED_Show();     //屏幕显示
  while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)==0)
		{	
      OLED_ShowCHinese(70,3,82);//有
			delay_ms(300);
		}	
		else
		{
			OLED_ShowCHinese(70,3,83);//无	
		}
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
		OLED_ShowCHinese(16,0,0);//科
		OLED_ShowCHinese(35,0,1);//乐
		OLED_ShowCHinese(54,0,2);//思
		OLED_ShowCHinese(73,0,3);//通

		
		OLED_ShowCHinese(16,3,84);//声
		OLED_ShowCHinese(35,3,85);//音
		OLED_ShowString(55,3,":");
		
		

}


