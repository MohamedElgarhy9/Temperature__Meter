/*
 * ADC.h
 *
 * Created: 3/21/2022 4:23:14 AM
 *  Author: Mohamed Maged
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_macros.h"
#include "DIO.h"

#ifndef ADC_H_
#define ADC_H_


void ADC_vInit(void); // ADC initializing function
unsigned short ADC_u16Read(void);  // ADC read function

#endif /* ADC_H_ */