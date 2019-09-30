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

#define INF 1000000
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

const int MaxM = 10240;

int M, V;
int G[MaxM], C[MaxM], minChange[MaxM][2];

int makeOR(int goal, int pL, int pR)
{
	if (goal == 0)
		return minChange[pL][0] + minChange[pR][0];

	return min(minChange[pL][1], minChange[pR][1]);
}

int makeAND(int goal, int pL, int pR)
{
	if (goal == 1)
		return minChange[pL][1] + minChange[pR][1];

	return min(minChange[pL][0], minChange[pR][0]);
}

int make(int goal, int operation, int pL, int pR)
{
	if (operation == 0)
		return makeOR(goal, pL, pR); else
		return makeAND(goal, pL, pR);
}

void solve(int iTest)
{
	scanf("%d %d", &M, &V);
	REP(i, (M-1)/2)
		scanf("%d %d", &G[i+1], &C[i+1]);
	REP(i, (M+1)/2) {
		int v = (M-1)/2 + 1 + i;
		int x;
		scanf("%d", &x);
		minChange[v][x] = 0;
		minChange[v][1 ^ x] = INF;
	}

	FORD(i, (M-1)/2, 1) {
		int L = i*2, R = i*2+1;
		REP(t, 2) {
			int ifDontChange = make(t, G[i], L, R);
			int ifChange = INF;
			if (C[i])
				ifChange = make(t, G[i] ^ 1, L, R) + 1;
			minChange[i][t] = min(ifChange, ifDontChange);
		}
	}

	int res = minChange[1][V];
	cout << "Case #" << iTest << ": ";
	if (res >= INF)
		cout << "IMPOSSIBLE" << endl; else
		cout << res << endl;
}

int main()
{
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);
	int nTest;
	scanf("%d", &nTest);
	for (int iTest = 1; iTest <= nTest; iTest++)
		solve(iTest);
	return 0;
}
