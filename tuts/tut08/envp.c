#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    int i = 0;
    while (envp[i] != NULL && envp[i][0] != '\0') {
        printf("%s\n", envp[i]);
        i++;
    }
    return 0;
}
