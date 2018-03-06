section .data
  path db `/bin/bash\0`
  argv dd path
  null dd 0

section .text
global _start
_start:
  mov eax, 0xb                  ;exec()
  mov ebx, path                 ;path to executable
  mov ecx, argv                 ;the command line
  mov edx, null                 ;envp
  int 0x80

  mov eax, 1                    ;exit()
  mov ebx, 1                    ;if we got here, exec() must have failed
  int 0x80
