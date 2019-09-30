#include<stdio.h>

#define max(a,b) ((a)<(b)?(a):(b))

int main(){
		long long q,h,s,d,n;
		scanf("%lld%lld%lld%lld%lld",&q,&h,&s,&d,&n);
		q=q*4;
		h=h*2;
		if(max(q,max(h,max(s,d/2+d%2)))==q)printf("%lld",n*q);
		else if(max(q,max(h,max(s,d/2+d%2)))==h)printf("%lld",n*h);
		else if(max(q,max(h,max(s,d/2+d%2)))==s)printf("%lld",n*s);
		else if(n>=2)printf("%lld",n/2*d+(n%2)*max(q,max(h,s)));
		else printf("%lld\n",n*max(q,max(h,s)));
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld%lld",&q,&h,&s,&d,&n);
   ^