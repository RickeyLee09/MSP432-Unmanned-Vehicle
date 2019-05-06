/*
 * sensorTask.c
 *
 *  Created on: 2017年10月17日
 *      Author: Rickey
 */


/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/I2C.h>

/* Example/Board Header files */
#include "Board.h"
#include <stdio.h>

#define TASKSTACKSIZE       640

uint16_t range[8];
//uint16_t range2[8];
Task_Struct task0Struct;
Char task0Stack[TASKSTACKSIZE];

/*
 *  ======== taskFxn ========
 *  Task for this function is created statically. See the project's .cfg file.
 */
Void sensorTaskFxn(UArg arg0, UArg arg1)
{
    int             j;
    uint8_t         selectBuffer[1];
    uint8_t         txBuffer[3];
    uint8_t         rxBuffer[1];
    I2C_Handle      i2c1, i2c2;
    I2C_Params      i2cParams;
    I2C_Transaction i2cTransaction;

    /* Create I2C for usage */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz;

    /* I2C1 Initialization */
    i2c1 = I2C_open(Board_I2C1, &i2cParams);
    if (i2c1 != NULL) {
        System_printf("I2C1 Initialized!\n");
    }
    else {
        System_abort("Error Initializing I2C\n");
    }

    /* I2C2 Initialization */
    i2c2 = I2C_open(Board_I2C2, &i2cParams);
    if (i2c2 == NULL) {
       System_abort("Error Initializing I2C\n");
    }else {
       System_printf("I2C2 Initialized!\n");
    }


while(1){
    selectBuffer[0] = 0x01;
    System_printf("Right sensor sample: ");

    for (j=0;j<4;j++){
    /* set switch address */
        txBuffer[0] = 0x01;
        i2cTransaction.slaveAddress = 0x70;
        i2cTransaction.writeBuf = selectBuffer;
        i2cTransaction.writeCount = 1;
        i2cTransaction.readBuf = NULL;
        i2cTransaction.readCount = 0;
        I2C_transfer(i2c1, &i2cTransaction);

    /* set sensor mode */
        txBuffer[0] = 0x00;
        txBuffer[1] = 0x18;
        txBuffer[2] = 0x01;
        i2cTransaction.slaveAddress = 0x29;
        i2cTransaction.writeBuf = txBuffer;
        i2cTransaction.readBuf = NULL;
        i2cTransaction.writeCount = 3;
        i2cTransaction.readCount = 0;
        I2C_transfer(i2c1, &i2cTransaction);

    /* Set sensor receive data */
        txBuffer[0] = 0x00;
        txBuffer[1] = 0x62;
        i2cTransaction.slaveAddress = 0x29;
        i2cTransaction.writeBuf = txBuffer;
        i2cTransaction.readBuf = rxBuffer;
        i2cTransaction.writeCount = 2;
        i2cTransaction.readCount = 1;

    /* Take samples and print them out onto the console */
        if (I2C_transfer(i2c1, &i2cTransaction)) {
            range[j] = rxBuffer[0];
        }else {
            System_printf("I2C Bus fault\n");
        }
        System_printf("%d ", range[j]);
        System_flush();
        selectBuffer[0] = selectBuffer[0] << 1;
    }
    System_printf("\n");
    System_flush();
    Task_sleep(10);

    //--------------------------- I2C 2 ---------------------------------
    selectBuffer[0] = 0x01;
    System_printf("Left sensor sample: ");

    for (j=0;j<4;j++){
        /* set switch address */
            txBuffer[0] = 0x01;
            i2cTransaction.slaveAddress = 0x70;
            i2cTransaction.writeBuf = selectBuffer;
            i2cTransaction.writeCount = 1;
            i2cTransaction.readBuf = NULL;
            i2cTransaction.readCount = 0;
            I2C_transfer(i2c2, &i2cTransaction);

        // set sensor mode
            txBuffer[0] = 0x00;
            txBuffer[1] = 0x18;
            txBuffer[2] = 0x01;
            i2cTransaction.slaveAddress = 0x29;
            i2cTransaction.writeBuf = txBuffer;
            i2cTransaction.readBuf = NULL;
            i2cTransaction.writeCount = 3;
            i2cTransaction.readCount = 0;
            I2C_transfer(i2c2, &i2cTransaction);


        /* Set sensor receive data */
            txBuffer[0] = 0x00;
            txBuffer[1] = 0x62;
            i2cTransaction.slaveAddress = 0x29;
            i2cTransaction.writeBuf = txBuffer;
            i2cTransaction.readBuf = rxBuffer;
            i2cTransaction.writeCount = 2;
            i2cTransaction.readCount = 1;

        /* Take samples and print them out onto the console */
            if (I2C_transfer(i2c2, &i2cTransaction)) {
                range[j+4] = rxBuffer[0];
            }else {
                    System_printf("I2C Bus fault\n");
             }

            System_printf("%d  ", range[j+4]);
            System_flush();
            selectBuffer[0] = selectBuffer[0] << 1;
        }
    System_printf("\n");
    System_flush();
    Task_sleep(10);
}

    /* Deinitialized I2C */

    I2C_close(i2c1);
    I2C_close(i2c2);
    System_printf("I2C closed!\n");

    System_flush();
}

