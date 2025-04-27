.text:
	global ft_read

	extern __errno_location

ft_read:
	push	rbp
	mov	rbp, rsp

	mov	rax, 0
	syscall

	cmp	rax, 0
	jl	_error

_end:
	pop	rbp
	ret

_error:
	xor	rcx, rcx

	mov	rcx, rax
	neg	rcx

	call	__errno_location

	mov	[rax], rcx
	mov	rax, -1
	jmp	_end
