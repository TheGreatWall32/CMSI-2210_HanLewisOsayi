.global _main
.p2align 2

.text
_main:
    sub     sp, sp, #48
    stp     x29, x30, [sp, #32]
    add     x29, sp, #32

    adrp    x0, promptString@PAGE
    add     x0, x0, promptString@PAGEOFF
    bl      _printf

    mov     x9, sp
    sub     x8, x29, #8
    str     x8, [x9]
    add     x8, sp, #16
    str     x8, [x9, #8]

    adrp    x0, scanFormat@PAGE
    add     x0, x0, scanFormat@PAGEOFF
    bl      _scanf

    ldur    x0, [x29, #-8]
    ldr     x1, [sp, #16]

gcd_loop:
    cbz     x1, print_result

    udiv    x2, x0, x1          // x2 = a / b
    msub    x2, x2, x1, x0      // x2 = a - (x2 * b)

    mov     x0, x1
    mov     x1, x2
    b       gcd_loop

print_result:
    mov     x9, sp
    str     x0, [x9]
    adrp    x0, resultFormat@PAGE
    add     x0, x0, resultFormat@PAGEOFF
    bl      _printf

    ldp     x29, x30, [sp, #32]
    add     sp, sp, #48
    mov     x0, #0
    ret

.section __TEXT,__cstring,cstring_literals
promptString:   .asciz "Enter two numbers >> "
scanFormat:     .asciz "%ld %ld"
resultFormat:   .asciz "%ld\n"
