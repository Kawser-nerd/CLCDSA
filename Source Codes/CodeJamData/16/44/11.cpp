#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int n, a[50][50], ans;
int b[1000];
int dp[1 << 16][26][26];
int Sx[1 << 16], Sy[1 << 16], len, p1, p2, xx[1 << 16], yy[1 << 16];
bool used[100], used1[100];
int sumx, sumy;

void dfs(int k);
void dfs1(int k);

void dfs(int k) {
	sumx += 1;
	used[k] = true;
	for (int i = 0; i < n; i++)
		if (a[k][i] && !used1[i])
			dfs1(i);
}

void dfs1(int k) {
	sumy += 1;
	used1[k] = true;
	for (int i = 0; i < n; i++)
		if (a[i][k] && !used[i])
			dfs(i);
}

void doit() {
	scanf("%d", &n);
	int tot = 0;
	for (int i = 0; i < n * n; i++) {
		char k;
		// k = '1';
		for (k = getchar(); k <= 32; k = getchar());
		a[i / n][i % n] = k - '0';
		tot += k - '0';
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++)
	// 		printf("%d ", a[i][j]);
	// 	printf("\n");
	// }
	p1 = p2 = len = 0;
	for (int i = 0; i < n; i++)
		used[i] = used1[i] = false;
	for (int i = 0; i < n; i++)
		if (!used[i]) {
			sumx = sumy = 0;
			dfs(i);
			if (sumx == sumy)
				tot -= sumx * sumx;
			else {
				if (sumx == 1 && sumy == 0) {
					p1 += 1;
				}else {
					// printf("?? %d %d\n", sumx, sumy);
					xx[len] = sumx;
					yy[len] = sumy;
					len += 1;
				}
			}
		}
	for (int i = 0; i < n; i++)
		if (!used1[i])
			p2 += 1;
	// printf("%d %d %d\n", len, p1, p2);
	for (int i = 0; i < (1 << len); i++) {
		Sx[i] = Sy[i] = 0;
		for (int j = 0; j < len; j++)
			if (i & (1 << j))
				Sx[i] += xx[j], Sy[i] += yy[j];
	}
	for (int i = 0; i < (1 << len); i++)
		for (int j = 0; j <= p1; j++)
			for (int p = 0; p <= p2; p++)
				dp[i][j][p] = 1e9;
	dp[0][0][0] = 0;
	for (int i = 0; i < (1 << len); i++)
		for (int j = 0; j <= p1; j++)
			for (int p = 0; p <= p2; p++)
				if (dp[i][j][p] <= n * n) {
					for (int q = (1 << len) - 1 - i; q > 0; q = (q - 1) & ((1 << len) - 1 - i)) {
						// printf("!!! %d %d %d %d %d %d\n", i, j, p, q, Sx[q], Sy[q]);
						if (Sx[q] >= Sy[q] && Sx[q] - Sy[q] + p <= p2) {
							dp[i | q][j][Sx[q] - Sy[q] + p] = min(dp[i | q][j][Sx[q] - Sy[q] + p], dp[i][j][p] + Sx[q] * Sx[q]);
						}else if (Sx[q] <= Sy[q] && Sy[q] - Sx[q] + j <= p1) {
							dp[i | q][Sy[q] - Sx[q] + j][p] = min(dp[i | q][Sy[q] - Sx[q] + j][p], dp[i][j][p] + Sy[q] * Sy[q]);
						}
					}
				}

	int ans = 1e9;
	// printf("%d\n", dp[1][1][0]);
	for (int i = 0; i <= p1; i++)
		for (int j = 0; j <= p2; j++) {
			ans = min(ans, dp[(1 << len) - 1][i][j] + max(p1 - i, p2 - j));
			// printf("?? %d %d %d\n", i, j, dp[(1 << len) - 1][i][j] + max(i, j));
		}
	// printf("?? %d\n", dp[0][1][1]);
	// printf("?? %d %d\n", ans, tot);
	printf("%d\n", ans - tot);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: " , i);
		doit();
	}
}
