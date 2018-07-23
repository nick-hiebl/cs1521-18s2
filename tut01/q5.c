#include <stdio.h>

void f(int n) {
    int x = 0;
    printf("Old x = %d, ", x);
    x = n;
    printf("new x = %d\n", x);
}

int main() {
    f(1);
    f(4);
    f(7);
    f(2);
}
