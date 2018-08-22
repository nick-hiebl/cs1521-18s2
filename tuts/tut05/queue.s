enqueue:
    # FUNCTION PROLOGUE

    li      $t0, 8
    lw      $s0, nitems

    bne     $s0, $t0, not_full

    li      $v0, -1
    j       enqueue_exit

not_full:
    lw      $s1, tail

    beqz    $s0, after_tail_adjust

    addi    $s1, $s1, 1
    rem     $s1, $s1, $t0

    sw      $s1, tail

after_tail_adjust:

    la      $s2, items
    li      $t0, 4
    mul     $s1, $s1, $t0
    add     $s2, $s2, $s1

    sw      $a0, ($s2)

    addi    $s0, $s0, 1
    sw      $s0, nitems

    li      $v0, 0

enqueue_exit:
    # FUNCTION EPILOGUE
