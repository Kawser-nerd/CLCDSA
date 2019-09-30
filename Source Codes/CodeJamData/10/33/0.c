#include <stdio.h>
#include <stdlib.h>

int A[600][600], M, N;

int check(int m, int n, int size) {
	int i, j;
	
	int V = A[m][n] == 0 ? 1 : 0;	
	for (i = m; i < m + size; i++) {
		if (i != m)
			V = A[i-1][n] == 0 ? 0 : 1;
		for (j = n; j < n + size; j++) {
			//printf("[%d]", A[i][j]);
			if (A[i][j] == 2) {
				return 0;
			} 
			if (A[i][j] != V) {
				V = A[i][j];
			} else {
				return 0;
			}			
		}
	}
	
	for (i = m; i < m + size; i++) {
		for (j = n; j < n + size; j++) {
			A[i][j] = 2;
		}
	}
	
	return 1;
}

int search(int size) {
	int i, j, C = 0;
	for (i = 0; i <= M - size; i++) {
		for (j = 0; j <= N - size; j++) {
			if (check(i, j, size) == 1) {
				C++;
			}
		}
	}
	
	return C;
}


int main() {
	int T, t, i,j,k;
	char Line[800];

	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d %d", &M, &N);
		for (i = 0; i < M; i++) {
			scanf("%s", &Line);
			for (j = 0; j < N/4; j++) {
				int V = 0;
				if (Line[j] >= '0' && Line[j] <= '9') {
					V = Line[j] - '0';
				}
				else {
					V = Line[j] - 'A' + 10;
				}
				
				A[i][j*4+3] = V % 2; V/=2;
				A[i][j*4+2] = V % 2; V/=2;
				A[i][j*4+1] = V % 2; V/=2;
				A[i][j*4+0] = V % 2; V/=2;
			}
		}

		int Count = 0;
		int R[800];
		int Max = M > N ? N : M;
		for (i = Max; i >= 1; i--) {
			R[i] = search(i);
			if (R[i] != 0)
				Count++;
		}
		/*
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				printf("%d", A[i][j]);
			}
			printf("\n");
		}
		*/
		printf("Case #%d: %d\n", t, Count);
		for (i = Max; i >= 1; i--) {
			if (R[i] != 0) 
			{
				printf("%d %d\n", i, R[i]);
			}
		}
		
	}
	
	return 0;
}
