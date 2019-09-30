#include "data.h"
#include <stdio.h>

main() {
	int T, K;
	scanf(" %d", &T);

	for(K = 1; K <= T; K++) {
		int A, B, i;

		scanf(" %d %d", &A, &B);

		double Q = 1.0;
		double best = B + 2.0; // just press enter -- don't need to do i = 0 case 'cause this is quicker

		for(i = 1; i <= A; i++) {
			double p_i;
			scanf(" %lf", &p_i);
			Q *= p_i;

			double this = (B + A - 2 * i + 1) * Q + (2 * B - 2 * i + 2 + A) * (1 - Q);
			//printf("%d:%lf ", i, this);
			if(this < best) best = this;
		}

		printf("Case #%d: %lf\n", K, best);
	}
}
