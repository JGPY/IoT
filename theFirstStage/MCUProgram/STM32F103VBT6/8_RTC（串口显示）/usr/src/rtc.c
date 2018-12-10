/********Í·ÎÄ¼þ********/
#include "share.h"

void RTC_Configuration(void)
{
		/* Enable PWR and BKP clocks */
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

		/* Allow access to BKP Domain */
		PWR_BackupAccessCmd(ENABLE);

		/* Reset Backup Domain */
		BKP_DeInit();

		/* Enable LSE */
		RCC_LSEConfig(RCC_LSE_ON);
		/* Wait till LSE is ready */
		while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)
		{
		}

		/* Select LSE as RTC Clock Source */
		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);  

		/* Enable RTC Clock */
		RCC_RTCCLKCmd(ENABLE);

		/* Wait for RTC registers synchronization */
		RTC_WaitForSynchro();

		/* Wait until last write operation on RTC registers has finished */
		RTC_WaitForLastTask();

		/* Enable the RTC Second */  
		RTC_ITConfig(RTC_IT_SEC, ENABLE);

		/* Wait until last write operation on RTC registers has finished */
		RTC_WaitForLastTask();

		/* Set RTC prescaler: set RTC period to 1sec */
		RTC_SetPrescaler(32767); /* RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1) */

		/* Wait until last write operation on RTC registers has finished */
		RTC_WaitForLastTask();

		RTC_SetCounter(20*3600+50*60+58);

		RTC_WaitForLastTask();
}
