print_flag:

    li      $s0, 0  #ROW
    li      $s1, 0  #COL
    lw      $s2, nrows #NROWS
    lw      $s3, ncols #NCOLS

    la      $s5, flag

    rowLoop:
        bge     $s0, $s2, endRowLoop

        li      $s1, 0
        colLoop:
            bge     $s1, $s3, endColLoop

            # mul     $t1, $s0, $s3
            # add     $t1, $t1, $s1
            #
            # lb      $t0, flag($t1)

            lb      $t0, ($s5)

            addi    $s5, $s5, 1

            li      $v0, 11
            move    $a0, $t0
            syscall

            addi    $s1, $s1, 1
            j       colLoop
        endColLoop:

        li      $v0, 11
        li      $a0, '\n'
        syscall

        addi    $s0, $s0, 1
        j       rowLoop
    endRowLoop:
