#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int N, M, K, A, B, i, j, num = 1000000, count = 0;
	scanf("%d%d%d", &N, &M, &K);
	int **neiber = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		neiber[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			neiber[i][j] = 0;
		}
	}
	for(i = 0; i < M; i++){
		scanf("%d%d", &A, &B);
		neiber[A][B] = 1;
		neiber[B][A] = 1;
	}
	int *seat = (int *)malloc(sizeof(int) * N);
	srand((unsigned)time(NULL));
	for(i = 0; i < num; i++){
//		printf("i = %d\n", i);
		for(j = 0; j < N; j++){
			seat[j] = j;
		}
		for(j = 0; j < K; j++){
			A = rand() % N;
			B = rand() % (N - 1);
			if(B >= A){
				B++;
			}
			int tmp = seat[A];
			seat[A] = seat[B];
			seat[B] = tmp;
		}
/*		printf("seat:\n");
		for(j = 0; j < N; j++){
			printf("%d ", seat[j]);
		}
		printf("\n");
*/		count++;
		for(j = 0; j < N; j++){
			if(neiber[seat[j]][seat[(j + 1) % N]] == 1){
//				printf("j = %d\n", j);
				count--;
				break;
			}
		}
//		printf("count = %d\n", count);
	}
	printf("%.9lf\n", (double)count / num);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &M, &K);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &A, &B);
   ^