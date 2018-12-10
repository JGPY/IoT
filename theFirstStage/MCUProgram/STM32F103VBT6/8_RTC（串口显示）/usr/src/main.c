#include"share.h"

typedef struct 
{
	u8 hour;
	u8 min;
	u8 sec;			
	//������������
	u16 w_year;
	u8  w_month;
	u8  w_date;
	u8  week;		 
}tm;					 
tm timer;

/********��������********/

/********��������********/
u8 RTC_Get(void);
void display(void);
int main(void)
{
  RCC_Configuration();
	delay_init(72);
	USART1_Init(9600);
	display();
	if(BKP_ReadBackupRegister(BKP_DR1) != 0xA6A5)
	{
		RTC_Configuration();
		BKP_WriteBackupRegister(BKP_DR1, 0xA6A5);    
	}

	while (1)
	{
		RTC_Get();
		display();
		delay_ms(1000);			
		delay_ms(1000);
		delay_ms(1000);
	}
}

u8 RTC_Get(void)
{
	u32 timecount=0; 
	u32 temp=0;	  
	   
  timecount = RTC_GetCounter(); //��ȡRTC��������ֵ			 

	temp=timecount%(24*60*60);     //�õ�������   	   
	timer.hour=temp/3600;     //Сʱ
	timer.min=(temp%3600)/60; //����	
	timer.sec=(temp%3600)%60; //����  
	return 0;
}	 
void display(void)
{
	usart1_putchar(0x30+timer.hour/10);
	usart1_putchar(0x30+timer.hour%10);
	usart1_putchar(':');

	usart1_putchar(0x30+timer.min/10);
	usart1_putchar(0x30+timer.min%10);
	usart1_putchar(':');

	usart1_putchar(0x30+timer.sec/10);
	usart1_putchar(0x30+timer.sec%10);
	usart1_putchar('\r');
	usart1_putchar('\n');
}


#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* Infinite loop */
  while (1)
  {
  }
}
#endif

