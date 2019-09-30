#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define sz(a)       int((a).size())
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define REP(i,n)    FOR(i,0,n)
#define UN(v)       sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)     memset(a,b,sizeof a)
#define pb          push_back
#define X           first
#define Y           second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> point;

const double pi = acos(-1.);

int n, m;
pii p[2], q[10];

long double dist(const pii &p, const pii &q) {
	int x = p.X - q.X, y = p.Y - q.Y;
	return sqrtl(x * x + y * y);
}

double f(pii q) {
	long double a = dist(p[0], q), b = dist(p[1], q), c = dist(p[0], p[1]);
	long double d = (c * c + a * a - b * b) / (2 * c);	
	long double A = acos(d / a), B = acos((c - d) / b);
	long double p = (a + b + c) * .5;
	return (A * a * a + B * b * b - 2 * sqrtl(max(0.0L, p * (p - a) * (p - b) * (p - c))));
}

void Solve(){
	cin >> n >> m;
	REP (i, n) cin >> p[i].X >> p[i].Y;
	REP (i, m) cin >> q[i].X >> q[i].Y;
	REP (i, m) {
		if (i) putchar(' ');
		printf("%.9lf", f(q[i]));
	}
	cout << endl;
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}
