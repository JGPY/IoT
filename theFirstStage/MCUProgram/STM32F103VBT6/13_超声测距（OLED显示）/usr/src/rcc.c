#include"share.h"
void RCC_Configuration(void)                                      //需要定义#include "stm32f10x_flash.h"
{
    ErrorStatus HSEStartUpStatus;
    RCC_HSEConfig(RCC_HSE_ON);	                 //使能外部晶振
    HSEStartUpStatus = RCC_WaitForHSEStartUp();	//等待外部晶振稳定
    
    if(HSEStartUpStatus==SUCCESS)                            //如果外部晶振启动成功，则进行下一步操作
    {
        RCC_HCLKConfig(RCC_SYSCLK_Div1);           //设置HCLK（AHB时钟）=SYSCLK
        RCC_PCLK1Config(RCC_HCLK_Div2);             //PCLK1(APB1) = HCLK/2
        RCC_PCLK2Config(RCC_HCLK_Div1);             //PCLK2(APB2) = HCLK

        //FLASH时序控制
        //推荐值：SYSCLK = 0~24MHz   Latency=0
        //                SYSCLK = 24~48MHz  Latency=1
        //                SYSCLK = 48~72MHz  Latency=2
        FLASH_SetLatency(FLASH_Latency_2);
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);        //开启FLASH预取指功能
        
        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);  //PLL设置 SYSCLK/1 * 9 = 8*1*9 = 72MHz
        RCC_PLLCmd(ENABLE);                                                               //启动PLL
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);    //等待PLL稳定
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);                 //系统时钟SYSCLK来自PLL输出
        while(RCC_GetSYSCLKSource()!=0x08);	                           //切换时钟后等待系统时钟稳定
    }    
}
