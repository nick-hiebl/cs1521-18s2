#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct _graphics {
   int   x;  // x coordinate
   int   y;  // y coordinate
   char  r;  // red level
   char  g;  // green level
   char  b;  // blue level
} Graphics;

void display(int device, Graphics item) {
    // do nothing
}

int main(void) {

    int picture = open("Picture", O_RDONLY);
    if (picture < 0) return 1;
    int device = open("/dev/display", O_WRONLY);
    if (device < 0) {
        close(picture);
        return 1;
    }
    size_t gsize = sizeof(Graphics);
    Graphics g[1000];
    int nb;

    while ((nb = read(picture, g, gsize * 1000)) > 0) {
        for (int i = 0; i < nb/gsize; i++)
            display(device, g[i]);
    }

    close(picture);
    close(device);

    return 0;
}
