#include <stdio.h>

// A?np?????????mod 1000000007???
int f(int np, char *A) {
	unsigned int ans;
	if (A[0] == 't') ans = 3;
	else ans = 6;
	for (int i = 1; i < np; i++) {
		if (A[i] == 't') {
			if (A[i-1] == 't') ans *= 2;
			else ;
		} else {
			if (A[i-1] == 't') ans *= 2;
			else ans *= 3;
		}
		ans %= 1000000007;
	}
	return ans;
}

int main() {
	int ans;
	int N;
	scanf("%d", &N);
	char S1[N+1];
	scanf("%s", S1);
	
	// A ??????????????('t' ???'y'??)
	char A[N];
	// np ???????
	int np = 0;
	for (int i = 0; S1[i] != '\0'; i++) {
		if (S1[i] == S1[i+1]) {
			A[np] = 'y';
			np++;
			i++;
		} else {
			A[np] = 't';
			np++;
		}
	}
	
	ans = f(np, A);

	printf("%d\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S1);
  ^