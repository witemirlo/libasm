section .text
	global ft_write

	extern __errno_location

ft_write:
	mov	rax, 1
	syscall

	cmp	rax, 0
	jl	.error

.end:
	ret

.error:
	xor	rcx, rcx

	mov	rcx, rax ; save error from syscall
	neg	rcx
	
	call	__errno_location wrt ..plt

	mov	[rax], rcx
	mov	rax, -1
	jmp	.end
