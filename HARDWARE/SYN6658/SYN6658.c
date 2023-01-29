#include "SYN6658.h"
#include "string.h"
#include "usart.h"
#include "led.h"
#include "delay.h"

u8 SYN_StopCom[]={0xFD,0X00,0X01,0X02};//停止合成
u8 SYN_SuspendCom[]={0XFD,0X00,0X01,0X03};//暂停合成
u8 SYN_RecoverCom[]={0XFD,0X00,0X01,0X04};//恢复合成
u8 SYN_ChackCom[]={0XFD,0X00,0X01,0X21};//状态查询
u8 SYN_PowerDownCom[]={0XFD,0X00,0X01,0X88};//进入POWER DOWN 状态命令

/***********************************************/



/***********************************************************
* 名    称：  YS-XFS5051 文本合成函数
* 功    能：  发送合成文本到XFS5051芯片进行合成播放
* 入口参数：  *HZdata:文本指针变量 
* 出口参数：
* 说    明： 本函数只用于文本合成，具备背景音乐选择。默认波特率9600bps。					 
* 调用方法：例： SYN_FrameInfo（“飞音云电子”）；
**********************************************************/
void SYN_FrameInfo(const char *HZdata)
{
/****************需要发送的文本**********************************/ 
		 u8 Frame_Info[250]; //定义的文本长度
         u8  HZ_Length;  
	     u8 i=0; 
		 HZ_Length =strlen(HZdata); 			//需要发送文本的长度
/*****************帧固定配置信息**************************************/           
		 Frame_Info[0] = 0xFD ; 			//构造帧头FD
		 Frame_Info[1] = 0x00 ; 			//构造数据区长度的高字节
		 Frame_Info[2] = HZ_Length+2; 		//构造数据区长度的低字节
		 Frame_Info[3] = 0x01 ; 			//构造命令字：合成播放命令		 		 
		 Frame_Info[4] = 0x00;       //文本编码格式：GB2312 
 
/*******************发送帧信息***************************************/
	for(i=0;i<HZ_Length;i++)
	{
		Frame_Info[i+5]=HZdata[i];
	}
	for(i=0;i<5+HZ_Length;i++)
	{
		
		USART_SendData(USART1,(u16)Frame_Info[i]); //发送帧配置
		delay_ms(1);
	}
		
}
