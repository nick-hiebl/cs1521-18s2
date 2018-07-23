#include <stdio.h>

typedef struct _Coord {
    unsigned int x;
    unsigned int y;
    unsigned int z;
} Coord;

void print_coord(Coord c) {
    printf("%u %u %u\n", c.x, c.y, c.z);
}

int main() {
    Coord a, b, coords[10], *p;

    a.x = 5; a.y = 6; a.z = 7;
    p = &a;
    b.x = 3; b.y = 3; b.z = 3;
    {
        print_coord(a);
        print_coord(b);
    }
    /*A*/
    (*p).x = 6; p->y++; p->z++;
    b = *p;
    {
        print_coord(a);
        print_coord(b);
        printf("%u\n", *((unsigned int *) p));
    }
    /*B*/
}
