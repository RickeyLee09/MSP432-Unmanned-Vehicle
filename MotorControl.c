/*
 * MotorControl.c
 *
 *  Created on: 2017年10月25日
 *      Author: Rickey
 */

/* XDCtools Header files */
#include "stdint.h"
#include <math.h>
#include<time.h>
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/PWM.h>

/* Example/Board Header files */
#include "Board.h"
#include "Robot.h"
#include "sensorTask.h"

extern uint32_t RHMotorState;
extern uint32_t LHMotorState;
//extern uint16_t range[8];
//uint32_t prevRHMotorState = 0;
//uint32_t prevLHMotorState = 0;
extern uint32_t Rdistance, Ldistance, Rspeed, Lspeed;
extern uint8_t state;

PWM_Handle pwm1, pwm2, pwm3, pwm4;
PWM_Params params;
uint16_t   pwmPeriod = 3000;      // Period and duty in microseconds
uint16_t   dutyInc = 100;

//initiate duty value
uint16_t    duty1=0;
uint16_t    duty2=0;
uint16_t    duty3=0;
uint16_t    duty4=0;

//UInt32 timer1, timer2;
UInt32 start, end, count_time;

int duty = 530;
int count = 0;
float v;
int flag;  //flag 1: left wall
           //flag 2: right wall

int previous_error_left=0;
int previous_error_right;
int error_left=0;
int error_right;
float integral_left=0;
float integral_right;
float derivative_left=0;
float derivative_right;
clock_t start, end;
//clock_t count_time = 0;

//PID Control for left wheel
int PIDControllerLeft(uint32_t input, uint32_t setpoint, float kp, float ki, float kd){
    error_left = setpoint - input;
    integral_left = integral_left + error_left;
    derivative_left = error_left - previous_error_left;
    int output = kp * error_left + ki * integral_left + kd * derivative_left;
    previous_error_left = error_left;

    return output;
}

//PID Control for right wheel
int PIDControllerRight(uint32_t input, int setpoint, float kp, float ki, float kd) {
    error_right = setpoint - input;
    integral_right = integral_right + error_right;
    derivative_right = error_right - previous_error_right;
    int output = kp * error_right + ki * integral_right + kd * derivative_right;
    previous_error_right = error_right;

    return output;
}


Void MotorControlTaskFxn(UArg arg0, UArg arg1)
{

    PWM_Params_init(&params);
    params.dutyUnits = PWM_DUTY_US;
    params.dutyValue = 0;
    params.periodUnits = PWM_PERIOD_US;
    params.periodValue = pwmPeriod;
    pwm1 = PWM_open(Board_PWM0, &params);
    pwm2 = PWM_open(Board_PWM1, &params);
    pwm3 = PWM_open(Board_PWM2, &params);
    pwm4 = PWM_open(Board_PWM3, &params);

    if (pwm1 == NULL) {
        System_abort("Board_PWM0 did not open");
    }
    PWM_start(pwm1);

    if (pwm2 == NULL) {
            System_abort("Board_PWM1 did not open");
    }
    PWM_start(pwm2);

    if (pwm3 == NULL) {
        System_abort("Board_PWM2 did not open");
        }
    PWM_start(pwm3);

    if (pwm4 == NULL) {
        System_abort("Board_PWM3 did not open");
    }
    PWM_start(pwm4);

    duty1 = 0;
    duty2 = 500; //right wheel
    duty3 = 0;
    duty4 = 500; //left wheel

    PWM_setDuty(pwm1, duty1);
    PWM_setDuty(pwm2, duty2);
    PWM_setDuty(pwm3, duty3);
    PWM_setDuty(pwm4, duty4);


    while (1) {
        //Start situation
        if(state == 0){
            stop();
        }

        //
//        if(state ==1){  //Go Straight
////            if((range[0]<30)||(range[1]<30)||(range[2]<30)||(range[3]<30)||(range[4]<30)||(range[5]<30)||(range[6]<30)||(range[7]<30)){
//                forward();
//        }

        if(state == 1){
            start=Clock_getTicks();
            duty4 = duty4 + PIDControllerLeft(Lspeed, 170, 0.2, 0.005, -0.3);
            double x = 5;
            double y = 2;
            double width = 0.08;
            double r1, r2, h2, cos_theta2, theta2, a1, a2, v_out, pwm;
            double d_inner = 0;
            double d_outer = 0;

            r1 = sqrt(x * x + y * y);
            r2 = r1 + 0.1;
            h2 = sqrt((x + width) * (x + width) + (y + width) * (y + width));
            cos_theta2 = (2 * r2 * r2 - h2 * h2) / (2 * r2 * r2);
            theta2 = acos(cos_theta2);
            a1 = (r1 * 3.1415926) / 3;
            a2 = r2 * theta2;
            v_out = (10 * a2) / a1;
            pwm = (20 * v_out - 30)-0.87;

            while(count_time<54000){
                duty4 = duty4 + PIDControllerLeft(Lspeed, 170, 0.2, 0.005, -0.3);
                duty2 = duty2 + PIDControllerRight(Rspeed, pwm, 0.2, 0.01, -0.2);
                PWM_setDuty(pwm1, duty1);
                PWM_setDuty(pwm2, duty2);
                PWM_setDuty(pwm3, duty3);
                PWM_setDuty(pwm4, duty4);
                Task_sleep(50);

                end=Clock_getTicks();
                count_time = end - start;
            }
                count_time = 60000;
                stop();

        }

        if(state == 2){     //Wall Following
            //left wall
                if (((range[4])>range[7])&&(range[5]>254)){
                    right_slight();
                }else if(((range[4])<range[7])&&(range[5]>254)){
                    left_slight();
                }else{
                    forward();
                }
                if((range[5]<80)&&(range[0]>(range[7]+20))){
                    right_limit();
                    Task_sleep(300);
                }

                if((range[6]>254)&&(range[4]<150)){
                    flag = 1;
                }
                if((range[6]>254)&&(range[4]>254)&&(flag==1)){
                    left_limit();
                    Task_sleep(500);
                }

            //right wall
                if (((range[3]-10)>range[0])&&(range[2]>254)){
                   left_slight();
                }else if(((range[3]-10)<range[0])&&(range[2]>254)){
                   right_slight();
                }else{
                   forward();
                }

                if ((range[2]<60)&&(range[7]>(range[0]+20))){
                   left_limit();
                   Task_sleep(300);
                }

                if((range[1]>250)&&(range[3]<150)){
                    flag = 2;
                }
                if((range[1]>250)&&(range[3]>250)&&(flag==2)){
                    right_limit();
                    Task_sleep(500);
                }
        }




    }
}

