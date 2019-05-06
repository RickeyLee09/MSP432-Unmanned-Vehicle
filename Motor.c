/* XDCtools Header files */
#include "stdint.h"
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/PWM.h>

/* Example/Board Header files */
#include "Board.h"
#include "Robot.h"

/*
 *  ======== MotorsFxn ========
 *  Task periodically increments the PWM duty for the on board LED.
 */

extern uint32_t RHMotorState;
extern uint32_t LHMotorState;


void RHMotorChannelAFallingFxn(unsigned int index){
    if (GPIO_read(MSP_EXP432P401R_P4_2)){
        RHMotorState++;
    }
    else{
        RHMotorState--;
    }
}

void LHMotorChannelAFallingFxn(unsigned int index){
    if (GPIO_read(MSP_EXP432P401R_P5_4))
        LHMotorState++;
    else
        LHMotorState--;
}




