################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
library/headers/include/%.obj: ../library/headers/include/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt -Ooff --include_path="D:/ti/workspace/blinkLed" --include_path="D:/ti/ccs1210/C2000Ware_4_02_00_00/device_support/f2802x" --include_path="D:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="D:/ti/workspace/blinkLed/library/headers/include" --include_path="D:/ti/workspace/blinkLed/library/common/include" --include_path="D:/ti/workspace/blinkLed/library/IQmath" --advice:performance=all -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="library/headers/include/$(basename $(<F)).d_raw" --obj_directory="library/headers/include" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


