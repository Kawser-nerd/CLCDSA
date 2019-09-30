// GCJ
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Self Template Code BGEIN

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;

int sgn(double x) { return (x > 1e-8) - (x < -1e-8); }
int count_bit(int x) { return x == 0? 0 : count_bit(x >> 1) + (x & 1); }

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

const int MAXN = 12;

int n, a;
char mat[MAXN][MAXN];
int res[MAXN];

void input() {
	scanf ("%d%d", &n, &a);
	rep (i, n) {
		scanf ("%s", mat[i]);
		// puts (mat[i]);
	}
}

bool check() {
	// puts ("check");
	// rep (i, n) {
	// 	printf ("%d%c", res[i], i == n - 1? '\n' : ' ');
	// }
	int cur = res[0];
	repf (i, 1, n - 1) {
		// printf ("%d now %d next %d %c\n", i, cur, res[i], mat[cur][res[i]]);
		if (mat[cur][res[i]] == 'N') {
			cur = res[i];
		}
	}
	return cur == a;
}

void solve() {
	rep (i, n) {
		res[i] = i;
	}

	bool flag = false;
	do {
		if (check()) {
			flag = true;
			break;
		}

	} while (next_permutation(res, res + n));

	if (!flag) {
		puts ("IMPOSSIBLE");
		return ;
	}
	rep (i, n) {
		printf ("%d%c", res[i], i == n - 1? '\n' : ' ');
	}
}

int main() {
	freopen ("D.out", "w", stdout);

	repcase {
		fprintf(stderr, "solving case %d / %d...\n", Case, t + Case - 1);
		printf ("Case #%d: ", Case++);

		input();

		solve();
	}
	return 0;
}