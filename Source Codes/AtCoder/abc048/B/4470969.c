#include<stdio.h>


int main (void){
	long long int a = 0;
	long long int b = 0;
	long long int x = 0;
	long long int counter = 0;
	long long int reserve = 0;

	scanf("%lld",&a);
	scanf("%lld",&b);
	scanf("%lld",&x);

	reserve = (b / x);
	counter = ((a - 1) / x);

	if(a == 0){
		counter = -1;
	}

	printf("%lld\n",reserve - counter);
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&a);
  ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&b);
  ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&x);
  ^