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

#define MAX 3003

const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};

char A[MAX + MAX][MAX + MAX];
char B[MAX + MAX][MAX + MAX];

int SolveTest(int test)
{
	int N;
	scanf("%d", &N);

	int x = MAX;
	int y = MAX;
	int z = 0;
	int xx, yy;

	CLEAR(A, 0);
	CLEAR(B, 0);
	int i, j, k;
	FOR(i, 0, N)
	{
		char buf[1 << 17];
		int M;
		scanf("%s%d", buf, &M);

		int len = strlen(buf);
		FOR(j, 0, M)
			FOR(k, 0, len)
				switch(buf[k])
				{
				case 'F':
					xx = x + DX[z];
					yy = y + DY[z];

					if(z == 0)
						A[x][y] = 1;
					if(z == 2)
						A[xx][yy] = 1;

					x = xx;
					y = yy;
					break;
				case 'L':
					z = (z + 1) & 3;
					break;
				case 'R':
					z = (z + 3) & 3;
					break;
				}
	}

	int res1 = 0;
	int res2 = 0;
	FOR(i, 0, MAX + MAX)
	{
		int Min = MAX + MAX;
		int Max = -1;
		int prev = -1;

		FOR(j, 0, MAX + MAX)
			if(A[i][j])
			{
				Min = min(Min, j);
				Max = max(Max, j);

				if(prev == -1)
					prev = j;
				else
				{
					res1 += j - prev;
					prev = -1;
				}
			}

		if(Max >= 0)
			FOR(j, Min, Max)
				B[i][j] = 1;
	}

	FOR(j, 0, MAX + MAX)
	{
		int Min = MAX + MAX;
		int Max = -1;

		FOR(i, 0, MAX + MAX)
			if(B[i][j])
			{
				Min = min(Min, i);
				Max = max(Max, i);
			}

		if(Max >= 0)
			res2 += Max - Min + 1;
	}

	printf("Case #%d: %d\n", test + 1, res2 - res1);
	fprintf(stderr, "Case #%d\n", test + 1);

	return 0;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
		SolveTest(t);

	return 0;
};
