.globl _start
_start:
	
/* Peripheral port setup*/
	ldr 	r0, =0x70000000
	orr 	r0, r0, #0x13
	mcr 	p15, 0, r0, c15, c2, 4

/* close the watchdog*/
	ldr 	r0, =0x7E004000
	mov 	r1, #0
	str 	r1, [r0]


//	ldr 	sp, =8*1024
	bl 		led_function

halt:
	b	halt

