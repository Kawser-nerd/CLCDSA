#include<stdio.h>
#define L long long
L F(L A,L B){return B?A/B*B*2+F(B,A%B):-A;}
main(){
	L N,X;
	scanf("%lld%lld",&N,&X);
	printf("%lld",N+F(N-X,X));
} ./Main.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&N,&X);
  ^