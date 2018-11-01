#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>

int main() {
    // Seed with microseconds
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec + tv.tv_usec);

    // Random integer. Angr won't try to guess this number. This let's us explore
    // a branch
    int r = rand();
    if (r > RAND_MAX / 2)
        puts("Large!");
    else
        puts("Small!");
}
