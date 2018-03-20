#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *argv0;

void usage() {
    fprintf(stderr, "USAGE: %s <flag_length>\n", argv0);
    exit(1);
}

int terminate_newline(char *s) {
    char *loc = strchr(s, '\n');
    if (loc) {
        *loc = '\0';
        return 1;
    }
    return 0;
}

void read_flag(unsigned long long length) {
    FILE *f = fopen("storage", "r");
    char buf[length + 1];
    char *bufp = buf;

    while (1) {
        char c = fgetc(f);
        if (c == EOF || c == '\n') break;
        else *bufp++ = c;
    }
    *bufp = '\0';

    printf("Hello, %s!\n", buf);
}

int main(int argc, char *argv[]) {
    argv0 = argv[0];
    if (argc != 2) usage();

    read_flag(strtoull(argv[1], NULL, 10));
    return 0;
}
