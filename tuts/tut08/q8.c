#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
    printf("A\n");
    if (fork() != 0) {
        printf("B\n");
    } else
        printf("C\n");
    sleep(1);
    printf("D\n");
}
