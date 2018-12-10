/****公共头文件****/
#include"share.h"

				   
//////////////////////////////////////////////////////////////////
//加入以下接口代码,支持标准printf函数,而不需要选择use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
_sys_exit(int x) 
{ 
	x = x; 
} 
//重定义fputc函数 
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//循环发送,直到发送完毕   
    USART1->DR = (u8) ch;      
	return ch;
}
#endif 


/****USART1配置函数****/
void USART1_Init(u32 bound)
{

	/*结构体声明*/
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);/*使能USART1的GPIO时钟*/
	USART_DeInit(USART1);  //复位串口1
	/*USART1_TX   PA.9*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
	GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化PA9

	/*USART1_TX   PA.10*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);  //初始化PA10

	/*配置USART1的初始化*/

	USART_InitStructure.USART_BaudRate = bound;/*配置USART1的波特率-一般设置为9600*/
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;/*无硬件流控*/
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	/*配置USART1收发模式*/

	USART_Init(USART1, &USART_InitStructure); /*初始化USART1*/
//	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);/*使能串口1的中断*/
	USART_Cmd(USART1, ENABLE);                    /*使能USART1*/
		
}

void usart1_putchar(u8 ch)
{
	USART_SendData(USART1,(u8) ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE)==RESET);
}



