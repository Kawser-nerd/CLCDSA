#include <cstdio>
#include <memory.h>

int a[1010], b[1010], tests, n, ans;

inline void swap(int &a, int &b) { int c = a; a = b; b = c; }
void sort(int l, int r) {
	int i = l, j = r, m = a[(i + j) >> 1];
	while (i < j) {
		while (a[i] < m) ++ i;
		while (a[j] > m) -- j;
		if (i <= j) {
			swap(a[i], a[j]);
			swap(b[i], b[j]);
			++ i, -- j;
		}
	}
	if (i < r) sort(i, r);
	if (l < j) sort(l, j);
}

int main(int argc, char *argv[]) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d\n", &tests);
	for (int cases = 1; cases <= tests; ++ cases) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i) scanf("%d%d", &a[i], &b[i]);
		sort(0, n - 1);
		ans = 0;
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < i; ++ j)
				if (b[j] > b[i]) ++ ans;
		printf("Case #%d: %d\n", cases, ans);
	}
	return 0;
}
