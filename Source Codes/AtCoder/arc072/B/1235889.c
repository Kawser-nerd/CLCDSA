#include <stdio.h>

int main(){
	long long int X, Y;
	scanf("%lld%lld", &X, &Y);
	if(X > Y + 1 || Y > X + 1){
		printf("Alice\n");
	}
	else{
		printf("Brown\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &X, &Y);
  ^