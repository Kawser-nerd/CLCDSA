#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

#define MAX 1001

int R[128][MAX];
int X[128];
int Y[128];
int Z[128];

int SolveTest(int test)
{
	int n;
	scanf("%d", &n);

	int i, j, k, l;
	vector< pair<int, PII> > v;
	FOR(i, 0, n)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v.PB(MP(z, PII(x, y)));
	}

	sort(ALL(v));

	FOR(i, 0, n)
	{
		X[i] = v[i].second.first;
		Y[i] = v[i].second.second;
		Z[i] = v[i].first;
	}

	v.clear();
	FOR(i, 0, n)
		FOR(j, 0, MAX)
			v.PB(MP(Z[i] + j, PII(i, j)));

	sort(ALL(v));
			

	int res = 0;
	CLEAR(R, -1);
	FOR(l, 0, SIZE(v))
	{
		i = v[l].second.first;
		j = v[l].second.second;

		if(j != 0)
			R[i][j] = R[i][j - 1];

		if(100*max(abs(X[i]), abs(Y[i])) <= Z[i] + j)
			R[i][j] = max(R[i][j], 1);

		FOR(k, 0, n)
			if(k != i)
			{
				int dist = max(750, 100*max(abs(X[i] - X[k]), abs(Y[i] - Y[k])));
				int time = Z[i] - Z[k] + j - dist;
				if(0 <= time && time < MAX && R[k][time] != -1)
					R[i][j] = max(R[i][j], R[k][time] + 1);
			}

		res = max(res, R[i][j]);
	}

	printf("Case #%d: %d\n", test + 1, res);

	return 0;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
