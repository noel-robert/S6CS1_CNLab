// Experiment No.3 - Named Pipes
// Program3
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
	int fd1;
	char *myfifo1 = "saveFileNew.txt";
	
	
	char readBuffer[100];
	do {
		fd1 = open(myfifo1, O_RDONLY);
		read(fd1, readBuffer, sizeof(readBuffer));
		close(fd1);
		
		// content display - simple
		printf("%s", readBuffer);
	} while(1 == 2);
	
	return 0;
}

// OUTPUT
// Words: 11        Sentences: 2    Characters: 45