#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 512;

int n, m, d0;
int matr[SIZE][SIZE];
int64 sums[SIZE][SIZE][3];

void Get(int x, int y, int64 *arr) {
	arr[0] = matr[x][y];
	arr[1] = matr[x][y] * x;
	arr[2] = matr[x][y] * y;
}

void GetSum(int x1, int y1, int x2, int y2, int64 *arr) {
	for (int u = 0; u<3; u++)
		arr[u] = sums[x2][y2][u] - sums[x1][y2][u] - sums[x2][y1][u] + sums[x1][y1][u];
}

void Sub(int x, int y, int64 *arr) {
	int64 t[4];
	Get(x, y, t);
	for (int i = 0; i<3; i++)
		arr[i] -= t[i];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d%d%d", &n, &m, &d0);
		for (int i = 0; i<n; i++) {
			char buff[SIZE];
			scanf("%s", buff);
			for (int j = 0; j<m; j++)
				matr[i][j] = d0 + (buff[j] - '0');
		}

		for (int i = 0; i<=n; i++)
			for (int j = 0; j<=m; j++) {
				if (i==0 || j==0) {
					for (int u = 0; u<3; u++)
						sums[i][j][u] = 0;
				}
				else {
					int64 t[4];
					Get(i-1, j-1, t);
					for (int u = 0; u<3; u++)
						sums[i][j][u] = sums[i-1][j][u] + sums[i][j-1][u] - sums[i-1][j-1][u] + t[u];
				}
			}

		int ans = 0;
		int bx = -1;
		int by = -1;
			
		for (int sz = 3; sz<=n && sz<=m; sz++)
			for (int i = 0; i+sz<=n; i++)
				for (int j = 0; j+sz<=m; j++) {
					int64 s[4];

					GetSum(i, j, i+sz, j+sz, s);
					Sub(i, j, s);
					Sub(i+sz-1, j, s);
					Sub(i, j+sz-1, s);
					Sub(i+sz-1, j+sz-1, s);

					if (2 * s[1] == s[0] * (2*i + sz - 1) &&
						2 * s[2] == s[0] * (2*j + sz - 1)) {
						if (ans < sz) {
							ans = sz;
							bx = i;
							by = j;
						}
					}
				}

		
		printf("Case #%d: ", tt);
		if (ans < 3) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);
//		printf("(%d %d)\n", bx, by);
		fflush(stdout);
	}
	return 0;
}
