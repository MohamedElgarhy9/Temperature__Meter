/*
 * ADC.c
 *
 * Created: 3/21/2022 3:42:04 AM
 *  Author: Mohamed Maged
 */ 


#include "ADC.h"

void ADC_vInit(void)
{
	//Enable the interrupt of the ADC specifically 
	SET_BIT(ADCSRA,ADIE);
	//Define the ADC reference voltage, REFS0 and REFS1 -> Setting the internal valtage= 2.56v as a refernce voltage 
	SET_BIT(ADMUX,REFS0); //configure VREF
	SET_BIT(ADMUX,REFS1);
	//Enable the ADC
	SET_BIT(ADCSRA,ADEN);
	//Choose which pin of portA passes to the ADC
	SET_BIT(ADMUX,MUX4); // pin0 connected to the ADC
	//Define the ADC clock, the  
	//CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	//Now the ADC is working with clock = F_CPU/64
}

unsigned short ADC_u16Read(void)
{
	unsigned short read_val;
	//Start conversion
	SET_BIT(ADCSRA,ADSC);
	//Loop until ADC finishes the conversion
	//As the interrupt flag will set to one at the end pf the conversion, then we shall clear it explicitly 
	while(READ_BIT(ADCSRA,ADIF)==0);
	SET_BIT(ADCSRA,ADIF);//Clear the flag 
	/** 
	This looping can be done in another way
	-> while(READ_BIT(ADCSRA,ADSC)==1);
	as we know that the ADSC bit will be cleared at the end of the conversion by the ADC
	**/
	read_val = ADCL; //Read ADCL **FIRST** register and store it in the read_val variable
	read_val |= (ADCH<<8); //Then read ADCH 
	return read_val;
	
}