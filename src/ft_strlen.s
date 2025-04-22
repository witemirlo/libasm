.text:
	global	ft_strlen
	
ft_strlen:
	push	rbp
	mov	rbp, rsp

	mov	rcx, 0

_loop:
	mov	al, [rdi]
	cmp	al, 0
	jne	_increase
	jmp	_end

_increase:
	inc	rcx
	inc	rdi
	jmp	_loop

_end:
	mov	rax, rcx

	pop	rbp
	ret
