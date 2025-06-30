section .text
	global ft_read

	extern __errno_location

ft_read:
	mov	rax, 0
	syscall

	cmp	rax, 0
	jl	.error

.end:
	ret

.error:
	xor	rcx, rcx

	mov	rcx, rax
	neg	rcx

	call	__errno_location wrt ..plt

	mov	[rax], rcx
	mov	rax, -1
	jmp	.end
