	.file	"heapsort.c"
	.text
	.p2align 4,,15
	.globl	heapsort
	.type	heapsort, @function

# void heapsort(int last)
# last in %edi

heapsort:
.LFB11:
	.cfi_startproc
	pushq	%rbx                 # push %rbx in the stack (save the value to stack before using)
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	%edi, %ebx           # i = last
	call	heapify_array        # call heapify_array
	testl	%ebx, %ebx           # test i, is i < 0?, set conditional code
	js	.L1                      # if i < 0 (signed), jump to .L1
	.p2align 4,,10
	.p2align 3
.L7:
	movl	%ebx, %edi           # move the value of i to %edi which is used for extract_max
	call	extract_max          # call extract_max
	movslq	%ebx, %rdx           # take 32 bits of i in %ebx and sign extend it to 64 bits in %rdx
	subl	$1, %ebx             # i--
	cmpl	$-1, %ebx            # compare "-1":i, set conditional code
	movl	%eax, heap(,%rdx ,4) # heap[i] = extract_max(i)
	jne	.L7                      # if i != -1, jump to .L7
.L1:
	popq	%rbx                 # pop %rbx back from the stack (restore the old value)
	.cfi_def_cfa_offset 8
	ret                          # return
	.cfi_endproc
.LFE11:
	.size	heapsort, .-heapsort
	.ident	"GCC: (SUSE Linux) 4.8.5"
	.section	.note.GNU-stack,"",@progbits
