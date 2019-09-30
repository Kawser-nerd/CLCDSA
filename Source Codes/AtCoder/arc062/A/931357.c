#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int i, N;
	long long A[1010], T[1010];
	long long V, VA, VA1, VA2, VT, VT1, VT2;
	scanf("%d", &N);
	for (i=0;i<N;i++) scanf("%lld%lld", &T[i], &A[i]);

	VA = A[0];
	VT = T[0];
//		printf("%lld %lld\n", VT, VA);
	for (i=1;i<N;i++) {
		if (VA <= A[i] && VT <= T[i]) {
			VA = A[i]; VT = T[i];
		} else {
			VA1 = VA + (A[i] - (VA % A[i])) % A[i];
			VT1 = VA1 / A[i] * T[i];
			VT2 = VT + (T[i] - (VT % T[i])) % T[i];
			VA2 = VT2 / T[i] * A[i];
			if (VA1 < VA || VT1 < VT) { VA = VA2; VT = VT2; }
			else if (VA2 < VA || VT2 < VT) { VA = VA1; VT = VT1; }
			else if (VA1 + VT1 < VA2 + VT2) { VA = VA1; VT = VT1; }
			else { VA = VA2; VT = VT2; }
		}
//		printf("%lld %lld\n", VT, VA);
	}

	V = VA + VT;
	printf("%lld\n", V);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:11:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i=0;i<N;i++) scanf("%lld%lld", &T[i], &A[i]);
                    ^