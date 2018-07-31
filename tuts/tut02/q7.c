#include <stdio.h>

#define READING   0x01
#define WRITING   0x02
#define AS_BYTES  0x04
#define AS_BLOCKS 0x08
#define LOCKED    0x10

void print_device(unsigned char device) {
    if (device == 0) {
        printf("Device has no settings");
        return;
    }
    printf("Device has:");
    if (device & READING) printf(" READING");
    if (device & WRITING) printf(" WRITING");
    if (device & AS_BYTES) printf(" BYTES");
    if (device & AS_BLOCKS) printf(" BLOCKS");
    if (device & LOCKED) printf(" LOCKED");
    printf("\n");
}

int main() {
    // Initialise device
    unsigned char device = (READING | AS_BYTES | LOCKED);

    print_device(device);

    // Perform operation

    print_device(device);

}
