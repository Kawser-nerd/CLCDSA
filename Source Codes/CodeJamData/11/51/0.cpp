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
double X1[100], Y1[100], X2[100], Y2[100], W;
char ss[1000002];

double solve(double P, double Q, double S) {
	int i;
	for (int uu = 0; uu < 100; uu++) {
		double R = (P + Q) / 2.0, Area = 0.0;
		F1(i,n-1) if (X2[i] <= R) {
			Area += (X2[i] - X2[i-1]) * (Y2[i-1] + Y2[i]);
		} else {
			double YY = Y2[i-1] + (Y2[i] - Y2[i-1]) * (R - X2[i-1]) / (X2[i] - X2[i-1]);
			Area += (R - X2[i-1]) * (Y2[i-1] + YY);
			break;
		}
		F1(i,m-1) if (X1[i] <= R) {
			Area -= (X1[i] - X1[i-1]) * (Y1[i-1] + Y1[i]);
		} else {
			double YY = Y1[i-1] + (Y1[i] - Y1[i-1]) * (R - X1[i-1]) / (X1[i] - X1[i-1]);
			Area -= (R - X1[i-1]) * (Y1[i-1] + YY);
			break;
		}
		if (Area >= S)
			Q = R;
		else 
			P = R;
	}

	return (P + Q) / 2.0;
}

int main() {
//	freopen("a.in", "r", stdin);

//	freopen("A-small-attempt0.in", "r", stdin);
//	freopen("A-small-attempt0.out", "w", stdout);

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		printf("Case #%d:\n", tt);
		cin >> W >> m >> n >> k;
		F0(i,m) cin >> X1[i] >> Y1[i];
		F0(i,n) cin >> X2[i] >> Y2[i];
		
		double Total = 0.0;
		F1(i,n-1) {
			Total += (X2[i] - X2[i-1]) * (Y2[i-1] + Y2[i]);
		}
		F1(i,m-1) {
			Total -= (X1[i] - X1[i-1]) * (Y1[i-1] + Y1[i]);
		}
		double Last = 0.0;
		for (i = 1; i < k; i++) {
			double x = solve(Last, W, i * Total / k);
			Last = x;
			printf("%.10lf\n", x);
		}
	}
	
	return 0;
}
