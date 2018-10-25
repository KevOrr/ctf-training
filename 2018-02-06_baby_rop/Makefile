CC := gcc
CCFLAGS := -O1 -fno-stack-protector -D FORTIFY_SROUCE=0

baby-rop: baby-rop.c
	$(CC) $(CCFLAGS) -m32 -o $@ $?

.PHONY: all
