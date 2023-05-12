// Experiment No. 6 - Client Server Communication using UDP
// Server program
// Noel John Robert
// B20CS1147


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    printf("Client Side\n");
    char buffer[32], message[32];

    int sockfd;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in foreignAddr;
    foreignAddr.sin_family = AF_INET;
    foreignAddr.sin_addr.s_addr = INADDR_ANY;
    foreignAddr.sin_port = 3008;

    int s = sizeof(struct sockaddr_in);
    connect(sockfd, (struct sockaddr*)&foreignAddr, sizeof(foreignAddr));

    do {
       printf("Sending message to server: ");
       fgets(message, sizeof(message), stdin);
       sendto(sockfd, message, sizeof(message), 0, (struct sockaddr*)&foreignAddr, s);

       recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&foreignAddr, &s);
       printf("\nMessage received from server: %s", buffer); 
    } while (strncmp(buffer, "stop", 4) != 0);

    close(sockfd);
}

/*
OUTPUT
Client Side
Sending message to server: Initial message to server

Message received from server: Message received by server.
Sending message to server: stop

Message received from server: stop
*/