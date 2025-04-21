section .data
	END_LINE	db 0x0
	msg		db "aa", 0

section .text
	global	_start

_start:
	; tmp
	mov	rax, 1
	mov	rdi, 1
	mov	rsi, msg
	mov	rdx, 1
	syscall

	; call function
	mov	rdi, msg
	call	strlen

	; exit with the return value of strlen
	mov	rdi, rax
	mov	rax, 60
	syscall

strlen:
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
