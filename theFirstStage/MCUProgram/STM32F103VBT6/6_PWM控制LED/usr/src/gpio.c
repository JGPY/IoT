
/********ͷ�ļ�********/
#include"share.h"

void LED_GPIO_Init(void)
{

    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(  RCC_APB2Periph_GPIOB |RCC_APB2Periph_AFIO , ENABLE);
 
    /****����LED��������Ľ�Ϊ���****/
   	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;         //I/O�ڵķ���
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;        //I/O�ڵ��������ٶ�
  	GPIO_Init(GPIOB, &GPIO_InitStructure);                   //��ʼ������˿�
}

