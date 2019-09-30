#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N ,i;
	scanf("%d", &N);
	char *S = (char *)malloc(sizeof(char) * (N + 1));
	scanf("%s", S);
	int *L = (int *)malloc(sizeof(int) * N);
	int *R = (int *)malloc(sizeof(int) * N);
	L[0] = (S[0] == 'E' ? 0 : 1);
	for(i = 1; i < N; i++){
		L[i] = L[i - 1] + (S[i] == 'E' ? 0 : 1);
	}
	R[N - 1] = (S[N - 1] == 'W' ? 0 : 1);
	for(i = N - 2; i >= 0; i--){
		R[i] = R[i + 1] + (S[i] == 'W' ? 0 : 1);
	}
	int ans = min(L[N - 2], R[1]);
	for(i = 1; i < N - 1; i++){
		ans = min(ans, L[i - 1] + R[i + 1]);
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^