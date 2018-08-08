#include <stdio.h>

struct bits {
    unsigned int one_bit:1,
                 two_bits:2,
                 red_bits:9,
                 blue_bits:20;
};

int main() {
    struct bits b;
    b.one_bit = 1;
    b.two_bits = 0;
    b.red_bits = 0;
    b.blue_bits = 0;

    printf("%x\n", *(unsigned int *)(void *)&b);
}
