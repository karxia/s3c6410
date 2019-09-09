led.bin : start.o led.o
	arm-none-eabi-ld -T leds.lds -o led.elf start.o led.o
	arm-none-eabi-objcopy -O binary led.elf led.bin
	arm-none-eabi-objdump -D led.elf > led.dis

start.o : start.S
	arm-none-eabi-gcc -o start.o start.S -C

led.o : led.c
	arm-none-eabi-gcc -o led.o led.c -c

clean:
	rm *.o led.elf led.bin led.dis -f
 
