/*
 *  ======== main.c ========
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

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/drivers/I2C.h>

/* Board Header files */
#include "Board.h"
#include "buttons.h"
#include <stdio.h>
#include "MSP_EXP432P401R.h"
#include "Robot.h"
#include "Motor.h"


Void clk0Fxn(UArg arg0);
Clock_Struct clk0Struct;
Clock_Handle clk2Handle;

/*
 *  ======== global system state variables ========
 */
uint8_t	state = 0;
uint32_t RHMotorState = 0;
uint32_t LHMotorState = 0;
uint32_t prevRHMotorState = 0;
uint32_t prevLHMotorState = 0;
uint32_t time = 0;
uint32_t prevTime = 0;

//Set Timer for speed calculation
Void clk0Fxn(UArg arg0)
{
    prevTime = time;
    time = Clock_getTicks();
}


/*
 *  ======== main ========
 */
int main(void)
{   /* Call board init functions */
    Board_initGeneral();
    Board_initGPIO();
    Board_initPWM();
    Board_initI2C();

    GPIO_setCallback(Board_BUTTON0, gpioButtonFxn0);
    GPIO_enableInt(Board_BUTTON0);
    GPIO_setCallback(Board_BUTTON1, gpioButtonFxn1);
    GPIO_enableInt(Board_BUTTON1);

    // Switch on the LEDs
    //
    GPIO_write(Board_LED0, Board_LED_ON);	// LH LED
    GPIO_write(Board_LED1, Board_LED_ON);	// RH LED, Red
    GPIO_write(Board_LED2, Board_LED_ON);	// RH LED, Green
    GPIO_write(Board_LED3, Board_LED_ON);	// RH LED, Blue

    /* GPIO Sensor */
    GPIO_write(Robot_Left_Sensor_INT, Robot_Sensor_ON);
    GPIO_write(Robot_Right_Sensor_INT, Robot_Sensor_ON);
    GPIO_write(Robot_Left_Sensor_PE, Robot_Sensor_ON);
    GPIO_write(Robot_Right_Sensor_PE, Robot_Sensor_ON);

    /*GPIO Motors */
    GPIO_setCallback(MSP_EXP432P401R_P6_1, RHMotorChannelAFallingFxn);
    GPIO_enableInt(MSP_EXP432P401R_P6_1);
    //GPIO_setCallback(MSP_EXP432P401R_P4_0, RHMotorChannelARisingFxn);
    //GPIO_enableInt(MSP_EXP432P401R_P4_0);
    GPIO_setCallback(MSP_EXP432P401R_P4_5, LHMotorChannelAFallingFxn);
    GPIO_enableInt(MSP_EXP432P401R_P4_5);
    //GPIO_setCallback(MSP_EXP432P401R_P4_7, LHMotorChannelARisingFxn);
    //GPIO_enableInt(MSP_EXP432P401R_P4_7);


    GPIO_write(Robot_MotorEN, Robot_Motor_ON);
    //GPIO_write()

    /* Construct BIOS Objects */
    Clock_Params clkParams;
    Clock_Params_init(&clkParams);
    clkParams.period = 1000/Clock_tickPeriod;
    clkParams.startFlag = TRUE;

    /* Construct a periodic Clock Instance */
    Clock_construct(&clk0Struct, (Clock_FuncPtr)clk0Fxn,
                    1000/Clock_tickPeriod, &clkParams);
    clk2Handle = Clock_handle(&clk0Struct);
    Clock_start(clk2Handle);


    System_printf("Starting the example\nSystem provider is set to SysMin. "
                  "Halt the target to view any SysMin contents in ROV.\n");
    /* SysMin will only print to the console when you call flush or exit */
    System_flush();

    /* Start BIOS */
    BIOS_start();

    return (0);
}
