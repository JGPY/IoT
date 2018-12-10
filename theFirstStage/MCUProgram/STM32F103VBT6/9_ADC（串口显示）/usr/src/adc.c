/********头文件********/
#include "share.h"

void ADC_GPIO_CONFIG(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO  | 
							RCC_APB2Periph_ADC1 , ENABLE);
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);
    /****配置ADC所在外设的脚为输出****/
   	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;         //I/O口的方向
  	GPIO_Init(GPIOA, &GPIO_InitStructure);                   //初始化外设端口
}

void ADC_Configuration(void)
{
		ADC_InitTypeDef ADC_InitStructure;
  	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
  	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
  	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
  	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
  	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  	ADC_InitStructure.ADC_NbrOfChannel = 1;
  	ADC_Init(ADC1, &ADC_InitStructure);

		ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 1, ADC_SampleTime_239Cycles5);
  	/****Enable ADC1****/
  	ADC_Cmd(ADC1, ENABLE);

  	/****Enable ADC1 reset calibaration register****/   
  	ADC_ResetCalibration(ADC1);

  	/****Check the end of ADC1 reset calibration register****/
  	while(ADC_GetResetCalibrationStatus(ADC1));

  	/****Start ADC1 calibaration****/
  	ADC_StartCalibration(ADC1);

  	/****Check the end of ADC1 calibration****/
  	while(ADC_GetCalibrationStatus(ADC1));
     
  	/****Start ADC1 Software Conversion****/ 
  	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}
