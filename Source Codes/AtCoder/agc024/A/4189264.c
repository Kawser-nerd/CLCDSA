#include<stdio.h>

int main(){
		long long a,b,c,k,ans;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
		ans=a-b;
		if(k%2==1)ans=ans*(-1);
		printf("%lld\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
   ^