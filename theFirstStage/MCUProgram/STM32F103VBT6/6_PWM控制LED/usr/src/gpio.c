
/********头文件********/
#include"share.h"

void LED_GPIO_Init(void)
{

    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(  RCC_APB2Periph_GPIOB |RCC_APB2Periph_AFIO , ENABLE);
 
    /****配置LED所在外设的脚为输出****/
   	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;         //I/O口的方向
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;        //I/O口的最高输出速度
  	GPIO_Init(GPIOB, &GPIO_InitStructure);                   //初始化外设端口
}

