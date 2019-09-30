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

#define MAX 6404

const int DX[] = {-1, -1, 1, 1, 0, 0};
const int DY[] = {-1, 1, -1, 1, -1, 1};

char A[128][128];
int C[128][128];
int D[128][128];
char E[MAX][MAX];
int Edge[MAX][MAX/2];
int CE[MAX];
int B[MAX];
int gN, gCnt;

int dfs(int a)
{
	if(a == gN - 1)
		return 1;
	if(B[a] == gCnt)
		return 0;
	B[a] = gCnt;

	int i;
	FOR(i, 0, CE[a])
	{
		int b = Edge[a][i];
		if(E[a][b] > 0 && B[b] != gCnt && dfs(b))
		{
			--E[a][b];
			++E[b][a];
			return 1;
		}
	}

	return 0;
}

int SolveTest(int test)
{
	int N, M;

	int i, j, k;
	scanf("%d%d", &N, &M);

	FOR(i, 0, N)
		scanf("%s", &A[i]);

//	CLEAR(A, '.');

	CLEAR(C, 0);
	int cnt[] = {0, 0};
	FOR(i, 0, N)
		FOR(j, 0, M)
			if(A[i][j] == '.')
			{
				D[i][j] = j & 1;
				C[i][j] = cnt[ D[i][j] ]++;
			}

	CLEAR(E, 0);
	FOR(i, 0, N)
		FOR(j, 0, M)
			if(A[i][j] == '.')
			{
				if(D[i][j] == 0)
				{
					FOR(k, 0, 6)
					{
						int x = i + DX[k];
						int y = j + DY[k];

						if(x < 0 || x >= N || y < 0 || y >= M || A[x][y] != '.')
							continue;

						int a = C[i][j];
						int b = cnt[0] + C[x][y];
						Edge[a][ CE[a]++ ] = b;
						Edge[b][ CE[b]++ ] = a;
						E[a][b] = 1;
					}

					int a = cnt[0] + cnt[1];
					int b = C[i][j];
					Edge[a][ CE[a]++ ] = b;
					Edge[b][ CE[b]++ ] = a;
					E[a][b] = 1;
				}
				else
				{
					int a = cnt[0] + C[i][j];
					int b = cnt[0] + cnt[1] + 1;
					Edge[a][ CE[a]++ ] = b;
					Edge[b][ CE[b]++ ] = a;
					E[a][b] = 1;
				}
			}

	gN = cnt[0] + cnt[1] + 2;
	
	int flow = 0;
	CLEAR(B, 0);
	gCnt = 0;
	while(true)
	{
		++gCnt;
		if(dfs(cnt[0] + cnt[1]) == 0)
			break;

		++flow;
	}

	printf("Case #%d: %d\n", test + 1, cnt[0] + cnt[1] - flow);
	fprintf(stderr, "Case #%d\n", test + 1);
	return 0;
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
		SolveTest(t);

	return 0;
};
