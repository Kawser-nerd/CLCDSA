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

ll sm[1000010];
int a[1000010];
int N;

ll get(int i, int j) {
	ll A = 0, B = 0, C = 0;
	if (i > 0) A = sm[i - 1];
	if (j < N - 1) C = sm[N - 1] - sm[j];
	B = sm[j];
	if (i > 0) B -= sm[i - 1];
	return max(A, max(B, C));
}

void solve() {
	ll p, q, r, s;
	cin >> N >> p >> q >> r >> s;
	forn(i, N) {
		a[i] = (i * p + q) % r + s;
		sm[i] = a[i];
		if (i > 0) sm[i] += sm[i-1];
	}

	ll ans = sm[N - 1];
	forn(i, N) {
		int L = i, R = N - 1;
		while (R - L > 3) {
			int m1 = L + (R - L) / 3;
			int m2 = R - (R - L) / 3;
			if (get(i, m1) < get(i, m2))
				R = m2;
			else
				L = m1;
		}

		for (int j = L; j <= R; j++) {
			ll z = get(i, j);
			if (z < ans) ans = z;
		}
	}

	printf("%.10f\n", double(sm[N - 1] - ans) / sm[N - 1]);
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
