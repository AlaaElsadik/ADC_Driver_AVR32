#ifndef BIT_MATHS_H_
#define BIT_MATHS_H_

#define SET_BIT(REG,BIT_NO) 		REG |=    (1<<BIT_NO)
#define CLR_BIT(REG,BIT_NO)			REG &= (~(1<<BIT_NO))
#define TOG_BIT(REG,BIT_NO)			REG ^=    (1<<BIT_NO)
#define GET_BIT(REG,BIT_NO)	  (((REG) >> (BIT_NO)) & 0x01)


#endif
