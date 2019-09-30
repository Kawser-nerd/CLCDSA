#include<stdio.h>

int main(){
	long long x,m=1e9+7;
	scanf("%lld",&x);
	long long a,b=1,c,d;
	for(a=1;a<=x;a++){
		b*=a;
		b=b%m;
	} 
	printf("%d",b);
} ./Main.c: In function ‘main’:
./Main.c:11:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%d",b);
         ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&x);
  ^