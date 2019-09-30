#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;
int g[100][100];

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		int n;
		scanf ("%d", &n);
		for (int i = 0; i < 2 * n - 1; i++)
			for (int p = i, q = 0; p >= 0; p--, q++)
				if (p < n && q < n)
					scanf ("%d", &g[p][q]);

		int ans = 1e9;
		for (int i = -2 * n; i <= 2 * n; i++)
			for (int j = -2 * n; j <= 2 * n; j++) {
//				if (i >= 0 && j >= 0) {
					int ok = 1;
					int lp = 0, lq = 0, rp = n - 1, rq = n - 1;
					for (int p = 0; p < n; p++)
						for (int q = 0; q < n; q++) {
							lp = min (min (lp, 2 * i - p), min (i - j + q, i + j - q));
							rp = max (max (rp, 2 * i - p), max (i - j + q, i + j - q));
							lq = min (min (lq, 2 * j - q), min (j - i + p, i + j - p));
							rq = max (max (rq, 2 * j - q), max (j - i + p, i + j - p));
							if (i - j + q >= 0 && i - j + q < n && j - i + p >= 0 && j - i + p < n && g[p][q] != g[i - j + q][j - i + p])
								ok = 0;
							if (i + j - q >= 0 && i + j - q < n && i + j - p >= 0 && i + j - p < n && g[p][q] != g[i + j - q][i + j - p])
								ok = 0;
						}
					if (ok) {
						int l = max ((rp - lp + 1), (rq - lq + 1));
						int L = max (max (i, n - i - 1), max (j, n - j - 1)) * 2 + 1;
						int k = l * l;
						if (ans > k) ans = k;
					}
//			        }
				ok = 1;
				lp = 0, lq = 0, rp = n - 1, rq = n - 1;
				for (int p = 0; p < n; p++)
					for (int q = 0; q < n; q++) {
						lp = min (min (lp, 2 * i + 1 - p), min (i - j + q, i + j + 1 - q));
						rp = max (max (rp, 2 * i + 1 - p), max (i - j + q, i + j + 1 - q));
						lq = min (min (lq, 2 * j + 1 - q), min (j - i + p, i + j + 1 - p));
						rq = max (max (rq, 2 * j + 1 - q), max (j - i + p, i + j + 1 - p));
						if (i - j + q >= 0 && i - j + q < n && j - i + p >= 0 && j - i + p < n && g[p][q] != g[i - j + q][j - i + p])
							ok = 0;
						if (i + j - q + 1 >= 0 && i + j - q + 1 < n && i + j - p + 1 >= 0 && i + j - p + 1 < n && g[p][q] != g[i + j - q + 1][i + j - p + 1])
							ok = 0;
					}
				if (ok) {
					int l = max ((rp - lp + 1), (rq - lq + 1));
					int L = max (max (i + 1, n - i - 1), max (j + 1, n - j - 1)) * 2;
					int k = l * l;
					if (ans > k) ans = k;
				}
			}
		printf ("Case #%d: %d\n", it + 1, ans - n * n);
	}
	return 0;
}