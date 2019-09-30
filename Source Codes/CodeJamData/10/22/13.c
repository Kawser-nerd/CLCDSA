#include <stdio.h>
#include <stdlib.h>

#define MAXN 50

void doit () {
	unsigned n, k, b, t;
	long long int x[MAXN], v[MAXN];
	int i;
	unsigned s = 0;
	unsigned slowinfront = 0;
	unsigned reached = 0;

	scanf ("%u %u %u %u ", &n, &k, &b, &t);
	for (i = 0; i < n; i++) {
		scanf ("%lli ", &x[i]);
	}
	for (i = 0; i < n; i++) {
		scanf ("%lli ", &v[i]);
	}
	
	for (i = n - 1; i >= 0 && reached < k; i--) {
		/* can chick i reach? */
		if (x[i]+v[i]*t >= b) {
			s += slowinfront;
			reached++;
		} else {
			slowinfront++;
		}
	}
	
	if (reached >= k) {
		printf ("%u\n", s);
	} else {
		printf ("IMPOSSIBLE\n");
	}
}

int main () {
	unsigned i, t;
	scanf ("%u ", &t);
	
	for (i = 1; i <= t; i++) {
		printf ("Case #%u: ", i);
		doit ();
	}
	
	return 0;
}
