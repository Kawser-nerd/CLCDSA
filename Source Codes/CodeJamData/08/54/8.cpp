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

#define MOD 10007

const int DX[] = {1, 2};
const int DY[] = {2, 1};

int A[128][128];
int Res[128][128];

int F(int x, int y)
{
	if(x < 0 || y < 0 || A[x][y])
		return 0;
	
	int& res = Res[x][y];
	if(res != -1)
		return res;
	if(x == 0 && y == 0)
		return res = 1;

	res = 0;
	int i;
	FOR(i, 0, 2)
		res += F(x - DX[i], y - DY[i]);

	res %= MOD;
	return res;
}

int SolveTest(int test)
{
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	CLEAR(A, 0);
	int i;
	FOR(i, 0, K)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		A[x - 1][y - 1] = 1;
	}

	CLEAR(Res, -1);
	printf("Case #%d: %d\n", test + 1, F(N - 1, M - 1));
	return 0;
}

int main()
{
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
		SolveTest(t);

	return 0;
};
