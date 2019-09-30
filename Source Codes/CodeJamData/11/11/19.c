#include <stdio.h>

int main() {

	int i, j, t;
	scanf("%d", &t);

	int count[101];

	for ( i = 0; i <= 100; ++i ) {

		for ( j = 1; j <= 100; ++j ) {

			if ( (i*j)%100 == 0 ) {

				count[i] = j;
				break;

			}

		}

	}

	for ( i = 0; i < t; ++i ) {

		int n, pd, pg;
		scanf("%d %d %d", &n, &pd, &pg);

		if ( ( pg == 0 && pd > 0 ) || ( pg == 100 && pd < 100 ) ) {

			printf("Case #%d: Broken\n", i+1);

		} else {

			if ( pd == 0 || pd == 100 ) {

				printf("Case #%d: Possible\n", i+1);

			} else {

				int min = count[pd];

				if ( min <= n )
					printf("Case #%d: Possible\n", i+1);
				else
					printf("Case #%d: Broken\n", i+1);

			}

		}

	}

	return 0;

}
