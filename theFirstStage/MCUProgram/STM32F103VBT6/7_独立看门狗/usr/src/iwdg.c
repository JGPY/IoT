/********ͷ�ļ�********/
#include "share.h"

void IWDG_Configuration(void)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); 	//����֮ǰҪ����ʹ�ܼĴ���д
  	IWDG_SetPrescaler(IWDG_Prescaler_64);           //�ڲ�����ʱ��16��Ƶ,��Ƶ��Ϊ��40K / 64 =  0.625K������һ������Ϊ��1.6ms
  	IWDG_SetReload(0xFFF);							//FFF*1.6ms = 6553.6MS
  	IWDG_ReloadCounter();							//ι���������������һ���ļ��д��0xAAAA�����򣬵�������Ϊ0ʱ�����Ź��������λ
  	IWDG_Enable(); 									//ʹ��
}
