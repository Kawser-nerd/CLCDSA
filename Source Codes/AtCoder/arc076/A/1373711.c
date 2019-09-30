#include<stdio.h>

int main(int argc, char const *argv[]){
	long long i,n,m,a,b,p=1000000007;
	scanf("%lld %lld",&n,&m);
	if(n==m){
		a=1;
		for(i=n;i>0;i--){
			a*=i;
			a%=p;
		}
		printf("%lld\n",(a*2%p)*a%p);
	}else if(n==(m+1)){
		a=1;
		for(i=m;i>0;i--){
			a*=i;
			a%=p;
		}
		b=a*n%p;
		printf("%lld\n",a*b%p);
	}else if(m==(n+1)){
		a=1;
		for(i=n;i>0;i--){
			a*=i;
			a%=p;
		}
		b=a*m%p;
		printf("%lld\n",a*b%p);
	}else printf("0\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&n,&m);
  ^