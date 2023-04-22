// Experiment No.3 - Named Pipes
// Program2
// Noel John Robert
// B20CS1147


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int fd, fd1;
	char *myfifo = "saveFile.txt";
	char *myfifo1 = "saveFileNew.txt";

	
	char readBuffer[100], writeBuffer[100];
	do {
		fd = open(myfifo, O_RDONLY);
		read(fd, readBuffer, sizeof(readBuffer));
		close(fd);
		
		// do operations - words, chrararcters, sentences
		int sentenceCount = 0, wordCount = 0, charCount = 0;
		for(int i=0; i<strlen(readBuffer)-1; i++) {
			if (isalnum(readBuffer[i])) charCount++;
			else if (readBuffer[i] == '.') sentenceCount++; 
			else if (isblank(readBuffer[i])) {wordCount++;}
		}
		
		wordCount++;	// to account for final word
		sprintf(writeBuffer, "Words: %d\t Sentences: %d\t Characters: %d\n", wordCount, sentenceCount, charCount);
		fd1 = open(myfifo1, O_WRONLY);
		write(fd1, writeBuffer, strlen(writeBuffer));
		close(fd1);
	} while(1 == 2);
	
	return 0;
}