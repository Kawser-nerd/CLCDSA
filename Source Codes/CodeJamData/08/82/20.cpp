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

struct Painter
{
	string color;
	int L, R;

	void read() {
		static char tmp[256];
		scanf("%s %d %d", tmp, &L, &R);
		color = tmp;
	}
};

inline bool operator < (const Painter &a, const Painter &b)
{
	if (a.L != b.L)
		return a.L < b.L;
	return a.R < b.R;
}

VPII select(const vector<Painter> &p, string color1, string color2 = "",  string color3 = "")
{
	VPII res;
	REP(i, p.sz)
		if ( (p[i].color == color1) || (p[i].color == color2)  || (p[i].color == color3) )
			res.pb(PII(p[i].L, p[i].R));

	return res;
}

int solve(const VPII &list)
{
	int cnt = 0;
	int L = 1, R = 0;
	REP(i, list.sz) {
		const PII &p = list[i];
		if (p.X <= L) {
			R = max(R, p.Y);
		} else {
			cnt++;
			L = R+1;
			if (p.X > L)
				return INF;
			R = p.Y;
		}
	}

	if (L < R)
		cnt++;

	if (R < 10000)
		return INF;
	return cnt;
}

int solve()
{
	int N;
	scanf("%d", &N);
	vector<Painter> painters(N);
	set<string> colorSet;
	REP(i, N) {
		painters[i].read();
		colorSet.insert(painters[i].color);
	}

	SORT(painters);
/*
	int stupid = INF;
	REP(i, 1 << N) {
		vector<string> sss;
		int cur = INF;
		REP(j, N)
			if (i & (1 << j))
				sss.pb(painters[j].color);
		cur = sss.sz;
		if (cur >= stupid)
			continue;

		UNIQUE(sss);
		if (sss.sz > 3)
			continue;

		vector<bool> cover(10000, false);
		REP(j, N)
			if (i & (1 << j))
				FOR(s, painters[j].L, painters[j].R+1)
					cover[s-1] = true;
		bool good = true;
		REP(j, 10000)
			if (cover[j] == false) {
				good = false;
				break;
			}

		if (good)
			stupid = min(stupid, cur);
	}
*/
	int ans = INF;
	vector<string> colorList(ALL(colorSet));
	REP(i, colorList.sz)
		ans = min(ans, solve(select(painters, colorList[i])));
	REP(i, colorList.sz)
	REP(j, i)
		ans = min(ans, solve(select(painters, colorList[i], colorList[j])));
	REP(i, colorList.sz)
	REP(j, i)
	REP(k, j)
		ans = min(ans, solve(select(painters, colorList[i], colorList[j], colorList[k])));
/*
	if (stupid != ans) {
		cout << "!!!! " << stupid << endl;
	}
*/
	return ans;
}

int main()
{
	freopen("B-small-attempt1.in", "rt", stdin);
	freopen("B-small-attempt1.out", "wt", stdout);
	int nTest;
	scanf("%d", &nTest);
	for (int iTest = 1; iTest <= nTest; iTest++) {
		printf("Case #%d: ", iTest);
		int r = solve();
		if (r >= INF)
			puts("IMPOSSIBLE"); else
			printf("%d\n", r);
	}
	return 0;
}
