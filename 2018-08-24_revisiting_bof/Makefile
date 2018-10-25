CC := gcc
CCFLAGS := -std=gnu99 -g -O1 -fno-stack-protector -D FORTIFY_SOURCE=0 -z execstack

all: bof bof_benign

bof_benign: bof_benign.c
	$(CC) $(CCFLAGS) -o $@ $?

bof: bof.c
	$(CC) $(CCFLAGS) -o $@ $?

clean:
	rm -rf bof

.PHONY: clean all
