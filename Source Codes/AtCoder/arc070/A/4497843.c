#include <stdio.h>

int main(void){

	long long int X;
	scanf("%lld", &X);

	long long int i;
	long long kake = 0;

	for(i = 0; i < 1000000000; i++){
		
		kake  = i * (i + 1);

		if(2 * X <= kake){
			break;
		}

	}

	printf("%lld\n", i);

	return 0;

} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &X);
  ^