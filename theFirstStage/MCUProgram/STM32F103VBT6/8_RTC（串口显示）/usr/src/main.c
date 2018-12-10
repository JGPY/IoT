#include"share.h"

typedef struct 
{
	u8 hour;
	u8 min;
	u8 sec;			
	//公历日月年周
	u16 w_year;
	u8  w_month;
	u8  w_date;
	u8  week;		 
}tm;					 
tm timer;

/********变量定义********/

/********函数声明********/
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
	   
  timecount = RTC_GetCounter(); //获取RTC计数器的值			 

	temp=timecount%(24*60*60);     //得到秒钟数   	   
	timer.hour=temp/3600;     //小时
	timer.min=(temp%3600)/60; //分钟	
	timer.sec=(temp%3600)%60; //秒钟  
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

