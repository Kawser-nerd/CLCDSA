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

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int L, D, N;
	scanf("%d%d%d", &L, &D, &N);
	vector<string> words;
	static char buf[1<<20];
	REP(i, D) {
		scanf("%s", buf);
		words.push_back(buf);
	}
	FOR(test, 1, N) {
		scanf("%s", buf);
		vector<vector<bool> > can(L, vector<bool>(26));
		int at = 0;
		REP(i, L) {
			if (buf[at] == '(') {
				++at;
				while (buf[at] != ')') {
					can[i][buf[at]-'a'] = true;
					++at;
				}
				++at;
			} else {
				can[i][buf[at++]-'a'] = true;
			}
		}
		int cnt = 0;
		REP(i, size(words)) {
			bool ok = true;
			REP(j, L)
				if (!can[j][words[i][j]-'a']) {
					ok = false;
					break;
				}
			if (ok)
				++cnt;
		}
		printf("Case #%d: %d\n", test, cnt);
	}

	exit(0);
}
