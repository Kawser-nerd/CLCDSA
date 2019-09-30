#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <cassert>
//#include <utility>
//#include <memory>
//#include <functional>
//#include <deque>
//#include <cctype>
//#include <ctime>
//#include <numeric>
//#include <list>
//#include <iomanip>

//#if __cplusplus >= 201103L
//#include <array>
//#include <tuple>
//#include <initializer_list>
//#include <forward_list>
//
//#define cauto const auto&
//#else

//#endif

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()) {
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t) {
	stringstream ss;
	ss << f;
	ss >> t;
}

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x)
#define debug(x)
#endif

#define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

void mainmain() {
	int n;
	cin >> n;
	vll a(n);
	vll b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<pll> u;
	vector<pll> d;
	vector<pll> t;
	rep(i, n) {
		if(a[i] - b[i] < 0) {
			d.PB(pll(a[i], b[i]));
		}
		else if(a[i] - b[i] > 0) {
			u.PB(pll(b[i], a[i]));
		}
		else {
			t.PB(pll(a[i], b[i]));
		}
	}
	sort(ALL(d));
	sort(ALL(t));
	sort(ALL(u));
	reverse(ALL(u));
	int ds = d.size();
	int us = u.size();
	ll x = 0;
	ll res = 0;
	ll sum = 0;
	rep(i,n) sum+=a[i]-b[i];
	rep(i, ds) {
		maxs(res, x + d[i].F);
		x += d[i].F - d[i].S;
	}
	rep(i, t.size()) {
		maxs(res, x + t[i].F);
		x += t[i].F - t[i].S;
	}
	rep(i, us) {
		maxs(res, x + u[i].S);
		x += -u[i].F + u[i].S;
	}
	cout << res << endl;
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(20);
	mainmain();
}