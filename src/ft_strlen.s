.text:
	global	ft_strlen
	
ft_strlen:
	push	rbp
	mov	rbp, rsp

	mov	rcx, 0
	jmp	_loop

_increase:
	inc	rcx
	inc	rdi

_loop:
	mov	al, [rdi]
	cmp	al, 0
	jne	_increase

_end:
	mov	rax, rcx

	pop	rbp
	ret
