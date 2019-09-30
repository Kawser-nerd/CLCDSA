#include<stdio.h>
#define X 1000000007

long long dist(long long a,long long b){if(a>b){return a-b;}return b-a;}

int main(void){
	long long n,m,x[131072],y[131072],i,p,s=0,t=0,a;
	scanf("%lld%lld",&n,&m);
	for(i = 1;i <= n;i++){scanf("%lld",&x[i]);}
	for(i = 1;i <= m;i++){scanf("%lld",&y[i]);}
	p = 0;
	for(i = 1;i < n;i++){
		a = (p+i*dist(x[i],x[i+1]))%X;
		s+=a;s%=X;
		p = a;
	}
	p = 0;
	for(i = 1;i < m;i++){
		a = (p+i*dist(y[i],y[i+1]))%X;
		t+=a;t%=X;
		p = a;
	}
	printf("%lld\n",(s*t)%X);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:9:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 1;i <= n;i++){scanf("%lld",&x[i]);}
                        ^
./Main.c:10:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 1;i <= m;i++){scanf("%lld",&y[i]);}
                        ^