section .data
  mystring db `Hello, world!\n`
  mystringlen equ $ - mystring

section .text
global _start
_start:
  mov eax, 4                    ;write()
  mov ebx, 1                    ;output file descriptor
  mov ecx, mystring             ;string to write
  mov edx, mystringlen          ;length of string
  int 0x80

  mov eax, 1                    ;exit()
  mov ebx, 0                    ;0 exit status = success
  int 0x80
