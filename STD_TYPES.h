#include<stdio.h>

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


/*New Data Types*/
typedef unsigned char       u8;
typedef signed char         s8;
typedef unsigned short int  u16;
typedef signed short int    s16;
typedef unsigned long int 	u32;
typedef signed long int 	s32;
typedef float 				f32;
typedef double 				f64;
typedef long double 		f96;

#define STD_TYPES_OK		1
#define STD_TYPES_NOK		0
#define STD_TIMEOUT_STATE	3
#define STD_BUSY_STATE 		4

#define NULL 				((void *)0)
	
#endif 
