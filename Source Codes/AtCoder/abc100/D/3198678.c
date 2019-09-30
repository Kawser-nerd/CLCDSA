#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
	long long *A = (long long *)a;
	long long *B = (long long *)b;
	if (*A < *B) return 1;
	if (*A > *B) return -1;
	return 0;
}

int main(){
	long long N,M,i,ans=0;
	scanf("%lld%lld",&N,&M);
	
	long long x[N],y[N],z[N];
	for(i=0;i<N;i++)scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
	
	for(int k=0;k<8;k++){
		int bit=k;
		long long value[N];
		long long tmp=0;
		for(i=0;i<N;i++)value[i]=0;
		
		if(bit%2==0)for(i=0;i<N;i++)value[i]+=x[i];
		else for(i=0;i<N;i++)value[i]-=x[i];
		
		bit/=2;
		if(bit%2==0)for(i=0;i<N;i++)value[i]+=y[i];
		else for(i=0;i<N;i++)value[i]-=y[i];
		
		bit/=2;
		if(bit%2==0)for(i=0;i<N;i++)value[i]+=z[i];
		else for(i=0;i<N;i++)value[i]-=z[i];
		
		qsort(value,N,sizeof(long long),compare);
		
		for(i=0;i<M;i++)tmp+=value[i];
		if(tmp>ans)ans=tmp;
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&N,&M);
  ^
./Main.c:17:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<N;i++)scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
                  ^