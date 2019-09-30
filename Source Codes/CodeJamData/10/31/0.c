#include <stdio.h>
#include <stdlib.h>

int main() {
	int T, t;
	scanf("%d\n", &T);
	for (t = 1; t <= T; t++) {
		int N, i, C, j;
		int A[10000][2];
		
		scanf("%d", &N);
		for (i = 0; i < N; i++) scanf("%d %d", &A[i][0], &A[i][1]);
		
		C = 0;
		for (i = 0; i < N - 1; i++) {
			for (j = i+1; j < N; j++) {
				if ((A[i][0] < A[j][0] && A[i][1] > A[j][1]) ||
					(A[i][0] > A[j][0] && A[i][1] < A[j][1]))
				{
					C++;
				}
			}
		}
		
		printf("Case #%d: %d\n", t, C);
	}
	
	return 0;
}
