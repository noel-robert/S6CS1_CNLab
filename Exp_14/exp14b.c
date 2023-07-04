// Experiment No.14(B) - Sliding Window Protocol, Selective Repeat
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
	printf("Input no of frames to be inputted: "); scanf("%d", &n);
	
	struct Frame f[n];
	
	// input data
	for (int i=0; i<n; i++) {
		printf("Input data of frame %d: ", i);
		scanf("%d", &f[i].data);
		f[i].seqNo = i;
		f[i].ack = -1;
	}
	
	int unAckArr[windowSize], unAckArrLim = 0;
	int x;
	int retransmit = 0;

	printf("\nTransmitting data:\n");
	for (int i=0; i<n; i=x) {
		if (i + windowSize >= n) x = n;
		else x = i + windowSize;


		printf("\nSending frames from %d to %d\n", f[i].seqNo, f[i].seqNo+(x-i-1));
		
		for (int j=i; j<x; j++) {
			f[j].ack = generateRandom();
			sleep(1);
			
			if (f[j].ack) {
				printf("Acknowledgement received for frame %d\n", f[j].seqNo);
			} else {
				printf("Failed to receive acknowledgement for %d\n", f[j].seqNo);
				sleep(1);
				retransmit++;
				unAckArr[unAckArrLim++] = f[j].seqNo;
			}
		}
		
		while(retransmit) {
			for (int j=0; j<unAckArrLim; j++) {
				printf("Re-sending frame %d\n", f[unAckArr[j]].seqNo);
				f[unAckArr[j]].ack = generateRandom();
				sleep(1);
				
				if (f[j].ack) {
					printf("Acknowledgement received for frame %d\n", f[unAckArr[j]].seqNo);
					retransmit--;
				} else {
					printf("Failed to receive acknowledgement for %d, retransmitting...\n", f[unAckArr[j]].ack);
					j--;
				}
			}
		}
		
		unAckArrLim = 0;
	}
	
	printf("Finished transmission\n");
	return 0;
}


/*OUTPUT
Input window size: 5
Input no of frames to be inputted: 10
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
Failed to receive acknowledgement for 0
Acknowledgement received for frame 1
Acknowledgement received for frame 2
Acknowledgement received for frame 3
Failed to receive acknowledgement for 4
Re-sending frame 0
Failed to receive acknowledgement for 0, retransmitting...
Re-sending frame 0
Failed to receive acknowledgement for 0, retransmitting...
Re-sending frame 0
Failed to receive acknowledgement for 0, retransmitting...
Re-sending frame 0
Acknowledgement received for frame 0
Re-sending frame 4
Acknowledgement received for frame 4

Sending frames from 5 to 9
Failed to receive acknowledgement for 5
Acknowledgement received for frame 6
Acknowledgement received for frame 7
Acknowledgement received for frame 8
Acknowledgement received for frame 9
Re-sending frame 5
Acknowledgement received for frame 5
Finished transmission
*/