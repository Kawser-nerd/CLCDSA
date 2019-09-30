#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007LL;

int A[100010]={0}, B[200010]={0}, E, flag, N;
long long C, P;

int check1(void) {
	int i;
	if (flag) {
		for (i=0;i<N;i++) if (A[i]%2) return 1;
	} else {
		for (i=0;i<N;i++) if (!(A[i]%2)) return 1;
	}
	return 0;
}

int check2(void) {
	int i;
	for (i=0;i<N;i++) B[A[i]]++;
	if (flag) {
		if (B[0] != 1) return 1;
		else for (i=2;i<N;i+=2) if (B[i] != 2) return 1;
	} else {
		for (i=1;i<N;i+=2) if (B[i] != 2) return 1;
	}

	C = 1LL;
	P = 2LL;
	E = N/2;
	while (E) {
		if (E & 1) {
			C *= P;
			C %= MOD;
		}
		P *= P;
		P %= MOD;
		E >>= 1;
	}
	return 0;
}

int main(void) {
	int i;
	scanf("%d", &N);
	for (i=0;i<N;i++) scanf("%d", &A[i]);
	if (N%2) flag = 1; else flag = 0;
	if (!check1() && !check2()) {
		printf("%lld\n", C);
	} else {
		printf("0\n");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:48:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i=0;i<N;i++) scanf("%d", &A[i]);
                    ^