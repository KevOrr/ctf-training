CC := gcc
CCFLAGS := -std=gnu99 -g -O1 -fno-stack-protector -D FORTIFY_SOURCE=0 -z execstack

bof: bof.c
	$(CC) $(CCFLAGS) -o $@ $?

clean:
	rm -rf bof

.PHONY: clean
