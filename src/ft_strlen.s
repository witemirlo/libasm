section .text
	global	ft_strlen
	
ft_strlen:
	mov	rcx, 0
	jmp	.loop

.increase:
	inc	rcx
	inc	rdi

.loop:
	mov	al, [rdi]
	cmp	al, 0
	jne	.increase

.end:
	mov	rax, rcx

	ret
