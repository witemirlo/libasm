section .text
	global	ft_strcpy

ft_strcpy:
	mov	rax, rdi ; put memory address of the dst in the register used in return value

.loop:
	movsb
	mov	cl, [rsi] ; second argument
	cmp	cl, 0
	jne	.loop

.end:
	movsb
	ret
