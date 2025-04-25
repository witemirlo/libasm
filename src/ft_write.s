.text:
	global ft_write
	extern __errno_location

ft_write:
	push	rbx
	mov	rbx, rsp
	
	xor	rax, rax

	mov	rax, 1
	syscall

	; jmp	_end; debug
	cmp	rax, 0
	jb	_end ; no esta haciendo lo que toca

_error:
	xor	rcx, rcx

	mov	rcx, rax ; save error from syscall
	neg	rcx
	
	call	__errno_location
	mov	[rax], rcx
	mov	rax, -1

_end:
	pop	rbx
	ret
