#include "SYN6658.h"
#include "string.h"
#include "usart.h"
#include "led.h"
#include "delay.h"

u8 SYN_StopCom[]={0xFD,0X00,0X01,0X02};//ֹͣ�ϳ�
u8 SYN_SuspendCom[]={0XFD,0X00,0X01,0X03};//��ͣ�ϳ�
u8 SYN_RecoverCom[]={0XFD,0X00,0X01,0X04};//�ָ��ϳ�
u8 SYN_ChackCom[]={0XFD,0X00,0X01,0X21};//״̬��ѯ
u8 SYN_PowerDownCom[]={0XFD,0X00,0X01,0X88};//����POWER DOWN ״̬����

/***********************************************/



/***********************************************************
* ��    �ƣ�  YS-XFS5051 �ı��ϳɺ���
* ��    �ܣ�  ���ͺϳ��ı���XFS5051оƬ���кϳɲ���
* ��ڲ�����  *HZdata:�ı�ָ����� 
* ���ڲ�����
* ˵    ���� ������ֻ�����ı��ϳɣ��߱���������ѡ��Ĭ�ϲ�����9600bps��					 
* ���÷��������� SYN_FrameInfo���������Ƶ��ӡ�����
**********************************************************/
void SYN_FrameInfo(const char *HZdata)
{
/****************��Ҫ���͵��ı�**********************************/ 
		 u8 Frame_Info[250]; //������ı�����
         u8  HZ_Length;  
	     u8 i=0; 
		 HZ_Length =strlen(HZdata); 			//��Ҫ�����ı��ĳ���
/*****************֡�̶�������Ϣ**************************************/           
		 Frame_Info[0] = 0xFD ; 			//����֡ͷFD
		 Frame_Info[1] = 0x00 ; 			//�������������ȵĸ��ֽ�
		 Frame_Info[2] = HZ_Length+2; 		//�������������ȵĵ��ֽ�
		 Frame_Info[3] = 0x01 ; 			//���������֣��ϳɲ�������		 		 
		 Frame_Info[4] = 0x00;       //�ı������ʽ��GB2312 
 
/*******************����֡��Ϣ***************************************/
	for(i=0;i<HZ_Length;i++)
	{
		Frame_Info[i+5]=HZdata[i];
	}
	for(i=0;i<5+HZ_Length;i++)
	{
		
		USART_SendData(USART1,(u16)Frame_Info[i]); //����֡����
		delay_ms(1);
	}
		
}
