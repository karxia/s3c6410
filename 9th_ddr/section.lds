SECTIONS {
	. = 0x00000000;
	
	.text : {
				start.o
				* (.text)
	}
	
	.redata : {
				* (.rodata)
	}

	.data : {
				* (.data)
	}

	__bss_start = .;
	.bass ALIGN(4) : {*(.bss) *(COMMON)}
	__bss_end = .;
}
