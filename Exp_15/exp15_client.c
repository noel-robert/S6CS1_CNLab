// Experiment No.15 - Salary Calculation, Client side
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
	printf("Client Side\n");
	
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in addr2;
	addr2.sin_family = AF_INET;
	addr2.sin_addr.s_addr = INADDR_ANY;
	addr2.sin_port = 3008;
	
	connect(sockfd, (struct sockaddr*)&addr2, sizeof(addr2));
	printf("Connection Established\n");
	
	do {
		struct Salary sal;
		printf("Input basic pay: "); scanf("%f", &sal.basicPay);
		if (sal.basicPay == 0) {
			printf("Exiting program\n");
			break;
		}
		printf("Input HRA: "); scanf("%f", &sal.hra);
		printf("Input DA: "); scanf("%f", &sal.da);
		printf("Input Professonal tax: "); scanf("%f", &sal.pt);
		printf("Input PF: "); scanf("%f", &sal.epf);
		send(sockfd, &sal, sizeof(sal), 0);
		
		char netSal[16];
		recv(sockfd, netSal, sizeof(netSal), 0);
		printf("Net Salary is %s\n\n", netSal);
	} while(true);
	printf("Connection terminated\n");
	close(sockfd);
}

/*OUTPUT
Client Side
Connection Established
Input basic pay: 25000
Input HRA: 2000
Input DA: 1000
Input Professonal tax: 1500
Input PF: 500
Net Salary is 26000.000000

Input basic pay: 0
Exiting program
Connection terminated
*/
