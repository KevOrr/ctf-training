LD := ld
LDFLAGS := -m elf_i386
ASM := nasm
ASMFLAGS := -f elf

SOURCES := $(wildcard *.s) $(wildcard *.S)
OBJECTS := $(patsubst %.s, %.o, $(SOURCES))
EXECUTABLES := $(patsubst %.s, %, $(SOURCES))

.PHONY: all

all: $(EXECUTABLES)
	rm -f $(OBJECTS)

$(EXECUTABLES): % : %.o
	$(LD) $(LDFLAGS) $< -o $@

$(OBJECTS): %.o : %.s
	$(ASM) $(ASMFLAGS) $< -o $@
