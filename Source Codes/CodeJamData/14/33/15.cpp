#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 1000000000
int n, m, k, T;

int calc1(int a, int b, int c1, int c2, int c3, int c4) {
	int c = a + c1 + c2 - c3 - c4, d = b + c1 + c3 - c2 - c4;
	if (c < 0 || d < 0)	return -1;
	if (a + c1 + c2 > m)	return -1;
	if (b + c1 + c3 > n)	return -1;
	if (a + c1 + c2 == 0)	return -1;
	if (b + c1 + c3 == 0)	return -1;
	int now = a + 1, sum = 0;
	for (int i = 0; i <= c1 + b + c3; i++) {
		sum += now;
		if (0 <= i && i < c1)	now++;
		if (0 <= i && i < c2)	now++;
		if (c1 + b <= i && i < c1 + b + c3)	now--;
		if (c2 + d <= i && i < c2 + d + c4)	now--;
	}
	return sum;
}

int calc2(int a, int b, int c1, int c2, int c3, int c4) {
	int c = a + c1 + c2 - c3 - c4, d = b + c1 + c3 - c2 - c4;
	return a + b + c + d + c1 + c2 + c3 + c4;
}

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &T);
	for (int Case = 1; Case <= T; Case++) {
		scanf("%d%d%d", &n, &m, &k);
		if (n < m)	swap(n, m);
		n--; m--;
		int ans = k;
		for (int a = 0; a <= m; a++)
			for (int b = 0; b <= n; b++)
				for (int c1 = 0; c1 <= m; c1++)
					for (int c2 = max(0, c1 - 1); c2 <= c1 + 1; c2++)
						for (int c3 = max(0, c1 - 1); c3 <= c1 + 1; c3++)
							for (int c4 = max(0, c1 - 1); c4 <= c1 + 1; c4++)
								if (calc1(a, b, c1, c2, c3, c4) >= k)	ans = min(ans, calc2(a, b, c1, c2, c3, c4));
		printf("Case #%d: %d\n", Case, ans);
	}
}
