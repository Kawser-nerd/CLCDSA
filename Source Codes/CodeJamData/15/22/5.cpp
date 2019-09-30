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

int f(int r, int c, int n, int color)
{
	int i, j;
	int cnt[] = { 0, 0, 0, 0, 0 };
	FOR(i, 0, r)
		FOR(j, 0, c)
			if ((i + j) % 2 == color)
			{
				int a = 4;
				if (i == 0)
					--a;
				if (i == r - 1)
					--a;
				if (j == 0)
					--a;
				if (j == c - 1)
					--a;

				++cnt[a];
			}

	int res = 0;
	RFOR(i, 5, 1)
	{
		int t = min(r*c - n, cnt[i]);
		res += i * t;
		n += t;
	}

	return (r - 1)*c + (c - 1)*r - res;
}

int SolveTest(int test)
{
	int r, c, n;
	scanf("%d%d%d", &r, &c, &n);

	printf("Case #%d: %d\n", test + 1, min(f(r, c, n, 0), f(r, c, n, 1)));
	return 0;
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

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
