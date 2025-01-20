# buttonblink
Press button to blink LED on NUCLEO-F411

This project is inspired by the examples in _Bare Metal Embedded C Programming_ 2024 Packt publishing

## Requirements
- Windows OS
- MinGW64 (from MSYS2)
- GNU Arm toolchain
- GNU Make
- OpenOCD

## Building
Compile main.c in Windows with the follow command:
```
arm-none-eabi-gcc "main.c" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -c -Iinc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"main.d" -MT"main.o" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "main.o"
```
This generates a file `main.o`. Arm GCC Standard C library files still required.