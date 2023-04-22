// Experiment No.3 - Named Pipes
// Program1
// Noel John Robert
// B20CS1147


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int fd;
	char *myfifo = "saveFile.txt";
	
	mkfifo(myfifo, 0666);
	char inputBuffer[100];
	
	do {	
		printf("Input a string: ");
		fgets(inputBuffer, sizeof(inputBuffer), stdin);
		
		fd = open(myfifo, O_WRONLY);
		write(fd, inputBuffer, strlen(inputBuffer)+1);
		close(fd);
	} while(1 == 2);
	
	return 0;
}

// OUTPUT
// Input a string: This is a random string. This is for testing Named Pipes.