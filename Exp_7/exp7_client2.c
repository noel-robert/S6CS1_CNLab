// Experiment No. 7 - System Time request using UDP.
// Client-2 program
// Noel John Robert
// B20CS1147 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>


int main () {
    printf("Client2\n");
    char message[128];
    char systemTime[32];

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
        if (strncmp(message, "stop", 4) == 0) break;

        recvfrom(sockfd, systemTime, sizeof(systemTime), 0, (struct sockaddr*)&foreignAddr, &s);
        printf("Current time is: %s\n", systemTime);
    } while (true);

    return 0;
}


/*OUTPUT
Client2
Sending message to server: time2
Current time is: Fri May 12 22:59:19 2023

Sending message to server: time4
Current time is: Fri May 12 22:59:26 2023

Sending message to server: stop
*/