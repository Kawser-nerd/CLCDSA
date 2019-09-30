#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char s[4];
int a[606], b[101][101];
vector<int> g[606];
int v[606];
int rx[303], ry[303];
char rz[303];

int f(int x) {
	if (x == 601) return 1;
	if (v[x]) return 0;
	int i;
	v[x] = 1;
	for (i = 0; i < g[x].size(); i++) if (f(g[x][i])) {
		g[g[x][i]].push_back(x);
		g[x][i] = g[x][g[x].size() - 1];
		g[x].pop_back();
		return 1;
	}
	return 0;
}

int main() {
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	int T, Tn;
	scanf("%d", &Tn);
	for (T = 1; T <= Tn; T++) {
		int i, j, n, m, r = 0, rn = 0;
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++) for (j = 0; j < n; j++) b[i][j] = 0;
		for (i = 0; i < 6 * n; i++) {
			a[i] = v[i] = 0;
			g[i].clear();
		}
		while (m--) {
			scanf("%s%d%d", &s, &i, &j);
			i--; j--;
			if (s[0] != '+') {
				r++;
				a[i] = a[j + n] = 1;
				b[i][j] |= 1;
			}
			if (s[0] != 'x') {
				r++;
				a[i + j + n + n] = a[i - j + n * 5] = 1;
				b[i][j] |= 2;
			}
		}
		g[600].clear();
		v[600] = 0;
		for (i = 0; i < n; i++) if (!a[i]) g[600].push_back(i);
		for (i = n; i < n + n; i++) if (!a[i]) g[i].push_back(601);
		for (i = n + n; i < n * 4; i++) if (!a[i]) g[600].push_back(i);
		for (i = n * 4; i < n * 6; i++) if (!a[i]) g[i].push_back(601);
		for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
			if (!a[i] && !a[j + n]) g[i].push_back(j + n);
			if (!a[i + j + n + n] && !a[i - j + n * 5]) g[i + j + n + n].push_back(i - j + n * 5);
		}
		while (f(600)) {
			r++;
			v[600] = 0;
			for (i = 0; i < n * 6; i++) v[i] = 0;
		}
		for (i = n; i < n + n; i++) if (!g[i].empty() && g[i][0] != 601) b[g[i][0]][i - n] |= 4;
		for (i = n * 4; i < n * 6; i++) if (!g[i].empty() && g[i][0] != 601) b[g[i][0] + i - n * 7 >> 1][g[i][0] - i + n * 3 >> 1] |= 8;
		for (i = 0; i < n; i++) for (j = 0; j < n; j++) if (b[i][j] & 12) {
			b[i][j] |= b[i][j] >> 2;
			rx[rn] = i;
			ry[rn] = j;
			rz[rn] = b[i][j] & 1 ? b[i][j] & 2 ? 'o' : 'x' : '+';
			rn++;
		}
		printf("Case #%d: %d %d\n", T, r, rn);
		for (i = 0; i < rn; i++) printf("%c %d %d\n", rz[i], rx[i] + 1, ry[i] + 1);
	}
	return 0;
}
