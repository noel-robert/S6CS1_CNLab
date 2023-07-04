// Experiment No.15 - Salary Calculation, Server side
// Noel John Robert
// 47

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct Salary {
	float basicPay;
	float hra;
	float da;
	float pt;
	float epf;
	// double netSalary;
};

void main() {
	printf("Server Side\n");
	
	int sockfd, newSocket;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in addr1, addr2;
	addr1.sin_family = AF_INET;
	addr1.sin_addr.s_addr = INADDR_ANY;
	addr1.sin_port = 3008;
	
	bind(sockfd, (struct sockaddr*)&addr1, sizeof(addr1));
	listen(sockfd, 5);
	
	int s = sizeof(struct sockaddr_in);
	newSocket = accept(sockfd, (struct sockaddr*)&addr2, (&s));
	printf("Connection Established\n");
	
	do {
		struct Salary sal;
		recv(newSocket, &sal, sizeof(sal), 0);
		
		if (sal.basicPay == 0) {
			printf("Exiting program\n");
			break;
		}
		
		printf("Data received from client\n");
		printf("Basic Pay: %f\n", sal.basicPay);
		printf("HRA: %f\n", sal.hra);
		printf("DA: %f\n", sal.da);
		printf("Professional Tax: %f\n", sal.pt);
		printf("EPF: %f\n\n", sal.epf);
		double net = sal.basicPay + sal.hra + sal.da - sal.pt - sal.epf;
		char netSal[16];
		sprintf(netSal, "%f", net);
		
		send(newSocket, netSal, sizeof(netSal), 0);
	} while(true);
	
	printf("Connection terminated\n");
	close(newSocket);
	close(sockfd);
}


/*OUTPUT
Server Side
Connection Established
Data received from client
Basic Pay: 25000.000000
HRA: 2000.000000
DA: 1000.000000
Professional Tax: 1500.000000
EPF: 500.000000
*/
