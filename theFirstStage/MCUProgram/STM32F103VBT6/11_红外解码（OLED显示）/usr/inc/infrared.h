#ifndef __INFRARED_H
#define __INFRARED_H	 
/********ͷ�ļ�********/
#include"share.h"

#define RDATA PBin(8)	 //����������������
#define REMOTE_ID 0 
extern u8 RmtCnt;  //�������´���
void Remote_Init(void); //���⴫��������ͷ���ų�ʼ��  
u8 Remote_Scan(void);

#endif
