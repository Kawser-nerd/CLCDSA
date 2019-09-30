#include <stdio.h>
#include <string.h>

#define MAX 1001

char matrix[MAX][MAX];

int
main (void)
{
	int T, N;
	int i, j, k, l;
	int flag, neigh, tmp;

	scanf ("%d", &T);
	for (i = 1; i <= T; ++i) {
		scanf ("%d", &N);
		memset (matrix, 0, sizeof (matrix));
		for (j = 1; j <= N; ++j) {
			scanf ("%d", &neigh);
			for (k = 1; k <= neigh; ++k) {
				scanf ("%d", &tmp);
				matrix[j][tmp] = 1;
			}
		}
		
		for (l = 1; l <= N; ++l) {
			for (j = 1; j <= N; ++j) {
				for (k = 1; k <= N; ++k) {
					if (matrix[j][l] && matrix[l][k]) {
						++matrix[j][k];
					}
				}
			}
		}
		printf ("Case #%d: ", i);
		flag = 0;
		for (j = 1; j <= N; ++j) {
			for (k = 1; k <= N; ++k) {
				if (matrix[j][k] > 1) {
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) printf ("Yes\n");
		else printf ("No\n");
	}
	return 0;
}
