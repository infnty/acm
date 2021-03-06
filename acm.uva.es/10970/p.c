__asm__(
".globl main\n"
"main:\n"
"	subl	$32, %esp\n"

"	movl	$'0', %ebx\n"
"A0:	movl	$1, dig(,%ebx,4)\n"
"	incl	%ebx\n"
"	cmpl	$'9', %ebx\n"
"	jbe	A0\n"

"	movl	$0, (%esp)\n"
"	movl	$buf, 4(%esp)\n"
"	movl	$1048576, 8(%esp)\n"
"	call	read\n"
"	movl	$' ', buf(%eax)\n"
"	movl	$'0', buf+1(%eax)\n"
"	movl	$' ', buf+2(%eax)\n"

"	movl	$buf, %esi\n"
"	movl	%esi, %edi\n"
"	dec	%esi\n"

"A1:	inc	%esi\n"
"	movzbl	(%esi), %ebx\n"
"	movl	dig(,%ebx,4), %ecx\n"
"	testl	%ecx, %ecx\n"
"	jz	A1\n"

"	subl	$'0', %ebx\n"
"	movl	%ebx, %eax\n"
"A2:	incl	%esi\n"
"	movzbl	(%esi), %ebx\n"
"	movl	dig(,%ebx,4), %ecx\n"
"	testl	%ecx, %ecx\n"
"	jz	A3\n"
"	imull	$10, %eax, %eax\n"
"	subl	$'0', %ebx\n"
"	addl	%ebx, %eax\n"
"	jmp	A2\n"
"A3:	testl	%eax, %eax\n"
"	jz	Adone\n"
"	pushl	%eax\n"

"A4:	inc	%esi\n"
"	movzbl	(%esi), %ebx\n"
"	movl	dig(,%ebx,4), %ecx\n"
"	testl	%ecx, %ecx\n"
"	jz	A4\n"

"	subl	$'0', %ebx\n"
"	movl	%ebx, %eax\n"
"A5:	incl	%esi\n"
"	movzbl	(%esi), %ebx\n"
"	movl	dig(,%ebx,4), %ecx\n"
"	testl	%ecx, %ecx\n"
"	jz	A6\n"
"	imull	$10, %eax, %eax\n"
"	subl	$'0', %ebx\n"
"	addl	%ebx, %eax\n"
"	jmp	A5\n"
"A6:	popl	%ebx\n"
"	imull	%ebx, %eax\n"
"	decl	%eax\n"
"	jz	Azero\n"

"	movl	%eax, %ebx\n"
"	xorl	%ecx, %ecx\n"

"A7:	movl	$1717986919, %eax\n"
"	imull	%ebx\n"
"	sarl	$2, %edx\n"
"	movl	%ebx, %eax\n"
"	sarl	$31, %eax\n"
"	subl	%eax, %edx\n"
"	leal	(%edx,%edx,4), %eax\n"
"	addl	%eax, %eax\n"
"	subl	%eax, %ebx\n"
"	pushl	%ebx\n"
"	incl	%ecx\n"
"	movl	%edx, %ebx\n"
"	test	%ebx, %ebx\n"
"	jnz	A7\n"

"A8:	popl	%eax\n"
"	add	$'0', %eax\n"
"	movb	%al, (%edi)\n"
"	incl	%edi\n"
"	dec	%ecx\n"
"	jnz	A8\n"

"	movb	$'\n', (%edi)\n"
"	inc	%edi\n"
"	jmp	A1\n"

"Azero:\n"
"	movw	$0x0A30, (%edi)\n"
"	inc	%edi\n"
"	inc	%edi\n"
"	jmp	A1\n"

"Adone:\n"
"	movl	$1, (%esp)\n"
"	movl	$buf, 4(%esp)\n"
"	subl	$buf, %edi\n"
"	movl	%edi, 8(%esp)\n"
"	call	write\n"
"	movl	$0, (%esp)\n"
"	call	exit\n"

".align 32\n"
".lcomm dig, 512\n"
".lcomm buf, 1048576\n"
);
