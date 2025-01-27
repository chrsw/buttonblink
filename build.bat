arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 -Iinc -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE buttonblink.c -o buttonblink.o
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 -Iinc -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE gpio.c -o gpio.o
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 -Iinc -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE systick.c -o systick.o
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 -Iinc -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE tim.c -o tim.o
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE stm32f411_startup.c -o stm32f411_startup.o
arm-none-eabi-gcc -nostdlib -T stm32_ls.ld *.o -o buttonblink.elf