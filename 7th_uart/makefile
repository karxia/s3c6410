INCLUDEDIR := $(shell pwd)/include
INCLUDEDIR += $(shell pwd)/arch/include



CPPFLAGS := -nostdinc $(addprefix -I,$(INCLUDEDIR))

app6410.bin : start.o clock.o uart.o
	arm-none-eabi-ld -Ttext 0 -o app6410.elf start.o clock.o uart.o
	arm-none-eabi-objcopy -O binary app6410.elf app6410.bin
	arm-none-eabi-objdump -D app6410.elf > lde.dis

start.o : ~/work/app_6410/7th_uart/arch/cpu/start.S
	arm-none-eabi-gcc $(CPPFLAGS)  -c ./arch/cpu/start.S -o start.o

clock.o : ~/work/app_6410/7th_uart/driver/clock/clock.c
	arm-none-eabi-gcc $(CPPFLAGS)  -c ./driver/clock/clock.c -o clock.o

uart.o : ~/work/app_6410/7th_uart/driver/uart/uart.c
	arm-none-eabi-gcc $(CPPFLAGS) -c ./driver/uart/uart.c -o uart.o

clean:
	rm *.o *.elf *.bin *.dis 
