#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

void fatal(char *);

int main() {
    int ch;

    Stack brackets;
    initStack(&brackets);

    while ((ch = getchar()) != EOF) {
        if (ch == '(' || ch == '[' || ch == '{') {
            int success = pushStack(&brackets, ch);
            if (!success) {
                fatal("Stack is full\n");
            }
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmptyStack(brackets)) {
                fatal("Too many closing brackets\n");
            }
            char lastBracket = popStack(&brackets);
            if (ch == ')' && lastBracket != '(') {
                fatal("Mismatch on ( .. )\n");
            } else if (ch == ']' && lastBracket != '[') {
                fatal("Mismatch on [ .. ]\n");
            } else if (ch == '}' && lastBracket != '{') {
                fatal("Mismatch on { .. }\n");
            }
        }
    }

    if (!isEmptyStack(brackets)) fatal("Too many opening brackets\n");

    printf("OK\n");
    return 0;
}

void fatal(char *msg) {
    fprintf(stderr, "%s", msg);
    exit(1);
}
