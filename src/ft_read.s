.text:
	global ft_read

	extern __errno_location

ft_read:
	push	rbp
	mov	rbp, rsp

	mov	rax, 0
	syscall

	cmp	rax, 0
	jl	.error

.end:
	pop	rbp
	ret

.error:
	xor	rcx, rcx

	mov	rcx, rax
	neg	rcx

	call	__errno_location wrt ..plt

	mov	[rax], rcx
	mov	rax, -1
	jmp	.end
