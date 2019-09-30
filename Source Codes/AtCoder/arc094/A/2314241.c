#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int A, B, C, S, M, ans;
	scanf("%d%d%d", &A, &B, &C);
	S = A + B + C;
	M = max(A, max(B, C));
	if(S % 2 == M % 2){
		ans = 3 * M - S;
	}
	else{
		ans = 3 * (M + 1) - S;
	}
	printf("%d\n", ans / 2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &A, &B, &C);
  ^