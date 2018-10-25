#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

uint8_t flags = 0;

void rop_1(uint32_t a) {
    if (a == 0xdeadbeef)
        flags |= 0b0001;
    else
        exit(1);
}

void rop_2(uint32_t a) {
    if (a == 0xcafebabe)
        flags |= 0b0010;
    else
        exit(1);
}

void rop_3(uint32_t a) {
    if (a == 0xbaddad)
        flags |= 0b0100;
    else
        exit(1);
}

void rop_4(uint32_t a) {
    if (a == 0x0ddba11)
        flags |= 0b1000;
    else
        exit(1);
}

void check() {
    char * a = strdup("You got it!");
    if (flags == 0b1111)
        puts(a);
    else
        exit(1);
}

void vuln() {
    uint32_t buf[20];
    puts("Can you collect all 4 flags?");
    fgets(buf, 20*sizeof(uint64_t), stdin);
}

int main() {
    vuln();
    puts("Oops, sorry!");
}
