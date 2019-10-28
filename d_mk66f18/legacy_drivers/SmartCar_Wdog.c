/******************************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,���������ܳ����¾��ֲ�
 * All rights reserved.
 * 
 * @file       		���Ź�
 * @company	        ���������ܳ����¾��ֲ�
 * @author     		������573763581		���Ļ� qq1280390945  
 * @version    		v1.0
 * @Software 		IAR 7.7+
 * @Target core		K66
 * @date       		2019-9-27
 *
 * @note��
		���Ź���ʼ���Ժ��ڶ�ʱ�ж��ڰ����趨��ʱ�䶨ʱι�������ڼ�ⵥƬ����������Ƭ���������Զ���λ��
		
		��������ҵ��ѧ���ܳ����¾��ֲ�ר�ã�����й¶
***************************************************************************************************************************/

#include "SmartCar_Wdog.h"

#ifdef __cplusplus
extern "C" {
#endif

static void WaitWctClose()
{
    /* Accessing register by bus clock    ͨ������ʱ�ӷ��ʼĴ���*/
    for (uint32_t i = 0; i < WDOG_WCT_INSTRUCITON_COUNT; i++)
    {
        (void)WDOG->RSTCNT;
    }
}
/**********************************************************************************************************************
*  @brief      ���Ź���ʼ��
*  @param      ms 		ι�����
*  @return     void
*  @since      v1.0
*  Sample usage:         Wdog_Init(100);
**********************************************************************************************************************/
void Wdog_Init(uint32_t ms)
{
    wdog_config_t config;            //����WDOG���ýṹ��
    /*If not wdog reset   �������WDOG����*/
    if (!(RCM_GetPreviousResetSources(RCM) & kRCM_SourceWdog))
    {
        WDOG_ClearResetCount(WDOG);  //�˺������wdog���ü���ֵ��
    }
    WDOG_GetDefaultConfig(&config);  //��ʼ��WDOG���ýṹ
    config.timeoutValue = ms;
    WDOG_Init(WDOG, &config);
    WaitWctClose();
}

/**********************************************************************************************************************
*  @brief      ι������
*  @param      NULL
*  @return     void
*  @since      v1.0
*  Sample usage:         Wdog_Feed();
**********************************************************************************************************************/
void Wdog_Feed(void)
{
  WDOG_Refresh(WDOG);
}


#ifdef __cplusplus
}
#endif

