#include<stdio.h>
#include<math.h>
#include<string.h>
#define T 1000000007
int main() {
	long long int a,sum=1;
	scanf("%lld",&a);
	for(int i=1;i<=a;i++){
		sum=(sum*i)%T;
	}
	printf("%lld",sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&a);
  ^