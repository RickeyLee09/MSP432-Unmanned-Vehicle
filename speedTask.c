/*
 * speedTask.c
 *
 *  Created on: 2017年11月10日
 *      Author: Rickey
 */

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/utils/Load.h>

/* Board Header files */
#include "Board.h"
#include "buttons.h"
#include <stdio.h>
#include "MSP_EXP432P401R.h"
#include "Robot.h"

extern uint32_t RHMotorState;
extern uint32_t LHMotorState;
extern uint32_t prevRHMotorState;
extern uint32_t prevLHMotorState;
extern uint32_t time;
extern uint32_t prevTime;
uint32_t Rdistance, Ldistance, Rspeed, Lspeed;


void speedTaskFxn(UArg arg0, UArg arg1){
    while(1){
    Rdistance = abs(RHMotorState) - abs(prevRHMotorState);
    Ldistance = abs(LHMotorState) - abs(prevLHMotorState);
    Rspeed = ((Rdistance * 1884)/750)/(time-prevTime); //transfer encoder number to millimeter then calculate the speed
    Lspeed = ((Ldistance * 1884)/750)/(time-prevTime);
    prevRHMotorState = RHMotorState;
    prevLHMotorState = LHMotorState;
    Task_sleep(150);
    }
}
