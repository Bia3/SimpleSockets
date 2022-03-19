//
// A simple server using TCP
//
// Created by Sean Ross on 3/18/22.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Called when sys call fails, displays error and exits
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[256];

    struct sockaddr_in serv_addr{}, cli_addr{};

    // Display Error and exit if the user did not pass in a port number
    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // sys call socket() returns -1 if the socket fails to open
    if (sockfd < 0) error((char *) &"ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = atoi(argv[1]);

    // Set up the fields for serv_addr
    serv_addr.sin_family = AF_INET;
    // htons() converts a port number in host byte order to a port number in network byte order
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY; // INADDR_ANY gets the IP of the host for server

    // system call bind() returns -1 if it fails to bind the port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error((char *) &"ERROR on binding");

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, reinterpret_cast<socklen_t *>(&clilen));
    // sys call accept will return -1 if it fails
    if (newsockfd < 0) error((char *) &"ERROR on accept");

    bzero(buffer,256);
    n = (int) read(newsockfd,buffer,255);
    if (n < 0 ) error((char *) &"ERROR reading from socket");
    printf("Here is the message: %s", buffer);

    n = (int) write(newsockfd, buffer, 255);
    if (n < 0) error((char *) &"ERROR writing to socket");

    return 0;
}





