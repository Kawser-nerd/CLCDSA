#include<stdio.h>

typedef unsigned nat;
typedef nat bool;
#define false 0
#define true 1

int m, n;
int A, x, y, a, b;

bool getcoords();

int main() {
	nat tc, cs;

	scanf("%u", &tc);
	for (cs = 0; cs != tc; ++cs) {
		scanf("%d%d%d", &m, &n, &A);

		printf("Case #%u: ", cs+1);
		if (getcoords())
			printf("%d %d %d %d %d %d\n", a, 0, 0, b, x, y);
		else
			puts("IMPOSSIBLE");
	}

	return 0;
}

#if 0
bool getcoords() {
	int u, v;
	for (a = 0; a <= m; ++a)
		for (y = 0; y <= n; ++y) {
			v = A - a*y;
			if (v == 0) {
				b = 0;
				x = 0;
				return true;
			}
			u = v < 0 ? -v : v;
			for (b = 2; b*b <= u; ++b) {
				if (u%b == 0) {
					x = a + v/b;
					if (0 <= x && x <= m && 0 <= b && b <= n)
						return true;
					x = a + b;
					if (0 <= x && x <= m) {
						b = v/b;
						if (0 <= b && b <= n)
							return true;
					}
				}
			}
		}
	return  false;
}

#endif


bool getcoords() {
	for (a = 0; a <= m; ++a)
		for (b = 0; b <= n; ++b)
			for (x = 0; x <= m; ++x)
				for (y = 0; y <= n; ++y) {
					if (a*y + b*x - a*b == A)
						return true;
				}
	return false;
}


