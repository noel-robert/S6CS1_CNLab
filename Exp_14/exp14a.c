// Experiment No.14(A) - Sliding Window Protocol, GoBackN
// Noel John Robert
// 47


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct Frame {
	int data;
	int seqNo;
	int ack;
};

int generateRandom() {
	srand(time(NULL));
	return rand()%2;
}

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
		
		printf("\nSending frames from %d to %d\n", f[i].seqNo, f[i].seqNo+(x-i-1));
		
		for (int j=i; j<x; j++) {

			f[j].ack = generateRandom();
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


/*OUTPUT
Input window size: 5
Input no of packets: 10
Input data of frame 0: 0
Input data of frame 1: 1
Input data of frame 2: 2
Input data of frame 3: 3
Input data of frame 4: 4
Input data of frame 5: 5
Input data of frame 6: 6
Input data of frame 7: 7
Input data of frame 8: 8
Input data of frame 9: 9

Transmitting data:

Sending frames from 0 to 4
Acknowledgement received from frame 0
Acknowledgement received from frame 1
Failed to receive acknowledgement, retransmitting...
Retransmitting from 2

Sending frames from 2 to 6
Acknowledgement received from frame 2
Failed to receive acknowledgement, retransmitting...
Retransmitting from 3

Sending frames from 3 to 7
Acknowledgement received from frame 3
Acknowledgement received from frame 4
Failed to receive acknowledgement, retransmitting...
Retransmitting from 5

Sending frames from 5 to 9
Acknowledgement received from frame 5
Failed to receive acknowledgement, retransmitting...
Retransmitting from 6

Sending frames from 6 to 9
Acknowledgement received from frame 6
Failed to receive acknowledgement, retransmitting...
Retransmitting from 7

Sending frames from 7 to 9
Acknowledgement received from frame 7
Acknowledgement received from frame 8
Acknowledgement received from frame 9
Finished transmission
*/