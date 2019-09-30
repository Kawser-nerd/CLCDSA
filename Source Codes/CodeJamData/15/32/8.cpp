#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 111;
const double eps = 1e-8;
const int INF = (1 << 29);

int go[N];
char str[N], keys[N];
int l, s, k;

double f[N][N];

double dfs(int i, int j) {
	if (i == s) {
		return 0;
	}

	if (f[i][j] > -eps) {
		return f[i][j];
	}
	f[i][j] = 0;
	for (int p = 1; p <= k; p++) {
		char key = keys[p];
		int q = j;
		while (q && str[q + 1] != key) {
			q = go[q];
		}
		if (str[q + 1] == key) {
			q++;
		}
		if (q == l) {
			f[i][j] += (1 + dfs(i + 1, go[q]));
		} else {
			f[i][j] += dfs(i + 1, q);
		}
	}
	f[i][j] /= k;
	return f[i][j];
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d %d %d", &k, &l, &s);
		scanf("%s", keys + 1); // k
		scanf("%s", str + 1); // l
		go[1] = 0;
		for (int i = 2; i <= l; i++) {
			int j = go[i - 1];
			while (j && str[j + 1] != str[i]) {
				j = go[j];
			}
			if (str[j + 1] == str[i]) {
				go[i] = ++j;
			} else {
				go[i] = 0;
			}
		}
		for (int i = 0; i <= s; i++) {
			for (int j = 0; j <= l; j++) {
				f[i][j] = -INF;
			}
		}

		f[0][0] = 0;
		for (int i = 0; i < s; i++) {
			for (int j = 0; j <= l; j++) {
				for (int p = 1; p <= k; p++) {
					char key = keys[p];
					int q = j;
					while (q && str[q + 1] != key) {
						q = go[q];
					}
					if (str[q + 1] == key) {
						q++;
					}
					if (q == l) {
						f[i + 1][go[q]] = max(f[i + 1][go[q]], f[i][j] + 1);
					} else {
						f[i + 1][q] = max(f[i + 1][q], f[i][j]);
					}
				}
			}
		}
		double maxV = 0;
		for (int i = 0; i <= l; i++) {
			maxV = max(maxV, f[s][i]);
		}

		for (int i = 0; i <= s; i++) {
			for (int j = 0; j <= l; j++) {
				f[i][j] = -1e9;
			}
		}
		static int testCount = 0;
		printf("Case #%d: %.8f\n", ++testCount, maxV - dfs(0, 0));
	}
	return 0;
}