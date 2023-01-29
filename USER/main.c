#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
 #include "SYN6658.h"
/************************************************
 ALIENTEK精英STM32开发板实验4
 串口 实验   
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
 int main(void)
 {		
	u16 a[9]={0xFD,0x00,0x06,0x01,0x01,0xC4,0xE3,0xBA,0xC3};
	u8 A[12]={0xFD,0x00,0x09,0x01,0x01,0x41,0xC0,0xE0,0xC3,0xA4,0xBA,0xD0};
	u8 i=0;
// 	u16 t;  
//	u16 len;	
//	u16 times=0;
	 
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(9600);	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
	KEY_Init();          //初始化与按键连接的硬件接口
 	while(1)
	{
		SYN_FrameInfo("");
		SYN_FrameInfo("一元在上");
		delay_ms(1000);
		delay_ms(300);
		SYN_FrameInfo("一角在下");
		delay_ms(1000);
		delay_ms(1000);
		delay_ms(1000);
//		delay_ms(1000);
//		delay_ms(1000);
//		delay_ms(1000);
//		for(i=0;i<9;i++)
//		{
//			USART_SendData(USART1,a[i]);
//			delay_ms(1);
//			
//		}
	}	 
 }

