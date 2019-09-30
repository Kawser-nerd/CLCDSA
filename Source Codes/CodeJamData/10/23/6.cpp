#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <string>
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

#define MOD 100003

Int Res[512][512];
Int C[512][512];

Int F(int cnt, int a, int n)
{
	Int& res = Res[cnt][a];
	if(res != -1)
		return res;
	if(a == n)
		return res = 1;

	res = 0;
	int i;
	FOR(i, a + 1, n + 1)
		if(i - a - 1 >= a - cnt - 1)
		{
			res += F(a, i, n)*C[i - a - 1][a - cnt - 1];
			res %= MOD;
		}

	return res;
}

int SolveTest(int test)
{
	int N;
	scanf("%d", &N);

	CLEAR(Res, -1);
	printf("Case #%d: %d\n", test + 1, int(F(0, 1, N)));
	return 0;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int i, j;
	FOR(i, 0, 512)
		C[i][i] = C[i][0] = 1;
	FOR(i, 0, 512)
		FOR(j, 1, i)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;

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
