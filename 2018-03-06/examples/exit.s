section .text
global _start
_start:
  mov eax, 1                    ;exit()
  mov ebx, 72                   ;just some random integer [0..255]
  int 0x80
