/*
 * screenTask.c
 *
 *  Created on: 9 Oct 2016
 *      Author: shailes
 */

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>

/* Board Header files */
#include "Sharp96x96.h"
#include <stdio.h>

/*
 *  screenTaskFxn
 */
void screenTaskFxn (UArg arg0, UArg arg1)
{
	Graphics_Context g_sContext;

	char test1_string[20];
    char test2_string[20];

    const uint8_t LHS =  10;
    const uint8_t RHS = 210;
    uint8_t y;

    Sharp96x96_LCDInit();

    Graphics_initContext(&g_sContext, &g_sharp96x96LCD);
    Graphics_setForegroundColor(&g_sContext, ClrBlack);
    Graphics_setBackgroundColor(&g_sContext, ClrWhite);
    Graphics_setFont(&g_sContext, &g_sFontCm20b);
    Graphics_clearDisplay(&g_sContext);
    Graphics_flushBuffer(&g_sContext);

    while (1) {
        Graphics_clearBuffer(&g_sContext);
    	y = 0;

    	sprintf(test1_string,"MotorR = %4.1f", 23.2) ;
        Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, LHS, y, GRAPHICS_TRANSPARENT_TEXT);
    	sprintf(test2_string,"MotorL = %4.1f", 17.0) ;
		Graphics_drawString(&g_sContext, test2_string, GRAPHICS_AUTO_STRING_LENGTH, RHS, y, GRAPHICS_TRANSPARENT_TEXT);
    	y += 20;

    	sprintf(test1_string,"DistR = %6.1f", 45.5) ;
        Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, LHS, y, GRAPHICS_TRANSPARENT_TEXT);
    	sprintf(test2_string,"DistL = %6.1f", 96.2) ;
		Graphics_drawString(&g_sContext, test2_string, GRAPHICS_AUTO_STRING_LENGTH, RHS, y, GRAPHICS_TRANSPARENT_TEXT);
    	y += 20;

		Graphics_flushBuffer(&g_sContext);
    	Task_sleep((UInt)arg0);
    }
}

