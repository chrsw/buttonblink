# buttonblink
Press button to blink LED on NUCLEO-F411

This project is inspired _Bare Metal Embedded C Programming_ . A book 
published by Packt in 2024.

## Requirements
- Windows OS
- MinGW64 (from MSYS2)
- GNU Arm toolchain
- GNU Make
- OpenOCD

## Building
Once all the tools are set up, compile all source files on the command prompt 
(cmd.exe) in Windows with the following commands:
```
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 -Iinc -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE main.c -o main.o
```

```
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 stm32f411_startup.c -o stm32f411_startup.o
```

```
arm-none-eabi-gcc -nostdlib -T stm32_ls.ld *.o -o buttonblink.elf
```

This generates a file `buttonblink.elf`. No Standard C Library required.