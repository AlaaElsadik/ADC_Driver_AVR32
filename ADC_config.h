/**************************************************************/
/*************** Name    : Alaa Sayed *************************/
/*************** Date    : 1/8/2022   *************************/
/*************** Version : 1.0V       *************************/
/*************** SWC     : ADC        *************************/
/**************************************************************/

#ifndef	ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* Ref-Voltage Options:
				1- AREF  
                2- AVCC 
                3- INTERNAL_2.56 
*/         

#define REFERENCE_VOLTAGE	AVCC

/* Right Or Left Adjust Result Mode 
   Options: 1- Set Bit => LEFT_ADJUST (8-Bit Resolution)
			2- Clr Bit => RIGHT_ADJUST(10-Bit Resolution)
*/
#define RESULT_ADJUST	RIGHT_ADJUST

/*	Options: DIVIDE_BY_2
			 DIVIDE_BY_4
			 DIVIDE_BY_8
			 DIVIDE_BY_16
			 DIVIDE_BY_32
			 DIVIDE_BY_64
			 DIVIDE_BY_128
 *
 */
#define ADC_u8PRESCALAR		DIVIDE_BY_128

/*Options: 1- BIT_MODE_8
		   2- BIT_MODE_10
		   */

#define ADC_RESOLUTION 	BIT_MODE_8


#define ADC_u32_TIME_OUT_VALUE             100000UL


/*Macros for conversion type
 * Options: 1- SINGLE
			2- CHAIN */

#define CONVERSION_TYPE			SINGLE







#endif
