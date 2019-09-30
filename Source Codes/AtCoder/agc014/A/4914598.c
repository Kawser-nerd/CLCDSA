#include <stdio.h>
#include <stdlib.h>
#define ll long long int
int main(void){
	ll A,B,C,ans=0;
	scanf("%lld%lld%lld",&A,&B,&C);
	while(1){
		if(A%2==1 || B%2==1 || C%2==1)break;
		if(A==B && B==C){
			ans = -1;
			break;
		}
		ans++;
		ll a=A,b=B,c=C;
		A = (b+c)/2;
		B = (a+c)/2;
		C = (a+b)/2;
	}
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&A,&B,&C);
  ^