#include <iostream>
#include <cstdio>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <functional>
#include <string>
#include <list>
#include <fstream>
#include <iomanip>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <nmmintrin.h>
#include <chrono>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

struct Edge {
	int from, to, weight;

	bool operator < (const Edge& obj) const {
		return weight < obj.weight;
	}
	bool operator > (const Edge& obj) const {
		return weight > obj.weight;
	}
};

struct Segtree {
	int n;
	vector<ll> x, laz;

	Segtree(int _n) {
		n = 1;
		while (n < _n) n *= 2;
		x.resize(n * 2);
		laz.resize(n * 2);
	}

	void upd(int k) {
		x[k] += laz[k];
		if (k * 2 + 1 < laz.size()) {
			laz[k * 2] += laz[k];
			laz[k * 2 + 1] += laz[k];
		}
		laz[k] = 0;
	}

	void add(int l, int r, ll v, int k = 1, int a = 0, int b = -1) {
		if (l == r) return;
		upd(k);
		if (b == -1) b = n;
		if (l == a && r == b) {
			laz[k] += v;
			return;
		}
		upd(k);
		int mid = (a + b) / 2;
		if (mid > l)
			add(l, min(mid, r), v, k * 2, a, mid);
		if (r > mid)
			add(max(mid, l), r, v, k * 2 + 1, mid, b);
		upd(k * 2);
		upd(k * 2 + 1);
		x[k] = max(x[k * 2], x[k * 2 + 1]);
	}

	ll rmq(int l, int r, int k = 1, int a = 0, int b = -1) {
		if (l == r) return 0;
		if (b == -1) b = n;
		upd(k);
		if (l == a && r == b) return x[k];
		int mid = (a + b) / 2;
		ll ret = LLONG_MIN;
		if (mid > l)
			ret= max(ret,rmq(l, min(mid, r), k * 2, a, mid));
		if (r > mid)
			ret = max(ret,rmq(max(mid, l), r, k * 2 + 1, mid, b));
		return ret;
	}

};


struct BIT {
#define SZ(a) (a & (-a))
#define LEFT(a) (a-SZ(a))
#define UP(a) (a+SZ(a))

	vector<ll> x;
	BIT(int n) : x(n + 1){}
	void add(int p, int v) {
		for (int i = ++p; x.size() > i; i = UP(i)) {
			x[i] += v;
		}
	}
	int sum(int r) {
		ll ret = 0;
		for (int i = ++r; 0 < i; i = LEFT(i)) {
			ret += x[i];
		}
		return ret;
	}
};

int main()
{

	int n;
	cin >> n;

	int cand[2][101];
	REP(i, 2) {
		REP(j, n) {
			scanf("%d", &cand[i][j]);
		}
	}

	int dp[2][101] = {};
	dp[0][0] = cand[0][0];
	REP(i, 2) {
		REP(j, n) {
			if (!i)
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + cand[i + 1][j]);
			if(j < n-1)
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + cand[i][j + 1]);
		}
	}

	cout << dp[1][n-1] << endl;
	return 0;
}