#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


#define forn(i,n)  for (int i=0; i<int(n); ++i)
typedef long long int64;
const int INF = (int) 1E9;

const double EPS = 1E-6;


struct pt {
	double x, y, r;
	int s;
};

#define sqr(n)  ((n)*(n))

double dist (pt a, pt b) {
	return sqrt (sqr(a.x-b.x) + sqr(a.y-b.y));
}

int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int tests;
	cin >> tests;
	forn(test,tests) {
		
		int n;
		cin >> n;
		vector<pt> a (n);
		forn(i,n)
			cin >> a[i].x >> a[i].y >> a[i].r >> a[i].s;

		int ans = 0,  ansm = 0;
		forn(i,1<<n) {
			bool ok = true;
			forn(j,n)
				if (i & (1<<j)) {
					forn(k,n)
						if (dist(a[j],a[k]) <= a[j].r + EPS)
							ok &= (i & (1<<k)) != 0;
					if (!ok)  break;
				}
			if (ok) {
				int score = 0;
				forn(j,n)
					if (i & (1<<j))
						score += a[j].s;
				if (score > ans)
					ans = score,  ansm = i;
			}
		}

		printf ("Case #%d: %d\n", test+1, ans);

	}

}