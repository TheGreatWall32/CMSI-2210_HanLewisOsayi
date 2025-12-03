; Windows x86-64 Assembly
; To assemble and link:
;   nasm -f win64 makeNBON.nasm -o makeNBON.obj
;   link /subsystem:console /nodefaultlib /entry:main makeNBON.obj makeNBOC.obj makeNBOWrapper.obj msvcrt.lib legacy_stdio_definitions.lib /OUT:makeNBON.exe

extern printf

extern test_nbo

section .data
    msg db "Testing Network Byte Order Conversion from Assembly", 0
    fmt db "%s", 0Dh, 0Ah, 0  ; Windows uses CRLF for newlines

section .text
global main
main:
    ; Set up stack frame (shadow space + align to 16 bytes)
    push rbp
    mov rbp, rsp
    sub rsp, 32        ; Allocate shadow space (32 bytes) + align stack

    ; Print header
    lea rcx, [fmt]     ; 1st parameter (format string)
    lea rdx, [msg]     ; 2nd parameter (message)
    call printf

    ; Call our C test function
    call test_nbo

    ; Clean up and return
    xor eax, eax       ; Return 0
    add rsp, 32        ; Clean up shadow space
    pop rbp
    ret