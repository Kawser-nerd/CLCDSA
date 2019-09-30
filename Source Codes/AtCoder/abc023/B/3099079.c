#include <stdio.h>
#include <string.h>

//A:AC
//int main() {
//	int x;
//	int ans=0;
//	
//	scanf("%d", &x);
//
//	ans = x / 10 + x % 10;
//
//	printf("%d\n", ans);
//
//	return 0;
//}

//B
int main(void) {
	int N;
	scanf("%d", &N);
	char S[101];
	int ans = -1;
	scanf("%s", S);
	int a = 0;
	int i;
	//printf("%d %s", N, S );
	if (N % 2) {
		a = 1;
		if ((N / 2) % 3 == 0) {
			for (i = 0; i < N; i++) {
				if (i % 3 == 0) {
					if (S[i] != 'b') {
						a = 0;
						break;
					}
				}
				else if (i % 3 == 1) {
					if (S[i] != 'c') {
						a = 0;
						break;
					}
				}
				else {
					if (S[i] != 'a') {
						a = 0;
						break;
					}
				}
			}


		}
		else if ((N / 2) % 3 == 1) {
			for (i = 0; i < N; i++) {
				if (i % 3 == 0) {
					if (S[i] != 'a') {
						a = 0;
						break;
					}
				}
				else if (i % 3 == 1) {
					if (S[i] != 'b') {
						a = 0;
						break;
					}
				}
				else {
					if (S[i] != 'c') {
						a = 0;
						break;
					}
				}
			}
		}
		else {
			for (i = 0; i < N; i++) {
				if (i % 3 == 0) {
					if (S[i] != 'c') {
						a = 0;
						break;
					}
				}
				else if (i % 3 == 1) {
					if (S[i] != 'a') {
						a = 0;
						break;
					}
				}
				else {
					if (S[i] != 'b') {
						a = 0;
						break;
					}
				}
			}

		}

		if (a) ans = N / 2;

	}

	printf("%d\n", ans);

	return 0;

} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^