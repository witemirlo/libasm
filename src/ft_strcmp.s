.text:
	global ft_strcmp

ft_strcmp:
	push	rbp
	mov	rbp, rsp
	xor	rax, rax
	xor	rcx, rcx

.loop:
	mov	al, [rdi]
	mov	cl, [rsi]

	cmp	al, 0 
	je	.end

	cmp	cl, 0 
	je	.end

	cmp	al, cl
	jne	.end

	inc	rdi
	inc	rsi
	jmp	.loop

.end:
	sub	rax, rcx

	pop	rbp
	ret
