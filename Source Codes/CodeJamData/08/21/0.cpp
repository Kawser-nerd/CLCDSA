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

int i, j, k, m, n, l;

ll x[100001], y[100001];

ll remainder[3][3];

ll triples(ll n) {
	return n * (n-1) * (n-2) / 6;
}

ll pairs(ll n) {
	return n * (n-1) / 2;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		ll A, B, C, D, x0, y0, M;
		cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;

		x[0] = x0;
		y[0] = y0;
		
		F1(i,n-1) {
			x[i] = (A * x[i-1] + B) % M;
			y[i] = (C * y[i-1] + D) % M;
		}

		F0(i,3) F0(j,3) remainder[i][j] = 0;
		F0(i,n) {
			remainder[ x[i] % 3 ][ y[i] % 3 ]++;
		}
		ll ans = 0;

		for (int i1 = 0; i1 < 3; i1++)
			for (int j1 = 0; j1 < 3; j1++)
				for (int i2 = i1; i2 < 3; i2++)
					for (int j2 = 0; j2 < 3; j2++)
						if (i2 > i1 || j2 >= j1)
							for (int i3 = i2; i3 < 3; i3++)
								for (int j3 = 0; j3 < 3; j3++)
									if (i3 > i2 || j3 >= j2)
										if ((i1+i2+i3)%3 == 0 && (j1+j2+j3)%3==0)
										{
											ll c1 = remainder[i1][j1];
											ll c2 = remainder[i2][j2];
											ll c3 = remainder[i3][j3];
											pii p1 = pii(i1, j1);
											pii p2 = pii(i2, j2);
											pii p3 = pii(i3, j3);
											if (p1 != p2 && p2 != p3) ans += c1 * c2 * c3;
											else if (p1 == p2 && p2 == p3) ans += triples(c1);
											else if (p1 == p2 && p2 != p3) ans += pairs(c1) * c3;
											else if (p1 != p2 && p2 == p3) ans += pairs(c3) * c1;
											else return 5;
										}
		printf("Case #%d: %lld\n", tt, ans);
	}


	
	return 0;
}
