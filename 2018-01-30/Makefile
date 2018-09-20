CC := gcc
CCFLAGS := -O1 -fno-stack-protector -D FORTIFY_SROUCE=0

all: checkval/checkval32 checkval/checkval64 login/login32 login/login64 checkval-fixed/checkval-fixed32 checkval-fixed/checkval-fixed64

checkval/checkval32: checkval/checkval.c
	$(CC) $(CCFLAGS) -m32 -o $@ $?

checkval/checkval64: checkval/checkval.c
	$(CC) $(CCFLAGS) -m64 -o $@ $?

checkval-fixed/checkval-fixed32: checkval-fixed/checkval-fixed.c
	$(CC) $(CCFLAGS) -m32 -o $@ $?

checkval-fixed/checkval-fixed64: checkval-fixed/checkval-fixed.c
	$(CC) $(CCFLAGS) -m64 -o $@ $?

login/login32: login/login.c
	$(CC) $(CCFLAGS) -m32 -o $@ $?

login/login64: login/login.c
	$(CC) $(CCFLAGS) -m64 -o $@ $?

.PHONY: all
