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

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
	int T, t;
	scanf("%d\n", &T);
	for (int t = 1; t <= T; t++) {
		int E, R, N;
		scanf("%d %d %d\n", &E, &R, &N);
		int M[50][50];
		memset(M, 0, sizeof(M));
		for (int i = 0; i < N; i++) {
			int V;
			scanf("%d", &V);
			if (i == 0) {
				for (int j = 0; j <= E; j++) {
					M[0][min(E, E-j+R)] = j * V;
				}
			}
			else {
				for (int j = R; j <= E; j++) {
					M[i][j] = 0;
					for (int k = R; k <= E; k++) {
						for (int spend = 0; spend <= k; spend++) {
							int remain = min(E, k - spend + R);
							if (remain == j) {
								M[i][j] = max(M[i][j], M[i-1][k] + spend*V);
							}
						}
					}
				}
			}
		}
		
		int maxV = 0;
		for (int i = 0; i <= E; i++) {
			maxV = max(maxV, M[N-1][i]);
		}
		printf("Case #%d: %d\n", t, maxV);
	}
}
