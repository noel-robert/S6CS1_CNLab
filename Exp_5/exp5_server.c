// Experiment No. 5 - Client Server Communication using TCP
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
    printf("Server_Side\n");
    char buffer[32], message[32];

    int sockfd, newSocket;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addrport, clientAddr;
    addrport.sin_family = AF_INET;
    addrport.sin_addr.s_addr = INADDR_ANY;
    addrport.sin_port = 3008;
    bind(sockfd, (struct sockaddr *)&addrport, sizeof(addrport));

    listen(sockfd, 12);
    
    int s = sizeof(struct sockaddr_in);
    newSocket = accept(sockfd, (struct sockaddr*)&clientAddr, (&s));  // synchronization point

    do {
        printf("\nConncetion Established");

        recv(newSocket, buffer, sizeof(buffer), 0);
        printf("\nMessage received from client: %s", buffer);

        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);
        send(newSocket, message, sizeof(message), 0);
    } while(strncmp(buffer, "stop", 4) != 0);

    close(newSocket);
    close(sockfd);
    return 0;
}


/*OUTPUT
Server_Side

Conncetion Established
Message received from client: Hello there
Enter message: General Kenobi!

Conncetion Established
Message received from client: stop
Enter message: stop
*/