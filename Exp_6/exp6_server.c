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
    printf("Server Side\n");
    char buffer[128], message[128];

    int sockfd;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in addrport;
    addrport.sin_family = AF_INET;
    addrport.sin_addr.s_addr = INADDR_ANY;
    addrport.sin_port = 3008;

    int s = sizeof(struct sockaddr_in);
    bind(sockfd, (struct sockaddr*)&addrport, sizeof(addrport));

    do {
        printf("\nConnection Established");
        
        recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrport, &s);
        printf("Message received from client: %s", buffer);

        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);
        sendto(sockfd, message, sizeof(message), 0, (struct sockaddr*)&addrport, s);
    } while (strncmp(buffer, "stop", 4) != 0);

    close(sockfd);
}

/*
OUTPUT
Server Side

Connection EstablishedMessage received from client: Initial message to server
Enter message: Message received by server.

Connection EstablishedMessage received from client: stop
Enter message: stop
*/