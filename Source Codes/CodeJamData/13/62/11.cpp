#define _CRT_SECURE_NO_WARNINGS
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
#define CL(a,x) memset(x, a, sizeof(x))
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, ans;
int a[50005];
double maxd[50005], mind[50005];
char ss[1000002];

int main() {
//	freopen("b.in", "r", stdin);

//	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("B-small-attempt1.out", "w", stdout);

	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
        cerr << tt << endl;

		cin >> n;
		F0(i,n) cin >> a[i];

		double P = 0.0, Q = 1000000.0, R;

		F0(i,n) { maxd[i] = -1e100; mind[i] = 1e100; }

		F0(j,n) F0(i,j)
		{ 
			if (a[j] - a[i] > maxd[j-i]) maxd[j-i] = a[j] - a[i];
			if (a[j] - a[i] < mind[j-i]) mind[j-i] = a[j] - a[i];
		}
		
		F0(m,200)
		{
			R = (P + Q) / 2;
			bool sg = 1;
			int de;
			double dmin = -1e100, dmax = 1e100;
			F1(de,n-1)
			{
				dmin = max(dmin, (maxd[de]-2*R)/de);
				dmax = min(dmax, (mind[de]+2*R)/de);
			}
			sg = (dmin <= dmax);
			if (sg) Q = R; else P = R;
		}
		printf("Case #%d: ", tt);
		printf("%.10lf\n", R);
	}
    cerr << "Press any key to continue" << endl;
    while (1);

	return 0;
}
