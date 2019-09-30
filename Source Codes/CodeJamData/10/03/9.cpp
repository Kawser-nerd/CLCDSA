#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

#define FOR(i,a,n) for (int i = (a); i < (n); ++i)
#define FORE(i,a,n) for (int i = (a); i <= (n); ++i)
#define FORD(i,a,b) for (int i = (a); i >= (b); --i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define LL long long
#define FIR(n) REP(i,n)
#define FJR(n) REP(j,n)
#define ALL(v) v.begin(), v.end()

#define FI FIR(n)
#define FJ FJR(n)
#define FR(i,a) FOR(i,a,n)
#define REPN(i) REP(i,n)


LL R, k, n;
LL g[1024], s[1024], next[1024];
int last_r[1024];
LL last_s[1024];

LL solve() {
	cin >> R >> k >> n;
	FI cin >> g[i];

	FI {
		if (g[i] > k) {
			s[i] = 0;
			next[i] = i;
		} else {
			s[i] = g[i];
			int j = i ;
			while (true) {
				++j; j %= n;
				if (j == i) break;
				if (s[i] + g[j] > k) break;
				s[i] += g[j];
			}
			next[i] = j;
		}
	}

	memset(last_r, -1, sizeof last_r);
	int r = 0;
	int cur = 0;
	LL res = 0;
	for (; r < R; ++r) {
		if (last_r[cur] == -1) {
			last_r[cur] = r;
			last_s[cur] = res;

			res += s[cur];
			cur = next[cur];
		} else {
			LL dr = r - last_r[cur];
			LL ds = res - last_s[cur];
			LL times = (R - last_r[cur]) / dr;
			res = last_s[cur] + times*ds;
			r = last_r[cur] + times *dr;
			break;
		}
	}

	for (; r < R; ++r) {
		res += s[cur];
		cur = next[cur];
	}

	return res;
}

int main() {

freopen("C-large.in", "rt", stdin); 
freopen("C-large.out", "w", stdout);

	int ttc;
	cin >> ttc;
	FORE(tc, 1, ttc) {
		printf("Case #%d: %lld\n", tc, solve());
	}
}
