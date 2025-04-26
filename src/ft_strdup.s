.text:
	global ft_strdup

	extern ft_strlen
	extern ft_strcpy

	extern malloc
	extern __errno_location

ft_strdup:
	push	rbp
	mov	rbp, rsp

	mov	rsi, rdi ; backup of arg

	; call ft_strlen
	call	ft_strlen

	; call malloc
	mov	rdi, rax
	call	malloc

	cmp	rax, 0
	je	_error ; jump if equal

	; call ft_strcpy
	mov	rdi, rax
	call	ft_strcpy

_end:
	pop	rbp
	ret

_error:
	xor	rcx, rcx

	mov	rcx, rax
	neg	rcx

	call	__errno_location

	mov	[rax], rcx
	mov	rax, 0
	jmp	_end
