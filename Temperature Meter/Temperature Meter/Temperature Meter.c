/*
 * Temperature_Meter.c
 *
 * Created: 3/21/2022 5:35:12 AM
 *  Author: Mohamed Maged
 */ 


#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"
char read_val;
unsigned short temperatue;
int main(void)
{
	LCD_vInit();
	ADC_vInit();
	LCD_vSend_String("temperature=");
	while(1)
	{

		temperatue=(ADC_u16Read()*0.25);
		if(temperatue<10)
		{
			LCD_vMoveCursor(1,13);
			LCD_vSend_Char((temperatue%10)+48);
			LCD_vSend_Char(0xDF);
			LCD_vSend_Char(0x43);
			LCD_vSend_Char(0x20);
		}
		else if( temperatue<100)
		{
			LCD_vMoveCursor(1,13);
			LCD_vSend_Char((temperatue/10)+48);
			LCD_vSend_Char((temperatue%10)+48);
			LCD_vSend_Char(0XDF);
			LCD_vSend_Char(0X43);
		}
		else
		{

		}
	}		
}
