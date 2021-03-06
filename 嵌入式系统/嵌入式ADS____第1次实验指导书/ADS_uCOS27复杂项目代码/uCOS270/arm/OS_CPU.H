/****************************************Copyright (c)**************************************************
**                               ������������Ƭ����չ���޹�˾
**                                     ��    ��    ��
**                                        ��Ʒһ�� 
**
**                                 http://www.zlgmcu.com
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: os_cpu.h
**��   ��   ��: ������
**����޸����ￄ1�7: 2003��6��24��
**��        ��: ��COS-II��LPC210x�ϵ���ֲ����CPU���ò��֣���ADS1.2����
**
**--------------��ʷ�汾��Ϣ----------------------------------------------------------------------------
** ������: ������
** ��  ��: 1.0
** �ա���: 2003��6��5��
** �衡��: ԭʼ�汾
**
**------------------------------------------------------------------------------------------------------
** �޸���: ������
** ��  ��: 1.1
** �ա���: 2003��6��13��
** �衡��: ���Ӻ���IsrEnIRQ
**
**------------------------------------------------------------------------------------------------------
** �޸���: ������
** ��  ��: 1.2
** �ա���: 2003��6��19��
** �衡��: !�����������жϷ�����
**         2����ȡ������OSNeedToSwapContext�����ĸĶ�
**
**------------------------------------------------------------------------------------------------------
** �޸���: ������
** ��  ��: 1.3
** �ա���: 2003��7��8��
** �衡��: ȥ������Ҫ�ĺ���IsrEnIRQ
**
**--------------��ǰ�汾�޶�------------------------------------------------------------------------------
** �޸���: 
** �ա���: 
** �衡��: 
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/

#ifdef  OS_CPU_GLOBALS
#define OS_CPU_EXT
#else
#define OS_CPU_EXT  extern
#endif

/**********************************************************************************************************
*                    ������������޹ص��������ￄ1�7
**********************************************************************************************************/

typedef unsigned char  BOOLEAN;                 /* ��������                                 */
typedef unsigned char  INT8U;                   /* �޷���8λ���ͱ���                        */
typedef signed   char  INT8S;                   /* �з���8λ���ͱ���                        */
typedef unsigned short INT16U;                  /* �޷���16λ���ͱ���                       */
typedef signed   short INT16S;                  /* �з���16λ���ͱ���                       */
typedef unsigned int   INT32U;                  /* �޷���32λ���ͱ���                       */
typedef signed   int   INT32S;                  /* �з���32λ���ͱ���                       */
typedef float          FP32;                    /* �����ȸ�������32λ���ȣ�                 */
typedef double         FP64;                    /* ˫���ȸ�������64λ���ȣ�                 */

typedef INT32U         OS_STK;                  /* ��ջ��32λ����                           */

/* �����Ǽ���UC/OS V1.XX���������ͣ���uC/OS-IIû��ʹ��  */
#define BYTE           INT8S
#define UBYTE          INT8U
#define WORD           INT16S
#define UWORD          INT16U
#define LONG           INT32S
#define ULONG          INT32U

/* *********************************************************************************************************
*                    ��ARM7��ϵ�ṹ��ص�һЩ���ￄ1�7
**********************************************************************************************************/
#define     OS_CRITICAL_METHOD     2            /* ѡ�񿪡����жϵķ�ʽ */


__swi(0x00) void OS_TASK_SW(void);              /*  ���������л�����          */
__swi(0x01) void _OSStartHighRdy(void);         /*  �������ȼ���ߵ����ￄ1�7        */
__swi(0x02) void OS_ENTER_CRITICAL(void);       /*  ���ж�                      */
__swi(0x03) void OS_EXIT_CRITICAL(void);        /*  ���ж�                      */

__swi(0x40) void *GetOSFunctionAddr(int Index); /*  ��ȡϵͳ��������ￄ1�7        */
__swi(0x41) void *GetUsrFunctionAddr(int Index);/*  ��ȡ�Զ�����������      */
__swi(0x42) void OSISRBegin(void);              /*  �жϿ�ʼ����                */
__swi(0x43) int  OSISRNeedSwap(void);           /*  �ж��ж��Ƿ���Ҫ�л�        */

__swi(0x80) void ChangeToSYSMode(void);         /*  �����л���ϵͳģʽ          */
__swi(0x81) void ChangeToUSRMode(void);         /*  �����л����û�ģʽ          */
__swi(0x82) void TaskIsARM(INT8U prio);         /*  ���������ARM����           */
__swi(0x83) void TaskIsTHUMB(INT8U prio);       /*  ���������THUMB             */

#define OS_STK_GROWTH    1                      /*  ��ջ�Ǵ������³���          */

#define     USR32Mode       0x10                /*  �û�ģʽ                    */
#define     SYS32Mode       0x1f                /*  ϵͳģʽ                    */
#define     NoInt           0x80

#ifndef USER_USING_MODE
#define	USER_USING_MODE	USR32Mode               /*  ����ȱʡģʽ                 */
#endif

#ifndef OS_SELF_EN
#define	OS_SELF_EN     0                        /*  ��������OS������ֱ���롢�̻�*/    
#endif


OS_CPU_EXT INT32U OsEnterSum;                   /*  ���жϼ������������жϵ��ź�����    */


/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
