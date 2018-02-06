#include <stdio.h>
#include <stdlib.h>

__attribute__((used)) void notreferenced() {
    puts("How'd you get here????");
}

void unhelpful_message() {
    char buf[16];
    puts("Hi, please enter your name");
    fread(buf, 32, sizeof(char), stdin);
    puts("This program really doesn't do anything useful yet");
}

int main() {
    unhelpful_message();
}
