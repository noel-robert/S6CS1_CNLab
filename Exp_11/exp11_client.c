// Experiment No.11 - DNS using UDP, Client side
// Noel John Robert
// 47

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdbool.h>

int main () {
	printf("Client Side");
	char buffer[16], message[64];
	
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	struct sockaddr_in foreignAddr;
	foreignAddr.sin_family = AF_INET;
	foreignAddr.sin_addr.s_addr = INADDR_ANY;
	foreignAddr.sin_port = 3008;
	
	int s = sizeof(struct sockaddr_in);
	connect(sockfd, (struct sockaddr*)&foreignAddr, sizeof(foreignAddr));
	
	do {
		printf("\nInput domain name: ");
		fgets(message, sizeof(message), stdin);
		sendto(sockfd, message, sizeof(message), 0, (struct sockaddr*)&foreignAddr, s);
		if (strncmp(message, "stop", 4) == 0) break;
		
		recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&foreignAddr, &s);
		if (strncmp(buffer, "NEG", 4) == 0) {
			printf("Domain not found\n");
			continue;
		}
		printf("IP Address of domain %s is %s", message, buffer);
	} while (true);
}
