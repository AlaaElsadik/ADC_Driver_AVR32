/**************************************************************/
/*************** Name    : Alaa Sayed *************************/
/*************** Date    : 1/8/2022   *************************/
/*************** Version : 1.0V       *************************/
/*************** SWC     : ADC        *************************/
/**************************************************************/


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/********************************** Register File *****************************************/
/* Macros For ADC Control Registers */
#define ADC_u8_ADMUX_REG		*((volatile u8 *)0x27)
#define ADC_u8_ADCSRA_REG		*((volatile u8 *)0x26)
#define ADC_u8_ADCH_REG			*((volatile u8 *)0x25)
#define ADC_u8_ADCL_REG			*((volatile u8 *)0x24)
#define ADC_u8_SFIOR_REG		*((volatile u8 *)0x50)

/* Casting The ADC Low Register as  u16 to read the High&low registers 
	as a one Value */
#define ADC_u16_ADCD_REG		*((volatile u16*)0x24)


/*******************************************************************************************/
/************************************ Registers Bits ***************************************/
/*******************************************************************************************/
/* Referenc Voltage Selection Bits
	Options: 1- 0 0  => AREF Pin Voltage
			 2- 0 1  => AVCC (Internal Vref)
			 3- 1 0  => Reserved
			 4- 1 1  => Intrna 2.56 Voltage*/
#define ADMUX_REFS1			7
#define ADMUX_REFS0			6


/* Right Or Left Adjust Result Mode
   Options: 1- Set Bit => Left Adjust(8-bits)
			2- Clr Bit => Right Adjust(10-bits)
*/
#define ADMUX_ADLAR			5

/*Macros For Analog Channel and Gain Selection Bits*/
/* Single Ended Channels*/
#define ADC_u8_CHANNEL_0		0
#define ADC_u8_CHANNEL_1        1
#define ADC_u8_CHANNEL_2        2
#define ADC_u8_CHANNEL_3        3
#define ADC_u8_CHANNEL_4        4
#define ADC_u8_CHANNEL_5        5
#define ADC_u8_CHANNEL_6        6
#define ADC_u8_CHANNEL_7		7

/* Differential Channels */
/*	Options: Positive Diff I/P   Negative Diff O/P		Gain
	1-		 ADC0				 ADC0	                10x
	2-       ADC1                ADC0                   10x
	3-       ADC0                ADC0                   200x
	4-       ADC1                ADC0                   200x
	5-       ADC2				 ADC2	                10x
*/
#define ADC_DIFF_CHANNEL0			8
#define ADC_DIFF_CHANNEL1			9
#define ADC_DIFF_CHANNEL2			10
#define ADC_DIFF_CHANNEL3			11
#define ADC_DIFF_CHANNEL4			12

/********************************************/
/* Macros For ACSRA Register */
/* ADC Enable Pin
   Options: 1- Set Bit => Enable ADC
			2- Clr Bit => Disable ADC
*/
#define ACSRA_ADEN			7

/* ADC Start Conversion Pin */
/* Options: 1- Set Bit => Start Each Conversion (At Free Running Mode)
            2- Clr Bit => Has No Effect (It's Auto Cleared After Conv End)
*/
#define ACSRA_ADSC			6

/* ADC Auto Trigger Enable Pin*/
/* Options: 1- Set Bit =>
			2- Clr Bit =>
*/
#define ACSRA_ADATE			5

/* ADC Interrupt Flag*/
/* Note: 1- ISR of ADC Is Only Executed while ADIE AND GIE(SREG_7) Are SET !
		 2- The Flag is Cleared By HW However, It's cleared by writing 1
*/
#define ACSRA_ADIF			4

/*ADC Interrupt Enable Pin*/
#define ACSRA_ADIE			3


/****************************************************************************/
/* ADC Prescalar Selet Bits*/
/* Options: ADPS2	ADPS1	ADPS0	=> Div/Factor
			0		0		0			2
			0		0		1			2
			0		1		0			4
			0		1		1			8
			1		0		0			16
			1		0		1			32
			1		1		0			64
			1		1		1			128
*/

#define ACSRA_ADPS2			2
#define ACSRA_ADPS1			1
#define ACSRA_ADPS0			0
/*********************************************************/
/* ADC Trigger Source (Start New Conversion Control Mode)*/
/*  Options:
	0 	0 	0 	=>	Free Running mode
	0 	0 	1 	=>	Analog Comparator
	0 	1 	0 	=>	External Interrupt Request 0
	0 	1 	1 	=>	Timer/Counter0 Compare Match
	1 	0 	0 	=>	Timer/Counter0 Overflow
	1 	0 	1 	=>	Timer/Counter Compare Match B
	1 	1 	0 	=>	Timer/Counter1 Overflow
	1 	1 	1 	=>	Timer/Counter1 Capture Event
*/

#define SFIOR_ADTS2		7
#define SFIOR_ADTS1		6
#define SFIOR_ADTS0		5

/**********************************************************************************************/


#define BIT_MODE_8		1
#define BIT_MODE_10		2



#define DIVIDE_BY_2		1
#define DIVIDE_BY_4		2
#define DIVIDE_BY_8		3
#define DIVIDE_BY_16	4
#define DIVIDE_BY_32	5
#define DIVIDE_BY_64	6
#define DIVIDE_BY_128	7

#define PRESCALAR_MASK	0b11111000
#define CHANNEL_MASK	0b11100000



#define LEFT_ADJUST		0
#define RIGHT_ADJUST	1



 #define AREF        			0
 #define AVCC         			1
 #define INTERNAL      			2


#define NOT_BUSY				0
#define BUSY					1

#define SINGLE 					0
#define CHAIN 					1




#endif /* ADC_PRIVATE_H_ */
