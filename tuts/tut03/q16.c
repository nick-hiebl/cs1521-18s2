#include <stdio.h>

struct x {
   unsigned char
      bit0 : 1, bit1 : 1, bit2 : 1, bit3 : 1,
      bit4 : 1, bit5 : 1, bit6 : 1, bit7 : 1;
};

union viewer {
    struct x bits;
    unsigned char c;
};

int main() {
    union viewer v;
    v.c = 0;

    v.bits.bit0 = 1;

    printf("%x\n", v.c);

    return 0;
}
