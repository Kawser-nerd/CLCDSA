#include<stdio.h>
#include<string.h>
#include<math.h>
int main() {
	int N;
	int T[100],i,j;
	int M;
	int P[100],X[100];
	scanf("%d",&N);
	for(i=0; i<N; i++) {
		scanf("%d",&T[i]);
	}
	scanf("%d",&M);
	for(i=0; i<M; i++) {
		scanf("%d %d",&P[i],&X[i]);
	}
	for(i=0; i<M; i++) {
		int sum=0;
		for(j=0; j<N; j++) {
			if(j!=P[i]-1) {
				sum+=T[j];
			} else {
				sum+=X[i];
			}
		}
		printf("%d\n",sum);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&T[i]);
   ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&M);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&P[i],&X[i]);
   ^