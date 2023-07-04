// Experiment No.11 - DNS using UDP, Server side
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

char* searchDomainNameList(char domain[64]) {
	char *domainName, *IP_Address;
	domainName = malloc(64 * sizeof(char));
	IP_Address = malloc(16 * sizeof(char));
	
	FILE* dnl;
	dnl = fopen("domainNameList.txt", "r");
	while(!feof(dnl)) {
		fscanf(dnl, "%s %s", domainName, IP_Address);
		if (strncmp(domainName, domain, strlen(domainName)) == 0) {
			fclose(dnl);
			return IP_Address;
		}
	}
	fclose(dnl);
	return "NEG";	// domain name not in file
}

int main () {
	printf("Server Side");
	char buffer[64], message[16];
	
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	struct sockaddr_in addrport;
	addrport.sin_family = AF_INET;
	addrport.sin_addr.s_addr = INADDR_ANY;
	addrport.sin_port = 3008;
	
	int s = sizeof(struct sockaddr_in);
	
	bind(sockfd, (struct sockaddr*)&addrport, sizeof(addrport));
	
	do {
		printf("\nConnection Established");
		recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrport, &s);
		if (strncmp(buffer, "stop", 4) == 0) break;
		
		strcpy(message, searchDomainNameList(buffer));
		sendto(sockfd, message, sizeof(message), 0, (struct sockaddr*)&addrport, s);
	} while (true);
	
	close(sockfd);
	return 0;
}

/*OUTPUT
Server Side
Connection Established
Connection Established
Connection Established
*/