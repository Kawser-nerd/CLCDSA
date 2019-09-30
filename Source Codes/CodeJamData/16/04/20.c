#include <stdio.h>

int main() {
	int t, k, c, s, nt, level;
	long long tiles[300];
	long long tile;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d:", i);
		scanf("%d %d %d", &k, &c, &s);
		nt = 0;
		tile = 0;
		level = 0;
		for (int j = 0; j < k; ++j) {
			tile = tile * k + j;
			if (++level == c) {
				tiles[nt++] = tile;
				tile = 0;
				level = 0;
			}
		}
		if (level > 0) {
			while (level < c) {
				tile *= k;
				level++;
			}
			tiles[nt++] = tile;
		}
		if (nt > s)
			printf(" IMPOSSIBLE");
		else
			for (int j = 0; j < nt; ++j) {
				printf(" %lld", tiles[j] + 1);
			}
		printf("\n");
	}
}
