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

## Installing Requirements

- Install the GNU Arm Embedded Toolchain https://developer.arm.com/downloads/-/gnu-rm
  - Use default settings (but make sure "Add path to environment variable" is checked).
- Install OpenOCD https://openocd.org/pages/getting-openocd.html
  - Get xpack version
  - Add executable to Windows path
  
This should build on Linux or macOS but the installation and tool instructions will vary.

## Building
Once all the tools are set up, compile all source files on the command prompt 
(cmd.exe) in Windows with the following commands:
```
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 -Iinc -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE buttonblink.c -o buttonblink.o
```

```
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 -Iinc -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE gpio.c -o gpio.o
```

```
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 -Iinc -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE systick.c -o systick.o
```

```
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 stm32f411_startup.c -o stm32f411_startup.o
```

```
arm-none-eabi-gcc -nostdlib -T stm32_ls.ld *.o -o buttonblink.elf
```

This generates a file `buttonblink.elf`. No Standard C Library required.

## Running
To run the application connect the board to the PC and run these commands.

Start OpenOCD:
```
openocd -f board/st_nucleo_f4.cfg
```

Start GDB in another command window:
```
arm-none-eabi-gdb
```

Connect to the OpenOCD server (in the GDB session):
```
target remote localhost:3333
```

Flash target:
```
monitor reset init
monitor flash write_image erase buttonblink.elf
```

Restart target:
```
monitor reset init
monitor resume
```

## Shutdown
These commands will quit the debug session. Run these commands in the (gdb) prompt:
```
monitor shutdown
disconnect
quit
```
