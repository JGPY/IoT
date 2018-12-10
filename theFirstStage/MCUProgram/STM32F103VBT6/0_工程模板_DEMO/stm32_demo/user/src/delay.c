/***********************************************************************
文件名称          ：使用SysTick的普通计数模式对延迟进行管理
编译环境          ：这部分程序基于MDK4.0编译环境
芯片型号          : STM32F103VET6
程序类型          : 应用类
晶振频率          : 8.000000 MHz
内存模式          : 
外部SRAM大小      : 
数据堆栈大小      : 
***************************************************************************/
/********头文件********/
#include"share.h"
/*******全局变量声明*******/	 
static u8  fac_us=0;    //us延时倍乘数
static u16 fac_ms=0;    //ms延时倍乘数

/************************初始化延迟函数****************************
//SYSTICK的时钟固定为HCLK时钟的1/8
//SYSCLK:系统时钟
//此函数 即为系统时钟初始化，未开中断
*******************************************************************/

void delay_init(u8 SYSCLK)
{
	SysTick->CTRL&=0xfffffffb;   //bit2清空,选择外部时钟 HCLK/8
	fac_us=SYSCLK/8;		    
	fac_ms=(u16)fac_us*1000;
}								    
/**************************延时nms*****************************
//注意nms的范围
//SysTick->LOAD为24位寄存器,所以,最大延时为:
//nms<=0xffffff*8*1000/SYSCLK
//SYSCLK单位为Hz,nms单位为ms
//对72M条件下,nms<=1864 
***************************************************************/

void delay_ms(u16 nms)
{	 		  	  
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;//时间加载(SysTick->LOAD为24bit)
	SysTick->VAL =0x00;           //清空计数器
	SysTick->CTRL=0x01 ;          //开始倒数  
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//等待时间到达   
	SysTick->CTRL=0x00;               //关闭计数器
	SysTick->VAL =0X00;               //清空计数器	  	    
}   
/****************************延时nus*********************************/	
	    								   
void delay_us(u32 nus)
{		
	u32 temp;	    	 
	SysTick->LOAD=nus*fac_us; //时间加载	  		 
	SysTick->VAL=0x00;        //清空计数器
	SysTick->CTRL=0x01 ;      //开始倒数 	 
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//等待时间到达   
	SysTick->CTRL=0x00;               //关闭计数器
	SysTick->VAL =0X00;               //清空计数器	 
}

/*******************************软件延时函数*****************************/

void Delay(u32 nCount)		//u32在stm32f10x.h和stdint.h中找到相关定义
{
  for(; nCount != 0; nCount--);
}

