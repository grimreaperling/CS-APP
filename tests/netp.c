#include "csapp.h"

int main(int argc, char **argv) {
    int listenfd, connfd;
    socklen_t clientlen;    
    struct sockaddr_storage clientaddr;

    if (argc != 2) {
        printf("Usage: ./netp <port>\n");
        exit(1);
    }

    /* Open the welcome socket. */
    listenfd = Open_listenfd(argv[1]);

    while (1) {
        clientlen = sizeof(struct sockaddr_storage);
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
    }
}
