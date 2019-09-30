#include <stdio.h>

int main(void) {
	int T, case_count;
	if (scanf("%d", &T) != 1) return 1;
	for (case_count = 1; case_count <= T; case_count++) {
		int Ac, Aj;
		int C[100], D[100], J[100], K[100];
		int i;
		if (scanf("%d%d", &Ac, &Aj) != 2) return 1;
		for (i = 0; i < Ac; i++) {
			if (scanf("%d%d", &C[i], &D[i]) != 2) return 1;
		}
		for (i = 0; i < Aj; i++) {
			if (scanf("%d%d", &J[i], &K[i]) != 2) return 1;
		}
		if (Ac > 2 || Aj > 2 || Ac + Aj > 2) {
			printf("Case #%d: large\n", case_count);
		} else {
			int a, b, c, d;
			if (Ac < 2 && Aj < 2) {
				a = b = c = d = 0;
			} else if (Ac == 2) {
				if (C[0] < C[1]) {
					a = C[0]; b = D[0];
					c = C[1]; d = D[1];
				} else {
					a = C[1]; b = D[1];
					c = C[0]; d = D[0];
				}
			} else if (Aj == 2) {
				if (J[0] < K[1]) {
					a = J[0]; b = K[0];
					c = J[1]; d = K[1];
				} else {
					a = J[1]; b = K[1];
					c = J[0]; d = K[0];
				}
			}
			printf("Case #%d: %d\n", case_count, c - b >= 720 || a + 24 * 60 - d >= 720 ? 2 : 4);
		}
	}
	return 0;
}
