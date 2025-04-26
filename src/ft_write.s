.text:
	global ft_write

	extern __errno_location

ft_write:
	push	rbp
	mov	rbp, rsp
	
	mov	rax, 1
	syscall

	cmp	rax, -1
	jg	_end

_error:
	xor	rcx, rcx

	mov	rcx, rax ; save error from syscall
	neg	rcx
	
	call	__errno_location

	mov	[rax], rcx
	mov	rax, -1

_end:
	pop	rbp
	ret
