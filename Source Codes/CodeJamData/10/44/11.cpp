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
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, ans;
char ss[1000002];

double px[5001], py[5001], qx[5001], qy[5001];

double solve1(double r1, double r2, double d) {
	double alp = acos( (r1*r1+d*d-r2*r2) / (2*r1*d) );
	if (alp < 0) alp += pi;

	return alp*r1*r1-r1*r1*sin(2*alp)/2;
}

void solve(double r1, double r2, double d) {
	double ans = solve1(r1, r2, d) + solve1(r2, r1, d);
	printf(" %.7lf", ans);
}

int main() {
//	freopen("d.in", "r", stdin);

	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);

//	freopen("D-large.in", "r", stdin);
//	freopen("D-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		printf("Case #%d:", tt);
		cin >> n >> m;
		F0(i,n) cin >> px[i] >> py[i];
		F0(i,m) cin >> qx[i] >> qy[i];

		F0(i,m) {
			// small
			solve( hypot(px[0]-qx[i], py[0]-qy[i]), hypot(px[1]-qx[i], py[1]-qy[i]), hypot(px[0]-px[1], py[0]-py[1]));
		}
		printf("\n");
	}
	
	return 0;
}
