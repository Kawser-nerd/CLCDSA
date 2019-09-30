#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return GCD(b, a % b);
	}
}

int main(){
	int N, A, i, g = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &A);
		g = GCD(g, A);
	}
	printf("%d\n", g);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A);
   ^