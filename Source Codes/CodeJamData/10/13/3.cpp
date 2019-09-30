#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <numeric>
#include <cctype>
#include <climits>
#include <cassert>
using namespace std;

typedef long long int64; 
typedef unsigned long long uint64;

template<typename T> int size(const T& c) { return int(c.size()); }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }
template<typename T> bool remin(T& x, T y) { if (x <= y) return false; x = y; return true; }
template<typename T> bool remax(T& x, T y) { if (x >= y) return false; x = y; return true; }

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n) - 1); i >= 0; --i)

int a1, a2, b1, b2;

bool win(int a, int b) {
	if (b > a) swap(a, b);
	if (a == b) return false;
	if (a-b >= b) return true;
	return !win(b, a-b);
}

const double tau = (1+sqrt(5.0))/2;

int lower(int n) {
	return int(ceil(n/tau));
}

int upper(int n) {
	return int(floor(n*tau));
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int ntests;
	scanf("%d", &ntests);
	FOR(test, 1, ntests) {
		printf("Case #%d: ", test);
		scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
		int64 res = int64(a2-a1+1)*(b2-b1+1);
		FOR(a, a1, a2) {
			int x1 = lower(a), x2 = upper(a);
			x1 = max(x1, b1); x2 = min(x2, b2);
			if (x1 <= x2) res -= x2-x1+1;
		}
		printf("%lld\n", res);
	}
}
