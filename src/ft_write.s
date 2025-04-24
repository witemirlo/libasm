.text:
	global ft_write

ft_write:
	push	rbx
	mov	rbx, rsp

	; call	___error
	; mov	[rax], 42

	mov	rax, 1
	syscall

_endl:
	pop	rbx
	ret
