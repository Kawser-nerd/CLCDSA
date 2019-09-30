#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define REP(i,a,n) for (int i = (a); i < (n); i++)

template<class T> T& setmin(T &a, const T &b) {return a = min(a, b);}
template<class T> T& setmax(T &a, const T &b) {return a = max(a, b);}
template<class T> T MODD(const T &a, const T &b) {T r = a%b; if (r < 0) r += b; return r;}


template <ll mod>
struct int_mod {
	ll v;
	int_mod() : v(0) {}
	int_mod(ll v_) : v(v_) {
		if (v < 0)
			v += mod;
		else if (v >= mod)
			v -= mod;
		if (v < 0 || v >= mod) {
			v %= mod;
			if (v < 0)
				v += mod;
		}
	}
	int_mod operator+(const int_mod &b) const {
		return v+b.v;
	}
	int_mod operator-(const int_mod &b) const {
		return v-b.v;
	}
	int_mod operator*(const int_mod &b) const {
		return v*b.v;
	}
	bool operator==(const int_mod &b) const {
		return v == b.v;
	}
	bool operator!=(const int_mod &b) const {
		return v != b.v;
	}
	int_mod& operator+=(const int_mod &b) {
		v += b.v;
		v %= mod;
		return *this;
	}
	int_mod& operator-=(const int_mod &b) {
		v -= b.v-mod;
		v %= mod;
		return *this;
	}
	int_mod& operator*=(const int_mod &b) {
		v *= b.v;
		v %= mod;
		return *this;
	}
};

template <ll mod>
int_mod<mod> operator+(ll a, const int_mod<mod> &b) {
	return int_mod<mod>(a)+b;
}

template <ll mod>
int_mod<mod> operator-(ll a, const int_mod<mod> &b) {
	return int_mod<mod>(a)-b;
}

template <ll mod>
int_mod<mod> operator-(const int_mod<mod> &b) {
	return int_mod<mod>(0)-b;
}

template <ll mod>
int_mod<mod> operator*(ll a, const int_mod<mod> &b) {
	return int_mod<mod>(a)*b;
}

const ll MOD = 1000000007;
typedef int_mod<MOD> im;

const int MAX = 1100000;
im fac[MAX];
im f[MAX];
im in[MAX];

void docase() {
	int N, X;
	scanf("%d%d", &N, &X);
	im res, bi = 1;
	REP(y,0,N+1) {
		//im bi = bin(N,y);
		if (y > 0)
			bi = bi*(N-y+1)*in[y];
		//printf("bin(%d,%d) = %lld\n", N, y, bi.v);
		if (y >= X)
			res += bi*bi*fac[y]*f[N-y];
	}
	printf("%lld\n", res.v);
}

int main() {
	fac[0] = 1;
	f[0] = 1;
	im ar = -1;
	REP(n,1,MAX) {
		fac[n] = fac[n-1]*n;
		f[n] = f[n-1]*n*n+ar*fac[n];
		ar = -ar;
	}
	in[1] = 1;
	REP(k,2,MAX) {
		in[k] = -(ll)(MOD/k)*in[MOD%k];
		assert(in[k]*k == 1);
	}
	int T;
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		docase();
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
