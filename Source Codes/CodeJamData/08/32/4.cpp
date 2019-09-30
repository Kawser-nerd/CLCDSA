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

typedef unsigned long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

#define MOD (2*3*5*7)
Int Res[2][64][64][MOD];
char buf[1 << 10];

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T, t;
	scanf("%d", &T);
	FOR(t, 0, T)
	{
		scanf("%s", buf);
		int N = strlen(buf);

		CLEAR(Res, 0);
		Res[0][0][0][0] = 1;

		int i, j, k, l, m;
		FOR(j, 0, N)
			FOR(k, 0, j + 1)
				FOR(l, 0, MOD)
					FOR(i, 0, 2)
						if(Res[i][j][k][l] != 0)
						{
							Res[i][j + 1][k][l] += Res[i][j][k][l];
							int rem = 0;
							FOR(m, k, j + 1)
							{
								rem *= 10;
								rem += buf[m] - '0';
								rem %= MOD;
							}

							if(i == 0)
								rem = (l + rem) % MOD;
							else
								rem = (l - rem + MOD) % MOD;

							Res[0][j + 1][j + 1][rem] += Res[i][j][k][l];
							Res[1][j + 1][j + 1][rem] += Res[i][j][k][l];
						}

		Int res = 0;
		FOR(i, 0, MOD)
			if(i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
				res += Res[0][N][N][i];

		printf("Case #%d: %llu\n", t + 1, res);
	}

	return 0;
};
