#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

void swap(int& a, int& b) {
	int t = a;
	a = b; 
	b = t;
}
void sort3(int& x1, int& x2, int& x3) {
	if (x1 > x2)
		swap(x1, x2);
	if (x1 > x3)
		swap(x1, x3);
	if (x2 > x3)
		swap(x2, x3);
}

int main() {
	int x1, x2, x3;
	
	int n = 0;
	int products[70][150], guess[70][3];
	memset(products, 0, sizeof(products));

	for (int x1 = 2; x1 <= 5; x1++) 
		for (int x2 = 2; x2 <= 5; x2++)
			for (int x3 = 2; x3 <= 5; x3++) {
				products[n][1]++;
				products[n][x3]++;
				products[n][x2]++;
				products[n][x2*x3]++;
				products[n][x1]++;
				products[n][x1*x3]++;
				products[n][x1*x2]++;
				products[n][x1*x2*x3]++;
				
				guess[n][0] = x1; 
				guess[n][1] = x2;
				guess[n][2] = x3;
				n++;
			}
	int t;
	scanf("%d %d %d %d %d", &t, &t, &t, &t, &t);
	
	printf("Case #1:\n");
	int R = 100, K = 7;
	for (int r = 0; r < R; r++) {
		int p[7];
		for (int k = 0; k < K; k++) {
			scanf("%d", &p[k]);
			//printf("[%d]", p[k]);
		}		
		
		int g[7][7][7];
		memset(g, 0, sizeof(g));	
		for (int i = 0; i < n; i++) {
			int isvalid = 1;
			for (int k = 0; k < K; k++) {
				if (products[i][p[k]] == 0) {
					isvalid = 0;
					break;
				}
			}
			
			if (isvalid == 1) {
				int x1 = guess[i][0];
				int x2 = guess[i][1];
				int x3 = guess[i][2];
				//printf("%d %d %d\n", x1, x2, x3);
				sort3(x1, x2, x3);
				g[x1][x2][x3]++;
			}
		}
			
		int maxV = 0, maxX[3];
		for (int x1 = 2; x1 <= 5; x1++) 
			for (int x2 = 2; x2 <= 5; x2++)
				for (int x3 = 2; x3 <= 5; x3++) {
					if (g[x1][x2][x3] > maxV) {
						//printf("---> %d %d %d\n", x1, x2, x3);
						maxV = g[x1][x2][x3];
						maxX[0] = x1; maxX[1] = x2; maxX[2] = x3;
					}
				}
				
		printf("%d%d%d\n", maxX[0], maxX[1], maxX[2]);
	}
}
