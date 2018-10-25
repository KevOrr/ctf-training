#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (atoi(argv[1]) == 0x31337dad)
        puts("How'd you know?......");
    else
        puts("That's not it!");
}
