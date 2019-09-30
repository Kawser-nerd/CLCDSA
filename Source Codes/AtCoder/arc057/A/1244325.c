#include <stdio.h>

long long int money,a,k,day;

int main(void)
{
	int i;
	scanf("%lld %lld",&a,&k);
	
	if(k!=0){
		for(i=0;;i++){
			money=1+k*a+a;
			a=money;
			day++;
			if(a>=2000000000000){
				printf("%lld\n",day);
				break;
			}
		}
	} else{
		printf("%lld\n",2000000000000-a);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&a,&k);
  ^