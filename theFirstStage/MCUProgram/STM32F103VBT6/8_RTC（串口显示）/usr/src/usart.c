/****����ͷ�ļ�****/
#include"share.h"

				   
//////////////////////////////////////////////////////////////////
//�������½ӿڴ���,֧�ֱ�׼printf����,������Ҫѡ��use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//����_sys_exit()�Ա���ʹ�ð�����ģʽ    
_sys_exit(int x) 
{ 
	x = x; 
} 
//�ض���fputc���� 
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//ѭ������,ֱ���������   
    USART1->DR = (u8) ch;      
	return ch;
}
#endif 


/****USART1���ú���****/
void USART1_Init(u32 bound)
{

	/*�ṹ������*/
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);/*ʹ��USART1��GPIOʱ��*/
	USART_DeInit(USART1);  //��λ����1
	/*USART1_TX   PA.9*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
	GPIO_Init(GPIOA, &GPIO_InitStructure); //��ʼ��PA9

	/*USART1_TX   PA.10*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
	GPIO_Init(GPIOA, &GPIO_InitStructure);  //��ʼ��PA10

	/*����USART1�ĳ�ʼ��*/

	USART_InitStructure.USART_BaudRate = bound;/*����USART1�Ĳ�����-һ������Ϊ9600*/
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;/*��Ӳ������*/
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	/*����USART1�շ�ģʽ*/

	USART_Init(USART1, &USART_InitStructure); /*��ʼ��USART1*/
//	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);/*ʹ�ܴ���1���ж�*/
	USART_Cmd(USART1, ENABLE);                    /*ʹ��USART1*/
		
}

void usart1_putchar(u8 ch)
{
	USART_SendData(USART1,(u8) ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE)==RESET);
}



