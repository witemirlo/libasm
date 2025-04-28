.text:
	global	ft_strcpy

ft_strcpy:
	push	rbp
	mov	rbp, rsp

	mov	rax, rdi ; put memory address of the dst in the register used in return value

.loop:
	movsb
	mov	cl, [rsi] ; second argument
	cmp	cl, 0
	jne	.loop

.end:
	movsb
	pop	rbp
	ret
