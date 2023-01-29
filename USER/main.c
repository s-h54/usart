#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
 #include "SYN6658.h"
/************************************************
 ALIENTEK��ӢSTM32������ʵ��4
 ���� ʵ��   
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
 int main(void)
 {		
	u16 a[9]={0xFD,0x00,0x06,0x01,0x01,0xC4,0xE3,0xBA,0xC3};
	u8 A[12]={0xFD,0x00,0x09,0x01,0x01,0x41,0xC0,0xE0,0xC3,0xA4,0xBA,0xD0};
	u8 i=0;
// 	u16 t;  
//	u16 len;	
//	u16 times=0;
	 
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(9600);	 //���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
	KEY_Init();          //��ʼ���밴�����ӵ�Ӳ���ӿ�
 	while(1)
	{
		SYN_FrameInfo("");
		SYN_FrameInfo("һԪ����");
		delay_ms(1000);
		delay_ms(300);
		SYN_FrameInfo("һ������");
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

