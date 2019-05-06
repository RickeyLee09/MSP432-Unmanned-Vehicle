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
#include <inttypes.h>

/* include sensor header file */
#include "sensorTask.h"
#include "Motor.h"


extern uint16_t range[8];
extern uint32_t RHMotorState;
extern uint32_t LHMotorState;
extern uint8_t state;

extern int count;
extern uint32_t Rspeed,Rdistance, Lspeed, Ldistance;
//extern UInt time;
extern UInt count_time;

//extern uint16_t range2[8];
/*
 *  screenTaskFxn
 */
void screenTaskFxn (UArg arg0, UArg arg1)
{
	Graphics_Context g_sContext;

	char test1_string[20];
    //uint16_t range[8];

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
        /* Print sensor distance */
        Graphics_clearBuffer(&g_sContext);
    	    y = 0;
        sprintf(test1_string,"Mode = %d mode", state) ;
            Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, LHS, y, GRAPHICS_TRANSPARENT_TEXT);

        y = y+20;

    	    sprintf(test1_string,"R_Sensor 1 = %3d", range[3]) ;
            Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, LHS, y, GRAPHICS_TRANSPARENT_TEXT);
        sprintf(test1_string,"L_Sensor 1 = %3d", range[4]) ;
            Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, RHS, y, GRAPHICS_TRANSPARENT_TEXT);

        y = y+20;

        sprintf(test1_string,"R_Sensor 2 = %3d", range[0]) ;
            Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, LHS, y, GRAPHICS_TRANSPARENT_TEXT);
        sprintf(test1_string,"L_Sensor 2 = %3d", range[7]) ;
            Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, RHS, y, GRAPHICS_TRANSPARENT_TEXT);

        y = y+20;

        sprintf(test1_string,"R_Sensor 3 = %3d", range[1]) ;
            Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, LHS, y, GRAPHICS_TRANSPARENT_TEXT);
        sprintf(test1_string,"L_Sensor 3 = %3d", range[6]) ;
            Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, RHS, y, GRAPHICS_TRANSPARENT_TEXT);

        y = y+20;

        sprintf(test1_string,"R_Sensor 4 = %3d", range[2]) ;
           Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, LHS, y, GRAPHICS_TRANSPARENT_TEXT);
        sprintf(test1_string,"L_Sensor 4 = %3d", range[5]) ;
           Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, RHS, y, GRAPHICS_TRANSPARENT_TEXT);

        y = y+20;

        sprintf(test1_string,"R_encoder = %3d", RHMotorState) ;
           Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, LHS, y, GRAPHICS_TRANSPARENT_TEXT);
        sprintf(test1_string,"L_encoder = %3d", LHMotorState) ;
           Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, RHS, y, GRAPHICS_TRANSPARENT_TEXT);

       y = y+20;

       sprintf(test1_string,"R_v = %3d mm/s", Rspeed) ;
          Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, LHS, y, GRAPHICS_TRANSPARENT_TEXT);
       sprintf(test1_string,"L_v = %3d mm/s", Lspeed) ;
          Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, RHS, y, GRAPHICS_TRANSPARENT_TEXT);

      y = y+20;

      sprintf(test1_string,"time = %d s", count_time) ;
          Graphics_drawString(&g_sContext, test1_string, GRAPHICS_AUTO_STRING_LENGTH, LHS, y, GRAPHICS_TRANSPARENT_TEXT);


        Graphics_flushBuffer(&g_sContext);
        Task_sleep(100);

    }
}

