INCLUDEDIR := $(shell pwd)/include
INCLUDEDIR += $(shell pwd)/arch/include



CPPFLAGS := -nostdinc $(addprefix -I,$(INCLUDEDIR))

app6410.bin : start.o clock.o  led.o
	arm-none-eabi-ld -Ttext 0x00000000 -o app6410.elf start.o clock.o  led.o
	arm-none-eabi-objcopy -O binary app6410.elf app6410.bin
	arm-none-eabi-objdump -D app6410.elf > app6410.dis

start.o : ~/work/app_6410/6th_clock/arch/cpu/start.S
	arm-none-eabi-gcc $(CPPFLAGS)  -c ./arch/cpu/start.S -o start.o
clock.o : ~/work/app_6410/6th_clock/driver/clock/clock.c
	arm-none-eabi-gcc $(CPPFLAGS)  -c ./driver/clock/clock.c -o clock.o

led.o : ~/work/app_6410/6th_clock/driver/led/led.c
	arm-none-eabi-gcc $(CPPFLAGS)  -c ./driver/led/led.c -o led.o


clean:
	rm *.o *.elf *.bin *.dis 
