/*
 * Temp_Meter.h
 *
 * Created: 3/22/2022 1:34:31 AM
 *  Author: Mohamed Maged
 */ 

#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"
unsigned short volt_in_mV;
unsigned short temperature;

#ifndef TEMP_METER_H_
#define TEMP_METER_H_

void display_Temp(void);

#endif /* TEMP_METER_H_ */