#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int f[110][1220][2];
int n, p, q, h[110], g[110];

void solve() {
	scanf("%d %d %d", &p, &q, &n);
	forn(i, n) scanf("%d %d", &h[i], &g[i]);

	forn(j, 1210) f[n][j][0] = f[n][j][1] = 0;
	for (int i = n - 1; i >= 0; i--) {
		int ttk = (h[i] + q - 1) / q;
		forn(j, 11 * i + 1) {
			f[i][j][1] = max(f[i+1][j+ttk-1][0], f[i+1][j+ttk][1]);
			f[i][j][0] = max(f[i+1][j+ttk][0], f[i+1][j+ttk+1][1]);
			forn(w, 2) {
				forn(sb, j + 1) {
					if (sb * p >= h[i]) {
						f[i][j][w] = max(f[i][j][w], f[i+1][j - sb][w] + g[i]);
						break;
					}

					int hl = h[i] - sb * p;
					if (w == 1) {
						hl -= q;
						if (hl <= 0) continue;
					}
					hl %= p + q;
					if (hl <= p) f[i][j][w] = max(f[i][j][w], f[i+1][j-sb][1] + g[i]);
				}

				forn(sk, 12) {
					int hl = h[i] - sk * q;
					if (hl <= 0) break;

					if (w == 1) {
						hl -= q;
						if (hl <= 0) continue;
					}
					hl %= p + q;
					if (hl <= p) f[i][j][w] = max(f[i][j][w], f[i+1][j+sk][1] + g[i]);
				}
			}
		}
	}

	// printf("> %d\n", f[1][2][1]);

	printf("%d\n", f[0][0][0]);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int q = 1; q <= tc; q++) {
		printf("Case #%d: ", q);
		solve();
		fprintf(stderr, "Case %d done.\n", q);
	}
	return 0;
}
