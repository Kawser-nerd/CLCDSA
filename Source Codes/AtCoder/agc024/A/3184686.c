#include <stdio.h>

int main(void){
    long long a,b,c,k;
    scanf("%lld %lld %lld %lld",&a,&b,&c,&k);
    if (k%2==0){
        printf("%lld\n",a-b);
    } else {
        printf("%lld\n",b-a);
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld %lld",&a,&b,&c,&k);
     ^