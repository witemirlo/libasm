.text:
	global	ft_strlen
	
ft_strlen:
	push	rbp
	mov	rbp, rsp

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

	pop	rbp
	ret
