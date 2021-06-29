.globl _start
_start:

/*hardware setting*/
/*Peri port setup */
	ldr 	r0, =0x70000000
	orr 	r0, r0, #0x13
	mcr 	P15, 0, r0, c15, c2, 4

/*close the watchdog*/
	ldr 	r0, =0x7e004000
	mov 	r1, #0
	str 	r1, [r0]

/*setting buffer*/
	ldr sp, =8*1024

/*setting clock*/

	bl 	clock_init
	bl  led_init
	bl  uart0_init

//	bl 	main

halt:
	b 	halt

