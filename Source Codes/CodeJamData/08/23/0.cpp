#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;

int i, j, k, m, n, l, o, p;
int a[5000001], q[5000001], h[5000001];

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int tt, tn;
	cin >> tn;

	F1(tt,tn) {
		cin >> n >> k; F1(i,k) cin >> q[i];
		printf("Case #%d:", tt);
		F1(i,n) a[i] = -1;
		m = 1;
		while (m < n) m *= 2;

		for (i = m; i < m+n; i++) h[i] = 1;
		for (i = m-1; i >= 1; i--) h[i] = h[2*i] + h[2*i+1];		

		F1(i,n) {
			int places = n-i+1;
			l = i % (places);
			if (l == 0) l += places;

			if (i == 1) {
				j = 1;
			} else {
				o = m + j;
				int lc = 0;
				while (o > 1) {
					if (o&1) {
						o /= 2;
						lc += h[2*o];
					} else {
						o /= 2;
					}
				}
				lc += l;
				lc %= places;
				if (lc == 0) lc += places;

				j = 1;
				while (j < m) {
					if (h[2*j] >= lc) j = 2*j;
					else {
						lc -= h[2*j];
						j = 2*j+1;
					}
				}
				j -= (m-1);
			}
			o = m - 1 + j;
			while (o >= 1) {
				h[o]--;
				o /= 2;
			}

			a[j] = i;
		}
		F1(i,k) printf(" %d", a[q[i]]);
		printf("\n");
	}

	return 0;
}
