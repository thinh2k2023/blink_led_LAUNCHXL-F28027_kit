################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Example_2802xGpioToggle.obj: D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/examples/structs/gpio_toggle/Example_2802xGpioToggle.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt -O3 --include_path="D:/ti/workspace/blinkLed" --include_path="D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/headers/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/libraries/math/IQmath/c28/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2802x_GlobalVariableDefs.obj: D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/headers/source/F2802x_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt -O3 --include_path="D:/ti/workspace/blinkLed" --include_path="D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/headers/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/libraries/math/IQmath/c28/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_codestartbranch.obj: D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/source/f2802x_codestartbranch.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt -O3 --include_path="D:/ti/workspace/blinkLed" --include_path="D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/headers/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/libraries/math/IQmath/c28/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_defaultisr.obj: D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/source/f2802x_defaultisr.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt -O3 --include_path="D:/ti/workspace/blinkLed" --include_path="D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/headers/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/libraries/math/IQmath/c28/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_piectrl.obj: D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/source/f2802x_piectrl.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt -O3 --include_path="D:/ti/workspace/blinkLed" --include_path="D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/headers/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/libraries/math/IQmath/c28/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_pievect.obj: D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/source/f2802x_pievect.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt -O3 --include_path="D:/ti/workspace/blinkLed" --include_path="D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/headers/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/libraries/math/IQmath/c28/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_sysctrl.obj: D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/source/f2802x_sysctrl.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt -O3 --include_path="D:/ti/workspace/blinkLed" --include_path="D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/headers/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/libraries/math/IQmath/c28/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2802x_usdelay.obj: D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/source/f2802x_usdelay.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt -O3 --include_path="D:/ti/workspace/blinkLed" --include_path="D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/common/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x/headers/include" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/libraries/math/IQmath/c28/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


