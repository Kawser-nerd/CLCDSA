#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
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

const int mod = 30031;
int n, k, p;
VI mask;

inline int ONES(int x) {
	x = (0x55555555&x)+(0x55555555&(x>>1));
	x = (0x33333333&x)+(0x33333333&(x>>2));
	x = (0x0f0f0f0f&x)+(0x0f0f0f0f&(x>>4));
	x = (0x00ff00ff&x)+(0x00ff00ff&(x>>8));
	x = (0x0000ffff&x)+(0x0000ffff&(x>>16));
	return x;
}

template<class T>
struct MATRIX {
	int m,n;
	vector<vector<T> > a;
	MATRIX(int m1,int n1=0):m(m1),n(n1){
		if (!n) n=m;
		a.resize(m);
		REP(i,m) a[i].resize(n);
	}
	MATRIX(vector<T> v):m(SIZE(v)),n(1){
		a.resize(m);
		REP(i,m) a[i].resize(1,v[i]);
	}
	MATRIX operator*(const MATRIX& x) {
		MATRIX r(m,x.n);
		REP(i,m) REP(j,x.n) REP(k,n)
			r.a[i][j] = (r.a[i][j] + ((a[i][k]*x.a[k][j]) % mod)) % mod;
		return r;
	}
	vector<T>& operator[](int i) {return a[i];}
	static MATRIX scalar(int d, T x) {
		MATRIX u(d);
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

inline bool ismove(int a, int b) {
	return (((ONES((a<<1)^b) == 2)) || (ONES((a<<1)^b) == 0)) && ((b&1) == 1);
}

int main() {
	int ccc;
	cin >> ccc;
	REP(cc,ccc) {
		mask.clear();
		cin >> n >> k >> p;
		REP(m,1<<p)
			if (ONES(m) == k)
				mask.PB(m);
		int x = SIZE(mask);
		MATRIX<int> a(x);
		REP(i,x) REP(j,x) {
			int m1 = mask[i];
			int m2 = mask[j];
			a[i][j] = ismove(m1,m2);
		}
		a = POWER(a,n-k,MATRIX<int>::scalar(x,1));
		int res = a[0][0];
		cerr << "Case #" << cc+1 << ": " << res << endl;
		cout << "Case #" << cc+1 << ": " << res << endl;
	}
}
