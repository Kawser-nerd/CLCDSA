#include<stdio.h>
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int main(){
	long long a,b,n=0,m=0,i,c=1;
	scanf("%lld/%lld",&a,&b);
	i=gcd(a,b);
	a/=i;
	b/=i;//printf("%lld\n",i);
	for(i=(2*a-b)/b/b;1;i++){
		n=i*b;
		m=(n*(n+1))/2-i*a;
		if(m<=0)continue;
		if(n<m)break;
		printf("%lld %lld\n",n,m);
		c=0;
	}
	if(c)printf("Impossible\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld/%lld",&a,&b);
  ^