################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/app/scheduler/AppScheduling.c \
../src/app/scheduler/driver_stm.c 

COMPILED_SRCS += \
./src/app/scheduler/AppScheduling.src \
./src/app/scheduler/driver_stm.src 

C_DEPS += \
./src/app/scheduler/AppScheduling.d \
./src/app/scheduler/driver_stm.d 

OBJS += \
./src/app/scheduler/AppScheduling.o \
./src/app/scheduler/driver_stm.o 


# Each subdirectory must supply rules for building sources it contributes
src/app/scheduler/%.src: ../src/app/scheduler/%.c src/app/scheduler/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/myTC275/automotive/tmp/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/src\/app\/scheduler\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

src/app/scheduler/AppScheduling.o: ./src/app/scheduler/AppScheduling.src src/app/scheduler/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/app/scheduler/driver_stm.o: ./src/app/scheduler/driver_stm.src src/app/scheduler/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-app-2f-scheduler

clean-src-2f-app-2f-scheduler:
	-$(RM) ./src/app/scheduler/AppScheduling.d ./src/app/scheduler/AppScheduling.o ./src/app/scheduler/AppScheduling.src ./src/app/scheduler/driver_stm.d ./src/app/scheduler/driver_stm.o ./src/app/scheduler/driver_stm.src

.PHONY: clean-src-2f-app-2f-scheduler

