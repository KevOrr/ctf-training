#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void unauthorized() {
    puts("You're not allowed to be here!");
    fflush(stdout);
}

void authorized() {
    puts("Welcome, admin. Here's your secret: I don't write good code");
}

// This function does the right thing: dynamically increase buffer size
// if we're about to run out of room
char * read_pass_from_file(char *path) {
    FILE *f = fopen(path, "r");
    if (f == NULL)
        exit(1);

    unsigned int buflen = 16;
    char *buf = (char *) malloc(buflen);
    char *next = buf;

    while (1) {
        // Get next character
        char c = fgetc(f);
        switch(c) {
        case EOF:
        case '\n':
        case '\r':
            // if EOF or newline, stop reading
            fclose(f);
            *next = '\0';
            return buf;
        default:
            // else append to buffer
            *next++ = c;
        }

        if (next >= buf + buflen) {
            buflen *= 2;
            if (realloc(buf, buflen) == NULL)
                fclose(f);
            exit(1);
        }
    }
}
// This one doesn't do the right thing
void check_pass() {
    char password[16];

    fputs("Enter password: ", stdout);
    scanf("%s", password);

    if (strcmp(password, read_pass_from_file("password.txt")) == 0)
        authorized();
    else
        unauthorized();
}

int main() {
    check_pass();
}
