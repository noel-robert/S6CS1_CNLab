// Experiment No.9 - Implementation of SMTP using TCP.
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


struct Email {
	char destinationAddress[32];
	char sedtinationDomain[16];
	char sourceAddress[32];
	char sourceDomain[16];
	char header[64];
	char body[1024];
};

void main() {

	printf("Client Side\n");
	
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in addr1;
	addr1.sin_family = AF_INET;
	addr1.sin_addr.s_addr = INADDR_ANY;
	addr1.sin_port = 3008;
	
	connect(sockfd, (struct sockaddr*)&addr1, sizeof(addr1));
	
	do {
		printf("Connection Established\n");
		struct Email mail;
		printf("Input destination E-Mail ID: "); fgets(mail.destinationAddress, sizeof(mail.destinationAddress), stdin);
		printf("Input source E-Mail ID: "); fgets(mail.sourceAddress, sizeof(mail.sourceAddress), stdin);
		printf("Input E-Mail header: "); fgets(mail.header, sizeof(mail.header), stdin);
		printf("Input E-Mail body: "); fgets(mail.body, sizeof(mail.body), stdin);
		
		send(sockfd, &mail, sizeof(mail), 0);		
	} while(false);

	close(sockfd);
}


/*OUTPUT
Client Side
Connection Established
Input destination E-Mail ID: receiver345@hotmail.com
Input source E-Mail ID: sender1234@reddifmail.com
Input E-Mail header: Announcement
Input E-Mail body: Launch event next week
*/