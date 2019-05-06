/*
 * buttons.c
 *
 *  Created on: 9 Oct 2016
 *      Author: shailes
 */
#include "stdint.h"

extern uint8_t state;

/*
 *  Callback function for the GPIO interrupt on Board_BUTTON0 and Board_BUTTON1.
 */
void gpioButtonFxn0(unsigned int index)
{
	state ++;
//	if (state == 4){
//	    state = 0;
//	}
}

void gpioButtonFxn1(unsigned int index)
{
	state = 0;
}

