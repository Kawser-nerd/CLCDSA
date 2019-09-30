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

#define MOD 1000000007

PII A[1 << 19];
int Res[1 << 20];
int I[32];

int Sum(int a)
{
	Int res = 0;
	int i;
	FOR(i, 0, 19)
	{
		if(a & 1)
			res += Res[ I[i] + a - 1 ];

		a >>= 1;
	}

	return int(res % MOD);
}

void Update(int pos, int a)
{
	int i;
	FOR(i, 0, 19)
	{
		Res[ I[i] + pos ] += a;
		Res[ I[i] + pos ] %= MOD;
		pos >>= 1;
	}
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int T, t;
	scanf("%d", &T);
	FOR(t, 0, T)
	{
		int N, M, x, y, z;
		scanf("%d%d%d%d%d", &N, &M, &x, &y, &z);
		Int X = x;
		Int Y = y;
		Int Z = z;
		
		int i, j;
		FOR(i, 0, M)
			scanf("%d", &A[i].first);
		FOR(i, M, N)
			A[i].first = int((X*A[i - M].first + Y*(i + 1 - M)) % Z);

		FOR(i, 0, N)
			A[i].second = -i;

		sort(A, A + N);
		CLEAR(Res, 0);

		I[0] = 0;
		FOR(i, 1, 32)
			I[i] = I[i - 1] + (N >> (i - 1)) + 1;

		FOR(i, 0, N)
		{
			int pos = -A[i].second;
			int res = Sum(pos);
			Update(pos, (res + 1) % MOD);
		}

		int res = 0;
		FOR(i, 0, N)
		{
			res += Res[i];
			res %= MOD;
		}

		printf("Case #%d: %d\n", t + 1, res);
	}

	return 0;
};
