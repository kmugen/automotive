################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../scheduler/AppScheduling.c \
../scheduler/driver_stm.c 

COMPILED_SRCS += \
./scheduler/AppScheduling.src \
./scheduler/driver_stm.src 

C_DEPS += \
./scheduler/AppScheduling.d \
./scheduler/driver_stm.d 

OBJS += \
./scheduler/AppScheduling.o \
./scheduler/driver_stm.o 


# Each subdirectory must supply rules for building sources it contributes
scheduler/%.src: ../scheduler/%.c scheduler/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/myTC275/automotive/tmp/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/scheduler\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

scheduler/AppScheduling.o: ./scheduler/AppScheduling.src scheduler/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

scheduler/driver_stm.o: ./scheduler/driver_stm.src scheduler/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-scheduler

clean-scheduler:
	-$(RM) ./scheduler/AppScheduling.d ./scheduler/AppScheduling.o ./scheduler/AppScheduling.src ./scheduler/driver_stm.d ./scheduler/driver_stm.o ./scheduler/driver_stm.src

.PHONY: clean-scheduler

