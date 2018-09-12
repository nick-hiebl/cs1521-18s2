int main(int argc, char *argv[]) {
    int infd; // input file descriptor

    infd = open(argv[1], O_RDONLY);
    infd = 0;

    char buffer[1000]; // input file buffer
    int  nread;        // # characters read

    while ((nread = read(infd, buffer, 1000)) > 0)
       write(1, buffer, nread);
}
