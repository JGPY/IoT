#include"share.h"
void RCC_Configuration(void)                                      //��Ҫ����#include "stm32f10x_flash.h"
{
    ErrorStatus HSEStartUpStatus;
    RCC_HSEConfig(RCC_HSE_ON);	                 //ʹ���ⲿ����
    HSEStartUpStatus = RCC_WaitForHSEStartUp();	//�ȴ��ⲿ�����ȶ�
    
    if(HSEStartUpStatus==SUCCESS)                            //����ⲿ���������ɹ����������һ������
    {
        RCC_HCLKConfig(RCC_SYSCLK_Div1);           //����HCLK��AHBʱ�ӣ�=SYSCLK
        RCC_PCLK1Config(RCC_HCLK_Div2);             //PCLK1(APB1) = HCLK/2
        RCC_PCLK2Config(RCC_HCLK_Div1);             //PCLK2(APB2) = HCLK

        //FLASHʱ�����
        //�Ƽ�ֵ��SYSCLK = 0~24MHz   Latency=0
        //                SYSCLK = 24~48MHz  Latency=1
        //                SYSCLK = 48~72MHz  Latency=2
        FLASH_SetLatency(FLASH_Latency_2);
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);        //����FLASHԤȡָ����
        
        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);  //PLL���� SYSCLK/1 * 9 = 8*1*9 = 72MHz
        RCC_PLLCmd(ENABLE);                                                               //����PLL
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);    //�ȴ�PLL�ȶ�
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);                 //ϵͳʱ��SYSCLK����PLL���
        while(RCC_GetSYSCLKSource()!=0x08);	                           //�л�ʱ�Ӻ�ȴ�ϵͳʱ���ȶ�
    }    
}
