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

#define INF (1 << 29)

int M[1 << 10];
int A[16][1 << 10];
int Res[16][16][1 << 10];

int F(int level, int miss, int mask, int P)
{
	if(level == P)
		return miss > M[mask] ? INF : 0;

	int& res = Res[level][miss][mask];
	if(res != -1)
		return res;

	return res = min(INF, min(
		F(level + 1, miss + 1, mask << 1, P) + F(level + 1, miss + 1, (mask << 1) + 1, P),
		F(level + 1, miss, mask << 1, P) + F(level + 1, miss, (mask << 1) + 1, P) + A[level][mask]));
}

int SolveTest(int test)
{
	int P;
	scanf("%d", &P);

	int i, j;
	FOR(i, 0, 1 << P)
		scanf("%d", &M[i]);

	RFOR(i, P, 0)
		FOR(j, 0, 1 << i)
			scanf("%d", &A[i][j]);

	CLEAR(Res, -1);
	printf("Case #%d: %d\n", test + 1, F(0, 0, 0, P));
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
