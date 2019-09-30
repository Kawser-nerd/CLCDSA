#include<stdio.h>
int main(){
	long a,b,c,d,e;
	scanf ("%ld%ld%ld",&a,&b,&c);
	d=(a*b)%1000000007;
	e=(c*d)%1000000007;
	printf ("%ld\n",e);
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%ld%ld%ld",&a,&b,&c);
  ^