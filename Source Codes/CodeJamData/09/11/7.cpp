#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <numeric>
using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n)-1); i >= 0; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int64;
typedef unsigned long long uint64;

template<typename T> int size(const T& c) { return (int)c.size(); }
template<typename T> void remin(T& a, const T& b) { if (b < a) a = b; }
template<typename T> void remax(T& a, const T& b) { if (b > a) a = b; }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }

int happy[11][1000000];

bool isHappy(int base, int num) {
	assert(num > 0);
	if (num == 1)
		return true;
	if (num < 1000000) {
		if (happy[base][num])
			return happy[base][num] == 1;
		happy[base][num] = -1;
	}
	int sum = 0, t = num;
	while (t) {
		sum += sqr(t%base);
		t /= base;
	}
	bool res = isHappy(base, sum);
	if (num < 1000000)
		happy[base][num] = res ? 1 : -1;
	return res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	static char s[1<<20];
	gets(s);
	FOR(test, 1, atoi(s)) {
		printf("Case #%d: ", test);
		gets(s);
		string st(s);
		istringstream iss(st);
		vector<int> bases;
		int x;
		while (iss >> x)
			bases.push_back(x);
		int res = 2;
		for (;;) {
			bool ok = true;
			REP(i, size(bases))
				if (!isHappy(bases[i], res)) {
					ok = false;
					break;
				}
			if (ok) break;
			++res;
		}
		printf("%d\n", res);
	}

	exit(0);
}
