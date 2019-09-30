#include <cstdio>
#include <memory.h>
int tests, n, m, f[1000][1000], ans, count[600];
int map[1000][1000];

inline int min(int a, int b) { return a > b ? b : a; }
inline int min(int a, int b, int c) { return min(min(a, b), c); }

int dup(char p, int k) {
	if (p <= '9') p = p - '0';
	else p = p - 'A' + 10;
	return ((p >> (3 - k)) & 1);
}

void init_map() {
	char buff[256];
	memset(map, 0, sizeof(map));
	for (int i = 1; i <= n; ++ i) {
		gets(buff);
		for (int j = 1; j <= m; ++ j)
			map[i][j] = dup(buff[(j - 1) >> 2], (j - 1) & 3);
	}
}

int main(int argc, char *argv[]) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &tests);
	for (int cases = 1; cases <= tests; ++ cases) {
		scanf("%d%d\n", &n, &m);
		init_map();
		memset(f, 0, sizeof(f));
		ans = 0;
		memset(count, 0, sizeof(count));
		int left = n * m;
		while (left) {
			int max = 0, pi, pj;
			for (int i = 1; i <= n; ++ i)
				for (int j = 1; j <= m; ++ j)
					if (map[i][j] == 1 - map[i - 1][j] && map[i][j] == 1 - map[i][j - 1] && map[i][j] == map[i - 1][j - 1]) 
						f[i][j] = min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1;
					else f[i][j] = 1;
			for (int i = 1; i <= n; ++ i)
				for (int j = 1; j <= m; ++ j) 
					if (f[i][j] > max) max = f[i][j], pi = i, pj = j;
			if (max == 1) { ++ ans, count[1] = left; break; }
			for (int i = pi - max + 1; i <= pi; ++ i)
				for (int j = pj - max + 1; j <= pj; ++ j)
					map[i][j] = 2;
			left -= max * max;
			//printf("%d %d %d %d\n", max, pi, pj, left);
			if (!count[max]) ++ ans;
			++ count[max];
		}
		printf("Case #%d: %d\n", cases, ans);
		for (int i = n; i; -- i)
			if (count[i]) printf("%d %d\n", i, count[i]);
	}
	return 0;
}
