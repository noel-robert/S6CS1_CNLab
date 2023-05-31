// Experiment No.13 - Stop and Wait Protocol
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
	int n;
	printf("Input no of frames to be sent: "); scanf("%d", &n);
	
	struct Frame f[n];
	
	// input data
	for (int i=0; i<n; i++) {
		printf("Input data of frame %d: ", i);
		scanf("%d", &f[i].data);
		f[i].seqNo = i;
		f[i].ack = -1;
	}
	
	printf("\nTransmitting Data:\n");
	
	for (int i=0; i<n; i++) {
		printf("Sending frame %d\n", f[i].seqNo);
		f[i].ack = generateRandom();
		
		sleep(1);
		
		if (f[i].ack) {
			printf("Acknowledgement received from frame %d\n\n", f[i].seqNo);
		} else {
			printf("Failed to receive acknowledgement, retransmitting...\n");
			i--;
		}
	}
	
	printf("Finished transmission\n");
	
	return 0;
}


/*OUTPUT
Input no of frames to be sent: 6
Input data of frame 0: 0
Input data of frame 1: 1
Input data of frame 2: 2
Input data of frame 3: 3
Input data of frame 4: 4
Input data of frame 5: 5

Transmitting Data:
Sending frame 0
Acknowledgement received from frame 0

Sending frame 1
Acknowledgement received from frame 1

Sending frame 2
Failed to receive acknowledgement, retransmitting...
Sending frame 2
Failed to receive acknowledgement, retransmitting...
Sending frame 2
Failed to receive acknowledgement, retransmitting...
Sending frame 2
Acknowledgement received from frame 2

Sending frame 3
Acknowledgement received from frame 3

Sending frame 4
Failed to receive acknowledgement, retransmitting...
Sending frame 4
Acknowledgement received from frame 4

Sending frame 5
Acknowledgement received from frame 5

Finished transmission
*/