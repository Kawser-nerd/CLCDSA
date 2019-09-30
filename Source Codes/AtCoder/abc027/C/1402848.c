#include <stdio.h>

#define int long long

signed main(){
	int N, i = 0;
	scanf("%lld", &N);
	for(i = 0, N++; N > 1; i = (i + 1) % 2){
		if(i == 0){
			N = (N + 1) / 2;
		}
		else{
			N = N / 2;
		}
	}
	if(i == 0){
		printf("Takahashi\n");
	}
	else{
		printf("Aoki\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^