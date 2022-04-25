.data
	a:	.word 0
	d:	.space 1000
	d_string:	.asciiz "Pls enter a number "
	i:	.word 1
	wordConst_0:	.word 1

.text
	la	$t0, d_string
	la	$t1, d

	loop_d:
		lbu	$t2, 0($t0)
		sb	$t2, 0($t1)
		addi	$t0, $t0, 1
		addi	$t1, $t1, 1
		bne	$t2, $zero, loop_d

	li	$v0, 4
	la	$a0, d
	syscall

	li	$v0, 5
	syscall
	sw	$v0, a

	foreach_0:
	lw	$t1, i
	lw	$t2, a
	sne	$s0, $t1, $t2

	beqz	$s0, end_foreach_0

	l.s	$f1, i
	cvt.s.w	$f1, $f1
	l.s	$f2, wordConst_0
	cvt.s.w	$f2, $f2
	add.s	$f2, $f1, $f2

	cvt.w.s	$f2, $f2
	s.s	$f2, i

	li	$v0, 1
	lw	$a0, i
	syscall

	j	foreach_0

	end_foreach_0:
	li	$v0, 10
	syscall

