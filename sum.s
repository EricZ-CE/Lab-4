.section .text
.globl data_sum
.type data_sum, @function

data_sum:
    movl $0, %eax

    cmpl $0, %esi
    jle sum_done

sum_loop:
    addl (%rdi), %eax
    addq $4, %rdi
    subl $1, %esi
    jnz sum_loop

sum_done:
    ret

.size data_sum, .-data_sum
.section .note.GNU-stack,"",@progbits
