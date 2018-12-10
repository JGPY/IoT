#include"share.h"

/****时钟配置***/
void RCC_Configuration(void)                                      //需要定义#include "stm32f10x_flash.h"
{
    ErrorStatus HSEStartUpStatus;
	RCC_DeInit();              /* RCC system reset(for debug purpose) RCC寄存器恢复初始化值*/
    RCC_HSEConfig(RCC_HSE_ON);	   /* Enable HSE 使能外部高速晶振*/             
    HSEStartUpStatus = RCC_WaitForHSEStartUp();	/* Wait till HSE is ready 等待外部高速晶振使能完成*/ 
     

    if(HSEStartUpStatus==SUCCESS)                            //如果外部晶振启动成功，则进行下一步操作
    {

	    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);  //PLL设置 SYSCLK/1 * 9 = 8*1*9 = 72MHz   
        /* APB1负责DA，USB，SPI，I2C，CAN，串口2，3，4，5，普通TIM 
	      APB2负责AD，I/O，高级TIM，串口1 */
        RCC_HCLKConfig(RCC_SYSCLK_Div1);           //设置HCLK（AHB时钟）=SYSCLK	/1=72MHz
        RCC_PCLK1Config(RCC_HCLK_Div2);             //PCLK1(APB1) = HCLK/2=36MHz
        RCC_PCLK2Config(RCC_HCLK_Div1);             //PCLK2(APB2) = HCLK=72MHz
		 
		/*FLASH时序延迟几个周期，等待总线同步操作。   
		推荐按照单片机系统运行频率， SYSCLK =0—24MHz时，取Latency=0；   
		        					 SYSCLK =24—48MHz时，取Latency=1；   
		            				 SYSCLK =48~72MHz时，取Latency=2*/   
		/*选择FLASH预取指缓存的模式*/   
        FLASH_SetLatency(FLASH_Latency_2);//FLASH_Latency_1 1延时周期  
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);       //开启FLASH预取指缓存功能
        
      	   
        RCC_PLLCmd(ENABLE);                                                               //启动PLL
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);        //等待PLL稳定
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);                 //系统时钟SYSCLK来自PLL输出
        while(RCC_GetSYSCLKSource()!=0x08);	                       //切换时钟后等待系统时钟稳定


		/*开始使能程序中需要使用的外设时钟*/ 
    }    
}
