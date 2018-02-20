CC := gcc
CCFLAGS := -O1 -fno-stack-protector -D FORTIFY_SROUCE=0

all: cops_and_roppers

cops_and_roppers: cops_and_roppers.c
	$(CC) $(CCFLAGS) -m32 -o $@ $?

clean:
	rm -f cops_and_roppers

.PHONY: all clean
