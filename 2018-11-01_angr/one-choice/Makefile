CC := gcc
CCFLAGS := -O1 -fno-stack-protector -D FORTIFY_SROUCE=0

one_choice: one_choice.c
	$(CC) $(CCFLAGS) -m32 -o $@ $?

clean:
	rm -f one_choice

.PHONY: clean
