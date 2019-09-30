#include <stdio.h>

int main(void){

	long long int A, B, C;

	scanf("%lld", &A);
	scanf("%lld", &B);
	scanf("%lld", &C);

	long long int min = 0;

	if(A%2 == 0 || B%2 == 0 || C%2 == 0){
		
		printf("%lld\n", min);
		return 0;
	
	}else if(A%2 != 0 && B%2 != 0 && C%2 != 0){
	
		long long int temp = 0;

		if(A > B){
			temp = A;
			A = B;
			B = temp;
		}
		
		if(B > C){
			temp = B;
			B = C;
			C = temp;
		}

	min = A * B;
	
	printf("%lld\n", min);

	}


	return 0;

} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &A);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &B);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &C);
  ^