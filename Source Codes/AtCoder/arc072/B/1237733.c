#include<stdio.h>

long long diff(long long a,long long b){if(a>b){return a-b;}return b-a;}

int main(void){
	long long a,b;
	scanf("%lld%lld",&a,&b);
	if(diff(a,b) <= 1){printf("Brown\n");}else{printf("Alice\n");}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&a,&b);
  ^