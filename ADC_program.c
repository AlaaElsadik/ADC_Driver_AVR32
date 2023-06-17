/**************************************************************/
/*************** Name    : Alaa Sayed *************************/
/*************** Date    : 3/8/2022   *************************/
/*************** Version : 1.0V       *************************/
/*************** SWC     : ADC        *************************/
/**************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATHS.h"

#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"

/* Busy Flag */
static u8 ADC_u8BusyFlag = NOT_BUSY;



void ADC_voidInit (void)
{
	/* Select Reference Voltage*/
	
	#if REFERENCE_VOLTAGE == AREF
	CLR_BIT(ADC_u8_ADMUX_REG,ADMUX_REFS1);
	CLR_BIT(ADC_u8_ADMUX_REG,ADMUX_REFS0);
	
	#elif REFERENCE_VOLTAGE == AVCC
	CLR_BIT(ADC_u8_ADMUX_REG,ADMUX_REFS1);
	SET_BIT(ADC_u8_ADMUX_REG,ADMUX_REFS0);
	
	#elif REFERENCE_VOLTAGE == INTERNAL
	SET_BIT(ADC_u8_ADMUX_REG,ADMUX_REFS1);
	SET_BIT(ADC_u8_ADMUX_REG,ADMUX_REFS0);
	
	#endif
	
	/*Select Result Adjust Mode*/
	#if  RESULT_ADJUST == LEFT_ADJUST
	SET_BIT(ADC_u8_ADMUX_REG,ADMUX_ADLAR);
	
	#elif	 RESULT_ADJUST ==	RIGHT_ADJUST
	CLR_BIT(ADC_u8_ADMUX_REG,ADMUX_ADLAR);
	
	#endif
	
	CLR_BIT(ADC_u8_ADCSRA_REG,ACSRA_ADATE);

	/* ADC PRESCALAR Selection*/
	ADC_u8_ADCSRA_REG &= PRESCALAR_MASK;
	ADC_u8_ADCSRA_REG |= ADC_u8PRESCALAR;
	
	/*ADC Enable*/
	SET_BIT(ADC_u8_ADCSRA_REG,ACSRA_ADEN);
	
	
}

u8 ADC_u8GetDigitalValueSynchronous	(u8 Copy_u8ChannelNm)
{

	if((Copy_u8ChannelNm < 32))
	{
		/*Check that the ADC is not in another conversion to prevent re-entrancy */
		if(ADC_u8BusyFlag == NOT_BUSY)
		{
			/*Raise the Busy flag of ADC*/
			ADC_u8BusyFlag = BUSY;

			/* Select Channel Mask */
			ADC_u8_ADMUX_REG &= CHANNEL_MASK;
			ADC_u8_ADMUX_REG |= Copy_u8ChannelNm;

			/* ADC Start Conversion*/
			SET_BIT(ADC_u8_ADCSRA_REG,ACSRA_ADSC);

			/* Wait for the flag */
			while((GET_BIT(ADC_u8_ADCSRA_REG,ACSRA_ADIF)) == 0);

			/* Clear ADC EOC Flag*/
			SET_BIT(ADC_u8_ADCSRA_REG,ACSRA_ADIF);

			/* Read The Data*/
			#if   ADC_RESOLUTION == BIT_MODE_10
			return ADC_u16_ADCD_REG;

			#elif  ADC_RESOLUTION == BIT_MODE_8
			return ADC_u8_ADCH_REG;

			#endif


			/*Release The Busy Flag and make ADC ready to other conversions*/
			ADC_u8BusyFlag = NOT_BUSY;
		}
	}

}
	
