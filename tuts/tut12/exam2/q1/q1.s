# COMP1521 Practice Prac Exam #1
# int everyKth(int *src, int n, int k, int*dest)

    .text
    .globl everyKth

# params: src=$a0, n=$a1, k=$a2, dest=$a3
everyKth:
# prologue
    addi $sp, $sp, -4
    sw   $fp, ($sp)
    la   $fp, ($sp)
    addi $sp, $sp, -4
    sw   $ra, ($sp)
    addi $sp, $sp, -4
    sw   $s0, ($sp)
    addi $sp, $sp, -4
    sw   $s1, ($sp)
    # if you need to save more $s? registers
    # add the code to save them here

# function body
# locals: i = $s0, j = $s1
    li      $s0, 0
    li      $s1, 0

for:
    bge     $s0, $a1, end_for

    rem     $t0, $s0, $a2
    beqz    $t0, copy
    j       no_copy

copy:

    li      $t1, 4
    mul     $t2, $t1, $s0 #t2 = 4 * i
    add     $t2, $t2, $a0 #t2 = src + 4 * i
    lw      $t3, ($t2)    #t3 = src[i]

    li      $t1, 4
    mul     $t2, $t1, $s1 #t2 = 4 * j
    add     $t2, $t2, $a3 #t2 = dest + 4 * j
    sw      $t3, ($t2)    #t3 = dest[j]

    addi    $s1, $s1, 1

no_copy:


    addi    $s0, $s0, 1
    j       for
end_for:

    move    $v0, $s1

    # add code for your everyKth function here

# epilogue
    # if you saved more than two $s? registers
    # add the code to restore them here
    lw   $s1, ($sp)
    addi $sp, $sp, 4
    lw   $s0, ($sp)
    addi $sp, $sp, 4
    lw   $ra, ($sp)
    addi $sp, $sp, 4
    lw   $fp, ($sp)
    addi $sp, $sp, 4
    j    $ra
