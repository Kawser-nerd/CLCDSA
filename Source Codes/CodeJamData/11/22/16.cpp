#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define FOR(i, a, b) for (int i = (a), _n = (b); i <= _n; ++i)
#define FORD(i, a, b) for (int i = (a), _n = (b); i >= _n; --i)
#define FORE(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int INF = 1000000000;

const int NMAX = 1000000;

int N, D, T[NMAX];

bool dasie(LL TT) {
//cout << "TT=" << TT << endl;
	int ind = N-1;
	LL right = 1LL * INF * INF;
	while (ind >= 0) {
		right -= D;
		if (T[ind]+TT < right) right = T[ind]+TT;
		if (T[ind]-TT > right) return false;
		--ind;
	}
	return true;
}

void testcase(int ncase) {
	N = 0;
	int C;
	scanf("%d%d", &C, &D);
	D *= 2;
	REP(i, C) {
		int P, V;
		scanf("%d%d", &P, &V);
		REP(i, V) T[N++] = 2*P;
	}
	
	LL left = 0, right = 1LL * INF * INF / 100;
	while (left != right) {
		LL mid = (left+right)/2;
		if (dasie(mid)) right = mid;
		else left = mid+1;
	}
	printf("Case #%d: %.6lf\n", ncase, left / 2.0);
}

int main() {
	int T;
	scanf("%d", &T);
	FOR(i, 1, T) testcase(i);
}
