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

int R[2 << 10][1 << 10];
int gN, gM;

int f(int n, int m, int k)
{
	if (n == gN || k <= 0)
		return max(0, m - 2) + max(0, k);

	int pos = n*(gM + 1) + m;
	int& res = R[pos][k];
	if (res != -1)
		return res;

	int i;
	res = max(0, m - 2) + max(0, k);
	if (m == 0)
	{
		FOR(i, 1, gM + 1)
			res = min(res, f(n + 1, i, k - i) + i);
	}
	else
	{
		int from = max(1, m - 2);
		int to = min(gM, m + 2);

		FOR(i, from, to + 1)
			res = min(res, f(n + 1, i, k - i) + min(2, i));
	}

	return res;
}

int SolveTest(int test)
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	gN = n;
	gM = m;
	CLEAR(R, -1);
	printf("Case #%d: %d\n", test + 1, f(0, 0, k));
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
