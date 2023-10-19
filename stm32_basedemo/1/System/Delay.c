#include "stm32f10x.h"


void Delay_us(uint32_t xus)
{
	SysTick->LOAD=72*xus;
	SysTick->VAL=0x00;
	SysTick->CTRL=0x00000005;  //0101 开启定时器，设置时钟源为高速
	while(!(SysTick->CTRL&0x00010000)); //等待定时器到0
	SysTick->CTRL=0x00000004;  //关闭定时器
}


void Delay_ms(uint32_t xms)
{
	while(xms--)
	{
		Delay_us(1000);
	}
}

void Delay_s(uint32_t xs)
{
	while(xs--)
	{
		Delay_ms(1000);
	}
}
