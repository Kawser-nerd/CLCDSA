#include <stdio.h>
#include <string.h>

char map[30][30];

int main(void) {
	int i, T;
	int n, m;
	int j, k, l;

	scanf("%d\n", &T);
	for (i = 0; i < T; ++i) {
		scanf("%d %d\n", &n, &m);

		for (j = 0; j < n; ++j) {
			for(k = 0; k < m; ++k) {
				scanf("%1s", &map[j][k]);
			}
		}

		for (j = 0; j < n; ++j) {
			for (k = 0; k < m; ++k) {
				if (map[j][k] != '?') {
					for (l = k + 1; l < m; ++l) {
						if (map[j][l] != '?')
							break;
						map[j][l] = map[j][k];
					}
					for (l = k - 1; l >= 0; --l) {
						if (map[j][l] != '?')
							break;
						map[j][l] = map[j][k];
					}
				}
			}
		}

		for (k = 0; k < m; ++k) {
			for (j = 0; j < n; ++j) {
				if (map[j][k] != '?') {
					for (l = j + 1; l < n; ++l) {
						if (map[l][k] != '?')
							break;
						map[l][k] = map[j][k];
					}
					for (l = j - 1; l >= 0; --l) {
						if (map[l][k] != '?')
							break;
						map[l][k] = map[j][k];
					}
				}
			}
		}

		printf("Case #%d:\n", i + 1);
		for (j = 0; j < n; ++j) {
			for (k = 0; k < m; ++k) {
				printf("%1c", map[j][k]);
			}
			printf("\n");
		}
	}
}
