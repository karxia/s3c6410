CC		= arm-none-eabi-gcc
LD 		= arm-none-eabi-ld
AR		= arm-none-eabi-ar
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP	= arm-none-eabi-objdump




INCLUDEDIR 	:= $(shell pwd)/include
INCLUDEDIR 	+= $(shell pwd)/arch/include
CRNT_DIR    := $(shell pwd)

CFLAGS		:= -Wall -Os -fno-builtin-printf -fno-builtin-putc -fno-builtin-putchar


CPPFLAGS 	:= -nostdinc $(addprefix -I,$(INCLUDEDIR))

export CC AR LD OBJCOPY  OBJDUMP INCLUDEDIR CFLAGS  CPPFLAGS 

objs		:=  start.o clock.o  led.o uart.o main.o lib/libc.a

app6410.bin : $(objs)
	${LD} -Tsection.lds  -o 8th_uart.elf $^
	${OBJCOPY} -O binary -S 8th_uart.elf $@
	${OBJCOPY} -D 8th_uart.elf > 8th_uart.dis

.PHONY : lib/libc.a
lib/libc.a:
	cd lib; make; cd ..



start.o : $(CRNT_DIR)/arch/cpu/start.S
	arm-none-eabi-gcc $(CPPFLAGS) $(CFLAGS) -c $(CRNT_DIR)/arch/cpu/start.S -o start.o
clock.o : $(CRNT_DIR)/driver/clock/clock.c
	arm-none-eabi-gcc $(CPPFLAGS) $(CFLAGS) -c $(CRNT_DIR)/driver/clock/clock.c -o clock.o

led.o : $(CRNT_DIR)/driver/led/led.c
	arm-none-eabi-gcc $(CPPFLAGS) $(CFLAGS) -c $(CRNT_DIR)/driver/led/led.c -o led.o
uart.o : $(CRNT_DIR)/driver/uart/uart.c
	arm-none-eabi-gcc $(CPPFLAGS) $(CFLAGS) -c $(CRNT_DIR)/driver/uart/uart.c -o uart.o
main.o : $(CRNT_DIR)/main.c
	arm-none-eabi-gcc $(CPPFLAGS) $(CFLAFS) -c $(CRNT_DIR)/main.c -o main.o

clean:
	make clean -C lib
	rm -rf *.o *.dis *.bin *.dis

