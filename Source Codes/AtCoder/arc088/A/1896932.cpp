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
#ifdef _MSC_VER
#define __builtin_popcount _mm_popcnt_u32
#define __builtin_popcountll _mm_popcnt_u64
#endif
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
};
typedef vector<vector<Edge>> Graph;

template<class T, class OP, class PROP>
class Lazy_Segment_Tree {//0-indexed ??
public:
	vector<T> data, lazy;
	vector<bool> isupd;
	int n;
	Lazy_Segment_Tree() {}
	void init(int a) {
		n = 1;
		while (n < a) n *= 2;
		data.resize(n * 2 - 1);
		lazy.resize(n * 2 - 1);
		isupd.resize(n * 2 - 1);
	}

	void prop(int num, int s) {
		if (isupd[num]) {
			data[num] = PROP()(data[num], lazy[num], 1, s);
			if (num < n - 1) {
				lazy[num * 2 + 1] = PROP()(lazy[num * 2 + 1], lazy[num]);
				lazy[num * 2 + 2] = PROP()(lazy[num * 2 + 2], lazy[num]);
				isupd[num * 2 + 1] = 1;
				isupd[num * 2 + 2] = 1;
			}
			lazy[num] = T();
			isupd[num] = 0;
		}
	}
	void op(int a, int b, T v, int num = 0, int base = 1) {
		int l = (num + 1 - base) * (n / base), r = l + n / base;
		prop(num, r - l);
		if (a == l && b == r) {
			isupd[num] = 1;
			lazy[num] = PROP()(lazy[num], v);
			prop(num, r - l);
		}
		else {
			int nr = (l + r) / 2;
			if (nr > a) op(a, min(b, nr), v, num * 2 + 1, base * 2);
			if (nr < b) op(max(a, nr), b, v, num * 2 + 2, base * 2);
			prop(num * 2 + 1, (r - l) / 2), prop(num * 2 + 2, (r - l) / 2);
			data[num] = OP()(data[num * 2 + 1], data[num * 2 + 2]);
		}
	}

	T query(int a, int b, int num = 0, int base = 1) {
		int l = (num + 1 - base) * (n / base), r = l + n / base;

		prop(num, r - l);

		if (a == l && b == r)
			return data[num];
		else {
			int nr = (l + r) / 2;
			T ret = T();
			if (nr > a) ret = OP()(ret, query(a, min(b, nr), num * 2 + 1, base * 2));
			if (nr < b) ret = OP()(ret, query(max(a, nr), b, num * 2 + 2, base * 2));
			return ret;
		}
	}
};


template<class T>
class ADD {
public:
	T operator ()(const T a, const T b, const int ra = 1, int rb = 1) {
		return a*ra + b*rb;
	}
};

template<class T>
class UPD {
public:
	T operator ()(const T a, const T b, const int ra = 1, int rb = 1) {
		return b;
	}
};

template<class T>
class RMQ {
public:
	T operator ()(const T a, const T b) {
		return max(a, b);
	}
};
template<class T>
class SUM {
public:
	T operator ()(const T a, const T b) {
		return a + b;
	}
};

struct N {
public:
	int num;
	N(int num) : num(num) {}
	N() :num(INT_MIN/2) {}
	N operator + (const N obj) const {
		return N(obj.num + num);
	}
	N operator * (const N obj) const {
		return N(obj.num * num);
	}
	bool operator < (const N obj)const {
		return obj.num > num;
	}
};


int main(void) {
	ll bufx, bufy;
	__int128 x, y;
	cin >> bufx >> bufy;
	x = bufx, y = bufy;
	int l = 0, r = 60;

	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (x * (((__int128)1) << mid) <= y) {
			l = mid;
		}
		else r = mid;
	}
	cout << l + 1 << endl;
	return 0;
}