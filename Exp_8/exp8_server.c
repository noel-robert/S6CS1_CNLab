// Experiment No. 8 - Implementation of FTP using TCP.
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


int main () {
    printf("Server\n");
    char buffer[32], message[512];  // buffer stores filename received

    int sockfd, clientSocket;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addrport, clientAddr;
    addrport.sin_family = AF_INET;
    addrport.sin_addr.s_addr = INADDR_ANY;
    addrport.sin_port = 3008;
    bind(sockfd, (struct sockaddr*)&addrport, sizeof(addrport));

    listen(sockfd, 10);

    int s = sizeof(struct sockaddr_in);
    // clientSocket = accept(sockfd, (struct sockaddr*)&clientAddr, &s);


    do {
        clientSocket = accept(sockfd, (struct sockaddr*)&clientAddr, &s);
        printf("\nConnection Established\n");

        recv(clientSocket, buffer, sizeof(buffer), 0);
        if (strncmp(buffer, "stop", 4) == 0) break;
        printf("Filename: %s", buffer);

        FILE *file1 = fopen(buffer, "r");
		fgets(message, sizeof(message), file1);
		fclose(file1);
		
		printf("\nSending data in %s to client\n", buffer);
		send(clientSocket, message, sizeof(message), 0);
        close(clientSocket);
    } while (true);

    // close(clientSocket);
    close(sockfd);
    return 0;
}


/*OUTPUT
Server

Connection Established
Filename: testfile1.txt
Sending data in testfile1.txt to client

Connection Established
Filename: testfile2.txt
Sending data in testfile2.txt to client
^C
*/