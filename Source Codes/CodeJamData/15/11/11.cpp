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

int n, a[2000], dif;

void solve(){
	scanf("%d", &n);
	FOE(i, 1, n) scanf("%d", &a[i]);
	LL res1 = 0;
	FOR(i, 1, n){
		if (a[i] > a[i + 1]) res1 += (LL)(a[i] - a[i + 1]); 	
	}
	printf("%I64d ", res1);
	int dif = 0;
	FOR(i, 1, n){
		if (a[i] > a[i + 1]) dif = max(dif, a[i] - a[i + 1]);	
	}
	LL res2 = 0;
	FOR(i, 1, n){
		res2 += (LL)min(a[i], dif);
	}
	printf("%I64d\n", res2);
}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int t;
	scanf("%d", &t);
	FOE(i, 1, t){
		printf("Case #%d: ", i);
		solve();	
	}
    return 0;
}
