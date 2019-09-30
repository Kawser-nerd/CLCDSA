#include<stdio.h>

int main(){
		long long l,x,y,s,d;
		scanf("%lld%lld%lld%lld%lld",&l,&x,&y,&s,&d);
		d+=l;
		if((d-s)%l<=l*(x+y)/(double)(2*y)||y-x<0){
				printf("%.9f\n",((d-s)%l)/(double)(x+y));
		}
		else printf("%.9f\n",(l-((d-s)%l))/(double)(y-x));
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld%lld",&l,&x,&y,&s,&d);
   ^