CC := gcc
CCFLAGS := -O1 -fno-stack-protector -D FORTIFY_SROUCE=0

basic_crackme: basic_crackme.c
	$(CC) $(CCFLAGS) -m32 -o $@ $?

clean:
	rm -f basic_crackme

.PHONY: clean
