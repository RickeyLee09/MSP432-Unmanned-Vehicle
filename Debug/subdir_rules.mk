################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
MSP_EXP432P401R.obj: ../MSP_EXP432P401R.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Users/rickey/CSRobot_01_2017/grlib" --include_path="/Users/rickey/CSRobot_01_2017/LCDDriver" --include_path="/Users/rickey/CSRobot_01_2017" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc/CMSIS" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="MSP_EXP432P401R.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Motor.obj: ../Motor.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Users/rickey/CSRobot_01_2017/grlib" --include_path="/Users/rickey/CSRobot_01_2017/LCDDriver" --include_path="/Users/rickey/CSRobot_01_2017" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc/CMSIS" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="Motor.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MotorControl.obj: ../MotorControl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Users/rickey/CSRobot_01_2017/grlib" --include_path="/Users/rickey/CSRobot_01_2017/LCDDriver" --include_path="/Users/rickey/CSRobot_01_2017" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc/CMSIS" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="MotorControl.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

build-640913521:
	@$(MAKE) -Onone -f subdir_rules.mk build-640913521-inproc

build-640913521-inproc: ../Robot.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/Applications/ti/xdctools_3_32_00_06_core/xs" --xdcpath="/Applications/ti/tirtos_msp43x_2_20_00_06/packages;/Applications/ti/tirtos_msp43x_2_20_00_06/products/bios_6_46_00_23/packages;/Applications/ti/tirtos_msp43x_2_20_00_06/products/tidrivers_msp43x_2_20_00_08/packages;/Applications/ti/tirtos_msp43x_2_20_00_06/products/uia_2_00_06_52/packages;/Applications/ti/ccsv7/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M4F -p ti.platforms.msp432:MSP432P401R -r release -c "/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS" --compileOptions "-mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path=\"/Applications/ti/ccsv7/ccs_base/arm/include\" --include_path=\"/Users/rickey/CSRobot_01_2017/grlib\" --include_path=\"/Users/rickey/CSRobot_01_2017/LCDDriver\" --include_path=\"/Users/rickey/CSRobot_01_2017\" --include_path=\"/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc/CMSIS\" --include_path=\"/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc\" --include_path=\"/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx\" --include_path=\"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include\" --include_path=\"/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS\" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi  " "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: build-640913521 ../Robot.cfg
configPkg/compiler.opt: build-640913521
configPkg/: build-640913521

buttons.obj: ../buttons.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Users/rickey/CSRobot_01_2017/grlib" --include_path="/Users/rickey/CSRobot_01_2017/LCDDriver" --include_path="/Users/rickey/CSRobot_01_2017" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc/CMSIS" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="buttons.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

heartBeatTask.obj: ../heartBeatTask.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Users/rickey/CSRobot_01_2017/grlib" --include_path="/Users/rickey/CSRobot_01_2017/LCDDriver" --include_path="/Users/rickey/CSRobot_01_2017" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc/CMSIS" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="heartBeatTask.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Users/rickey/CSRobot_01_2017/grlib" --include_path="/Users/rickey/CSRobot_01_2017/LCDDriver" --include_path="/Users/rickey/CSRobot_01_2017" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc/CMSIS" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="main.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

screenTask.obj: ../screenTask.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Users/rickey/CSRobot_01_2017/grlib" --include_path="/Users/rickey/CSRobot_01_2017/LCDDriver" --include_path="/Users/rickey/CSRobot_01_2017" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc/CMSIS" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="screenTask.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

sensorTask.obj: ../sensorTask.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Users/rickey/CSRobot_01_2017/grlib" --include_path="/Users/rickey/CSRobot_01_2017/LCDDriver" --include_path="/Users/rickey/CSRobot_01_2017" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc/CMSIS" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="sensorTask.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

speedTask.obj: ../speedTask.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Users/rickey/CSRobot_01_2017/grlib" --include_path="/Users/rickey/CSRobot_01_2017/LCDDriver" --include_path="/Users/rickey/CSRobot_01_2017" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc/CMSIS" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="speedTask.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


