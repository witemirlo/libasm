section .text
	global ft_strdup

	extern ft_strlen
	extern ft_strcpy

	extern malloc

ft_strdup:
	;push	rbp
	;mov	rbp, rsp

	; backup of original argument
	push	r12
	mov	r12, rdi

	; call ft_strlen
	call	ft_strlen

	; call malloc
	mov	rdi, rax
	inc	rdi
	call	malloc wrt ..plt

	cmp	rax, 0
	je	.end

	; call ft_strcpy
	mov	rdi, rax
	mov	rsi, r12
	call	ft_strcpy

.end:
	pop	r12
	;pop	rbp
	ret
