#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
	long long int *A = (long long int *)a;
	long long int *B = (long long int *)b;
	if (*A > *B) return 1;
	if (*A < *B) return -1;
	return 0;
}

int main(){
	long long N,i,ans=0;
	scanf("%lld",&N);
	long long A[N],sum[N+1];
	sum[0]=0;
	for(i=0;i<N;i++){
		scanf("%lld",&A[i]);
		sum[i+1]=0;
		sum[i+1]=sum[i]+A[i];
	}
	
	qsort(sum,N+1,sizeof(long long),compare);
	
	long long c=1;
	for(i=0;i<N;i++){
		if(sum[i]==sum[i+1])c++;
		else{
			ans+=c*(c-1)/2;
			c=1;
		}
	}
	ans+=c*(c-1)/2;
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&N);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&A[i]);
   ^