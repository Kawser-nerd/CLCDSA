#include<stdio.h>

long long N,M;
long long a[2000],b[2000],c[2000];
long long d[1001];
long long neg[1001];

long long main(){
	
	scanf("%lld%lld",&N,&M);
	for(long long i=0;i<M;i++){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		c[i]*=-1;
	}
	
	for(long long i=2;i<=1000;i++)d[i]=99999999999999999;

	for(int j=0;j<N*2;j++){
		for(long long i=0;i<M;i++){
		
			if(neg[a[i]]==1)neg[b[i]]=1;
			if(d[a[i]]!=99999999999999999 && d[b[i]]>d[a[i]]+c[i]){
				d[b[i]]=d[a[i]]+c[i];
				if(j>=N)neg[b[i]]=1;
			}
		}
	}
	if(neg[N])printf("inf\n");
	else printf("%lld",-d[N]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&N,&M);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
   ^