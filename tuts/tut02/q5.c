#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

void fatal(char *);

int main() {
    int ch;

    while ((ch = getchar()) != EOF) {

    }

    printf("OK\n");
    return 0;
}

void fatal(char *msg) {
    fprintf(stderr, "%s", msg);
    exit(1);
}
