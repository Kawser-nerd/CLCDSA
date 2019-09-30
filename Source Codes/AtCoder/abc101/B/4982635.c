#include <stdio.h>

int digit_sum(n){
	int Sum = 0;
	while(n > 0){
		Sum += n % 10;
		n /= 10;
	}
	return Sum;
}

int main(){
	int N;
	scanf("%d", &N);
	int S_N;
	S_N = digit_sum(N);
	if(N % S_N) printf("No");
	else printf("Yes");
	
	return 0;
} ./Main.c: In function ‘digit_sum’:
./Main.c:3:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
 int digit_sum(n){
     ^
./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^