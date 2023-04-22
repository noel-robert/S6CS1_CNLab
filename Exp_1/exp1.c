// Experiment No.1 - Fork Implementation
// Noel John Robert
// B20CS1147

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {	
	printf("Input no. of elements in array: ");
	int n; scanf("%d", &n);
	int arr[n];
	
	printf("Input %d elements into array: ", n);
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	
	
	
	pid_t pid = fork();
	
	if (pid < 0) { printf("Error in forking"); return 0; }
	else if (pid == 0) { 
		printf("Child process\n");
		printf("Array in descending order ");
		
		for(int i=0; i<n-1; i++) {
			for(int j=0; j<n-i-1; j++) {
				if (arr[j] < arr[j+1]) {
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		for(int i=0; i<n; i++) printf("%d ", arr[i]);
		printf("\n");
	} else {
		printf("Parent process\n");
		printf("Array in ascending order ");
		
		for(int i=0; i<n-1; i++) {
			for(int j=0; j<n-i-1; j++) {
				if (arr[j] > arr[j+1]) {
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		for(int i=0; i<n; i++) printf("%d ", arr[i]);	
		printf("\n");
	}
	return 0;
}

// Output
// Input no. of elements in array: 7
// Input 7 elements into array: 2 9 8 10 63 45 0
// Parent process
// Array in ascending order 0 2 8 9 10 45 63 
// Child process
// Array in descending order 63 45 10 9 8 2 0