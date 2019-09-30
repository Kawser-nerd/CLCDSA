#include <stdio.h>

int main() {
	int t, T, a;
	int R, C, N;
	int N2, a2;
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%d %d %d", &R, &C, &N);
		a = 0;
		if(N <= (R*C+1)/2) {
			a = 0;
		} else if(R == 1 || C == 1) {
			a = R*C-1 - (R*C-N)*2;
		}
		else if(R*C%2 == 1) {
			N2 = N;
			a2 =0;
			N -= (R*C-1)/2;
			if(N == 2) {
				a = 3;
			} else if(N <= 4) {
				a += 2*N;
			} else {
				a += 2*4;
				N -= 4;
				if(N <= R+C-6) {
					a += 3*N;
				} else {
					a += 3*(R+C-6);
					N -= R+C-6;
					a += 4*N;
				}
			}
		}
		else {
			N -= (R*C+1) / 2;
			if(N <= 2) {
				a += 2*N;
			} else {
				a += 2*2;
				N -= 2;
				if(N <= R+C-4) {
					a += 3*N;
				} else {
					a += 3*(R+C-4);
					N -= R+C-4;
					a += 4*N;
				}
			}
		}

		printf("Case #%d: %d\n", t, a);
	}
	return 0;
}
