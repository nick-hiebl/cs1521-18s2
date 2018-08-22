max:

    # FUNCTION PROLOGUE

    # $a1 is length
    li      $t0, 1
    bne     $a1, $t0, max_recursive

    lw      $s0, ($a0) # s0 = a[0]
    move    $v0, $s0    # return s0
    j       max_exit

max_recursive:

    lw      $s0, ($a0)

    la      $a0, 4($a0)
    addi    $a1, $a1, -1

    jal     max

    bgt     $v0, $s0, max_exit

    move    $v0, $s0 # return a[0]

max_exit:
    # FUNCTION EPILOGUE
