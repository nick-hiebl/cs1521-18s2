#include <stdio.h>

void printBits(unsigned short w){
    printf("%.4x -> ", w);
    for(int i = 15; i >= 0; i--){
        printf("%d", ((1 << i) & w) > 0);
        if(i % 4 == 0) printf(" ");
    }
    printf("\n");
}


int main(void){
    unsigned short a, b, c;
    a = 0x5555;  b = 0xAAAA;  c = 0x0001;

    printf("%16s: ", "a"); printBits(a);
    printf("%16s: ", "b"); printBits(b);
    printf("%16s: ", "c"); printBits(c);
    putchar('\n');
    printf("%16s: ", "a | b");          printBits(a | b);
    // printf("%16s: ", "a & b");          printBits(a & b);
    // printf("%16s: ", "a ^ b");          printBits(a ^ b);
    // printf("%16s: ", "a & ~b");         printBits(a & ~b);
    // printf("%16s: ", "c << 6");         printBits(c << 6);
    // printf("%16s: ", "a >> 4");         printBits(a >> 4);
    // printf("%16s: ", "a & (b << 1)");   printBits(a & (b << 1));
    // printf("%16s: ", "b | c");          printBits(b | c);
    // printf("%16s: ", "a & ~c");         printBits(a & ~c);

    return 0;
}
