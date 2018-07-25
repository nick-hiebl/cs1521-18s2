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

    for (p = &coords[0]; p <= &coords[9]; p++) {
        p->x = 0;
        p->y = 0;
        p->z = 0;

        print_coord(*p);
    }
}
