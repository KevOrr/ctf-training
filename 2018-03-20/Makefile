CC := gcc
CCFLAGS := -g -O1 -fno-stack-protector -D FORTIFY_SOURCE=0

all: run readflag

run: run.c
	$(CC) $(CCFLAGS) -m32 -o $@ $?

readflag: readflag.c
	$(CC) $(CCFLAGS) -m32 -o $@ $?

clean: rm -f run readflag

.PHONY: clean all
