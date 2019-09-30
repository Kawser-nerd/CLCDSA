#include <stdio.h>
#include <string.h>
#include <math.h>
#include <gmp.h>

#ifdef DEBUG
#define ddd(s, ...) printf(s, __VA_ARGS__)
#else
#define ddd(s, ...)
#endif


int main(void) {
	int t, T;

	scanf("%d", &T);
	t = 0;
	while (t<T) {
		int a1, a2;
		int r1[4], r2[4];
		int i, j;
		int c, v;

		scanf("%d", &a1);
		for (i=0; i<4; i++) {
			if (i == a1-1)
				scanf("%d %d %d %d",
				    &r1[0], &r1[1], &r1[2], &r1[3]);
			else
				scanf("%*d %*d %*d %*d");
		}
		scanf("%d", &a2);
		for (i=0; i<4; i++) {
			if (i == a2-1)
				scanf("%d %d %d %d",
				    &r2[0], &r2[1], &r2[2], &r2[3]);
			else
				scanf("%*d %*d %*d %*d");
		}

		c = 0;
		for (i=0; i<4; i++)
			for (j=0; j<4; j++)
				if (r1[i] == r2[j]) {
					c++;
					v = r1[i];
					break;
				}

		printf("Case #%d: ", t+1);
		if (c == 0) {
			printf("Volunteer cheated!\n");
		} else if (c == 1) {
			printf("%d\n", v);
		} else {
			printf("Bad magician!\n");
		}

		t++;
	}


	return (0);
}
