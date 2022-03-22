/*

 * Temperature_Meter.c
 *
 * Created: 3/21/2022 5:35:12 AM
 * Author: Mohamed Maged
 
 */ 

#include "Temp_Meter.h"

int main(void)
{
	LCD_vInit();
	ADC_vInit();
	LCD_vSend_String("temp=");
	while(1)
	{
		volt_in_mV = 2.5*ADC_u16Read();
		if(volt_in_mV >= 1000) //Temperature is +ve
			{
				temperature = (volt_in_mV - 1000)/10;
				LCD_vMoveCursor(1,6);
				display_Temp();
			}			
		else //Temperature is -ve
			{
				temperature = (1000 - volt_in_mV)/10;
				LCD_vMoveCursor(1,6);
				LCD_vSend_Char('-');
				display_Temp();
			}
	}				
}
void display_Temp(void)
{
	if (temperature<10)
	{
		LCD_vSend_Char((temperature%10)+48);
		LCD_vSend_Char(0xDF);
		LCD_vSend_Char('C');
		LCD_vSend_Char(0x20);
	}
	else if(temperature<100)
	{
		LCD_vSend_Char((temperature/10)+48);
		LCD_vSend_Char((temperature%10)+48);
		LCD_vSend_Char(0XDF);
		LCD_vSend_Char('C');
		LCD_vSend_Char(0x20);
	}
	else if(temperature<=150)
	{
		LCD_vSend_Char((temperature/100)+48);
		LCD_vSend_Char(((temperature/10)-10)+48);
		LCD_vSend_Char((temperature%10)+48);
		LCD_vSend_Char(0XDF);
		LCD_vSend_Char('C');
	}
}
