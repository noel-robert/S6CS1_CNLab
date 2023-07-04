// Experiment No. 7 - System Time request using UDP.
// Server program
// Noel John Robert
// B20CS1147 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>


int main () {
    printf("Server\n");
    char buffer[128];

    int sockfd;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in addrport;
    addrport.sin_family = AF_INET;
    addrport.sin_addr.s_addr = INADDR_ANY;
    addrport.sin_port = 3008;

    int s = sizeof(struct sockaddr_in);
    bind(sockfd, (struct sockaddr*)&addrport, sizeof(addrport));

    time_t rawTime;
    char systemTime[32];

    do {
        printf("\Connection Established");
        recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrport, &s);
        printf("\nMessage received from client: %s", buffer);

        time(&rawTime);
        strcpy(systemTime, ctime(&rawTime));

        sendto(sockfd, systemTime, sizeof(systemTime), 0, (struct sockaddr*)&addrport, s);
    } while (strncmp(buffer, "stop", 4) != 0);

    close(sockfd);
    return 0;
}


/*OUTPUT
Server

Connection Established
Message received from client: time1

Connection Established
Message received from client: time2

Connection Established
Message received from client: time3

Connection Established
Message received from client: time4

Connection Established
Message received from client: stop
*/