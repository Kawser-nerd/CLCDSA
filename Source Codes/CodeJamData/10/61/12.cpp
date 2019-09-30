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

#define INF (1 << 20)

char buf[1 << 20];
char A[2][1 << 20];
int Res[2][7 << 10][7 << 10];
int R[128][128][4];

int F(int from, int to, int last)
{
	int& res = R[from][to][last];
	if(res != -1)
		return res;

	if(from >= to)
		return res = 0;

	int i;
	res = INF;

	if(buf[from] == 'A' + last)
		return res = F(from + 1, to, last);

	if(buf[to - 1] == 'A' + last)
		return res = F(from, to - 1, last);

	FOR(i, from + 1, to + 1)
		res = min(res, F(from, i, buf[from] - 'A') + 2 + F(i, to, last));

	return res;
}


int SolveTest2(int test)
{
	scanf("%s", buf);
	int len = strlen(buf);

	CLEAR(R, -1);

	printf("Case #%d: %d\n", test + 1, F(0, len, buf[0] - 'A') + 2 + len);
	return 0;
}


int SolveTest(int test)
{
	scanf("%s", buf);
	int len = strlen(buf);

	int i, j, k, l;
	int B[] = {0, 0, 0};
	B[ buf[0] - 'A' ] = 1;
	A[0][0] = A[1][0] = buf[0];

	int cnt = 1;
	FOR(i, 0, 3)
		if(B[i] == 0)
		{
			A[0][cnt] = 'A' + i;
			++cnt;
		}

	A[1][1] = A[0][2];
	A[1][2] = A[0][1];

	FOR(i, 3, len)
	{
		A[0][i] = A[0][i - 3];
		A[1][i] = A[1][i - 3];
	}

	FOR(i, 0, len + 1)
		FOR(j, 0, i + 1)
			FOR(k, 0, 2)
				Res[k][i][j] = INF;

	Res[0][0][0] = Res[1][0][0] = 0;
	FOR(i, 0, len)
		FOR(j, 0, i + 1)
			FOR(k, 0, 2)
				if(Res[k][i][j] != INF)
				{
					int from = 0;
					int to = 2;
					if(j > 1)
					{
						from = k;
						to = k + 1;
					}

					FOR(l, from, to)
					{
						if(j != 0 && buf[i] == A[l][j - 1])
							Res[l][i + 1][j] = min(Res[l][i + 1][j], Res[k][i][j]);

						if(buf[i] == A[l][j])
							Res[l][i + 1][j + 1] = min(Res[l][i + 1][j + 1], Res[k][i][j] + 1);

						if(j > 1 && buf[i] == A[l][j - 2])
							Res[l][i + 1][j - 1] = min(Res[l][i + 1][j - 1], Res[k][i][j] + 1);

						if(j > 2 && buf[i] == A[l][j - 3])
							Res[l][i + 1][j - 2] = min(Res[l][i + 1][j - 2], Res[k][i][j] + 2);
					}
				}

	int res = INF;
	FOR(i, 0, len + 1)
		FOR(k, 0, 2)
			res = min(res, Res[k][len][i] + i);

	printf("Case #%d: %d\n", test + 1, res + len);
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
