/********头文件********/
#include "share.h"

void IWDG_Configuration(void)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); 	//访问之前要首先使能寄存器写
  	IWDG_SetPrescaler(IWDG_Prescaler_64);           //内部低速时钟16分频,即频率为：40K / 64 =  0.625K，所以一个周期为：1.6ms
  	IWDG_SetReload(0xFFF);							//FFF*1.6ms = 6553.6MS
  	IWDG_ReloadCounter();							//喂狗程序。软件必须以一定的间隔写入0xAAAA，否则，当计数器为0时，看门狗会产生复位
  	IWDG_Enable(); 									//使能
}
