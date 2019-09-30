#include <stdio.h>
int n;
int ten[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int aaa[4]={3,5,7};
int result=0;


int main(){
	long long int a,b,c,k;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
	
	if(k%2==0)
	{
		printf("%lld",a-b);
	}else
	{
		printf("%lld",b-a);
	}
	} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
  ^