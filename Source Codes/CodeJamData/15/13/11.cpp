#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s); i>=(e); i--)
#define LL long long
#define eps 1e-12
#define pi acos(-1.0)
LL max(LL a,LL b){if (a>b){return a;} else {return b;}}
LL min(LL a,LL b){if (a<b){return a;} else {return b;}}

struct P{
    double x, y;
    P(){}
    P(int x, int y):x(double(x)), y(double(y)){}
    P(double x, double y):x(x) , y(y){}
    P operator+ (const P &a) const {return P(x+a.x, y+a.y);}
    P operator- (const P &a) const {return P(x-a.x, y-a.y);}
    double operator^ (const P &a) const {return x*a.x+y*a.y;}
    void in(){scanf("%lf%lf", &x, &y);}
    void out(){printf("REQUIRED %.7f %.7f\n", x, y);}
    double dist(P a, P b) {return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
    double sqdist(P a, P b) {return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}

};

int x[4001], y[4001];

double f(int y, int x){
	double z = atan2(y, x) * 180 / pi;
	if (z + eps < 0.00) z += 360.00;	
	return z;
}

double a[4001];

void solve(){
	int n;
	scanf("%d", &n);
	FOE(i, 1, n) scanf("%d%d", &x[i], &y[i]);
	FOE(i, 1, n){
		int res = 0;
		FOE(j, 1, n) if (i != j){
			a[j + (j > i?-1:0)] = f(x[j] - x[i], y[j] - y[i]);	
		}
		sort(a + 1, a + n);
	//	printf("CHECK %d\n", i);
	//	FOE(j, 1, n - 1) printf("%.9f  ", a[j]);
	//	puts("");
		int p2 = 1;
		FOE(j, 1, n - 1){
			bool ok = true;
			while (ok){
				int nxt = (p2 % (n - 1) + 1);
				if (nxt != j && a[nxt] + (nxt < j? 360.00:0.00) < a[j] + 180.00 + eps) p2 = nxt;
				else ok = false;	
			}
		//	printf("%d %d\n", j, p2);
			int tot = p2 - j + 1;
			if (tot <= 0) tot = p2 + (n - 1) - j + 1;
			res = max(res, tot);
			if (p2 == j) p2 = (p2 % (n - 1) + 1);
			//printf("%d %d\n", j, p2);
		}
		printf("%d\n", n - res - 1);
	}
}

int main(){
	freopen("C-large.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int t;
	scanf("%d", &t);
	FOE(i, 1, t){
		printf("Case #%d:\n", i);
		solve();	
	}
    return 0;
}
