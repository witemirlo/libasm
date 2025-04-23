.text:
	global	ft_strcpy

ft_strcpy:
	push	rbp
	mov	rbp, rsp

	mov	rax, rdi ; put memory address of the dst in the register used in return value

_loop:
	mov	al, [rsi] ; second argument
	cmp	al, 0
	jne	_cpy
	jmp	_end

_cpy:
	movsb
	inc	rsi
	inc	rdi
	jmp	_loop

_end:
	mov	rdi, 0
	pop	rbp
	ret
