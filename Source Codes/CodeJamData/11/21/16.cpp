#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <functional>
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

const int NMAX = 100;

char T[NMAX][NMAX+1];
double WP[NMAX], WP_bez[NMAX][NMAX], OWP[NMAX], OOWP[NMAX];

void testcase(int ncase) {
	int N;
	scanf("%d", &N);
	REP(i, N) scanf("%s", T[i]);
	
	REP(i, N) {
		int wins = 0, all = 0;
		REP(j, N) {
			if (T[i][j] != '.') ++all;
			if (T[i][j] == '1') ++wins;
		}
		WP[i] = 1.0 * wins / all;
		REP(k, N) {
			int nall = all, nwins = wins;
			if (T[i][k] != '.') --nall;
			if (T[i][k] == '1') --nwins;
			WP_bez[i][k] = 1.0 * nwins / nall;
		}
	}
	REP(i, N) {
		double sum = 0;
		int all = 0;
		REP(j, N) if (T[i][j] != '.') {
			sum += WP_bez[j][i];
			++all;
		}
		OWP[i] = sum / all;
	}
	REP(i, N) {
		double sum = 0;
		int all = 0;
		REP(j, N) if (T[i][j] != '.') {
			sum += OWP[j];
			++all;
		}
		OOWP[i] = sum / all;
	}
	
	printf("Case #%d:\n", ncase);
	REP(i, N) printf("%.10lf\n", 0.25 * WP[i] + 0.5 * OWP[i] + 0.25 * OOWP[i]);
}

int main() {
	int T;
	scanf("%d", &T);
	FOR(i, 1, T) testcase(i);
}
