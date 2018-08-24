#include <stdio.h>
#include <unistd.h>

void super_secret_shell() {
    const char *new_env[] = {"PS1=omgroot> "};
    execle("/bin/bash", "-bash", "--norc", "--noprofile", NULL, new_env);
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
