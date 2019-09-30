#include <stdio.h>
#define mod 1000000007 //10^9+7

long long calc(long long a,long long b){
	if(b==0)return 1;
	if(b%2==0){
		long long d = calc(a,b/2);
		return (d*d)%mod;
	}return (a*calc(a,b-1))%mod;
}

long long comb(long long n,long long m){
	long long tmp=1,tmp2=1;
	for(int i=n;i>=n-m+1;i--)tmp=(tmp*i)%mod;
	for(int i=1;i<=m;i++)tmp2 = (tmp2*i)%mod;
	return (tmp*calc(tmp2,mod-2))%mod;
}

int main(void){
	int N,i,p[100000]={0};
	long long M,m,ans=1,k=0;
	scanf("%d%lld",&N,&M);
	m=M;
	for(i=2;i*i<=M;i++){
		while(m%i==0){
			m/=i;
			p[k]++;
		}
		k++;
	}
	if(m>1)p[k]++;
	
	for(i=0;i<=k;i++){
		if(p[i]!=0)
		ans *= comb(p[i]+N-1,p[i]);
		ans %= mod;
	}
	
	printf("%lld",ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%lld",&N,&M);
  ^