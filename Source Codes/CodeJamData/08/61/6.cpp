#include <cstdio>

int T, n, bxmax, bxmin, bymax, bymin, nx[1000], ny[1000], ni, x, y;
char s[256];

bool z(int a, int b, int c, int d, int x, int y) {
	if (c < a) a ^= c ^= a ^= c;
	if (d < b) b ^= d ^= b ^= d;
	return a <= x && x <= c && b <= y && y <= d;
}

bool nb(int x, int y) {
	if (bxmax)
		for (int i = 0; i < ni; ++i) {
			if (z(bxmin, bymin, x, y, nx[i], ny[i])) return 1;
			if (z(bxmin, bymax, x, y, nx[i], ny[i])) return 1;
			if (z(bxmax, bymin, x, y, nx[i], ny[i])) return 1;
			if (z(bxmax, bymax, x, y, nx[i], ny[i])) return 1;
		}
	else
		for (int i = 0; i < ni; ++i)
			if (x == nx[i] && y == ny[i])
				return 1;
	return 0;
}

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		bxmax = bymax = ni = 0;
		bxmin = bymin = 1000001;
		printf("Case #%d:\n", r);
		scanf("%d", &n); gets(s);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%s", &x, &y, s);
			if (*s == 'B') {
				if (bxmax < x) bxmax = x;
				if (bxmin > x) bxmin = x;
				if (bymax < y) bymax = y;
				if (bymin > y) bymin = y;
			} else {
				nx[ni] = x;
				ny[ni] = y;
				++ni;
			}
			gets(s);
		}
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &x, &y);
			if (bxmin <= x && x <= bxmax && bymin <= y && y <= bymax)
				puts("BIRD");
			else if (nb(x, y))
				puts("NOT BIRD");
			else puts("UNKNOWN");
		}
	}
	return 0;
}
