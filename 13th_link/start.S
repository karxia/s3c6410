.globl _start
_start:

/* Peri port setup */
	ldr	 	r0, =0x70000000
	orr 	r0, r0, #0x13
	mcr 	P15, 0, r0, c15, c2, 4

/* close the watchdog*/
	ldr 	r0, =0x7E004000
	mov 	r1, #0
	str 	r1, [r0]

/* remap */
	adr 	r0, _start
	ldr 	r1, =_start
	ldr 	r2, =bss_start
	cmp 	r0, r1
	beq 	clean_bss

copy_loop:
	ldr 	r3, [r0], #4
	str 	r3, [r1], #4
	cmp 	r1, r2
	bne  	copy_loop

