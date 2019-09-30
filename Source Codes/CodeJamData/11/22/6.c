#include "stdio.h"

int d, n;
int a[1000];
int b[1000];

int poisk (long long t) {
	long long last = -1000000000000000000l;
	int i;
	long long first;
	for (i = 0; i < n; i++) {
		first = a[i] - t;
		if (first < last + d) 
			first = last + d;
		last = first + (b[i] - 1) * (long long) d;
		if (last - a[i] > t) {
			return 0;
		}
	}
	return 1;
}

int main () {
	int tn;
	scanf ("%d\n", &tn);
	int tt;
	for (tt = 0; tt < tn; tt++) {
		scanf ("%d %d", &n, &d);
		d *= 2;
		int i;
		for (i = 0; i < n; i++) {
			scanf ("%d %d", &a[i], &b[i]);
			a[i] *= 2;
			//printf (">> %d %d\n", a[i], b[i]);
		}
		long long mt = 2000000000001l;
		long long l = -1;
		long long r = mt;
		while (r - l > 1) {
			long long x = (r + l) / 2;
			if (poisk (x)) r = x;
			else l = x;
		}
		//printf ("%lld\n", r);
		printf ("Case #%d: %lf\n", tt + 1, r * 0.5);

	}
	return 0;
}
