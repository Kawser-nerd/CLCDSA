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

int X[64];
int V[64];

int SolveTest(int test)
{
	int N, B, T, K;
	scanf("%d%d%d%d", &N, &K, &B, &T);

	int i;
	FOR(i, 0, N)
		scanf("%d", &X[i]);
	FOR(i, 0, N)
		scanf("%d", &V[i]);

	int res = 0;
	RFOR(i, N, 0)
	{
		if(K == 0)
			break;

		Int time = V[i];
		time *= T;

		if(B - X[i] <= time)
			--K;
		else
			res += K;
	}

	if(K == 0)
		printf("Case #%d: %d\n", test + 1, res);
	else
		printf("Case #%d: IMPOSSIBLE\n", test + 1);

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
