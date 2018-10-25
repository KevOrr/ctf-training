#include <stdio.h>
#include <string.h>
/* #include <strings.h> */
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

char *argv0;

int fd = -1;
char buf[0x1000];

void error() {
    perror(argv0);
    fflush(stdout);
    fflush(stderr);
    exit(errno);
}

void iama_cop_ama() {
    puts("I bust roppers. Very simple. You rop, I find you, and send you to SEGFAULT prison");
}

void RUN() {
    uint32_t local_buf[0x10];

    // I made sure not to make the same mistake as before!!
    fgets(local_buf, (sizeof local_buf)*(sizeof local_buf[0]), stdin);
    puts("I don't care what you have to say, that cop's gonna find us! Get outta here!!!");
}

void open_flag(uint32_t key) {
    char * path = strdup("flag");
    if (key == 0x1337) {
        fd = open(path, O_RDONLY);
        if (fd == -1)
            error();
    } else {
        exit(1);
    }
}

void read_flag(uint32_t key) {
    if (key*3 == 2*(key + 7)) {
        if (read(fd, buf, (sizeof buf) - 1) == 0)
            error();
    } else {
        exit(1);
    }
}

void print_flag(uint32_t key) {
    if (6*key*key - 9*key - 6 == 0) // bet you can't solve this quadratic!
        puts(buf);
    else
        exit(1);
}

void usage() {
    fprintf(stderr, "USAGE: %s COP|ROPPER", argv0);
    exit(1);
}

int main(int argc, char *argv[]) {
    argv0 = argv[0];
    if (argc != 2)
        usage();

    if (strcasecmp(argv[1], "cop") == 0)
        iama_cop_ama();
    else if (strcasecmp(argv[1], "ropper") == 0)
        RUN();
    else
        usage();

}
