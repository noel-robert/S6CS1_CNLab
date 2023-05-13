// Experiment No. 8 - Implementation of FTP using TCP.
// Client1 program
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


int main () {
    printf("Client1\n");
    char buffer[512], message[32];  // buffer stores content of file

    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in foreignAddr;
    foreignAddr.sin_family = AF_INET;
    foreignAddr.sin_addr.s_addr = INADDR_ANY;
    foreignAddr.sin_port = 3008;
    connect(sockfd, (struct sockaddr*)&foreignAddr, sizeof(foreignAddr));
    
    
    do {
        printf("\nInput filename: ");
        scanf("%s", message);
        if (strncmp(message, "stop", 4) == 0) break;
        send(sockfd, message, sizeof(message), 0);

        recv(sockfd, buffer, sizeof(buffer), 0);
        printf("\nContent of file is: %s\n", buffer);
    } while (true);
    
    close(sockfd);
    return 0;
}


/*OUTPUT
Client1

Input filename: testfile1.txt

Content of file is: Placeholder text in testfile1 to be accessed by Server upon request from Client1.

Input filename: stop
*/