void forward(){
    //duty2 = duty2 + PIDControllerRight(Rspeed, 80, 0.2, 0.005, -0.3);
    //duty4 = duty4 + PIDControllerLeft(Lspeed, 80, 0.2, 0.01, -0.2);

    PWM_setDuty(pwm1, duty1);
    PWM_setDuty(pwm2, duty);
    PWM_setDuty(pwm3, duty3);
    PWM_setDuty(pwm4, duty);

    Task_sleep(50);
}

void left(){
    //duty2 = duty2 + PIDControllerRight(Rspeed, 80, 0.2, 0.01, -0.3);
    //duty4 = duty4 + PIDControllerLeft(Lspeed, 10, 0.2, 0.01, -0.3);

    PWM_setDuty(pwm1, duty1);
    PWM_setDuty(pwm2, duty);
    PWM_setDuty(pwm3, duty3);
    PWM_setDuty(pwm4, 100);

    Task_sleep(50);
}

void left_limit(){
    //duty2 = duty2 + PIDControllerRight(Rspeed, 80, 0.2, 0.01, -0.3);
    //duty4 = duty4 + PIDControllerLeft(Lspeed, 10, 0.2, 0.01, -0.3);

    PWM_setDuty(pwm1, duty1);
    PWM_setDuty(pwm2, duty);
    PWM_setDuty(pwm3, duty3);
    PWM_setDuty(pwm4, 0);

    Task_sleep(50);
}

void left_slight(){
    //duty2 = duty2 + PIDControllerRight(Rspeed, 80, 0.2, 0.01, -0.3);
    //duty4 = duty4 + PIDControllerLeft(Lspeed, 70, 0.2, 0.01, -0.3);

    PWM_setDuty(pwm1, duty1);
    PWM_setDuty(pwm2, duty);
    PWM_setDuty(pwm3, duty3);
    PWM_setDuty(pwm4, duty-100);

    Task_sleep(10);
}

void right(){
    //duty2 = duty2 + PIDControllerRight(Rspeed, 10, 0.2, 0.01, -0.3);
    //duty4 = duty4 + PIDControllerLeft(Lspeed, 80, 0.2, 0.01, -0.3);

    PWM_setDuty(pwm1, duty1);
    PWM_setDuty(pwm2, 50);
    PWM_setDuty(pwm3, duty3);
    PWM_setDuty(pwm4, duty);

    Task_sleep(50);
}

void right_limit(){
    //duty2 = duty2 + PIDControllerRight(Rspeed, 0, 0.2, 0.01, -0.3);
    //duty4 = duty4 + PIDControllerLeft(Lspeed, 80, 0.2, 0.01, -0.3);

    PWM_setDuty(pwm1, duty1);
    PWM_setDuty(pwm2, 0);
    PWM_setDuty(pwm3, duty3);
    PWM_setDuty(pwm4, duty);

    Task_sleep(50);
}

void right_slight(){
    //duty2 = duty2 + PIDControllerRight(Rspeed, 70, 0.2, 0.01, -0.3);
    //duty4 = duty4 + PIDControllerLeft(Lspeed, 80, 0.2, 0.01, -0.3);

    PWM_setDuty(pwm1, duty1);
    PWM_setDuty(pwm2, duty-100);
    PWM_setDuty(pwm3, duty3);
    PWM_setDuty(pwm4, duty);

    Task_sleep(10);
}

void stop(){
    PWM_setDuty(pwm1, duty1);
    PWM_setDuty(pwm2, 0);
    PWM_setDuty(pwm3, duty3);
    PWM_setDuty(pwm4, 0);
    Task_sleep(50);
}
