#include <stdlib.h>
#include <stdio.h>

void doit (void) {
	unsigned r, k, n, i, j;
	unsigned g[1000] /* <= 10^7 < 2^24 */,
	         h[27][1000] /* <= n <= 10^3 < 2^10 */;
	unsigned long long x[27][1000] /* <= k*R < 2^57 */;
	
	/* h[i][j] is which group will be first in queue after 2^i rides if group j
	   was first in the beginning.
	   x[i][j] is the amount of revenue this generates

	   2^i <= r <= 10^8 < (2^10)^2*2^7 = 2^27 so i < 27
	*/
	
	unsigned long long revenue /* <= k*R <= 10^9 * 10^8 = 10^17 < (2^10)^5*2^7 = 2^57 */;
	unsigned pos /* n <= 10^3 < 2^10 */;
	
	scanf ("%u %u %u", &r, &k, &n);
	
	for (i = 0; i < n; i++) {
		scanf ("%u", &g[i]);
	}
	
	/* Calculate h[0] and x[0] */
	/* Also possible in O(n), but n is max 1000, so who cares?! */
	for (i = 0; i < n; i++) {
		x[0][i] = 0;
		for (j = 0; j < n && x[0][i]+g[(i+j) % n] <= k; j++) {
			x[0][i] += g[(i+j) % n];
		}
		h[0][i] = (i+j) % n;
	}
	
	/* Calculate h[i] and x[i] for i > 0, r >= 2^i */
	for (i = 1; (r >> i) != 0; i++) {
		for (j = 0; j < n; j++) {
			x[i][j] = x[i-1][j] + x[i-1][ h[i-1][j] ];
			h[i][j] = h[i-1][ h[i-1][j] ];
		}
	}

	/* Calculate revenue */	
	pos = 0;
	revenue = 0;
	for (i = 0; (r >> i) != 0; i++) {
		if ((r >> i) & 1) {
			revenue += x[i][pos];
			pos = h[i][pos];
		}
	}
	
	printf ("%llu\n", revenue);
}

int main () {
	int i, t;
	
	scanf ("%u", &t);
	for (i = 1; i <= t; i++) {
		printf ("Case #%u: ", i);
		doit ();
	}
	
	return 0;
}
