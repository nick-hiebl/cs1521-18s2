#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void fatal(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s URL\n", argv[0]);
        exit(1);
    }
    // Open the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) fatal("ERROR socket");

    // Get server info
    server = gethostbyname(argv[1]);
    if (server == NULL) fatal("ERROR gethost");

    // Initialize serv_addr
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    // Convert port
    serv_addr.sin_port = htons(80);

    // Try connecting
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        fatal("ERROR connecting");
    }

    // Create a buffer to store request/info in
    char buffer[BUFSIZ];

    // Create request
    char *reqFmt = "GET %s HTTP/1.1\r\nHost: 127.0.0.1\r\n\r\n";
    sprintf(buffer, reqFmt, argv[1]);

    // Show request for educational purposes
    printf("Sending request: %s\n", buffer);

    // Write the request to the socket
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) fatal("ERROR writing to socket");

    // Collect response
    printf("Response:\n");
    while ((n = read(sockfd,buffer,BUFSIZ)) > 0)
        write(1, buffer, n);
    if (n < 0) fatal("ERROR reading from socket");

    // Close socket
    close(sockfd);
    return 0;
}
