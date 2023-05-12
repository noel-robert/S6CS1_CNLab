// Experiment No. 5 - Client Server Communication using TCP
// Client program
// Noel John Robert
// B20CS1147


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    printf("Server_Side\n");
    char buffer[256];

    int sockfd, newSocket;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr1;
    addr1.sin_family = AF_INET;
    addr1.sin_addr.s_addr = INADDR_ANY;
    addr1.sin_port = 3008;
    bind(sockfd, (struct sockaddr*)&addr1, sizeof(addr1));

    listen(sockfd, 5);
    
    newSocket = accept(sockfd, (struct sockaddr*)&addr2, );

    return 0;
}

/*TODO:
The steps involved in establishing a socket on the client side are as follows:
1.	Create a socket with the socket() system call [done]
2.	Connect the socket to the address of the server using the connect() system call
3.	Send and receive data. There are a number of ways to do this, but the simplest is to use the read() and write() system calls.
*/