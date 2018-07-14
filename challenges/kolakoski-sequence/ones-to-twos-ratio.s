	.file	"ones-to-twos-ratio.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	"122"
	.text
	.globl	_Z9kolakoskiB5cxx11i
	.type	_Z9kolakoskiB5cxx11i, @function
_Z9kolakoskiB5cxx11i:
.LFB1021:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1021
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movl	%esi, -60(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-35(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev
	leaq	-35(%rbp), %rdx
	movq	-56(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
.LEHB0:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
.LEHE0:
	leaq	-35(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev
	movq	$3, -32(%rbp)
.L11:
	movl	-60(%rbp), %eax
	cltq
	cmpq	-32(%rbp), %rax
	jbe	.L2
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
.LEHB1:
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv
	movq	%rax, %rdx
	movl	-60(%rbp), %eax
	cltq
	cmpq	%rax, %rdx
	jnb	.L2
	movl	$1, %eax
	jmp	.L3
.L2:
	movl	$0, %eax
.L3:
	testb	%al, %al
	je	.L18
	movq	-32(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	movb	%al, -33(%rbp)
	movb	$48, -34(%rbp)
.L10:
	movzbl	-34(%rbp), %eax
	cmpb	-33(%rbp), %al
	jge	.L5
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv
	movq	%rax, %rdx
	movl	-60(%rbp), %eax
	cltq
	cmpq	%rax, %rdx
	jnb	.L5
	movl	$1, %eax
	jmp	.L6
.L5:
	movl	$0, %eax
.L6:
	testb	%al, %al
	je	.L7
	movq	-32(%rbp), %rax
	andl	$1, %eax
	testq	%rax, %rax
	je	.L8
	movl	$49, %edx
	jmp	.L9
.L8:
	movl	$50, %edx
.L9:
	movq	-56(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLEc
.LEHE1:
	movzbl	-34(%rbp), %eax
	addl	$1, %eax
	movb	%al, -34(%rbp)
	jmp	.L10
.L7:
	addq	$1, -32(%rbp)
	jmp	.L11
.L16:
	movq	%rax, %rbx
	leaq	-35(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
.L17:
	movq	%rax, %rbx
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB3:
	call	_Unwind_Resume
.LEHE3:
.L18:
	nop
	movq	-56(%rbp), %rax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L15
	call	__stack_chk_fail
.L15:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1021:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1021:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1021-.LLSDACSB1021
.LLSDACSB1021:
	.uleb128 .LEHB0-.LFB1021
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L16-.LFB1021
	.uleb128 0
	.uleb128 .LEHB1-.LFB1021
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L17-.LFB1021
	.uleb128 0
	.uleb128 .LEHB2-.LFB1021
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB3-.LFB1021
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE1021:
	.text
	.size	_Z9kolakoskiB5cxx11i, .-_Z9kolakoskiB5cxx11i
	.section	.rodata
.LC1:
	.string	":"
.LC2:
	.string	"\n"
	.text
	.globl	_Z10printRatioNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.type	_Z10printRatioNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_Z10printRatioNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB1022:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -16(%rbp)
	movl	$0, -12(%rbp)
	movq	$0, -8(%rbp)
.L23:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv
	cmpq	-8(%rbp), %rax
	seta	%al
	testb	%al, %al
	je	.L20
	movq	-8(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
	movzbl	(%rax), %eax
	cmpb	$49, %al
	sete	%al
	testb	%al, %al
	je	.L21
	addl	$1, -16(%rbp)
	jmp	.L22
.L21:
	addl	$1, -12(%rbp)
.L22:
	addq	$1, -8(%rbp)
	jmp	.L23
.L20:
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEi
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi
	movl	$.LC2, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1022:
	.size	_Z10printRatioNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_Z10printRatioNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.section	.rodata
.LC3:
	.string	""
	.align 8
.LC4:
	.string	"Enter the desired length of your Kolakoski sequence\n"
.LC5:
	.string	"Here is the sequence: \n"
.LC6:
	.string	"Here is the ratio 1s:2s: \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1023:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1023
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$168, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-164(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev
	leaq	-164(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movl	$.LC3, %esi
	movq	%rax, %rdi
.LEHB4:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
.LEHE4:
	leaq	-164(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev
	leaq	-164(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev
	leaq	-164(%rbp), %rdx
	leaq	-128(%rbp), %rax
	movl	$.LC3, %esi
	movq	%rax, %rdi
.LEHB5:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
.LEHE5:
	leaq	-164(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev
	movl	$.LC4, %esi
	movl	$_ZSt4cout, %edi
.LEHB6:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-164(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt3cin, %edi
	call	_ZNSirsERi
	movl	-164(%rbp), %edx
	leaq	-96(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_Z9kolakoskiB5cxx11i
.LEHE6:
	leaq	-96(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB7:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_
.LEHE7:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
.LEHB8:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	$.LC5, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movl	$.LC2, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$.LC6, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-160(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_
.LEHE8:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
.LEHB9:
	call	_Z10printRatioNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.LEHE9:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
.LEHB10:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.LEHE10:
	leaq	-128(%rbp), %rax
	movq	%rax, %rdi
.LEHB11:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.LEHE11:
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
.LEHB12:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	$0, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L32
	jmp	.L39
.L33:
	movq	%rax, %rbx
	leaq	-164(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume
.LEHE12:
.L34:
	movq	%rax, %rbx
	leaq	-164(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev
	jmp	.L28
.L37:
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	.L30
.L38:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	.L30
.L36:
	movq	%rax, %rbx
.L30:
	leaq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	.L28
.L35:
	movq	%rax, %rbx
.L28:
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB13:
	call	_Unwind_Resume
.LEHE13:
.L39:
	call	__stack_chk_fail
.L32:
	addq	$168, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1023:
	.section	.gcc_except_table
.LLSDA1023:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1023-.LLSDACSB1023
.LLSDACSB1023:
	.uleb128 .LEHB4-.LFB1023
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L33-.LFB1023
	.uleb128 0
	.uleb128 .LEHB5-.LFB1023
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L34-.LFB1023
	.uleb128 0
	.uleb128 .LEHB6-.LFB1023
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L36-.LFB1023
	.uleb128 0
	.uleb128 .LEHB7-.LFB1023
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L37-.LFB1023
	.uleb128 0
	.uleb128 .LEHB8-.LFB1023
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L36-.LFB1023
	.uleb128 0
	.uleb128 .LEHB9-.LFB1023
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L38-.LFB1023
	.uleb128 0
	.uleb128 .LEHB10-.LFB1023
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L36-.LFB1023
	.uleb128 0
	.uleb128 .LEHB11-.LFB1023
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L35-.LFB1023
	.uleb128 0
	.uleb128 .LEHB12-.LFB1023
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB13-.LFB1023
	.uleb128 .LEHE13-.LEHB13
	.uleb128 0
	.uleb128 0
.LLSDACSE1023:
	.text
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1101:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L42
	cmpl	$65535, -8(%rbp)
	jne	.L42
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L42:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1101:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z9kolakoskiB5cxx11i, @function
_GLOBAL__sub_I__Z9kolakoskiB5cxx11i:
.LFB1102:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1102:
	.size	_GLOBAL__sub_I__Z9kolakoskiB5cxx11i, .-_GLOBAL__sub_I__Z9kolakoskiB5cxx11i
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z9kolakoskiB5cxx11i
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
