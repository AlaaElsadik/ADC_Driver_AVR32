/**************************************************************/
/*************** Name    : Alaa Sayed *************************/
/*************** Date    : 1/8/2022   *************************/
/*************** Version : 1.0V       *************************/
/*************** SWC     : ADC        *************************/
/**************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



/**************************************************************************************/
/*Description: Analog to digital converter initialization
 * 			   This function uses configuration file to set ref. voltage, prescaler and
 *			   result adjust mode.
 * Inputs: void
 * Outputs: void
 * Preconditions: N/A
 *																			          */
/**************************************************************************************/
void ADC_voidInit (void);


/**************************************************************************************/
/*Description: Analog to digital converting using polling technique
 * Inputs:	1- Copy_u8ChannelNm : the channel connected to your sensor Vo

 * 			2- Copy_pu16DigitalVal: An address of a variable that will contain the
 * 									conversion result (The digital value)
 * Outputs: Error state
 * 				Options: 1- OK
 * 						 2- NOK
 * Preconditions: N/A
 *																			          */
/**************************************************************************************/
u8 ADC_u8GetDigitalValueSynchronous	(u8 Copy_u8ChannelNm);





#endif
