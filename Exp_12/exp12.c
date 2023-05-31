// Experiment No.12 - Leaky Bucket Algorithm
// Noel John Robert
// 47

#include <stdio.h>
#include <stdlib.h>

int main() {
	int incomingSize, outgoingRate, bucketSize, n, store = 0;
	
	printf("Enter bucket size: "); scanf("%d", &bucketSize);
	printf("Enter outgoing rate: "); scanf("%d", &outgoingRate);
	printf("Enter no. of inputs: "); scanf("%d", &n);
	
	
	while (n != 0) {
		printf("Input incoming packet size: ");
		scanf("%d", &incomingSize);
		if (incomingSize < 0) {
			printf("Negative input size not possible");
			n--;
			continue;
		}
		
		if (incomingSize <= (bucketSize - store)) {
			store += incomingSize;
			printf("Bucket Buffer size %d out of %d\n", store, bucketSize);
		} else {
			/*
			int empty = bucketSize - store;
			int drop = incomingSize - empty;
			printf("Dropped %d packet(s)\n", drop);
			store += incomingSize - drop;
			printf("Bucket Buffer size: %d out of %d\n", store, bucketSize);
			store = bucketSize;
			*/
			printf("Packet dropped\n");
		}
		
		store = store - outgoingRate;
		if (store < 0) store = 0;
		
		printf("After outgoing, %d packets left out of %d\n\n", store, bucketSize);
		
		n--;
	}
	
	return 0;
}

/*OUTPUT
Enter bucket size: 50
Enter outgoing rate: 10
Enter no. of inputs: 6
Input incoming packet size: 15
Bucket Buffer size 15 out of 50
After outgoing, 5 packets left out of 50

Input incoming packet size: 50
Packet dropped
After outgoing, 0 packets left out of 50

Input incoming packet size: 60
Packet dropped
After outgoing, 0 packets left out of 50

Input incoming packet size: 35
Bucket Buffer size 35 out of 50
After outgoing, 25 packets left out of 50

Input incoming packet size: 45
Packet dropped
After outgoing, 15 packets left out of 50

Input incoming packet size: 35
Bucket Buffer size 50 out of 50
After outgoing, 40 packets left out of 50

*/
