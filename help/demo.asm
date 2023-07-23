; Disassembly of file: demo.o
; Sun Jul 23 15:22:53 2023
; Type: ELF32
; Syntax: NASM
; Instruction set: 80386


global add: function
global main: function


SECTION .text   align=1 exec                            ; section number 1, code

add:    ; Function begin
        push    ebp                                     ; 0000 _ 55
        mov     ebp, esp                                ; 0001 _ 89. E5
        sub     esp, 16                                 ; 0003 _ 83. EC, 10
        mov     edx, dword [ebp+8H]                     ; 0006 _ 8B. 55, 08
        mov     eax, dword [ebp+0CH]                    ; 0009 _ 8B. 45, 0C
        add     eax, edx                                ; 000C _ 01. D0
        mov     dword [ebp-4H], eax                     ; 000E _ 89. 45, FC
        mov     eax, dword [ebp-4H]                     ; 0011 _ 8B. 45, FC
        mov     esp,ebp
        pop     ebp
                                                   ; 0014 _ C9
        ret                                             ; 0015 _ C3
; add End of function

main:   ; Function begin
        push    ebp                                     ; 0016 _ 55
        mov     ebp, esp                                ; 0017 _ 89. E5
        sub     esp, 16                                 ; 0019 _ 83. EC, 10
        push    2                                       ; 001C _ 6A, 02
        push    1                                       ; 001E _ 6A, 01
        call    add                                     ; 0020 _ E8, FFFFFFFC(rel)
        add     esp, 8                                  ; 0025 _ 83. C4, 08
        mov     dword [ebp-4H], eax                     ; 0028 _ 89. 45, FC
        mov     eax, 1                                  ; 002B _ B8, 00000001
        leave                                           ; 0030 _ C9
        ret                                             ; 0031 _ C3
; main End of function


SECTION .data   align=1 noexec                          ; section number 2, data


SECTION .bss    align=1 noexec                          ; section number 3, bss


