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

/* set the GPKCON as the output pin */
	ldr 	r1, =0x7F008800
	ldr  	r0, =#0x11110000
	str 	r0, [r1]
	
/* set the GPK3 0 */
	ldr 	r1, =0x7F008808
	mov 	r0, #0
	str 	r0, [r1]

loop:
	str 	r0, [r1]
	add 	r0, r0, #10
	cmp 	r0, #0xF0
	moveq 	r0, #0
	bl 	delay
	b 	loop

delay:
	mov 	r2, #0x10000000
delay_loop:
	sub r2, r2, #1
	cmp r2, #0
	bne delay_loop
	mov pc, lr

halt:
	b	halt

