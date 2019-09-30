#include <stdlib.h>
#include <stdio.h>

#define MAXN 1001

void doit () {
	unsigned i, j, n;
	unsigned a[MAXN], b[MAXN];
	unsigned res = 0;

	scanf ("%u", &n);
	for (i = 0; i < n; i++) {
		scanf ("%u%u", &a[i], &b[i]);
	}
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			if ((a[i] > a[j] && b[i] < b[j]) || (a[i] < a[j] && b[i] > b[j])) {
				res++;
			}
		}
	}
	printf ("%u\n", res);
}

int main () {
	unsigned i, t;
	
	scanf ("%u", &t);
	for (i = 1; i <= t; i++) {
		printf ("Case #%u: ", i);
		doit ();
	}
	
	return 0;
}
