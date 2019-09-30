#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

const int MAXR = 200;
const int MAXC = 200;

ll dp[MAXR][13];
int gcd[13][13];
int lcm[13][13];
// number of ways with i rows with j rotations
// first row are always 3's
// only have 3, 6, 4 rows, so nothing too complex
//
const int H[4] = {3, 4, 4, 5}, L[4] = {1, 3, 6, 4};

void precomp() {
	for(int i = 1; i <= 12; i++) {
		for(int j = 1; j <= 12; j++) {
			for(int g = 1; g <= 12; g++) {
				if(i % g == 0 && j % g == 0) {
					gcd[i][j] = g;
				}
			}

			lcm[i][j] = i * j / gcd[i][j];
		}
	}

	memset(dp, 0, sizeof(dp));

	dp[0][1] = 1;

	for(int r = 1; r < MAXR; r++) {
		for(int d = 0; d < 4; d++) {
			if(r < H[d]) continue;
			for(int m = 1; m <= 12; m++) {
				dp[r][lcm[m][L[d]]] += dp[r - H[d]][m] * gcd[m][L[d]];
				dp[r][lcm[m][L[d]]] %= MOD;
			}
		}
	}
}

ll lookup(ll R, ll C) {
	ll res = 0;

	for(int m = 1; m <= 12; m++) {
		if(C % m == 0) {
			res += dp[R - 2][m] + 2 * dp[R][m] + dp[R + 2][m];
		}
	}

	return res;
}

int main() {
	precomp();
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		int R, C; cin >> R >> C;
		ll res = lookup(R, C);
		cout << "Case #" << t << ": " << res << '\n';
	}
	return 0;
}

// consider the highest 3 in the cc
// it can't have anything above, so it has to have l/r/d
// l/r extends => it must wrap all the way
// d => row below is also full
// => row after is not full
// => cc's of 3's are just 2 bands
//
// rows possible:
// 2 rows of 3's
// 1 row of 2's
// 2 rows of 2's and 1's (6 different) (222211)
// 2 rows of 2's and 1's (3 different (221)
// 3 rows of 2's and 1's (4 different) (2221)
//
// 6
// x + 1 + x + 1 - 1
// 1 + x + 1 + x - 1
// 2 + x + 2 - 6
// x + 2 + x - 1
