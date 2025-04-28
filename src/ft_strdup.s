.text:
	global ft_strdup

	extern ft_strlen
	extern ft_strcpy

	extern malloc
	extern __errno_location

ft_strdup:
	push	rbp
	mov	rbp, rsp

	mov	r11, rdi ; backup of arg, malloc changes rsi

	; call ft_strlen
	call	ft_strlen

	; call malloc
	mov	rdi, rax
	call	malloc

	cmp	rax, 0
	je	.error ; jump if equal

	; call ft_strcpy
	mov	rdi, rax
	mov	rsi, r11
	call	ft_strcpy

.end:
	pop	rbp
	ret

.error:
	xor	rcx, rcx

	mov	rcx, rax
	neg	rcx

	call	__errno_location

	mov	[rax], rcx
	mov	rax, 0
	jmp	.end
