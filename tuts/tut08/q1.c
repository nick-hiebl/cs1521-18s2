int addStruct(char *fileName, struct X data) {
    int fd = open(fileName, O_WRONLY|O_APPEND|O_CREAT);
    if (fd < 0) return -1;
    int size = sizeof(struct X);
    if (write(fd, &data, size) != size) {
        close(fd);
        return -1;
    }
    close(fd);
    return 1;
}
