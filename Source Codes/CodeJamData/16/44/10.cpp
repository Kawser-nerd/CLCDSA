#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

void chmin(int& a, int b) { a = min(a, b); }

const int INFT = 10000;
int T;
int N;
char G[30][30];
int B[30];

vector<pair<int, int> > rect;
int dp[1 << 17][28][28];
int sz[1 << 17], ux[1 << 17], uy[1 << 17];

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;) {
		scanf("%d", &N);
		int orig = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%s", &(G[i]));
			B[i] = 0;
			for (int j = 0; j < N; ++j) if (G[i][j] == '1') {
				B[i] |= 1 << j;
				++orig;
			}
		}
		for (;;) {
			bool update = false;
			for (int i = 0; i < N; ++i) {
				for (int j = i + 1; j < N; ++j) {
					if ((B[i] & B[j]) != 0) {
						int m = B[i] | B[j];
						if (m != B[i] || m != B[j]) update = true;
						B[i] = B[j] = m;
					}
				}
			}
			if (!update) break;
		}

		sort(B, B + N);

		rect.clear();
		int sq = 0;
		int val = -1, chain = 0;
		int rx = N, ry = N;
		for (int i = 0; i < N; ++i) {
			if (B[i] == 0) {
				continue;
			}
			if (val != B[i]) {
				if (chain > 0) {
					int x = chain, y = __builtin_popcount(val);
					if (x != y) rect.push_back({ x, y });
					else {
						sq += x * x;
						rx -= x; ry -= x;
					}
				}
				val = B[i];
				chain = 1;
			} else {
				++chain;
			}
		}
		if (chain > 0 && val != -1) {
			int x = chain, y = __builtin_popcount(val);
			if (x != y) rect.push_back({ x, y });
			else {
				sq += x * x;
				rx -= x; ry -= x;
			}
		}

		for (auto a : rect) {
			rx -= a.first;
			ry -= a.second;
		}

		int R = rect.size();
		for (int i = 0; i < (1 << R); ++i) {
			int sx = 0, sy = 0;
			for (int j = 0; j < R; ++j) if (i & (1 << j)) {
				sx += rect[j].first;
				sy += rect[j].second;
			}
			ux[i] = max(sx, sy) - sx;
			uy[i] = max(sx, sy) - sy;
			sz[i] = max(sx, sy) * max(sx, sy);
		}

		//printf("%d %d\n", rx, ry);
		//for (int i = 0; i < R; ++i) printf(" %d %d\n", rect[i].first, rect[i].second);
		for (int i = 0; i < (1 << R); ++i) for (int j = 0; j <= rx; ++j)  for (int k = 0; k <= ry; ++k) dp[i][j][k] = INFT;
		dp[(1 << R) - 1][rx][ry] = 0;
		for (int i = (1 << R) - 1; i > 0; --i) {
			for (int j = rx; j >= 0; --j) {
				for (int k = ry; k >= 0; --k) if (dp[i][j][k] < INFT) {
					for (int i2 = i; i2; i2 = (i2 - 1) & i) {
						int j2 = j - ux[i2], k2 = k - uy[i2];
						if (j2 >= 0 && k2 >= 0) chmin(dp[i ^ i2][j2][k2], dp[i][j][k] + sz[i2]);
					}
				}
			}
		}

		int ans = INFT;
		for (int j = 0; j <= rx; ++j) {
			for (int k = 0; k <= ry; ++k) {
				if (dp[0][j][k] < INFT) {
					if (j != k) fprintf(stderr, "><\n");
					chmin(ans, dp[0][j][k] + j);
				}
			}
		}
		ans += sq;
		ans -= orig;
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}
