CC := gcc
CCFLAGS := -O1 -fno-stack-protector -D FORTIFY_SROUCE=0

all: baby-rop32 baby-rop64

baby-rop32: baby-rop.c
	$(CC) $(CCFLAGS) -m32 -o $@ $?

baby-rop64: baby-rop.c
	$(CC) $(CCFLAGS) -m64 -o $@ $?

.PHONY: all
