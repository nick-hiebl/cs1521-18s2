#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *m = malloc(sizeof(int));
    printf("Stack %p, Heap %p\n", &n, m);
}
