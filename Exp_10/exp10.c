// Experiment No.10 - Distance Vector Routing Algorithm
// Noel John Robert
// 47

#include <stdio.h>
#include <stdlib.h>

struct node {
	int distance[10];	// distance to another node
	int from[10];		// distance from 'which' node
};

int main() {
	int costmatrix[20][20];
	
	int n;
	printf("Input no. of routers: "); scanf("%d", &n);
	struct node router[n];
	
	printf("Input cost matrix: ");
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			scanf("%d", &costmatrix[i][j]);
			costmatrix[i][i] = 0;
			
			// setting values in routing table for a node
			router[i].distance[j] = costmatrix[i][j];
			router[i].from[j] = j;
		}
	}
	
	// routing
	int count;
	do {
		count = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				for (int k=0; k<n; k++) {
					if (router[i].distance[j] > costmatrix[i][k] + router[k].distance[j]) {
						router[i].distance[j] = costmatrix[i][k] + router[k].distance[j];
						router[i].from[j] = k;
						count++;
					}
				}
			}
		}
	} while (count != 0);
	
	
	// final
	for (int i=0; i<n; i++) {
		printf("\n\nFor router %d\n", i);
		for (int j=0; j<n; j++) {
			printf("\tNode %d via %d, distance = %d\n", j, router[i].from[j], router[i].distance[j]);
		}
	}
	
	return 0;
}

/*OUTPUT
Input no. of routers: 3
Input cost matrix: 0 2 1 3 0 5 5 6 0


For router 0
	Node 0 via 0, distance = 0
	Node 1 via 1, distance = 2
	Node 2 via 2, distance = 1


For router 1
	Node 0 via 0, distance = 3
	Node 1 via 1, distance = 0
	Node 2 via 0, distance = 4


For router 2
	Node 0 via 0, distance = 5
	Node 1 via 1, distance = 6
	Node 2 via 2, distance = 0
*/
