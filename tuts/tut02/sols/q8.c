#include <stdio.h>

typedef unsigned int Word;

void printBits(Word w){
    for(int i = 31; i >= 0; i--){
        printf("%d", ((1 << i) & w) > 0);
        if(i % 4 == 0) printf(" ");
    }
    printf("\n");
}

Word reverseBits(Word w){
    Word result = 0;
    for(int i = 0; i < 32; i++){
        result += (((1 << (31 - i)) & w) > 0) << i;
    }
    return result;
}

int main(void){
    Word w = 0x01234567;

    printBits(w);
    w = reverseBits(w);
    printBits(w);

    return 0;
}
