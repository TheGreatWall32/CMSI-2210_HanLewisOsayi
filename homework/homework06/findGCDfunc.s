.global _findGCD
.align 2

.text
_findGCD:

loop:
    cbz     x1, done

    udiv    x2, x0, x1          // x2 = a / b
    msub    x2, x2, x1, x0      // x2 = a - (x2 * x1)

    mov     x0, x1              // a = old b
    mov     x1, x2              // b = remainder

    b       loop

done:
    ret
