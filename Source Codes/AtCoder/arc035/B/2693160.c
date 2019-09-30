#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

signed compare(const void *a, const void *b){
	int sub = *(int *)a - *(int *)b;
	if(sub < 0){
		return -1;
	}
	else if(sub == 0){
		return 0;
	}
	else{
		return 1;
	}
}

int fact(int n){
	if(n == 0){
		return 1;
	}
	else{
		return (n * fact(n - 1)) % p;
	}
}

signed main(){
	int N, i, j;
	scanf("%lld", &N);
	int *T = (int *)malloc(sizeof(int) * N);
	int *S = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &T[i]);
	}
	qsort(T, N, sizeof(int), compare);
	S[0] = T[0];
	for(i = 1; i < N; i++){
		S[i] = S[i - 1] + T[i];
	}
	int ans1 = 0, ans2 = 1;
	for(i = 0; i < N; i++){
		ans1 += S[i];
	}
	for(i = 1, j = 1; i < N; i++){
		if(T[i - 1] == T[i]){
			j++;
		}
		else{
			ans2 = (ans2 * fact(j)) % p;
			j = 1;
		}
	}
	ans2 = (ans2 * fact(j)) % p;
	printf("%lld\n", ans1);
	printf("%lld\n", ans2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &T[i]);
   ^