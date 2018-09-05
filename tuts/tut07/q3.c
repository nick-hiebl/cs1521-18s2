int update(int fd, int k, struct X new) {
    size_t size = sizeof(struct X);
    off_t offset = k * size;
    if (lseek(fd, offset, SEEK_SET) != offset) return -1;
    if (write(fd, &new, size) != size) return -1;
    return 0;
}
