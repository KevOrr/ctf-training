#include <stdio.h>
#include <stdint.h>

void checkval() {
    uint64_t correct = 0xdeadbeef;
    char buf;

    puts("Enter value");
    scanf("%s", &buf);

    if (correct == 0x10aded)
        puts("How did you get past that?");
    else
        puts("You didn't think I'd actually let you in did you?");
}

int main() {
    checkval();
}
