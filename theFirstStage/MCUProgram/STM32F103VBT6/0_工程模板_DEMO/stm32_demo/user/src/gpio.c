/*************************************************************************
�ļ�����          ������GPIO
���뻷��          ���ⲿ�ֳ������MDK4.0���뻷��
оƬ�ͺ�          : STM32F103VBT6
��������          : Ӧ����
����Ƶ��          : 8.000000 MHz
�ڴ�ģʽ          : 
�ⲿSRAM��С      : 
���ݶ�ջ��С      : 
***************************************************************************/
/********����ͷ�ļ�********/
#include"share.h"
void GPIO_CONFIG(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(  RCC_APB2Periph_GPIOD 
                            , ENABLE);
    
    /****������LED��������Ľ�Ϊ���****/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4| GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //I/O�ڵķ���-����ʽ���
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //I/O�ڵ��������ٶ�
    GPIO_Init(GPIOD, &GPIO_InitStructure);            //��ʼ������PD��4��5��6��7�˿�
    /****�����ö���������������Ľ�Ϊ����****/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0| GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  //I/O�ڵķ���-��������
    GPIO_Init(GPIOD, &GPIO_InitStructure);            //��ʼ������PD��0��1��2��3�˿�

}
