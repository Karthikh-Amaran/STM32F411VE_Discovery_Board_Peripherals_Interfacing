/*
 *
 *  Created on: 26-Jan-2023
 *      Author: Karthikh Amaran
 */

#include<stdio.h>
#include<stdint.h>
#include"adc.h"
#include"stm32f4xx.h"
#include "uart.h"

uint32_t sensor_value;
int __io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
}

void delay()
{
	volatile int i=0;
	for(i=0;i<200000;i++);
}
int main(void)
{
	int count =0;
	uart2_rxtx_init(); // PA2 TX : PA3 RX
	pa1_adc_init();
	start_continuous_conversion();
	printf("TimeStamp,Value\r\n");
	while(1)
	{
		count++;
		sensor_value = adc_read(); // ADC IN PA1
		printf("%d,%d\r\n",count,(int)(sensor_value));
		delay();
	}
}
