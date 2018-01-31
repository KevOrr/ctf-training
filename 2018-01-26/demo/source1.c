#include <stdio.h>

int main () {
    unsigned char a = 4 + 5;
    unsigned char b = a + 3;
    unsigned char c = a >> 1;

    printf("%u %u %u\n", a, b, c);
}
