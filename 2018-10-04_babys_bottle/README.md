# Pwnable Challenges!

1. Make an account at http://pwnable.kr/
2. Login if necessary and click on `PLAY` on the top bar
3. Challenges are ordered by increasing difficulty

# Today's challenges

Today we'll be attempting 2 challenges: `fd` and `bof`. I'll include the
relevant files in [fd/](fd/) and [bof/](bof/), though I recommend grabbing them
straight from the source.

## `fd`

This challenge requires knowledge of POSIX file descriptors (remember `stdin`,
`stdout`, and `stderr`!), command line arguments, the C functions `atoi`,
`strcmp`, `system`, and the POSIX C function `read`. `man` and the web are your
friends here.

## `bof`

This challenge is an intro to buffer overflows. It will require a disassembler
(Binja or `objdump` or IDA or `radare2` if you're feeling brave). `gdb` can help
debug buffer overflows and other exploits.

## `col`

This challenge is all about finding collisions in a simple hash function. If
you're not familiar with hashing,
[here](https://en.wikipedia.org/wiki/Hash_function) is a good reference,
especially the intro and searching the page for "collision".

Happy hacking! And ask questions.
