#include"share.h"

/****ʱ������***/
void RCC_Configuration(void)                                      //��Ҫ����#include "stm32f10x_flash.h"
{
    ErrorStatus HSEStartUpStatus;
	RCC_DeInit();              /* RCC system reset(for debug purpose) RCC�Ĵ����ָ���ʼ��ֵ*/
    RCC_HSEConfig(RCC_HSE_ON);	   /* Enable HSE ʹ���ⲿ���پ���*/             
    HSEStartUpStatus = RCC_WaitForHSEStartUp();	/* Wait till HSE is ready �ȴ��ⲿ���پ���ʹ�����*/ 
     

    if(HSEStartUpStatus==SUCCESS)                            //����ⲿ���������ɹ����������һ������
    {

	    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);  //PLL���� SYSCLK/1 * 9 = 8*1*9 = 72MHz   
        /* APB1����DA��USB��SPI��I2C��CAN������2��3��4��5����ͨTIM 
	      APB2����AD��I/O���߼�TIM������1 */
        RCC_HCLKConfig(RCC_SYSCLK_Div1);           //����HCLK��AHBʱ�ӣ�=SYSCLK	/1=72MHz
        RCC_PCLK1Config(RCC_HCLK_Div2);             //PCLK1(APB1) = HCLK/2=36MHz
        RCC_PCLK2Config(RCC_HCLK_Div1);             //PCLK2(APB2) = HCLK=72MHz
		 
		/*FLASHʱ���ӳټ������ڣ��ȴ�����ͬ��������   
		�Ƽ����յ�Ƭ��ϵͳ����Ƶ�ʣ� SYSCLK =0��24MHzʱ��ȡLatency=0��   
		        					 SYSCLK =24��48MHzʱ��ȡLatency=1��   
		            				 SYSCLK =48~72MHzʱ��ȡLatency=2*/   
		/*ѡ��FLASHԤȡָ�����ģʽ*/   
        FLASH_SetLatency(FLASH_Latency_2);//FLASH_Latency_1 1��ʱ����  
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);       //����FLASHԤȡָ���湦��
        
      	   
        RCC_PLLCmd(ENABLE);                                                               //����PLL
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);        //�ȴ�PLL�ȶ�
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);                 //ϵͳʱ��SYSCLK����PLL���
        while(RCC_GetSYSCLKSource()!=0x08);	                       //�л�ʱ�Ӻ�ȴ�ϵͳʱ���ȶ�


		/*��ʼʹ�ܳ�������Ҫʹ�õ�����ʱ��*/ 
    }    
}
