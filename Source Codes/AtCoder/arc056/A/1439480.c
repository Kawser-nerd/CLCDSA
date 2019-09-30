#include <stdio.h>

int main(void)
{
	long long int a,b,k,l,sum,sum2;
	scanf("%lld %lld %lld %lld",&a,&b,&k,&l);
	
	sum=(k/l)*b+(k%l)*a;
	if(k%l!=0){
		sum2=((k/l)+1)*b;
	} else{
		sum2=(k/l)*b;
	}
	
	if(sum>sum2){
		printf("%lld\n",sum2);
	} else{
		printf("%lld\n",sum);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld %lld",&a,&b,&k,&l);
  ^