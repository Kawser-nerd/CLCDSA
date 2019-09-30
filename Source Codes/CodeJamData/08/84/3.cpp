#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cassert>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string>
#include <utility>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long int64;

const double EPS = 1E-8;

const int MOD = 30031;

int d[2001][1 << 10];
int n, k, p;

int a[1 << 10][1 << 10];
int res[1 << 10][1 << 10];
int tmp[1 << 10][1 << 10];
int bitc[1 << 10];
int bit[20];

#define mult(a, b) {int bnd=1<<p; forn(i, bnd) if (bitc[i] == k) forn(j, bnd) tmp[i][j] = 0;forn(i, bnd) if (bitc[i] == k) forn(j, bnd) if (bitc[j] == k) forn(kk, bnd) tmp[i][j] = (tmp[i][j] + a[i][kk]*b[kk][j]) % MOD; forn(i, bnd)if (bitc[i] == k) forn(j, bnd) a[i][j]=tmp[i][j];}


int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	bit[0] = 1;
	for(int i = 1; i < 20; ++i)
		bit[i] = bit[i - 1] << 1;

	forn(i, 1 << 10)
		forn(j, 10)
			if (i & bit[j]) ++bitc[i];

	int tk;
	scanf("%d\n", &tk);
	for(int tc = 1; tc <= tk; ++tc) {
		printf("Case #%d: ", tc);
		memset(d, 0, sizeof d);
		cin >> n >> k >> p;
		if (k > p) {
			puts("0");
			continue;
		}
		memset(a, 0, sizeof a);
		forn(msk, 1 << p) {
			if (!(msk & bit[0])) continue;
			int nm = msk >> 1;
			for(int j = 0; j < p; ++j)
				if ((nm & bit[j]) == 0)
					a[msk][nm | bit[j]] = 1;
		}
		
		memset(res, 0, sizeof res);
		forn(i, 1 << p)
			res[i][i] = 1;

		n = n - k;
		while (n)
			if (n & 1) {
				mult(res, a);
				//memcpy(res, tmp, sizeof tmp);
				--n;
			} else {
				mult(a, a);
				//memcpy(a, tmp, sizeof tmp);
				n >>= 1;
			}

		int msk = (1 << k) - 1;
		int ans = res[msk][msk];
		cerr << tc << endl;

		printf("%d\n", ans % MOD);
	}

	return 0;
}