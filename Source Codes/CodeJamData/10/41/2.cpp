#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

const int SIZE = 324;

int n;
char matr[SIZE][SIZE];

char isnow[SIZE][SIZE];
bool CanBeDiamond(int s) {
	int nb = 2*n-1;
	int sb = 2*s-1;
	for (int i = 0; i<=sb-nb; i++)
		for (int j = 0; j<=sb-nb; j++) {
			if (!((i+n-1) ^ j ^ s)) continue;
			bool ok = true;
			memset(isnow, 0, sizeof(isnow));
			for (int u = 0; u<nb && ok; u++) {
				for (int v = 0; v<nb && ok; v++) if (isdigit(matr[u][v])) {
					int x = i + u;
					int y = j + v;
					if (x > s-1) x = sb-1 - x;
					if (y > s-1) y = sb-1 - y;
					if (x+y < s-1) ok = false;
					if (!((x ^ y ^ s) & 1)) ok = false;
					if (isnow[x][y] && isnow[x][y] != matr[u][v]) ok = false;
					isnow[x][y] = matr[u][v];
				}
			}
			if (ok) return true;
		}
	return false;
}

char buff[1024];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	gets(buff);
	sscanf(buff, "%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		gets(buff);
		sscanf(buff, "%d", &n);
		memset(matr, 0, sizeof(matr));
		for (int i = 0; i<2*n-1; i++) gets(matr[i]);

		int i;
		for (i = n; ; i++) if (CanBeDiamond(i)) break;

		int score = i*i - n*n;
		fprintf(stderr, "%d: %d\n", tt, i);
		printf("Case #%d: %d\n", tt, score);
	}
	return 0;
}
