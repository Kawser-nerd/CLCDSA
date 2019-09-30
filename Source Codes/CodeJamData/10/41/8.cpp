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

int A[256][256];

int SolveTest(int test)
{
	int K;
	scanf("%d", &K);
	int N = K + K - 1;

	CLEAR(A, -1);

	int i, j, k;
	FOR(i, 0, N)
	{
		int off = abs(i - (K - 1));
		int from = off;
		int to = N - off;
		FOR(j, from, to)
			A[i][j] = -2;
		for(j = from; j < to; j += 2)
			scanf("%d", &A[i][j]);
	}

	int resx = K;
	int resy = K;

	FOR(i, 0, N)
	{
		int found = 0;
		FOR(j, 0, N)
			FOR(k, 0, N)
				if(A[j][k] != -1)
				{
					int x = i + i - j;
					if(x >= 0 && x < N && A[x][k] != -1 && A[x][k] != A[j][k])
					{
						found = 1;
						break;
					}
				}

		if(found == 0)
			resx = min(resx, abs(i - (K - 1)));
	}

	FOR(i, 0, N)
	{
		int found = 0;
		FOR(j, 0, N)
			FOR(k, 0, N)
				if(A[j][k] != -1)
				{
					int y = i + i - k;
					if(y >= 0 && y < N && A[j][y] != -1 && A[j][y] != A[j][k])
					{
						found = 1;
						break;
					}
				}

		if(found == 0)
			resy = min(resy, abs(i - (K - 1)));
	}

	int M = K + resx + resy;
	printf("Case #%d: %d\n", test + 1, M*M - K*K);

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
