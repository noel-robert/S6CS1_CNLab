// Experiment No.2 - InterProcess Communication using Pipes
// Noel John Robert
// B20CS1147

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
	FILE *file1;
	int fd1[2], fd2[2];
	char readBuffer[100], writeBuffer[100], fileName[20];
	
	int pipe1 = pipe(fd1);
	if (pipe1 == 0) printf("Pipe1 created Successfully\n");
	else if (pipe1 == -1) printf("Error in Pipe-1 creation\n");
	
	int pipe2 = pipe(fd2);
	if (pipe2 == 0) printf("Pipe2 created Successfully\n");
	else if (pipe2 == -1) printf("Error in Pipe-2 creation\n");
	
	printf("\n");
	pid_t pid = fork();
	
	if (pid < 0) { printf("Error in forking"); return 0; }
	else if (pid == 0) {
		// child process
		read(fd1[0], readBuffer, sizeof(readBuffer));
		
		file1 = fopen(readBuffer, "r");
		fgets(writeBuffer, sizeof(writeBuffer), file1);	// copy data from file to writeBuffer
		fclose(file1);
		
		write(fd2[1], writeBuffer, sizeof(writeBuffer));
	}
	else {
		// parent process
		printf("Input filename: "); scanf("%s", fileName);
		write(fd1[1], fileName, sizeof(fileName));
		
		wait(NULL);
		
		read(fd2[0], readBuffer, sizeof(readBuffer));
		printf("\nContent of file is: %s", readBuffer);
	}
	
	return 0;
}


// Content of exp2Text.txt
// Hello there

// OUTPUT
// Pipe1 created Successfully
// Pipe2 created Successfully

// Input filename: exp2Text.txt

// Content of file is: Hello there