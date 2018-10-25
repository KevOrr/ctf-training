CC := gcc
CCFLAGS := -O1 -fno-stack-protector -D FORTIFY_SROUCE=0

all: rop_chaining

rop_chaining: rop_chaining.c
	$(CC) $(CCFLAGS) -m32 -o $@ $?

clean:
	rm -f rop_chaining

.PHONY: all clean
