#include"share.h"
/****************��λ��ģ���2�ſ�***************/
/********��������********/
u16 AD_value;
u16 AD_value_con;
u32 temp;
u8 save[4],i;

/********��������********/
void read_ad(void);
void conversion_ad(void);
void display_ad(void);
/********��ȡAD********/
void read_ad(void)
{	
	for(i=0;i<4;i++)
	{
		ADC_SoftwareStartConvCmd(ADC1, ENABLE);
		while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));
		AD_value=0;
	    AD_value=ADC_GetConversionValue(ADC1);
		temp+=AD_value;
	}
	AD_value=temp>>2;
	temp=0;	
}

/********ת��AD********/
void conversion_ad(void)
{
	AD_value_con=(AD_value*3300)/4096;
	save[0]=AD_value_con/1000%10;
	save[1]=AD_value_con/100%10;
	save[2]=AD_value_con/10%10;
	save[3]=AD_value_con%10;
}
/********��ʾAD********/
void display_ad(void)
{
	usart1_putchar('A');
	usart1_putchar('D');
	usart1_putchar('_');
	usart1_putchar('V');
	usart1_putchar(' ');
	usart1_putchar('i');
	usart1_putchar('s');
	usart1_putchar(' ');
  
  usart1_putchar(save[0]+0x30);
	usart1_putchar('.');
	usart1_putchar(save[1]+0x30);
	usart1_putchar(save[2]+0x30);
	usart1_putchar(save[3]+0x30);
	usart1_putchar('\r');
	usart1_putchar('\n');
}
int main(void)
{
  RCC_Configuration();
	delay_init(72);
	USART1_Init(9600);
	ADC_GPIO_CONFIG();
	ADC_Configuration();

    while (1)
    {
                          	           
				read_ad();
				conversion_ad();
				display_ad();
				delay_ms(500);
	
		}
}

