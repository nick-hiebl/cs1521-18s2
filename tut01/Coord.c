#include <stdio.h>

typedef struct _Coord {
    unsigned int x;
    unsigned int y;
    unsigned int z;
} Coord;

void modify1(Coord c) {
    c.x = 5;
}

void modify2(Coord *c) {
    c->x = 5;
}
void print_coord(Coord c) {
    printf("%u %u %u\n", c.x, c.y, c.z);
}

int main() {
    Coord coord;
    coord.x = 1; coord.y = 1; coord.z = 1;
    printf("initial "); print_coord(coord);

    modify1(coord);
    printf("modify1 "); print_coord(coord);

    modify2(&coord);
    printf("modify2 "); print_coord(coord);
}
