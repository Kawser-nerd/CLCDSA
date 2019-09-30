#include <stdio.h>

static int r, c, n;
static char s[16+4][16+4];

static int count(void) {

	int i, j, sum;

	sum = 0;
	for ( i = 1; i < r+1; ++i )
		for ( j = 1; j < c+1; ++j ) {
			if ( ! s[i][j] ) continue;
			if ( s[i-1][j] ) sum++;
			if ( s[i][j-1] ) sum++;
		}

	return sum;

}

static void clear(void) {

	int i, j;
	for ( i = 0; i < r+2; ++i )
		for ( j = 0; j < c+2; ++j )
			s[i][j] = 0;

}

int main() {

	int t, _t;
	scanf("%d", &t);

	for ( _t = 0; _t < t; ++_t ) {

		scanf("%d %d %d", &r, &c, &n);

		int i, j, p;

		int o = 100000000;

		for ( p = 0; p < (1 << (r*c))*2; ++p ) {

			clear();
			int pp = p;
			int nn = 0;

			while ( pp > 0 ) {
				if ( pp%2 == 0 ) nn++;
				pp /= 2;
			}

			if ( nn != n )
				continue;

			pp = p;

			for ( i = 1; i <= r; ++i ) {
				for ( j = 1; j <= c; ++j ) {
					s[i][j] = (pp%2 == 0);
					pp /= 2;
				}
			}

			int newo = count();
			if ( newo < o )
				o = newo;

		}

		printf("Case #%d: %d\n", _t+1, o);

	}

	return 0;

}
