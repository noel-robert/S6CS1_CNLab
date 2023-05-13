// Experiment No.9 - Implementation of SMTP using TCP.
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


struct Email {
	char destinationAddress[32];
	char destinationDomain[16];
	char sourceAddress[32];
	char sourceDomain[16];
	char header[64];
	char body[1024];
};

char* extract(char address[32]) {
	char *domain;
	int start, end;
	start = end = strlen(address);

	for (int i=0; i<strlen(address); i++) {
		if (address[i] == '@')
			start = i+1;
		if (i > start && address[i] == '.')
			end = i;
	}

	int domainLength = end - start;
	domain = malloc(domainLength * sizeof(char));

	int pos = 0;
	while (pos < domainLength) { 
		domain[pos] = address[start+pos]; 
		pos++; 
	}
	domain[pos] = '\0';

	return domain;
}

void main() {
	printf("Server Side\n");
	
	int sockfd, newsocket;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in addr1, addr2;
	addr1.sin_family = AF_INET;
	addr1.sin_addr.s_addr = INADDR_ANY;
	addr1.sin_port = 3008;
	
	bind(sockfd, (struct sockaddr*)&addr1, sizeof(addr1));
	listen(sockfd, 5);
	
	int s = sizeof(struct sockaddr_in);
	newsocket = accept(sockfd, (struct sockaddr*)&addr2, (&s));
	
	do {
		printf("Connection Established\n");
		struct Email mail;
		recv(newsocket, &mail, sizeof(mail), 0);
		
		printf("Input destination E-Mail ID: %s\n", mail.destinationAddress);
		printf("Input source E-Mail ID: %s\n", mail.sourceAddress);
		printf("Input E-Mail header: %s\n", mail.header);
		printf("Input E-Mail body: %s\n", mail.body);

		// operations
		strcpy(mail.destinationDomain, extract(mail.destinationAddress));
		strcpy(mail.sourceDomain, extract(mail.sourceAddress));

		printf("Destination E-Mail Domain: %s\n", mail.destinationDomain);
		printf("Source E-Mail Domain: %s\n", mail.sourceDomain);
	} while(false);
	
	close(newsocket);
	close(sockfd);
}


/*OUTPUT
Server Side
Connection Established
Input destination E-Mail ID: receiver345@hotmail.com

Input source E-Mail ID: sender1234@reddifmail.com

Input E-Mail header: Announcement

Input E-Mail body: Event launch on the next week.

Destination E-Mail Domain: hotmail
Source E-Mail Domain: reddifmail
*/