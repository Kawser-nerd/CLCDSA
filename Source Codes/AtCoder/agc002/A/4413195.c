#include <stdio.h>

int main(void){

	long long int a, b;
	
	scanf("%lld", &a);
	scanf("%lld", &b);

	if(a <= 0 && b >= 0){
	
		printf("Zero\n");
		return 0;

	}else if(a < 0 && b <0){

		if((b - a)%2 == 0){
			printf("Negative\n");
			return 0;
		}else{
			printf("Positive\n");
			return 0;
		}
	}else if(a > 0 && b > 0){
	
		printf("Positive\n");
		return 0;

	}	

} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &a);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &b);
  ^