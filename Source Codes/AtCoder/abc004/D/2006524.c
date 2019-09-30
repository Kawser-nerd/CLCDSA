#include <stdio.h>

int sum(int N){
	return (N * (N + 1)) / 2;
}

int op_num(int x, int N){
	if(x + N <= 0){
		return sum(-x) - sum(-x - N);
	}
	else if(x >= 0){
		return sum(x + N - 1) - sum(x - 1);
	}
	else{
		return sum(-x) + sum(x + N - 1);
	}
}

int min(int a, int b){
	return a <= b ? a : b;
}

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int R, G, B, i, j, k, ans = (int)(1e9);
	scanf("%d%d%d", &R, &G, &B);
	for(i = -1000; i <= 0; i++){
		for(j = 1; j <= 2000; j++){
			k = max(i + R + j + G - 1, 100 - B / 2);
			ans = min(ans, op_num(i + 100, R) + op_num(i + R + j - 1, G) + op_num(k - 100, B));
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &R, &G, &B);
  ^