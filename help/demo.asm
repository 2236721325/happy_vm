; Disassembly of file: demo.o
; Sat Jul 22 20:06:24 2023
; Type: ELF32
; Syntax: NASM
; Instruction set: 80386


global add: function
global main: function


SECTION .text   align=1 exec                            ; section number 1, code

add:    ; Function begin
        push    ebp                                     ; 0000 _ 55
        mov     ebp, esp                                ; 0001 _ 89. E5
        mov     edx, dword [ebp+8H]                     ; 0003 _ 8B. 55, 08
        mov     eax, dword [ebp+0CH]                    ; 0006 _ 8B. 45, 0C
        add     eax, edx                                ; 0009 _ 01. D0
        pop     ebp                                     ; 000B _ 5D
        ret                                             ; 000C _ C3
; add End of function

main:   ; Function begin
        push    ebp                                     ; 000D _ 55
        mov     ebp, esp                                ; 000E _ 89. E5
        sub     esp, 16                                 ; 0010 _ 83. EC, 10
        push    2                                       ; 0013 _ 6A, 02
        push    1                                       ; 0015 _ 6A, 01
        call    add                                     ; 0017 _ E8, FFFFFFFC(rel)
        add     esp, 8                                  ; 001C _ 83. C4, 08
        mov     dword [ebp-4H], eax                     ; 001F _ 89. 45, FC
        mov     eax, 1                                  ; 0022 _ B8, 00000001
        leave                                           ; 0027 _ C9
        ret                                             ; 0028 _ C3
; main End of function


SECTION .data   align=1 noexec                          ; section number 2, data


SECTION .bss    align=1 noexec                          ; section number 3, bss


