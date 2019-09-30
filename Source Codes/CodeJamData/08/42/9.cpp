#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// BEGIN CUT HERE
#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())

#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define sz size()

typedef long long i64;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
// END CUT HERE

void solve()
{
	int W, H, A;
	scanf("%d %d %d", &W, &H, &A);
	int x1, y1, x2, y2;

	if (A > W*H) {
		cout << "IMPOSSIBLE";
		return;
	}

	x1 = W;
	y2 = (A+W-1)/W;
	x2 = x1*y2 - A;
	y1 = 1;
	cout << "0 0 " << x1 << " " << y1 << " " << x2 << " " << y2;
}

int main()
{
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.out", "wt", stdout);
	int nTest;
	scanf("%d", &nTest);
	for (int iTest = 1; iTest <= nTest; iTest++) {
		cout << "Case #" << iTest << ": ";
		solve();
		cout << endl;
	}
	return 0;
}
