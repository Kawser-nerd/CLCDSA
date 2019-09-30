#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

void solve(int tiles, int depth)
{
	size_t i;
	size_t t;
	size_t d;

	t = 0;
	d = depth;

	for(i = 0; i < tiles; i++) {
		t = t * tiles + i;
		d--;

		if(d == 0) {
			printf(" %llu", t + 1);
			t = 0;
			d = depth;
		}
	}

	if(d != depth) {
		while(d > 0) {
			t = t * tiles;
			d--;
		}

		printf(" %llu", t);
	}
}

int main(int argc, char *argv[])
{
	size_t size;
	size_t i;

	int k, c, s;

	scanf("%llu", &size);

	/**
	 * k = original nb of tiles
	 * c = depth of the tree
	 * s = students
	 */
	for(i = 0; i < size; i++) {
		scanf("%u %u %u", &k, &c, &s);
		printf("Case #%u:", i + 1);

		/* Checking if doable */
		if(ceil((double)k / (double)c) > s) {
			printf(" IMPOSSIBLE");
		} else {
			/* Multiple output :( */
			solve(k, c);
		}

		putchar('\n');
	}

	return EXIT_SUCCESS;
}
