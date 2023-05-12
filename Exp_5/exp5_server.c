// Experiment No. 5 - Client Server Communication using TCP
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

int main() {


    return 0;
}


/*TODO:
The steps involved in establishing a socket on the server side are as follows:
1.	Create a socket with the socket() system call
2.	Bind the socket to an address using the bind() system call. For a server socket on the Internet, an address consists of a port number on the host machine.
3.	Listen for connections with the listen() system call
4.	Accept a connection with the accept() system call. This call typically blocks until a client connects with the server.
5.	Send and receive data
*/