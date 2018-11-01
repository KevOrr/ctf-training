#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void win() {
    puts("Good job!");
    system("/bin/bash -i");
    exit(0);
}

void lose() {
    puts("Maybe next time?");
    raise(SIGSEGV); // Be extra nasty
}

int main(int argc, const char* argv[]) {
    if (argc != 2) lose();

    // check length
    size_t len = strlen(argv[1]);
    if (len != 21) lose();

    // Copy argv[1] into flag
    char *flag = malloc(len + 1);
    strncpy(flag, argv[1], len + 1);
    flag[len] = '\0';

    for (size_t i=0; flag[i]!='\0'; i++) {
        if (flag[i] == '\n') {
            flag[i] = '\0';
            break;
        }
    }

    if (flag[ 0] != 'f') lose();
    if (flag[ 1] != 'l') lose();
    if (flag[ 2] != 'a') lose();
    if (flag[ 3] != 'g') lose();
    if (flag[ 4] != '{') lose();
    if (flag[ 5] != 'M') lose();
    if (flag[ 6] != 'a') lose();
    if (flag[ 7] != 'n') lose();
    if (flag[ 8] != 'u') lose();
    if (flag[ 9] != '@') lose();
    if (flag[10] != 'l') lose();
    if (flag[11] != '_') lose();
    if (flag[12] != '0') lose();
    if (flag[13] != 'r') lose();
    if (flag[14] != '_') lose();
    if (flag[15] != '@') lose();
    if (flag[16] != 'n') lose();
    if (flag[17] != 'g') lose();
    if (flag[18] != 'r') lose();
    if (flag[19] != '?') lose();
    if (flag[20] != '}') lose();

    win();
}
