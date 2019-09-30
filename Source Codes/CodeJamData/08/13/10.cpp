#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define REP(i,n) FOR(i,0,n)
#define REPD(i,n) FORD(i,0,n)
#define VAR(v,w) __typeof(w) v=(w)
#define FORE(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define PB push_back
#define ALL(c) (c).begin(),(c).end()
#define SIZE(c) ((int)(c).size())
#define MP make_pair
#define FT first
#define SD second
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<double> VD;
typedef vector<LD> VLD;
typedef vector<LL> VLL;
typedef vector<bool> VB;
typedef istringstream ISS;
typedef ostringstream OSS;

struct mat {
	int m,n;
	vector<vector<int> > a;
	mat(int m1,int n1=0):m(m1),n(n1){
		if (!n) n=m;
		a.resize(m);
		REP(i,m) a[i].resize(n);
	}
	mat(vector<int> v):m(SIZE(v)),n(1){
		a.resize(m);
		REP(i,m) a[i].resize(1,v[i]);
	}
	mat operator*(const mat& x) {
		mat r(m,x.n);
		REP(i,m) REP(j,x.n) REP(k,n)
			r.a[i][j] = (r.a[i][j] + a[i][k]*x.a[k][j]) % 1000;
		return r;
	}
	vector<int>& operator[](int i) {return a[i];}
	static mat scalar(int d, int x) {
		mat u(d);
		REP(i,d)
			u.a[i][i] = x;
		return u;
	}
};

template<class T, class E>
T POWER(T x, E y, T unit) {
	T p = x, r = unit;
	while (y) {
		if (y&1)
			r = r*p;
		p = p*p;
		y >>= 1;
	}
	return r;
}

int main() {
	int ccc;
	cin >> ccc;
	REP(cc,ccc) {
		int n;
		cin >> n;
		mat a(2);
		a[0][0] = 6;
		a[0][1] = 996;
		a[1][0] = 1;
		a[1][1] = 0;
		a = POWER(a,n-1,mat::scalar(2, 1));
		int res = (6*a[0][0]+2*a[0][1]+999)%1000;
		cout << "Case #" << cc+1 << ": " << res/100 << (res/10)%10 << res%10 << endl;
	}
}
