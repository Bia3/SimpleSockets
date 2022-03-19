//
// A simple client
//
// Created by Sean Ross on 3/18/22.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Called when sys call fails, displays error and exits
void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr{};
    struct hostent *server;

    char buffer[256];
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // sys call socket() returns -1 if the socket fails to open
    if (sockfd < 0) error((char *) &"ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == nullptr) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    // sys call connect() returns -1 on fail
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error((char *) &"ERROR connecting");

    printf("Please enter the message: ");

    bzero(buffer,256);
    fgets(buffer,255,stdin);

    n = (int) write(sockfd,buffer,strlen(buffer));
    // sys call write() returns -1 on fail
    if (n < 0) error((char *) &"ERROR writing to socket");

    bzero(buffer,256);

    n = (int) read(sockfd,buffer,255);
    // sys call read() returns -1 on fail
    if (n < 0) error((char *) &"ERROR reading from socket");

    printf("%s\n",buffer);

    close(sockfd);
    return 0;
}