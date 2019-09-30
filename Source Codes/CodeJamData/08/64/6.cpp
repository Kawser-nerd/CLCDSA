#include <cstdio>

int T, e[10][10], a[10], b[10], p[10], n, m, x, y;

bool rc(int k) {
//	printf("? k = %d\n", k);
	if (k == m) {
		for (int i = 1; i < m; ++i)
			if (!e[p[a[i]]][p[b[i]]])
				return 0;
		return 1;
	}
	bool f;
	for (int i = 0; i < n; ++i) {
		f = 0;
		for (int j = 0; j < k && !f; ++j)
			f = (p[j] == i);
		if (f)
			continue;
		p[k] = i;
		if (rc(k + 1))
			return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d: ", r);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				e[i][j] = 0;
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", &x, &y);
			e[x - 1][y - 1] = e[y - 1][x - 1] = 1;
		}
		scanf("%d", &m);
		for (int i = 1; i < m; ++i) {
			scanf("%d%d", a + i, b + i);
			--a[i];
			--b[i];
		}
		if (rc(0))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
