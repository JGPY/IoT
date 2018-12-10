/*************************************************************************
文件名称          ：配置GPIO
编译环境          ：这部分程序基于MDK4.0编译环境
芯片型号          : STM32F103VBT6
程序类型          : 应用类
晶振频率          : 8.000000 MHz
内存模式          : 
外部SRAM大小      : 
数据堆栈大小      : 
***************************************************************************/
/********公共头文件********/
#include"share.h"
void GPIO_CONFIG(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(  RCC_APB2Periph_GPIOD 
                            , ENABLE);
    
    /****如配置LED所在外设的脚为输出****/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4| GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //I/O口的方向-推挽式输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //I/O口的最高输出速度
    GPIO_Init(GPIOD, &GPIO_InitStructure);            //初始化外设PD的4、5、6、7端口
    /****如配置独立按键所在外设的脚为输入****/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0| GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  //I/O口的方向-浮空输入
    GPIO_Init(GPIOD, &GPIO_InitStructure);            //初始化外设PD的0、1、2、3端口

}
