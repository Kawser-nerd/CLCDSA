#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, A, B, i;
	scanf("%d%d%d", &N, &A, &B);
	int *S = (int *)malloc(sizeof(int) * N);
	double average = 0, maxS = 0, minS = 1e9;
	for(i = 0; i < N; i++){
		scanf("%d", &S[i]);
		average += S[i];
		if(maxS < S[i]){
			maxS = S[i];
		}
		if(minS > S[i]){
			minS = S[i];
		}
	}
	average /= N;
	if(maxS - minS == 0){
		printf("-1\n");
	}
	else{
		double P, Q;
		P = B / (maxS - minS);
		Q = A - P * average;
		printf("%.12lf %.12lf\n", P, Q);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &A, &B);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &S[i]);
   ^