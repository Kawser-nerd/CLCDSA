#include <stdio.h>

int main(){
	int N, k;
	scanf("%d%d", &N, &k);
	if(N / 2 >= k){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &k);
  ^