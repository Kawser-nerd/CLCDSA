#include<stdio.h>
#include<stdlib.h>

int compare(const void *a,const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	long long N,M,s=0,ans=0;
	scanf("%lld %lld",&N,&M);
	
	long long A[N];
	long long sum[N+1];
	sum[0]=0;
	for(long long i=0;i<N;i++){
		scanf("%lld",&A[i]);
		s=(s+A[i])%M;
		sum[i+1]=s;
	}
	
	qsort(sum,N+1,sizeof(long long int),compare);
	
	long long c=1;
	for(long long int i=0;i<N;i++){
		if(sum[i]==sum[i+1])c++;
		else{
			if(c>1)ans+=c*(c-1)/2;
			c=1;
		}
	}
	ans+=c*(c-1)/2;
	
	printf("%lld\n",ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&N,&M);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&A[i]);
   ^