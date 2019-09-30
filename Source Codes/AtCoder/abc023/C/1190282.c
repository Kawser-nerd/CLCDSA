#include<stdio.h>

int main(void){
	long long i,res,r,c,k,n,sr[131072],sc[131072],rc[131072]={0},cc[131072]={0},rcc[131072]={0},ccc[131072]={0};
	scanf("%lld%lld%lld%lld",&r,&c,&k,&n);
	for(i = 1;i <= n;i++){
		scanf("%lld%lld",&sr[i],&sc[i]);
		rc[sr[i]]++;cc[sc[i]]++;
	}
	for(i = 1;i <= r;i++){rcc[rc[i]]++;}
	for(i = 1;i <= c;i++){ccc[cc[i]]++;}
	res = 0;
	for(i = 0;i <= k;i++){res+=(rcc[i]*ccc[k-i]);}
	for(i = 1;i <= n;i++){
		if(rc[sr[i]]+cc[sc[i]] == k){res--;}
		if(rc[sr[i]]+cc[sc[i]] == k+1){res++;}
	}
	printf("%lld\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld",&r,&c,&k,&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&sr[i],&sc[i]);
   ^