.arch armv8-a
.file	"sum.c"
.text
.align	2
.global	sum
.type	sum, %function
sum:
.LFB0:
	.cfi_startproc
	sub	sp, sp, #32	// allocate stack frame
	.cfi_def_cfa_offset 32

	/* Upon entry, the long function parameter is in register x0
	   End with the long function return value in register x0

	   Use the following stack offsets for your local variables:
	   [sp, 8]  - long n, the function parameter
	   [sp, 16] - long res
	   [sp, 24] - long i
	*/

	//=====================================
	// TODO: begin your assembly code here

	// store n 
	str x0, [sp, 8]

	// initialize and store res = 0
	mov x1, #0
	str x1, [sp, 16]

	// initialize i = 1 and store
	mov x2, #1
	str x2, [sp, 24]

	// if n <= 0, return -1
	ldr x0, [sp, 8]
	cmp x0, #0
	ble EndWithMinusOne

Loop:
	// Load i into x2
	ldr x2, [sp, 24]

	// Load n into x0
	ldr x0, [sp, 8]

	// Compare i and n
	cmp x2, x0
	bgt End  // If i > n, exit loop

	// Load res into x1
	ldr x1, [sp, 16]

	// res = res + i
	add x1, x1, x2

	// Store updated res back to [sp, 16]
	str x1, [sp, 16]

	// Increment i by 1
	add x2, x2, #1

	// Store updated i back to [sp, 24]
	str x2, [sp, 24]

	// Repeat the loop
	b Loop

End:
	// Load the result res into x0 (return value)
	ldr x0, [sp, 16]
	add	sp, sp, #32	// deallocate stack frame
	.cfi_def_cfa_offset 0
	ret

EndWithMinusOne:
	// Return -1 if n <= 0
	mov x0, #-1
	add	sp, sp, #32	// deallocate stack frame
	ret

	//=====================================
	// TODO: end your assembly code here
	//=====================================

	.cfi_endproc
.LFE0:
	.size	sum, .-sum
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
