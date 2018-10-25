#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void super_secret_shell() {
    puts("Welcome, admin");
    system("/bin/bash");
}

void do_hello() {
    char name[50]; // TODO support users with really long names
    fputs("Please enter your name: ", stdout);
    gets(name);
    printf("Hello, %s!\n", name);
}

int main() {
    do_hello();

    return 0;
}
