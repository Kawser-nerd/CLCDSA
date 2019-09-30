#include <stdio.h>
#include <stdlib.h>

int compare_long(const void *a, const void *b) {long *A = (long *)a;long *B = (long *)b;if (*A > *B) return 1;if (*A < *B) return -1;return 0;}

int main(void){
	int N,i;
	long long M;
	scanf("%d%lld",&N,&M);
	long long A[N+1],B[N+1],ans=0;
	A[0] = 0;
	for(i=1;i<=N;i++)scanf("%lld",&A[i]);
	for(i=1;i<=N;i++)A[i] = (A[i]+A[i-1])%M;
	qsort(A, N+1, sizeof(long long), compare_long);
	
	int j=0;
	B[0]=1;
	for(i=1;i<=N;i++){
		if(A[i]==A[i-1])B[j]++;
		else B[++j] = 1;
	}
	for(i=0;i<=j;i++){
		ans += (B[i]*(B[i]-1))/2;
	}
	
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%lld",&N,&M);
  ^
./Main.c:12:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=1;i<=N;i++)scanf("%lld",&A[i]);
                   ^