//#pragma comment(linker, "/STACK:134217728")

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
#include <numeric>
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

int SolveTest(int test)
{
	int N;
	scanf("%d", &N);

	int i, j;
	priority_queue< pair<Int, Int> > Q;
	int cnt = 0;
	FOR(i, 0, N)
	{
		int d, h, m;
		scanf("%d%d%d", &d, &h, &m);
		FOR(j, 0, h)
		{
			Int time = m + j;
			time *= 360;
			Int first = time * (360 - d) / 360;
			Q.push(MP(-first, -time));
			++cnt;
		}
	}

	int res = cnt;
	int best = res;
	while (!Q.empty())
	{
		Int time = -Q.top().first;
		Int next = -Q.top().second;
		Q.pop();

		if (time < next)
			--res;
		else
			++res;

		best = min(best, res);
		if (res > cnt + cnt)
			break;

		Q.push(MP(-time - next, -next));
	}

	printf("Case #%d: %d\n", test + 1, best);
	return 0;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

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
