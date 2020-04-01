app6410.bin : start.o clock.o
	arm-none-eabi-ld -Ttext 0 -o app6410.elf start.o clock.o
	arm-none-eabi-objcopy -O binary app6410.elf app6410.bin
	arm-none-eabi-objdump -D app6410.elf > lde.dis

start.o : ~/work/app_6410/6th_clock/arch/cpu/start.S
	arm-none-eabi-gcc  -c /home/dl/work/app_6410/6th_clock/arch/cpu/start.S -o start.o
clock.o : ~/work/app_6410/6th_clock/driver/clock/clock.c
	arm-none-eabi-gcc -c ./driver/clock/clock.c -o clock.o

clean:
	rm *.o *.elf *.bin *.dis 
