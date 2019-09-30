#include<stdio.h>

int main(){
		long long a,b,k,l,ans;
		scanf("%lld%lld%lld%lld",&a,&b,&k,&l);
		ans=k/l*b;
		if(a*(k%l)>b)ans+=b;
		else ans+=(k%l)*a;
		printf("%lld\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld",&a,&b,&k,&l);
   ^