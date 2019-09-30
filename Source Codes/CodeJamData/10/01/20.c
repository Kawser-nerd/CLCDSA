#include <stdio.h>
#include <stdlib.h>

void doit (unsigned i) {
	unsigned n, k, mask;
	
	scanf ("%u %u", &n, &k);
	
	mask = 0xffffffff >> (32-n);
	if ((k & mask) == mask) {
		printf ("Case #%u: ON\n", i);
	} else {
		printf ("Case #%u: OFF\n", i);
	}
}


int main () {
	unsigned t, i;
	
	scanf ("%u", &t);
	for (i = 1; i <= t; i++) {
		doit (i);
	}
	
	return 0;
}
