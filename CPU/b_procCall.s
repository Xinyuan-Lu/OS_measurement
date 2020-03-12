	.file	"b_procCall.c"
	.text
	.globl	NUM_LOOPS
	.data
	.align 4
	.type	NUM_LOOPS, @object
	.size	NUM_LOOPS, 4
NUM_LOOPS:
	.long	100000000
	.text
	.globl	rdtsc
	.type	rdtsc, @function
rdtsc:
.LFB3923:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	rdtsc
	salq	$32, %rdx
	orq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3923:
	.size	rdtsc, .-rdtsc
	.globl	procedure0
	.type	procedure0, @function
procedure0:
.LFB3924:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3924:
	.size	procedure0, .-procedure0
	.globl	procedure1
	.type	procedure1, @function
procedure1:
.LFB3925:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3925:
	.size	procedure1, .-procedure1
	.globl	procedure2
	.type	procedure2, @function
procedure2:
.LFB3926:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3926:
	.size	procedure2, .-procedure2
	.globl	procedure3
	.type	procedure3, @function
procedure3:
.LFB3927:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3927:
	.size	procedure3, .-procedure3
	.globl	procedure4
	.type	procedure4, @function
procedure4:
.LFB3928:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3928:
	.size	procedure4, .-procedure4
	.globl	procedure5
	.type	procedure5, @function
