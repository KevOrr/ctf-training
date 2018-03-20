#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int terminate_newline(char *s) {
    char *loc = strchr(s, '\n');
    if (loc) {
        *loc = '\0';
        return 1;
    }
    return 0;
}

int main() {
    unsigned long long buflen = 0x10000;
    char *buf = malloc(buflen * sizeof(char));

    fputs("This is a simple hello world application.\n"
          "To save space, I'm using the same file for my RSA private key as temporary data.\n"
          "Please enter your name: ", stdout);
    fflush(stdout);

    fgets(buf, buflen, stdin);

    char *cmd;
    asprintf(&cmd, "{ echo \"%s\"; cat storage; } >temp && mv temp storage && ./readflag %u", buf, strlen(buf));
    return system(cmd);
}
