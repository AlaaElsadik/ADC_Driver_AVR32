/*
 * main.c
 *
 *  Created on: Aug 3, 2022
 *      Author: Alaa Sayed
 */

#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"


int main (void)

{
	u16 Local_u16DigitalVal;
	u16 Local_u16AnalogVal;
	ADC_voidInit();


	while(1)
	{
		Local_u16DigitalVal = ADC_u8GetDigitalValueSynchronous(ADC_u8_CHANNEL_0);
		Local_u16AnalogVal = ((u32)Local_u16DigitalVal * 5000UL) / 1024;
	}
	return 0;

}



