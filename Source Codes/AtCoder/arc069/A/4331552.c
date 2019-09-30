#include<stdio.h>
#include<math.h>
#include<string.h>
int main() {
	long long int m,n,num;//n?S,m?C 
	scanf("%lld %lld",&n,&m);
	if(2*n<m){
		num=(2*n+m)/4;
	}else if(2*n==m){
		num=n;
	}else{
		num=m/2;
	}
	printf("%lld",num);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&n,&m);
  ^