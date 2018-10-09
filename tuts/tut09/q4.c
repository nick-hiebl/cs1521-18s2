// gcc q4.c -pthread -o q4

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <semaphore.h>

void delay(int);

int main(void) {
    int pid;

    sem_t *print_lock;

    print_lock = sem_open("print_lock", O_CREAT, 0644, 1);

    setbuf(stdout, NULL);
    if ((pid = fork()) != 0) {
        for (int i = 0; i < 5; i++) {
            sem_wait(print_lock);
            for (int j = 0; j < 26; j++)
                putchar('a'+j);
            putchar('\n');
            sem_post(print_lock);
            delay(100000);
        }
    }
    else {
        for (int i = 0; i < 5; i++) {
            sem_wait(print_lock);
            for (int j = 0; j < 26; j++)
                putchar('A'+j);
            putchar('\n');
            sem_post(print_lock);
            delay(100000);
        }
    }
    sem_destroy(print_lock);
    return 0;
}

void delay(int max) {
    for (int i = 0; i < max; i++) /* waste time */;
}
