/*
 *  ======== main.c ========
 */
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>

/* Board Header files */
#include "Board.h"
#include "buttons.h"
#include <stdio.h>

/*
 *  ======== global system state variables ========
 */
uint8_t	state = 1;

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

    System_printf("Starting the example\nSystem provider is set to SysMin. "
                  "Halt the target to view any SysMin contents in ROV.\n");
    /* SysMin will only print to the console when you call flush or exit */
    System_flush();

    /* Start BIOS */
    BIOS_start();

    return (0);
}