procedure5:
.LFB3929:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	movl	%r8d, -20(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3929:
	.size	procedure5, .-procedure5
	.globl	procedure6
	.type	procedure6, @function
procedure6:
.LFB3930:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	movl	%r8d, -20(%rbp)
	movl	%r9d, -24(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3930:
	.size	procedure6, .-procedure6
	.globl	procedure7
	.type	procedure7, @function
procedure7:
.LFB3931:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	movl	%r8d, -20(%rbp)
	movl	%r9d, -24(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3931:
	.size	procedure7, .-procedure7
	.section	.rodata
	.align 8
.LC0:
	.string	"Procedure Call (0 args): %f cycles\n"
	.text
	.globl	measureProc0
	.type	measureProc0, @function
measureProc0:
.LFB3932:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -16(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L13
.L14:
	movl	$0, %eax
	call	procedure0
	addl	$1, -20(%rbp)
.L13:
	movl	NUM_LOOPS(%rip), %eax
	cmpl	%eax, -20(%rbp)
	jl	.L14
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	testq	%rax, %rax
	js	.L15
	cvtsi2sdq	%rax, %xmm0
	jmp	.L16
.L15:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L16:
	movl	NUM_LOOPS(%rip), %eax
	cvtsi2sd	%eax, %xmm1
	divsd	%xmm1, %xmm0
	leaq	.LC0(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3932:
	.size	measureProc0, .-measureProc0
	.section	.rodata
	.align 8
.LC1:
	.string	"Procedure Call (1 arg): %f cycles\n"
	.text
	.globl	measureProc1
	.type	measureProc1, @function
measureProc1:
.LFB3933:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -16(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L18
.L19:
	movl	$0, %edi
	call	procedure1
	addl	$1, -20(%rbp)
.L18:
	movl	NUM_LOOPS(%rip), %eax
	cmpl	%eax, -20(%rbp)
	jl	.L19
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	testq	%rax, %rax
	js	.L20
	cvtsi2sdq	%rax, %xmm0
	jmp	.L21
.L20:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L21:
	movl	NUM_LOOPS(%rip), %eax
	cvtsi2sd	%eax, %xmm1
	divsd	%xmm1, %xmm0
	leaq	.LC1(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3933:
	.size	measureProc1, .-measureProc1
	.section	.rodata
	.align 8
.LC2:
	.string	"Procedure Call (2 args): %f cycles\n"
	.text
	.globl	measureProc2
	.type	measureProc2, @function
measureProc2:
.LFB3934:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -16(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L23
.L24:
	movl	$0, %esi
	movl	$0, %edi
	call	procedure2
	addl	$1, -20(%rbp)
.L23:
	movl	NUM_LOOPS(%rip), %eax
	cmpl	%eax, -20(%rbp)
	jl	.L24
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	testq	%rax, %rax
	js	.L25
	cvtsi2sdq	%rax, %xmm0
	jmp	.L26
.L25:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L26:
	movl	NUM_LOOPS(%rip), %eax
	cvtsi2sd	%eax, %xmm1
	divsd	%xmm1, %xmm0
	leaq	.LC2(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3934:
	.size	measureProc2, .-measureProc2
	.section	.rodata
	.align 8
.LC3:
	.string	"Procedure Call (3 args): %f cycles\n"
	.text
	.globl	measureProc3
	.type	measureProc3, @function
measureProc3:
.LFB3935:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -16(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L28
.L29:
	movl	$0, %edx
	movl	$0, %esi
	movl	$0, %edi
	call	procedure3
	addl	$1, -20(%rbp)
.L28:
	movl	NUM_LOOPS(%rip), %eax
	cmpl	%eax, -20(%rbp)
	jl	.L29
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	testq	%rax, %rax
	js	.L30
	cvtsi2sdq	%rax, %xmm0
	jmp	.L31
.L30:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L31:
	movl	NUM_LOOPS(%rip), %eax
	cvtsi2sd	%eax, %xmm1
	divsd	%xmm1, %xmm0
	leaq	.LC3(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3935:
	.size	measureProc3, .-measureProc3
	.section	.rodata
	.align 8
.LC4:
	.string	"Procedure Call (4 args): %f cycles\n"
	.text
	.globl	measureProc4
	.type	measureProc4, @function
measureProc4:
.LFB3936:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -16(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L33
.L34:
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$0, %edi
	call	procedure4
	addl	$1, -20(%rbp)
.L33:
	movl	NUM_LOOPS(%rip), %eax
	cmpl	%eax, -20(%rbp)
	jl	.L34
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	testq	%rax, %rax
	js	.L35
	cvtsi2sdq	%rax, %xmm0
	jmp	.L36
.L35:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L36:
	movl	NUM_LOOPS(%rip), %eax
	cvtsi2sd	%eax, %xmm1
	divsd	%xmm1, %xmm0
	leaq	.LC4(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3936:
	.size	measureProc4, .-measureProc4
	.section	.rodata
	.align 8
.LC5:
	.string	"Procedure Call (5 args): %f cycles\n"
	.text
	.globl	measureProc5
	.type	measureProc5, @function
measureProc5:
.LFB3937:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -16(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L38
.L39:
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$0, %edi
	call	procedure5
	addl	$1, -20(%rbp)
.L38:
	movl	NUM_LOOPS(%rip), %eax
	cmpl	%eax, -20(%rbp)
	jl	.L39
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	testq	%rax, %rax
	js	.L40
	cvtsi2sdq	%rax, %xmm0
	jmp	.L41
.L40:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L41:
	movl	NUM_LOOPS(%rip), %eax
	cvtsi2sd	%eax, %xmm1
	divsd	%xmm1, %xmm0
	leaq	.LC5(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3937:
	.size	measureProc5, .-measureProc5
	.section	.rodata
	.align 8
.LC6:
	.string	"Procedure Call (6 args): %f cycles\n"
	.text
	.globl	measureProc6
	.type	measureProc6, @function
measureProc6:
.LFB3938:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -16(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L43
.L44:
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$0, %edi
	call	procedure6
	addl	$1, -20(%rbp)
.L43:
	movl	NUM_LOOPS(%rip), %eax
	cmpl	%eax, -20(%rbp)
	jl	.L44
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	testq	%rax, %rax
	js	.L45
	cvtsi2sdq	%rax, %xmm0
	jmp	.L46
.L45:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L46:
	movl	NUM_LOOPS(%rip), %eax
	cvtsi2sd	%eax, %xmm1
	divsd	%xmm1, %xmm0
	leaq	.LC6(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3938:
	.size	measureProc6, .-measureProc6
	.section	.rodata
	.align 8
.LC7:
	.string	"Procedure Call (7 args): %f cycles\n"
	.text
	.globl	measureProc7
	.type	measureProc7, @function
measureProc7:
.LFB3939:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -16(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L48
.L49:
	pushq	$0
	pushq	$0
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$0, %edi
	call	procedure7
	addq	$24, %rsp
	addl	$1, -20(%rbp)
.L48:
	movl	NUM_LOOPS(%rip), %eax
	cmpl	%eax, -20(%rbp)
	jl	.L49
	movl	$0, %eax
	call	rdtsc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	testq	%rax, %rax
	js	.L50
	cvtsi2sdq	%rax, %xmm0
	jmp	.L51
.L50:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L51:
	movl	NUM_LOOPS(%rip), %eax
	cvtsi2sd	%eax, %xmm1
	divsd	%xmm1, %xmm0
	leaq	.LC7(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3939:
	.size	measureProc7, .-measureProc7
	.globl	measureProcCall
	.type	measureProcCall, @function
measureProcCall:
.LFB3940:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %eax
	call	measureProc0
	movl	$0, %eax
	call	measureProc1
	movl	$0, %eax
	call	measureProc2
	movl	$0, %eax
	call	measureProc3
	movl	$0, %eax
	call	measureProc4
	movl	$0, %eax
	call	measureProc5
	movl	$0, %eax
	call	measureProc6
	movl	$0, %eax
	call	measureProc7
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3940:
	.size	measureProcCall, .-measureProcCall
	.globl	main
	.type	main, @function
main:
.LFB3941:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$0, %eax
	call	measureProcCall
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3941:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
