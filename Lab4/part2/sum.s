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
	str x0,[sp,8]

// initialize and store 0
	mov x1, #0

	str x1,[sp,16]

	//initialize i and store
	mov x1, #1
	str x2,[sp, 24]

	// if n <= 0
Loop:
    // Load i into x2
    ldr x2, [sp, 24]

    // Load n into x0
    ldr x0, [sp, 8]

    // Compare i and n
    cmp x2, x0
    bgt END  // If i > n, exit loop

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

	ldr x0,[sp, 16]






	// TODO: end your assembly code here
	//=====================================

	add	sp, sp, 32	// deallocate stack frame
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	sum, .-sum
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
