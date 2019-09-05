led.bin: start.o
	arm-none-eabi-ld -Ttext 0 -o led.elf start.o
	arm-none-eabi-objcopy -O binary led.elf led.bin
	arm-none-eabi-objdump -D led.elf > led.dis

start.o : start.S
	arm-none-eabi-gcc -o start.o start.S -c

clean:
	rm *.o led.elf led.bin led.dis

