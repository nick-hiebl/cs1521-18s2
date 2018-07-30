#include <stdio.h>

void set1(int i) {
    i = 5;
}

void set2(int *i) {
    *i = 5;
}

int main() {
    int i = 0;
    printf("i = %d\n", i);
    set1(i);
    printf("i = %d\n", i);
    set2(&i);
    printf("i = %d\n", i);
}
