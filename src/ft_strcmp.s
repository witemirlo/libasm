.text:
	global ft_strcmp

ft_strcmp:
	push	rbp
	mov	rbp, rsp
	xor	rax, rax
	xor	rcx, rcx

_loop:
	mov	al, [rdi]
	mov	cl, [rsi]

	cmp	al, 0 
	je	_end

	cmp	cl, 0 
	je	_end

	cmp	al, cl
	jne	_end

	inc	rdi
	inc	rsi
	jmp	_loop

_end:
	sub	rax, rcx

	pop	rbp
	ret
