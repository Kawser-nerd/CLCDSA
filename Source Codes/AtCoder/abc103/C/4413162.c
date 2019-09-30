#include <stdio.h>

int main(void){

	int N;
	int a[1000000];

	scanf("%d", &N);
	
	int i;

	for(i = 1; i <= N; i++ ){
		scanf("%d", &a[i]);
	}

	int ans = 0;
	int ANS = 0;

	for(i = 1; i <= N; i++){
		ans = a[i] - 1;
		ANS = ANS + ans;
	}
	
	printf("%d\n", ANS);
	
	return 0;

} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^