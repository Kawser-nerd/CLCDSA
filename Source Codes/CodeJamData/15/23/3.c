#include <stdio.h>

int main() {

	int _t, t;
	scanf("%d", &_t);

	for ( t = 1; t <= _t; ++t ) {

		int n;
		scanf("%d", &n);
		if ( n > 2 ) abort();

		int d1, m1;
		int d2, m2;
		int count;

		scanf("%d %d %d", &d1, &count, &m1);
		if ( count > 2 ) abort();

		if ( count == 2 ) {
			d2 = d1;
			m2 = m1+1;
			if ( n != 1 ) abort();
		}

		if ( n == 2 ) {
			int h;
			scanf("%d %d %d", &d2, &h, &m2);
			if ( h != 1 ) abort();
			count += h;
			if ( count > 2 ) abort();
		}

		if ( count == 1 ) {
			printf("Case #%d: 0\n", t);
			continue;
		}

		if ( m1 == m2 ) {
			printf("Case #%d: 0\n", t);
			continue;
		}

		if ( m2 < m1 ) {
			int tmp = m2;
			m2 = m1;
			m1 = tmp;
			tmp = d2;
			d2 = d1;
			d1 = tmp;
		}

//		if ( d1 <= d2 ) {
			__int128 f1 = (2*360-d1)*(__int128)m1;
			__int128 f2 = (360-d2)*(__int128)m2;
			if ( f2 < f1 ) {
				printf("Case #%d: 0\n", t);
				continue;
			}
			if ( f2 >= f1 ) {
				printf("Case #%d: 1\n", t);
				continue;
			}
			abort();
//		}

//		printf("Case #%d: 1\n", t);

	}

	return 0;

}
