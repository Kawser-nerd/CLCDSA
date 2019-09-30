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
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	x = abs(x);
	int z = (x + y)/2;

	int cnt = 0;
	while(n >= 4*cnt + 1)
	{
		n -= 4*cnt + 1;
		++cnt;
	}

	double res = cnt > z ? 1.0 : 0.0;
	if(cnt == z && x != 0)
	{
		if(n >= 2*cnt + y + 1)
			res = 1.0;
		else if(n >= y + 1)
		{
			int i;
			double c = 1.0;
			FOR(i, 0, n - y)
			{
				res += c;
				c *= n - i;
				c /= i + 1;
			}

			FOR(i, 0, n)
				res /= 2;
		}
	}

	printf("Case #%d: %.11lf\n", test + 1, res);
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
