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
#define eps 1e-9
#define pi acos(-1.0)
#define fail {printf("Impossible\n"); return 0;}
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

int n, m, a[2001];

void solve(){
	scanf("%d%d", &n, &m);
	FOE(i, 1, n) scanf("%d", &a[i]);
	
	LL low = 0, high = 1e14, res;
	while (low <= high){
		LL mid = (low + high) / 2;
		LL cnt = 0;
		FOE(i, 1, n) cnt += (mid + a[i] - 1) / a[i];
		if (cnt >= m){
			high = mid - 1;	
		} else {
			res = mid;
			low = mid + 1;	
		}
	}
	
	LL cnt = 0;
	FOE(i, 1, n) cnt += (res + a[i] - 1) / a[i];
	
	m = m - cnt;
	
	FOE(i, 1, n) if (res % a[i] == 0){
		m--;
		if (m == 0) printf("%d\n", i);	
	}
	
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t;
	scanf("%d", &t);
	FOE(i, 1, t){
		printf("Case #%d: ", i);
		solve();	
	}
    return 0;
}
