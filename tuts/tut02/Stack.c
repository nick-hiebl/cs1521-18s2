#include <stdio.h>

#include "Stack.h"

void initStack(Stack *s) {
    s->top = 0;
}

int  pushStack(Stack *s, Item val) {
    if (s->top == MAX_STACK) return 0;
    s->items[s->top] = val;
    s->top++;
    return 1;
}

Item popStack(Stack *s) {
    s->top--;
    Item ret = s->items[s->top];
    return ret;
}

int  isEmptyStack(Stack s) {
    return s.top == 0;
}

void showStack(Stack s) {
    printf("<");
    for (int i = 0; i < s.top; i++) {
        printf(" '%c'", s.items[i]);
    }
    printf(" >\n");
}
