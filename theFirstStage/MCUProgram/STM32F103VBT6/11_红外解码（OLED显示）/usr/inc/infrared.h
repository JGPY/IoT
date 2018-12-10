#ifndef __INFRARED_H
#define __INFRARED_H	 
/********头文件********/
#include"share.h"

#define RDATA PBin(8)	 //红外数据输入引脚
#define REMOTE_ID 0 
extern u8 RmtCnt;  //按键按下次数
void Remote_Init(void); //红外传感器接收头引脚初始化  
u8 Remote_Scan(void);

#endif
