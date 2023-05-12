// Experiment No. 5 - Client Server Communication using TCP
// Client program
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
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in foreignAddr;
    foreignAddr.sin_family = AF_INET;
    foreignAddr.sin_addr.s_addr = INADDR_ANY;
    foreignAddr.sin_port = 3008;
    connect(sockfd, (struct sockaddr *)&foreignAddr, sizeof(foreignAddr));  // synchronization point

    do {
        printf("\nSending message to server: ");
        fgets(message, sizeof(message), stdin);
        send(sockfd, message, sizeof(message), 0);

        recv(sockfd, buffer, sizeof(buffer), 0);
        printf("\nMessage received from Server: %s", buffer);
    } while(strncmp(buffer, "stop", 4) != 0);

    close(sockfd);
    return 0;
}

/*OUTPUT
Client Side

Sending message to server: Hello there

Message received from Server: General Kenobi!

Sending message to server: stop

Message received from Server: stop
*/