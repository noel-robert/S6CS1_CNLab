// Experiment No.14 - Sliding Window Protocol, GoBackN
// Noel John Robert
// 47

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Frame {
	int data;
	int seqNo;
	int ack;
};

int main() {
	int windowSize;
	printf("Input window size: "); scanf("%d", &windowSize);
	
	int n;
	printf("Input no of packets: "); scanf("%d", &n);
	
	struct Frame f[n];
	
	// input data
	for (int i=0; i<n; i++) {
		printf("Input data of frame %d: ", i);
		scanf("%d", &f[i].data);
		f[i].seqNo = i;
		f[i].ack = -1;
	}
	
	printf("\nTransmitting data:\n");
	int x;
	for (int i=0; i<n; i=x) {
		if (i + windowSize >= n) x = n;
		else x = i + windowSize;
		
		/*
		for (int j=i; j<x; j++) 
			printf("Sending frame %d\n", f[j].seqNo);
		printf("\n");
		*/
		printf("Sending frames from %d to %d\n\n", f[i].seqNo, f[i].seqNo+(x-i));
		
		for (int j=i; j<x; j++) {
			f[j].ack = rand()%2;
			sleep(1);
			
			if (f[j].ack) {
				printf("Acknowledgement received from frame %d\n", f[j].seqNo);
			} else {
				printf("Failed to receive acknowledgement, retransmitting...\n");
				printf("Retransmitting from %d\n", f[j].seqNo);
				sleep(1);
				x = j;
				break;
			}
		}
	}
	
	printf("Finished transmission\n");
	return 0;
}
